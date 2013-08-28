ACLOCAL_AMFLAGS = -I autotools/m4

lib_LTLIBRARIES = libjpeg-bridge.la

libjpeg_bridge_la_SOURCES = libjpeg-bridge.c
libjpeg_bridge_la_LDFLAGS = -version-info 0:0:0

libjpeg_bridge_la_CFLAGS = -I$(srcdir)/../jpeg-9 \
	-I$(srcdir)/../include \
	$(HYBRIS_CFLAGS)



