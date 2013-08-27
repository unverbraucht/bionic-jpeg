## Process this file with automake to produce Makefile.in
#
#  Automake Makefile for the JPEG library
#
#  This file is written by Bob Friesenhahn, Guido Vollbeding
#

# Sources to build library
LIBSOURCES = ../jpeg-9/jaricom.c ../jpeg-9/jcapimin.c ../jpeg-9/jcapistd.c ../jpeg-9/jcarith.c ../jpeg-9/jccoefct.c ../jpeg-9/jccolor.c \
        ../jpeg-9/jcdctmgr.c ../jpeg-9/jchuff.c ../jpeg-9/jcinit.c ../jpeg-9/jcmainct.c ../jpeg-9/jcmarker.c ../jpeg-9/jcmaster.c \
       ../jpeg-9/jcomapi.c ../jpeg-9/jcparam.c ../jpeg-9/jcprepct.c ../jpeg-9/jcsample.c ../jpeg-9/jctrans.c ../jpeg-9/jdapimin.c \
        ../jpeg-9/jdapistd.c ../jpeg-9/jdarith.c ../jpeg-9/jdatadst.c ../jpeg-9/jdatasrc.c ../jpeg-9/jdcoefct.c ../jpeg-9/jdcolor.c \
        ../jpeg-9/jddctmgr.c ../jpeg-9/jdhuff.c ../jpeg-9/jdinput.c ../jpeg-9/jdmainct.c ../jpeg-9/jdmarker.c ../jpeg-9/jdmaster.c \
        ../jpeg-9/jdmerge.c ../jpeg-9/jdpostct.c ../jpeg-9/jdsample.c ../jpeg-9/jdtrans.c ../jpeg-9/jerror.c ../jpeg-9/jfdctflt.c \
        ../jpeg-9/jfdctfst.c ../jpeg-9/jfdctint.c ../jpeg-9/jidctflt.c ../jpeg-9/jidctfst.c ../jpeg-9/jidctint.c ../jpeg-9/jquant1.c \
        ../jpeg-9/jquant2.c ../jpeg-9/jutils.c ../jpeg-9/jmemmgr.c ../jpeg-9/jmemnobs.c

# System dependent sources
#SYSDEPSOURCES = jmemansi.c jmemname.c jmemnobs.c jmemdos.c jmemmac.c

# Headers which are installed to support the library
INSTINCLUDES  = ../jpeg-9/jerror.h ../jpeg-9/jmorecfg.h ../jpeg-9/jpeglib.h

# Headers which are not installed
OTHERINCLUDES = ../jpeg-9/cderror.h ../jpeg-9/cdjpeg.h ../jpeg-9/jdct.h ../jpeg-9/jinclude.h ../jpeg-9/jmemsys.h ../jpeg-9/jpegint.h \
        ../jpeg-9/jversion.h ../jpeg-9/transupp.h


# Configuration files
CONFIGFILES= jconfig.cfg jconfig.bcc jconfig.mc6 jconfig.dj jconfig.wat \
        jconfig.vc jconfig.mac jconfig.st jconfig.manx jconfig.sas \
        jconfig.vms

# Support scripts for configure
CONFIGUREFILES= config.guess config.sub install-sh ltmain.sh depcomp \
        missing ar-lib

# Miscellaneous support files
OTHERFILES= jconfig.txt ckconfig.c jmemdosa.asm libjpeg.map

# Test support files
TESTFILES= testorig.jpg testimg.ppm testimg.bmp testimg.jpg testprog.jpg \
        testimgp.jpg

AM_CFLAGS	 = -I$(srcdir)/../ubuntu


# libtool libraries to build
lib_LTLIBRARIES = libjpeg2.la

# Library sources for libjpeg.la
libjpeg2_la_SOURCES = $(LIBSOURCES)

# LDFLAGS for libjpeg.la
libjpeg2_la_LDFLAGS = -no-undefined \
        -version-info $(JPEG_LIB_VERSION)

if HAVE_LD_VERSION_SCRIPT
  libjpeg2_la_LDFLAGS += -Wl,--version-script=$(srcdir)/../jpeg-9/libjpeg.map
endif

# Headers to install
include_HEADERS = $(INSTINCLUDES)

# Other distributed headers
noinst_HEADERS = $(OTHERINCLUDES)

# Other distributed files
EXTRA_DIST =  $(DOCS) $(DISTMANS) $(MKFILES) $(CONFIGFILES) $(SYSDEPSOURCES) \
        $(OTHERFILES) $(TESTFILES)

# Files to be cleaned
CLEANFILES = testout.ppm testout.bmp testout.jpg testoutp.ppm testoutp.jpg \
        testoutt.jpg

# Install jconfig.h
install-data-local:
	$(mkinstalldirs) $(DESTDIR)$(includedir)
	$(INSTALL_HEADER) jconfig.h $(DESTDIR)$(includedir)/jconfig.h

# Uninstall jconfig.h
uninstall-local:
	rm -f $(DESTDIR)$(includedir)/jconfig.h

