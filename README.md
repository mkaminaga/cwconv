2016/05/15 mkaminaga

cwconv
====
	The command line tool to easily convert command line argument into morse code.

Requirement
====
	Windows CL compiler (Visual C++ compiler).

Install
====
	1. Setup build environment to use cl compiler.
		You have to get cl compiler by installing Visual studio Community 2015 and Windows SDK.

	2. Set path collectly.
		There are four environmental variables related to Visual studio community and Windows SDK; PATH, LIB, LIBPATH and INCLUDE. These pathes are used by cl.exe, nmake.exe and link.exe.

	3. Actually build this program.
		In command line or in IDE, build main.cpp. In commandline build with makefile, the binary will generated under build/.
