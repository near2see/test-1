cls
set iced_home=c:\icwin;
set iced_path=
set iced_cmd_path=c:\icwin\tech\samples
set drc_path=c:\icwin\tutor;
if _%1==_ goto done
c:\icwin\iced %1 start=c:\icwin\samples\drc\new menu=DRC pause=0 maximize=yes win=500
:done
