# App can compile for platform:
#    PLATFORM=EZX-E2
#    PLATFORM=EZX-Z6
#    PLATFORM=EZX-V8
#    PLATFORM=EZX-E8
#    PLATFORM=EZX-EM30
#    PLATFORM=EZX-Z6W
#    PLATFORM=EZX-U9
#    PLATFORM=EZX-ZN5 (defaul)
#    PLATFORM=EZX-AURA
#    PLATFORM=EZX-VE66
#    PLATFORM=EZX-EM35
#.
# For example - compile this source for Motorla ZN5:
#.
# cd /PROJECT_FOLDER/
# make clean
# make PLATFORM=EZX-ZN5
#.

######Config######

APPNAME    := HelloWorldUI
UPLOAD_PATH :=  /mmc/mmca1/bin/
BUILDTIME := $(shell TZ=UTC date -u "+%Y.%m.%d-%H:%M%z")
export BUILDTIME 
##################

TOOLPREFIX := /arm-eabi
ARMLIB     := $(TOOLPREFIX)/arm-linux-gnueabi/lib


ifeq ($(PLATFORM),)
PLATFORM = EZX-ZN5
endif

ifeq ($(PLATFORM),EZX-E2)
QTDIR    :=    $(TOOLPREFIX)/lib/qt-e2
EZXDIR    :=    $(TOOLPREFIX)/lib/ezx-e2
LINKLIB := -lm -lqte-mt -lezxappbase
DIRECTIV := -DEZX_E2
TARGET    =       $(APPNAME)_E2
endif


ifeq ($(PLATFORM),EZX-Z6)
QTDIR    :=    $(TOOLPREFIX)/lib/qt-2.3.8
EZXDIR    :=    $(TOOLPREFIX)/lib/ezx-z6
LINKLIB := -lm -lqte-mt -lezxappbase
DIRECTIV := -DEZX_Z6
TARGET    =       $(APPNAME)_Z6
endif


ifeq ($(PLATFORM),EZX-V8)
QTDIR    :=    $(TOOLPREFIX)/lib/qt-v8
EZXDIR    :=    $(TOOLPREFIX)/lib/ezx-v8
LINKLIB := -lm -lqte-mt -lezxappbase
DIRECTIV := -DEZX_V8
TARGET    =       $(APPNAME)_V8
ZNEWCHECKBOX = 1
endif


ifeq ($(PLATFORM),EZX-E8)
ARMLIB     := $(TOOLPREFIX)/arm-linux-gnueabi/lib_E8
QTDIR    :=    $(TOOLPREFIX)/lib/qt-e8
EZXDIR    :=    $(TOOLPREFIX)/lib/ezx-e8
LINKLIB := -lm -lqte-mt -lezxappbase
DIRECTIV := -DEZX_E8
TARGET    =       $(APPNAME)_E8
endif


ifeq ($(PLATFORM),EZX-EM30)
ARMLIB     := $(TOOLPREFIX)/arm-linux-gnueabi/lib_E8
QTDIR    :=    $(TOOLPREFIX)/lib/qt-em30
EZXDIR    :=    $(TOOLPREFIX)/lib/ezx-em30
EZXDIR2    :=    $(TOOLPREFIX)/lib/ezx-e8
LINKLIB := -lm -lqte-mt -lezxappbase
DIRECTIV := -DEZX_EM30
TARGET    =       $(APPNAME)_EM30
endif


ifeq ($(PLATFORM),EZX-Z6W)
QTDIR    :=    $(TOOLPREFIX)/lib/qt-z6w
EZXDIR    :=    $(TOOLPREFIX)/lib/ezx-z6w
LINKLIB := -lm -lqte-mt -lezxappbase
DIRECTIV := -DEZX_Z6W
TARGET    =       $(APPNAME)_Z6W
endif


ifeq ($(PLATFORM),EZX-U9)
QTDIR    :=    $(TOOLPREFIX)/lib/qt-zn5
EZXDIR    :=    $(TOOLPREFIX)/lib/ezx-u9
EZXDIR2    :=    $(TOOLPREFIX)/lib/ezx-zn5
LINKLIB := -lm -lqte-mt -lezxappbase
DIRECTIV := -DEZX_U9
TARGET    =       $(APPNAME)_U9
endif


ifeq ($(PLATFORM),EZX-ZN5)
QTDIR    :=    $(TOOLPREFIX)/lib/qt-zn5
EZXDIR    :=    $(TOOLPREFIX)/lib/ezx-zn5
LINKLIB := -lm -lqte-mt -lezxappbase   # -lezxmystuff-base -lezx_mp_commonplayer -lezxcalendarengine
DIRECTIV := -DEZX_ZN5
TARGET    =       $(APPNAME)_ZN5
endif

ifeq ($(PLATFORM),EZX-AURA)
QTDIR    :=    $(TOOLPREFIX)/lib/qt-zn5
EZXDIR    :=    $(TOOLPREFIX)/lib/ezx-aura
EZXDIR2    :=    $(TOOLPREFIX)/lib/ezx-aura
LINKLIB := -lm -lqte-mt -lezxappbase
DIRECTIV := -DEZX_AURA
TARGET    =       $(APPNAME)_AURA
endif

ifeq ($(PLATFORM),EZX-EM35)
ARMLIB     := $(TOOLPREFIX)/arm-linux-gnueabi/lib_E8
QTDIR    :=    $(TOOLPREFIX)/lib/qt-em35
EZXDIR    :=    $(TOOLPREFIX)/lib/ezx-em35
LINKLIB := -lm -lqte-mt -lezxappbase
DIRECTIV := -DEZX_EM35
TARGET    =       $(APPNAME)_EM35
endif


ifeq ($(PLATFORM),EZX-VE66)
ARMLIB     := $(TOOLPREFIX)/arm-linux-gnueabi/lib_E8
QTDIR    :=    $(TOOLPREFIX)/lib/qt-em35
EZXDIR    :=    $(TOOLPREFIX)/lib/ezx-ve66
LINKLIB := -lm -lqte-mt -lezxappbase
DIRECTIV := -DEZX_VE66
TARGET    =       $(APPNAME)_VE66
endif



CC        =    $(TOOLPREFIX)/bin/arm-linux-gnueabi-gcc
CXX        =    $(TOOLPREFIX)/bin/arm-linux-gnueabi-g++
LD        =    $(TOOLPREFIX)/bin/arm-linux-gnueabi-g++
STRIP   =   $(TOOLPREFIX)/bin/arm-linux-strip
CFLAGS    =    -pipe -Wall -W -O2 -DNO_DEBUG $(INCPATH)
CXXFLAGS=    -pipe -DQWS -fno-exceptions -fno-rtti -Wall -W -O2 -DNO_DEBUG $(DIRECTIV) $(INCPATH)
INCPATH    =    -I./include -I$(TOOLPREFIX)/arm-linux-gnueabi/include -I$(QTDIR)/include -I$(EZXDIR)/include -I$(EZXDIR2)/include 
LDFLAGS    =    -s
LINK    =    $(TOOLPREFIX)/bin/arm-linux-gnueabi-gcc
LFLAGS    =    -Wl,-rpath-link,$(EZXDIR)/lib
LIBS    =    -L/home/fill/tttt_alllib $(SUBLIBS) -L$(ARMLIB) -L$(EZXDIR)/lib -L$(EZXDIR2)/lib -L$(QTDIR)/lib $(LINKLIB)
MOC        =    $(QTDIR)/bin/moc
UIC        =    $(QTDIR)/bin/uic

####### Files

HEADERS =	HelloWorld.h
            
SOURCES =	main.cpp\
            HelloWorld.cpp
	    
OBJECTS =   main.o\
			HelloWorld.o

INTERFACES =	
UICDECLS =	
UICIMPLS =	
SRCMOC	=	moc_HelloWorld.cpp
OBJMOC	=	moc_HelloWorld.o
DIST	=	
#TARGET	=	test
INTERFACE_DECL_PATH = .

####### Implicit rules

.SUFFIXES: .cpp .cxx .cc .C .c

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o $@ $<

####### Build rules


all: $(TARGET)

$(TARGET): $(UICDECLS) $(OBJECTS) $(OBJMOC) 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJMOC) $(LIBS)
#		$(STRIP) -s $(TARGET)

moc: $(SRCMOC)

tmake: Makefile

#Makefile: Hello.pro
#	tmake Hello.pro -o Makefile

dist:
	$(TAR) Hello.tar Hello.pro $(SOURCES) $(HEADERS) $(INTERFACES) $(DIST)
	$(GZIP) Hello.tar

clean:
	-rm -f $(OBJECTS) $(OBJMOC) $(SRCMOC) $(UICIMPLS) $(UICDECLS) 
	#$(TARGET)
	-rm -f *~ core
	$(RM) moc_*.cpp

####### Sub-libraries


###### Combined headers


####### Compile

#----------- obj -----------------------------
#main.o: main.cpp
HelloWorld.o: HelloWorld.cpp  \
	          HelloWorld.h
#			moc_HelloWorld.cpp

#--------- moc's -----------------------------	

moc_HelloWorld.cpp: HelloWorld.h
	$(MOC) HelloWorld.h -o moc_HelloWorld.cpp
#----------------------------------------------	
installsmb: $(TARGET)
	smbclient -U guest smb://192.168.16.2/
	smb: \> cd /log 
	$(UPLOAD_PATH) $(TARGETS)

installftp: $(TARGETS)
	ncftpput -u root -p "" 192.168.16.2 $(UPLOAD_PATH) $(TARGETS)	
