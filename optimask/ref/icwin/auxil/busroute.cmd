default global #bus.add.message.on = 1;
default local #scratch.layer = 251;

!*********************************************************************!
!                                                                     !
!        Get bus parameters - use old parameters as defaults          !
!                                                                     !
!*********************************************************************!

! ************** Get bus layer: ************** 

@_get_lay; &
   local #prompt="bus layer"; &
   if(macro_exists(#bus.last.layer)) local #default=%bus.last.layer;
local #layer = %ret.value
global #bus.last.layer = %ret.value

! *********** Get number of wires ************

@_get_int; &
   local #prompt="number of wires"; &
   local #min=1; &
   if(macro_exists(#bus.last.n.wires)) local #default=%bus.last.n.wires;
local #n.wires = %ret.value
global #bus.last.n.wires = %ret.value

! ************** Get wire width ************** 

@_get_real; &
   local #prompt="wire width"; &
   if(macro_exists(#bus.width.%layer)) local #default=%bus.width.%layer; &
   local #min=%res.step;
local #width = %ret.value
global #bus.width.%layer = %ret.value

! ************* Get wire spacing *************

@_get_real; &
   local #prompt="wire spacing"; &
   if(macro_exists(#bus.space.%layer)) local #default=%bus.space.%layer; &
   local #min=%res.step;
local #space = %ret.value
global #bus.space.%layer = %ret.value

!*********************************************************************!
!                                                                     !
!                      Remove old BUSROUTE.OUT                        !
!                                                                     !
!*********************************************************************!

! If an old BUSROUTE.OUT exists and BUSROUT.EXE crashes then BUSROUTE.CMD 
! will mistake the existing file for new output generated by the upcoming
! call to BUSROUT.EXE.  We will try to avoid that possibility by deleting
! any existing BUSROUTE.OUT.  This is not fool proof, since the system 
! will deny a request to delete a "protected" file.

dos '^del "%tmp^busroute.out" > NUL'

!*********************************************************************!
!                                                                     !
!                              Do it                                  !
!                                                                     !
!*********************************************************************!

local #pitch = {%space + %width}
local #total.width = {%n.wires * %pitch + %space}
local #n.select.push = %n.select

if(%n.select.push) unselect push
if(%bus.add.message.on){
   #bus.add.message.on = 0;
   $Press <Enter> to route bus outline (This message will not appear next time)
   pause 0
}
local #save.snap.angle = %snap.angle  ! save snap angle to restore later
snap angle = 90
view on; ! Make sure screen is updated if user pans while adding wire
add wire layer=%scratch.layer width=%total.width type=0 
view off;
snap angle = %save.snap.angle

! ****** Setup for UNED after BUSROUTE.CMD can no longer be cancelled ******

global #uned.file.name = "do_nothing"
global #ed.file.name = %tmp^busroute.out
global #uned.enabled = 0 ! flag indicating nothing yet done

select new
show prog=1 file=%tmp^busroute.sho
dos "^%exec.dir^busroute.exe %tmp %scratch.layer %layer %use.wire.type %width %space %n.wires"

global #ed.id0 = %id.max
@"%tmp^busroute.out"; view off
global #ed.id1 = %id.max;
global #uned.enabled = 1

delete
if(%n.select.push) select pop;
