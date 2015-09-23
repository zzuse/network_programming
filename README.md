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

set route in your mistral, below is example for atca13, you can change it yours.
ip route add 192.160.13.3/32 via 192.161.108.254 dev eth1 src 192.161.108.1
ip route add 192.160.13.4/32 via 192.161.110.254 dev eth3 src 192.161.110.1
ip route add 192.160.13.131/32 via 192.161.109.254 dev eth2 src 192.161.109.1
ip route add 192.160.13.132/32 via 192.161.111.254 dev eth4 src 192.161.111.1
D: ping mistral sigtran IP from 0-0-2,0-0-10, make sure the connection is ok
E: run traffic.

mpchg -s STOP_KOM
mpchg -s NO_MATED_PAIR
