# makefile
# date 2016-09-06 11:10:08
# Copyright 2016 Mamoru kaminaga
# #You have to fix "CC" and "LINK" for your environment.
OUTDIR = build
TARGET = cwconv.exe
PDBFILE = symbols/exe/cwconv.pdb
MAPFILE = maps/cwconv.map
RESFILE = resource.res

SRC = common.cc main.cc morse_player.cc
OBJS = $(OUTDIR)/common.obj $(OUTDIR)/main.obj $(OUTDIR)/morse_player.obj

LIBS = "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" "dsound.lib" "winmm.lib" "winmm.lib"

CC = "C:\"Microsoft Visual Studio 14.0"\VC\bin\cl.exe"
LINK = "C:\"Microsoft Visual Studio 14.0"\VC\bin\link.exe"
RM = del

#Debug build
#CPPFLAGS = /nologo /W4 /Zi /O2 /MT /D"UNICODE" /D"_UNICODE" /I"C:\projects" /TP /EHsc /Fd"$(OUTDIR)/" /D"_CRT_SECURE_NO_WARNINGS" /D"DIRECTINPUT_VERSION=0x0800"
#LFLAGS = $(LIBS) /NOLOGO /SUBSYSTEM:WINDOWS /LIBPATH:"C:\projects" /PDB:"$(PDBFILE)" /MAP:"$(MAPFILE)" /DEBUG

#Release build
CPPFLAGS = /nologo /W4 /Zi /O2 /MT /D"UNICODE" /D"_UNICODE" /I"C:\projects" /EHsc /Fd"$(OUTDIR)/" /D"_CRT_SECURE_NO_WARNINGS" /D"DIRECTINPUT_VERSION=0x0800" /D"NODEBUG"
LFLAGS = $(LIBS) /NOLOGO /SUBSYSTEM:WINDOWS /LIBPATH:"C:\projects" /PDB:"$(PDBFILE)" /MAP:"$(MAPFILE)"

ALL: $(TARGET)

$(TARGET): $(OBJS) $(RESFILE)
	$(LINK) $(LFLAGS) /OUT:$(TARGET) $(OBJS) $(RESFILE)

.cc{$(OUTDIR)}.obj:
	$(CC) $(CPPFLAGS) /Fo"$(OUTDIR)\\" /c $<
