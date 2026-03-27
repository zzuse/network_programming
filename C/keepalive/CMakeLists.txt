add_executable(pingclient pingclient.c)
target_link_libraries(pingclient zz)

add_executable(pingserver pingserver.c)
target_link_libraries(pingserver zz)
