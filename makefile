# makefile
# since 2016-05-07

#Input files
OUTDIR = build
PROGRAM = cwconv
SRC = main.cpp morse.cpp common.cpp
OBJS = $(OUTDIR)\main.obj $(OUTDIR)\morse.obj $(OUTDIR)\common.obj

# describe tools
CC = "C:\"Microsoft Visual Studio 14.0"\VC\bin\cl.exe"
LINK = "C:\"Microsoft Visual Studio 14.0"\VC\bin\link.exe"
LIBS =	"kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib"\
	  	"comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib"\
	  	"uuid.lib" "odbc32.lib" "odbccp32.lib"\
	   	winmm.lib
RM = del

CPPFLAGS = /nologo /W4 /Zi /DUNICODE /D_UNICODE /Fo"$(OUTDIR)\\" /MT
LFLAGS = /NOLOGO /DEBUG /MAP:$(PROGRAM).map /PDB:$(PROGRAM).pdb $(LIBS)\
	/ERRORREPORT:NONE\
	/SUBSYSTEM:WINDOWS\
	/PDB:"$(OUTDIR)\$(PROGRAM).pdb"

ALL: $(OUTDIR)\$(PROGRAM).exe

CLEAN:
	$(RM) $(OUTDIR)\*

$(OUTDIR)\$(PROGRAM).exe: $(OBJS)
	$(LINK) $(LFLAGS) /OUT:$(OUTDIR)\$(PROGRAM).exe $(OBJS)

.cpp{$(OUTDIR)}.obj:
	$(CC) $(CPPFLAGS) /c $<
