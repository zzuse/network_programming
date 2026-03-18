add_executable(unixstreamserver unixstreamserver.c)
target_link_libraries(unixstreamserver zz)

add_executable(unixstreamclient unixstreamclient.c)
target_link_libraries(unixstreamclient zz)

add_executable(unixdataserver unixdataserver.c)
target_link_libraries(unixdataserver zz)

add_executable(unixdataclient unixdataclient.c)
target_link_libraries(unixdataclient zz)
