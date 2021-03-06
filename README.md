# bionic-jpeg, an example of using libhybris to access Android
  libraries from Ubuntu

Imported from [this launchpad of John McAleely](https://launchpad.net/bionic-jpeg)
and adapted to current libhybris changes.

# Original README

A port of the Independent JPEG Group's JPEG library, such that the
core library is an Android binary, and the client utilities are Ubuntu
binaries. Uses libHybris as a bridge between the two worlds.

Hybris is a library that provides dynamic symbol loading, patterned
after dlopen() and peers.

Hybris assumes the calling code is linked to glibc, and built as part
of the conventional ubuntu image. The library loaded is assumed to be
linked to bionic, and therefore built for use on Android systems.

Hybris therefore allows an Ubuntu executable to link to a binary
Android library.

The API's required by Ubuntu from Android are managed as part of the
libhybris package, so most people will never need to use hybris
directly, and can instead use the provided ubuntu libraries.

This example is intended to clarify what libhybris is, and to provide
model for the contingency of a handset needing to extend libhybris.

There is no attempt made to modify the IJG code, which is re-used
verbatim.

# What's included

* jpeg-9: The current IJG source (from
   http://www.ijg.org/files/jpegsrc.v9.tar.gz) This directory is
   read-only in this example - no need to build from here.

* include: A suitable jconfig.h for Android and Ubuntu

* jpeg-library: Build files to create libjpeg for Android, using the NDK

* jpeg-client: Build files to create the IJG clients (cjpeg, djpeg,
  jpegtran, rdjpgcom, wrjpgcom) for Ubuntu

* jpeg-bridge: Source for a library to wrap libhybris into a jpeglib.h
  compatible API

# Install

Note that libjpeg has been renamed to libjpeg2 in the build scripts,
to avoid a collision with existing libjpeg installs

* Get an Android NDK install, and build the android library
```
    $ cd jpeg-library
    $ <path-to-ndk>/ndk-build
```

* Get an Ubuntu ARMHF build environment (eg a pbuilder for saucy/armhf)
    * Install libhybris' source, and the tools needed to build it
```
    # apt-get install automake autoconf libtool pkg-config
    # apt-get source libhybris
    # cd <eg libhybris-0.1.0+git20130606+c5d897a>/hybris
    # autoreconf --install --prefix=/opt/libhybris
    # ./configure
    # make
    # make install
```

* Now configure and make the samples
```
    # cd jpeg-bridge
    # ./configure --with-hybris-internal-include-path=/path/to/libhybris/source/hybris/include/
    # make

    # cd jpeg-client
    # ./configure --with-hybris-common-lib-path=/opt/libhybris/lib
    # make
```

* copy the binaries to your device

  * Put the jpeg-library/libs/armeabi/libjpeg2.so into the android zip
  * copy jpeg-bridge/libjpeg-bridge.so to somewhere in ubuntu
  * copy jpeg-client/cjpeg to somewhere in ubuntu

  * launch a shell on the ubuntu device, and setup the load library path
```
    $ export LD_LIBRARY_PATH=/path/to/libjpeg-bridge.so
    $ cjpeg (enjoy!)
```

