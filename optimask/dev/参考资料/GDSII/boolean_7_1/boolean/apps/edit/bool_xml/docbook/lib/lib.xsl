<?xml version='1.0'?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                xmlns:doc="http://nwalsh.com/xsl/documentation/1.0"
                exclude-result-prefixes="doc"
                version='1.0'>

<!-- ********************************************************************
     $Id: lib.xsl,v 1.4 2000/10/19 20:56:08 ndw Exp $
     ********************************************************************

     This file is part of the XSL DocBook Stylesheet distribution.
     See ../README or http://nwalsh.com/docbook/xsl/ for copyright
     and other information.

     This module implements DTD-independent functions

     ******************************************************************** -->

<doc:reference xmlns="">
<referenceinfo>
<releaseinfo role="meta">
$Id: lib.xsl,v 1.4 2000/10/19 20:56:08 ndw Exp $
</releaseinfo>
<author><surname>Walsh</surname>
<firstname>Norman</firstname></author>
<copyright><year>1999</year><year>2000</year>
<holder>Norman Walsh</holder>
</copyright>
</referenceinfo>
<title>Library Template Reference</title>

<partintro>
<section><title>Introduction</title>

<para>This is technical reference documentation for the DocBook XSL
Stylesheets; it documents (some of) the parameters, templates, and
other elements of the stylesheets.</para>

<para>This is not intended to be <quote>user</quote> documentation.
It is provided for developers writing customization layers for the
stylesheets, and for anyone who's interested in <quote>how it
works</quote>.</para>

<para>Although I am trying to be thorough, this documentation is known
to be incomplete. Don't forget to read the source, too :-)</para>
</section>
</partintro>
</doc:reference>

<xsl:template name="dot.count">
  <!-- Returns the number of "." characters in a string -->
  <xsl:param name="string"></xsl:param>
  <xsl:param name="count" select="0"/>
  <xsl:choose>
    <xsl:when test="contains($string, '.')">
      <xsl:call-template name="dot.count">
        <xsl:with-param name="string" select="substring-after($string, '.')"/>
        <xsl:with-param name="count" select="$count+1"/>
      </xsl:call-template>
    </xsl:when>
    <xsl:otherwise>
      <xsl:value-of select="$count"/>
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>

<!-- ================================================================== -->

<xsl:template name="copy-string">
  <!-- returns 'count' copies of 'string' -->
  <xsl:param name="string"></xsl:param>
  <xsl:param name="count" select="0"/>
  <xsl:param name="result"></xsl:param>

  <xsl:choose>
    <xsl:when test="$count>0">
      <xsl:call-template name="copy-string">
        <xsl:with-param name="string" select="$string"/>
        <xsl:with-param name="count" select="$count - 1"/>
        <xsl:with-param name="result">
          <xsl:value-of select="$result"/>
          <xsl:value-of select="$string"/>
        </xsl:with-param>
      </xsl:call-template>
    </xsl:when>
    <xsl:otherwise>
      <xsl:value-of select="$result"/>
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>

<!-- ================================================================== -->

<doc:template name="xpointer.idref" xmlns="">
<refpurpose>Extract IDREF from an XPointer</refpurpose>
<refdescription>
<para>The <function>xpointer.idref</function> template returns the
ID portion of an XPointer which is a pointer to an ID within the current
document, or the empty string if it is not.</para>
<para>In other words, <function>xpointer.idref</function> returns
<quote>foo</quote> when passed either <literal>#foo</literal>
or <literal>#xpointer(id('foo'))</literal>, otherwise it returns
the empty string.</para>
</refdescription>
</doc:template>

<xsl:template name="xpointer.idref">
  <xsl:param name="xpointer">http://...</xsl:param>
  <xsl:choose>
    <xsl:when test="starts-with($xpointer, '#xpointer(id(')">
      <xsl:variable name="rest" select="substring-after($xpointer, '#xpointer(id(')"/>
      <xsl:variable name="quote" select="substring($rest, 1, 1)"/>
      <xsl:value-of select="substring-before(substring-after($xpointer, $quote), $quote)"/>
    </xsl:when>
    <xsl:when test="starts-with($xpointer, '#')">
      <xsl:value-of select="substring-after($xpointer, '#')"/>
    </xsl:when>
    <!-- otherwise it's a pointer to some other document -->
  </xsl:choose>
</xsl:template>

<!-- ================================================================== -->

</xsl:stylesheet>
