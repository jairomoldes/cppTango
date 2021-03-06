prefix = @CMAKE_INSTALL_PREFIX@
exec_prefix = ${prefix}
includedir = ${prefix}/@CMAKE_INSTALL_INCLUDEDIR@
libdir = ${prefix}/@CMAKE_INSTALL_LIBDIR@
tangodsdir = @TANGO_DEVICE_SERVER_PATH@

Name: @CMAKE_PROJECT_NAME@
Description: TANGO C++ client/server API library
Version: @LIBRARY_VERSION@
Cflags: -std=c++11 -I${includedir}
Requires: omniDynamic4 >= 4.1.6, libzmq
Libs: -L${libdir} -ltango
