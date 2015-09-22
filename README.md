# netScripts
my useful network scripts
---
tshark -i any port 3868 -w filename.cap
tshark -i any -c 4 -d tcp.port==3968,diameter host 169.254.64.12

rpm -qil libpcap-devel
rpm -qil libpcap
rpm -i libpcap-devel-1.0.0-6.20091201git117cb5.el6.x86_64.rpm

tcp.port == 3968
http://wiki.wireshark.org/CaptureSetup/CapturePrivileges
cap vmnet1
ip.addr == 172.25.126.1 && tcp.port == 3968

netstat   -ano
