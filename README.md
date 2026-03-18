# Learn Network  

## Shell
In this directory, basicly only have some useful network shell scripts

## Network programming
In this directory, I am learning network programming with C, but with newly CMake and Ninja build system.
Tutor reference repository: https://github.com/froghui/yolanda.git

```
cd C
mkdir build
cd build
cmake .. -G Ninja
cmake --build .
# CLEAN
cmake --build . --target clean
# or CLEAN
ninja -t clean
```

## Run

*  C/makesocket Chapter 4 
    start `bin/make_socket`
    Family: 0x02
    Port: 0x3039
    Address: 0x00000000
    Socket FD: 3
*  C/tcpserver Chapter 5 
    start `bin/tcpserver`
    then start `bin/tcpclient <IPaddress>`
    you will find client send 10MB data to server, and server print "1K read for x" for 10000 times.
*  C/udpserver Chapter 6
    start `bin/udpserver`
    then start `bin/udpclient <IPaddress>`
    then type some message in client, and press enter, you will see the message in server.
*  C/localsocket Chapter 7
    start `bin/unixstreamserver <local_path>`
    then start `bin/unixstreamclient <local_path>`
    then type some message in client, and press enter, you will see the message in server.
    start `bin/unixdataserver <local_path>`
    then start `bin/unixdataclient <local_path>`
    then type some message in client, and press enter, you will see the message in server.