set(LOG4TANGO_HEADERS
        log4tango/Appender.hh
        log4tango/AppenderAttachable.hh
        log4tango/LayoutAppender.hh
        log4tango/FileAppender.hh
        log4tango/RollingFileAppender.hh
        log4tango/OstreamAppender.hh
        log4tango/Layout.hh
        log4tango/PatternLayout.hh
        log4tango/XmlLayout.hh
        log4tango/Logger.hh
        log4tango/LogSeparator.hh
        log4tango/LoggerStream.hh
        log4tango/LogStream.hh
        log4tango/LogStreambuf.hh
        log4tango/LoggingEvent.hh
        log4tango/Level.hh
        log4tango/NDC.hh
        log4tango/TimeStamp.hh
        log4tango/Filter.hh
        log4tango/Export.hh
        log4tango/Portability.hh)

set(LOG4TANGO_THREADING
        log4tango/threading/DummyThreads.hh
        log4tango/threading/PThreads.hh
        log4tango/threading/MSThreads.hh
        log4tango/threading/Threading.hh)

set(CLIENT_HEADERS
        tango/client/accessproxy.h
        tango/client/apiexcept.h
        tango/client/cbthread.h
        tango/client/dbapi.h
        tango/client/devapi.h
        tango/client/devasyn.h
        tango/client/event.h
        tango/client/eventconsumer.h
        tango/client/filedatabase.h
        tango/client/group.h
        tango/client/lockthread.h
        tango/client/Database.h
        tango/client/DbDevice.h
        tango/client/ApiUtil.h
        tango/client/DeviceData.h
        tango/client/DeviceAttribute.h
        tango/client/DevicePipe.h
        tango/client/Connection.h
        tango/client/DeviceProxy.h
        tango/client/AttributeProxy.h
        tango/client/device/device_command_info.h)

set(CLIENT_HELPERS
        tango/client/helpers/DeviceProxyHelper.h
        tango/client/helpers/PogoHelper.h
        tango/client/helpers/TangoExceptionsHelper.h
        tango/client/helpers/Xstring.h)

set(CLIENT_TEMPLATES
        tango/client/devapi_attr.tpp
        tango/client/devapi_utils.tpp
        tango/client/api_util.tpp
        tango/client/devapi_pipe.tpp
        tango/client/event_consumer.tpp)

set(SERVER_HEADERS
        tango/server/attrdesc.h
        tango/server/attrprop.h
        tango/server/attrmanip.h
        tango/server/attribute.h
        tango/server/auto_tango_monitor.h
        tango/server/basiccommand.h
        tango/server/blackbox.h
        tango/server/classattribute.h
        tango/server/classpipe.h
        tango/server/command.h
        tango/server/coutappender.h
        tango/server/device.h
        tango/server/device_2.h
        tango/server/device_3.h
        tango/server/device_4.h
        tango/server/device_5.h
        tango/server/deviceclass.h
        tango/server/devintr.h
        tango/server/dintrthread.h
        tango/server/dserver.h
        tango/server/dserverclass.h
        tango/server/dserversignal.h
        tango/server/encoded_attribute.h
        tango/server/encoded_format.h
        tango/server/eventsupplier.h
        tango/server/except.h
        tango/server/fwdattrdesc.h
        tango/server/fwdattribute.h
        tango/server/log4tango.h
        tango/server/logcmds.h
        tango/server/logging.h
        tango/server/logstream.h
        tango/server/multiattribute.h
        tango/server/pipe.h
        tango/server/pipedesc.h
        tango/server/pollcmds.h
        tango/server/pollext.h
        tango/server/pollobj.h
        tango/server/pollring.h
        tango/server/pollthread.h
        tango/server/readers_writers_lock.h
        tango/server/rootattreg.h
        tango/server/seqvec.h
        tango/server/tango_config.h
        tango/server/tango_monitor.h
        tango/server/tangoappender.h
        tango/server/tangorollingfileappender.h
        tango/server/utils.h
        tango/server/w_attribute.h
        tango/server/w_pipe.h
        tango/server/subdev_diag.h
        tango/server/device_6.h)

set(SERVER_TEMPLATES
        tango/server/attribute.tpp
        tango/server/attrsetval.tpp
        tango/server/attribute_spec.tpp
        tango/server/attrprop.tpp
        tango/server/utils.tpp
        tango/server/pipe.tpp
        tango/server/device_3.tpp
        tango/server/fwdattribute.tpp
        tango/server/fwdattribute_spec.tpp
        tango/server/pollext.tpp
        tango/server/pollring.tpp
        tango/server/pollthread.tpp
        tango/server/utils.tpp
        tango/server/utils_spec.tpp
        tango/server/w_attribute.tpp
        tango/server/w_attrsetval.tpp
        tango/server/w_attribute_spec.tpp
        tango/server/w_pipe.tpp)

configure_file(tango/server/tango_const.h.in ${PROJECT_BINARY_DIR}/include/tango/server/tango_const.h)

if(WIN32)
    set(SERVER_HEADERS_WIN32
            tango/server/w32win.h
            tango/server/coutbuf.h
            tango/server/ntservice.h)

    set_source_files_properties(${SERVER_HEADERS} PROPERTIES LANGUAGE CXX)
    set_source_files_properties(${SERVER_TEMPLATES} PROPERTIES LANGUAGE CXX)
    set_source_files_properties(${CLIENT_TEMPLATES} PROPERTIES LANGUAGE CXX)
    set_source_files_properties(${SERVER_TEMPLATES} PROPERTIES HEADER_FILE_ONLY TRUE)

    set(INCLUDE_OBJECT_MS
            tango.h
            ${SERVER_HEADERS}
            ${SERVER_HEADERS_WIN32}
            ${CLIENT_HEADERS}
            ${CLIENT_HELPERS}
            ${LOG4TANGO_HEADERS}
            ${LOG4TANGO_THREADING})
install(FILES tango.h DESTINATION include)
install(FILES ${SERVER_HEADERS} ${SERVER_TEMPLATES} DESTINATION "include/tango/server")
install(FILES ${CLIENT_HEADERS} ${CLIENT_TEMPLATES} ${CLIENT_HELPERS} DESTINATION "include/tango/client")

    install(FILES ${LOG4TANGO_HEADERS}
            DESTINATION include/log4tango)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/log4tango/config.h DESTINATION include/log4tango)
install(FILES ${LOG4TANGO_THREADING}
        DESTINATION include/log4tango/threading)
else(WIN32)
add_library(include_objects OBJECT tango.h ${SERVER_HEADERS} ${CLIENT_HEADERS} ${CLIENT_HELPERS} ${LOG4TANGO_HEADERS} ${LOG4TANGO_THREADING})

install(FILES tango.h DESTINATION "${CMAKE_INSTALL_FULL_INCLUDEDIR}")

#install current dir
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION "${CMAKE_INSTALL_FULL_INCLUDEDIR}"
        PATTERN "CMakeLists.txt" EXCLUDE
        PATTERN "*.in" EXCLUDE)

#install configured files
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/log4tango/config.h DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR}/log4tango)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/tango/server/tango_const.h DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR}/tango/server)
endif(WIN32)
