# simple unified Makefile for mxToolKit

LIB_NAME = libmxtk

CXX ?= g++

PREFIX ?= /usr/local

CFLAGS += -O3 -pipe -DNDEBUG
CXXFLAGS =

SYS = $(shell $(CXX) -dumpmachine)
ifneq (, $(findstring mingw, $(SYS)))
PLATFORM = win32

STATIC_LIB_EXT = lib
SHARED_LIB_EXT = dll

LIBS = -lcomctl32 -lcomdlg32 -lgdi32 -lopengl32 -lwinmm -static-libgcc -static-libstdc++
else
CFLAGS += -fPIC

PLATFORM = qt

STATIC_LIB_EXT = a
SHARED_LIB_EXT = so

MOC ?= moc

MOC_HEADERS = $(wildcard src/$(PLATFORM)/*_i.h)
MOC_PREFIX = $(subst $(PLATFORM)/,$(PLATFORM)/moc_,$(MOC_HEADERS))
MOC_SRC = $(MOC_PREFIX:%_i.h=%.cpp)
MOC_OBJS = $(MOC_SRC:%.cpp=%.o)

INCLUDE = $(shell pkg-config --cflags Qt5OpenGL gl)
LIBS = $(shell pkg-config --libs Qt5OpenGL gl)
endif

SRC = $(wildcard src/$(PLATFORM)/*.cpp) $(wildcard src/common/*.cpp)
OBJS = $(SRC:%.cpp=%.o)

INCLUDE += -Iinclude -Isrc/$(PLATFORM)
LDFLAGS += -shared

DEST_LIB = $(PREFIX)/lib
DEST_INC = $(PREFIX)/include

STATIC_LIB = lib/$(LIB_NAME)-$(PLATFORM).$(STATIC_LIB_EXT)
SHARED_LIB = lib/$(LIB_NAME)-$(PLATFORM).$(SHARED_LIB_EXT)

all: $(STATIC_LIB) $(SHARED_LIB)

$(STATIC_LIB): $(OBJS) $(MOC_OBJS)
	ar rcs $(STATIC_LIB) $(OBJS) $(MOC_OBJS)

$(SHARED_LIB): $(OBJS) $(MOC_OBJS)
	$(CXX) $(OBJS) $(MOC_OBJS) $(LDFLAGS) $(LIBS) -o $(SHARED_LIB)

#ifeq (, $(findstring mingw, $(SYS)))
moc_%.cpp: %_i.h
	$(MOC) $< -o $@
#endif

.cpp.o:
	$(CXX) $(CFLAGS) $(CPPFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: all clean install

# clean

clean:
	$(RM) $(OBJS) $(MOC_OBJS)

# install

install:
	install -m 644 $(STATIC_LIB) $(DEST_LIB)
	install -m 644 $(SHARED_LIB) $(DEST_LIB)
	install -m 644 -D ../../include/mx/* $(DEST_INC)/mx
