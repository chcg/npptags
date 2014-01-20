#############################################################################
#                                                                           #
#               Makefile for building a MinGW NppTags.dll                   #
#                                                                           #
#  NOTE: remember to keep tabs in the file. Don't convert them to spaces!   #
#                                                                           #
#############################################################################

.SUFFIXES: .exe .res .a .o .gch .c .cpp .cc .cxx .m .rc .p .f .F .r .y .l .s .S .def .h

ARCH = i686-w64-mingw32
CC = $(ARCH)-gcc
CXX = $(ARCH)-g++
AR = $(ARCH)-ar
RANLIB = $(ARCH)-ranlib
WINDRES = $(ARCH)-windres

#
CFLAGS = -c -O2 -DUNICODE -mtune=i686
CXXFLAGS = $(CFLAGS) -W -Wall -Wno-write-strings -gstabs -mwindows
RESFLAGS = -O coff
LIBS = -static-libgcc -lshlwapi -lgdi32 -lcomctl32
LDFLAGS = -Wl,--out-implib,$(TARGET) -shared -mthreads

.c.o:
	$(CC) $(CFLAGS) -o $@ $<

.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ $<

.rc.o:
	$(WINDRES) $(RESFLAGS) -o $@ -i $<

PROGRAM = NppTags
TARGET = $(PROGRAM).dll

now: $(TARGET)

all: clean depend now

PROGRAM_SRCS_CPP = \
	DlgAbout.cpp \
	DlgSelectTag.cpp \
	DlgTree.cpp \
	NppTags.cpp \
	SqliteDatabase.cpp \
	Tag.cpp \
	TagsDatabase.cpp \
	Options.cpp \
	Version.cpp \
	WaitCursor.cpp

PROGRAM_SRCS_C = \
	readtags.c \
	sqlite3.c

PROGRAM_OBJS_CPP=$(PROGRAM_SRCS_CPP:.cpp=.o)
PROGRAM_OBJS_C=$(PROGRAM_SRCS_C:.c=.o)

PROGRAM_RC=$(PROGRAM)_res.rc
PROGRAM_OBJS_RC=$(PROGRAM_RC:.rc=.o)

$(PROGRAM).dll: $(PROGRAM_OBJS_CPP) $(PROGRAM_OBJS_C) $(PROGRAM_OBJS_RC)
	$(CXX) -o $@ $(PROGRAM_OBJS_CPP) $(PROGRAM_OBJS_C) $(PROGRAM_OBJS_RC) $(LDFLAGS) $(LIBS)

depend: $(PROGRAM_SRCS_CPP)
	$(CXX) -MM $^ > Makefile.deps

clean:
	rm -f $(PROGRAM_OBJS_CPP) $(PROGRAM_OBJS_C) $(PROGRAM_OBJS_RC) $(PROGRAM).dll $(PROGRAM).dll.map $(PROGRAM).a tags tags.sqlite Makefile.deps
	touch Makefile.deps

### code dependencies ###

$(PROGRAM)_res.o: $(PROGRAM)_res.rc Version.h

include Makefile.deps
