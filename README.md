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
*  C/makesocket Chapter 4 -- commit 264f1ae307b95ebc0243ceda45d0b53cbb69cec7
*  C/sendmsg Chapter 5