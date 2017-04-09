# makefile
# date 2016-09-06 11:10:08
# Copyright 2016 Mamoru kaminaga
# #You have to fix "CC" and "LINK" for your environment.

# Set `CC` compiler path
CC = "C:\"Microsoft Visual Studio 14.0"\VC\bin\cl.exe"

# Set `LINK` linker path
LINK = "C:\"Microsoft Visual Studio 14.0"\VC\bin\link.exe"

OUTDIR = build
TARGET = cwconv.exe
PDBFILE = symbols/exe/cwconv.pdb
MAPFILE = maps/cwconv.map
RESFILE = resource.res

SRC = common.cc main.cc morse_player.cc sound_device.cc
OBJS = $(OUTDIR)/common.obj $(OUTDIR)/main.obj $(OUTDIR)/morse_player.obj $(OUTDIR)/sound_device.obj

LIBS = "kernel32.lib" "user32.lib" "gdi32.lib" "winspool.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "odbc32.lib" "odbccp32.lib" "dsound.lib" "winmm.lib" "dxguid.lib"

# Debug build
#CPPFLAGS = /nologo /W4 /Zi /O2 /MT /D"UNICODE" /D"_UNICODE" /TP /EHsc /Fd"$(OUTDIR)/"
#LFLAGS = $(LIBS) /NOLOGO /SUBSYSTEM:WINDOWS /LIBPATH:"C:\projects" /PDB:"$(PDBFILE)" /MAP:"$(MAPFILE)" /DEBUG

# Release build
CPPFLAGS = /nologo /W4 /Zi /O2 /MT /D"UNICODE" /D"_UNICODE" /EHsc /Fd"$(OUTDIR)/" /D"NODEBUG"
LFLAGS = $(LIBS) /NOLOGO /SUBSYSTEM:WINDOWS /PDB:"$(PDBFILE)" /MAP:"$(MAPFILE)"

ALL: $(TARGET)

$(TARGET): $(OBJS) $(RESFILE)
	$(LINK) $(LFLAGS) /OUT:$(TARGET) $(OBJS) $(RESFILE)

.cc{$(OUTDIR)}.obj:
	$(CC) $(CPPFLAGS) /Fo"$(OUTDIR)\\" /c $<
