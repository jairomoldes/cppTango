include(FindPkgConfig)
include(FindDoxygen)
include(GNUInstallDirs)

if(NOT CMAKE_BUILD_TYPE)
    message("No build type specified - default is RELEASE")
    set(CMAKE_BUILD_TYPE RELEASE)
endif()

if(NOT TANGO_DEVICE_SERVER_PATH)
    #TODO windows
    set(TANGO_DEVICE_SERVER_PATH ${CMAKE_INSTALL_FULL_BINDIR})
endif()

if (ENV{IDL_BASE})
    message("Using IDL_BASE=$ENV{IDL_BASE}")
    set(IDL_PKG_INCLUDE_DIRS $ENV{IDL_BASE}/include)
else()
    pkg_search_module(IDL_PKG REQUIRED tangoidl)
    if(NOT IDL_PKG_FOUND)
        message(FATAL "tango-idl library is required for Tango. Please install it from https://github.com/tango-controls/tango-idl")
    endif()
endif()

if (ENV{OMNI_BASE})
    message("Using OMNI_BASE=$ENV{OMNI_BASE}")
    set(OMNIORB_PKG_INCLUDE_DIRS $ENV{OMNI_BASE}/include)
    if(WIN32)
        set(OMNIIDL_PATH $ENV{OMNI_BASE}/bin/x86_win32/)
        link_directories($ENV{OMNI_BASE}/lib/x86_win32/)
        include_directories($ENV{OMNI_BASE}/include)
        #set(OMNIORB_PKG_LIBRARIES "omniORB4.lib;omniDynamic4.lib;omnithread.lib;COS4.lib")
        if (CMAKE_BUILD_TYPE STREQUAL "Debug")
            set(OMNIORB_PKG_LIBRARIES "omniORB4_rtd.lib;omniDynamic4_rtd.lib;omnithread_rtd.lib;COS4_rtd.lib;msvcstubd.lib")
        else()
            set(OMNIORB_PKG_LIBRARIES "omniORB4_rt.lib;omniDynamic4_rt.lib;omnithread_rt.lib;COS4_rt.lib;msvcstub.lib")
        endif()
    else()
        set(OMNIIDL_PATH ${OMNI_BASE}/bin/)
        include_directories(${OMNI_BASE}/include)
        link_directories(${OMNI_BASE}/lib)
        set(OMNIORB_PKG_LIBRARIES "-lomniORB4 -lomnithread -lCOS4 -lomniDynamic4")
    endif()
else()
    #CORBA
    pkg_search_module(OMNIORB_PKG REQUIRED omniORB4)
    #dynamic CORBA
    pkg_search_module(OMNIDYN_PKG REQUIRED omniDynamic4)
    if(NOT OMNIORB_PKG_FOUND)
        message(FATAL "omniORB4 library is required for Tango")
    endif()
endif()

if (ENV{ZMQ_BASE})
    message("Using ZMQ_BASE=$ENV{ZMQ_BASE}")
    set(ZMQ_PKG_INCLUDE_DIRS $ENV{ZMQ_BASE}/include)
    if (WIN32)
        link_directories($ENV{ZMQ_BASE}/lib/Debug)
        link_directories($ENV{ZMQ_BASE}/lib/Release)
        if (MSVC90)
            if (CMAKE_BUILD_TYPE STREQUAL "Debug")
                set(ZMQ_PKG_LIBRARIES "libzmq-v90-mt-gd-4_1_7.lib")
            else()
                set(ZMQ_PKG_LIBRARIES "libzmq-v90-mt-4_1_7.lib")
            endif()
        endif()
        if (MSVC10)
            if (CMAKE_BUILD_TYPE STREQUAL "Debug")
                set(ZMQ_PKG_LIBRARIES "libzmq-v100-mt-gd-4_1_7.lib")
            else()
                set(ZMQ_PKG_LIBRARIES "libzmq-v100-mt-4_1_7.lib")
            endif()
        endif()
        if (MSVC12)
            if (CMAKE_BUILD_TYPE STREQUAL "Debug")
                set(ZMQ_PKG_LIBRARIES "libzmq-v120-mt-gd-4_1_7.lib")
            else()
                set(ZMQ_PKG_LIBRARIES "libzmq-v120-mt-4_1_7.lib")
            endif()
        endif()
        if (MSVC14)
            if (CMAKE_BUILD_TYPE STREQUAL "Debug")
                set(ZMQ_PKG_LIBRARIES "libzmq-v140-mt-gd-4_1_7.lib")
            else()
                set(ZMQ_PKG_LIBRARIES "libzmq-v140-mt-4_1_7.lib")
            endif()
        endif()
    else()
        set(ZMQ_PKG_LIBRARIES "-lzmq")
        link_directories(${ZMQ_BASE}/lib)
    endif()
    include_directories($ENV{ZMQ_BASE}/include)
else()
    pkg_search_module(ZMQ_PKG REQUIRED libzmq)
    if(NOT ZMQ_PKG_FOUND)
        message(FATAL "ZMQ library is required for Tango")
    endif()
endif()

message("Verifying ${OMNIIDL_PATH}omniidl")
if(WIN32)
    execute_process(COMMAND ${OMNIIDL_PATH}omniidl.exe -V RESULT_VARIABLE FAILED)
else()
    execute_process(COMMAND ${OMNIIDL_PATH}omniidl -V RESULT_VARIABLE FAILED)
endif()

if(${FAILED})
    message(SEND_ERROR " No omniidl was found! rv=${FAILED}")
endif()

#assuming build platform == target
set(PLATFORM 32)
IF(WIN32)
    IF(CMAKE_CL_64)
        set(PLATFORM 64)
    ENDIF()
ELSE()
if(${CMAKE_SIZEOF_VOID_P} EQUAL 8)
    set(PLATFORM 64)
endif()
ENDIF()

IF (NOT (WIN32))
add_compile_options(-std=c++11)

#setup for GNU CXX compiler
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message("found GNU compiler ...")
    if(CMAKE_BUILD_TYPE MATCHES RELEASE)
        message("setup for release build ...")
        add_definitions(-D_FORTIFY_SOURCE=3)
    else()
        message("setup for debug build ...")
        add_compile_options(-O0 -Wall -Wextra)# -pedantic
    endif()
    add_compile_options(-std=c++11)
    add_definitions(-DGNU_CXX)
endif()
ENDIF()
include(configure/config.cmake)
include(configure/coveralls.cmake)
