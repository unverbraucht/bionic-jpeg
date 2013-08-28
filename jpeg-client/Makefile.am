## Process this file with automake to produce Makefile.in
#
#  Automake Makefile for the JPEG library
#
#  This file is written by Bob Friesenhahn, Guido Vollbeding
#  Modified to demonstrate libhybris
#

ACLOCAL_AMFLAGS = -I autotools/m4

# Test support files
TESTFILES= testorig.jpg testimg.ppm testimg.bmp testimg.jpg testprog.jpg \
        testimgp.jpg

# Executables to build
bin_PROGRAMS = cjpeg djpeg jpegtran rdjpgcom wrjpgcom

AM_CFLAGS	 = -I$(srcdir)/../include

# Executable sources & libs
cjpeg_SOURCES    = ../jpeg-9/cjpeg.c ../jpeg-9/rdppm.c ../jpeg-9/rdgif.c ../jpeg-9/rdtarga.c ../jpeg-9/rdrle.c ../jpeg-9/rdbmp.c \
                   ../jpeg-9/rdswitch.c ../jpeg-9/cdjpeg.c
cjpeg_LDADD      = $(srcdir)/../jpeg-bridge/libjpeg-bridge.la $(HYBRIS_LIBS)

djpeg_SOURCES    = ../jpeg-9/djpeg.c ../jpeg-9/wrppm.c ../jpeg-9/wrgif.c ../jpeg-9/wrtarga.c ../jpeg-9/wrrle.c ../jpeg-9/wrbmp.c \
                   ../jpeg-9/rdcolmap.c ../jpeg-9/cdjpeg.c
djpeg_LDADD      = $(srcdir)/../jpeg-bridge/libjpeg-bridge.la $(HYBRIS_LIBS)
jpegtran_SOURCES = ../jpeg-9/jpegtran.c ../jpeg-9/rdswitch.c ../jpeg-9/cdjpeg.c ../jpeg-9/transupp.c
jpegtran_LDADD   = $(srcdir)/../jpeg-bridge/libjpeg-bridge.la $(HYBRIS_LIBS)
rdjpgcom_SOURCES = ../jpeg-9/rdjpgcom.c
wrjpgcom_SOURCES = ../jpeg-9/wrjpgcom.c


# Files to be cleaned
CLEANFILES = testout.ppm testout.bmp testout.jpg testoutp.ppm testoutp.jpg \
        testoutt.jpg


# Run tests
test: check-local
check-local:
	rm -f testout*
	./djpeg -dct int -ppm -outfile testout.ppm  $(srcdir)/testorig.jpg
	./djpeg -dct int -bmp -colors 256 -outfile testout.bmp  $(srcdir)/testorig.jpg
	./cjpeg -dct int -outfile testout.jpg  $(srcdir)/testimg.ppm
	./djpeg -dct int -ppm -outfile testoutp.ppm $(srcdir)/testprog.jpg
	./cjpeg -dct int -progressive -opt -outfile testoutp.jpg $(srcdir)/testimg.ppm
	./jpegtran -outfile testoutt.jpg $(srcdir)/testprog.jpg
	cmp $(srcdir)/testimg.ppm testout.ppm
	cmp $(srcdir)/testimg.bmp testout.bmp
	cmp $(srcdir)/testimg.jpg testout.jpg
	cmp $(srcdir)/testimg.ppm testoutp.ppm
	cmp $(srcdir)/testimgp.jpg testoutp.jpg
	cmp $(srcdir)/testorig.jpg testoutt.jpg
