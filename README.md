Copyright 2016 Mamoru kaminaga<br>

cwconv
====
  Play morse from command line.<br>

Requirement
====
  Windows PC and suitable compiler (In my case, Visual C++, CL compiler).<br>
  Windows SDK.<br>
  DirectSound.<br>

Install
====
  1. Setup build environment<br>
  You have to setup environment for command line build.<br>

  2. Set path<br>
  Set environmental variables (PATH, LIB, LIBPATH and INCLUDE) for Windows SDK.<br>

  3. Fix makefile<br>
  Fix variable "CC" and "LINK" to your environment.<br>

  4. Build this program in command line.<br>
  Build cwconv !

Usage
====
  options:<br>
  -help:     Show help<br>
  -nowindow: Not show output console<br>
  -nosound:  Not play midi sound<br>
  -wpm:      Set WPM, default is 20<br>
  -paris:    Set PARIS, default is 20<br>
  -s:        Input string to be morse signal<br>
  example)<br>
  -wpm 20 -s Good Morning!<br>
  result)<br>
