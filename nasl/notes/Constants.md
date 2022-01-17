Plugin categories
– ACT_INIT: the plugin just sets a few KB items (kinds of global variables
for all plugins).

– ACT_SCANNER: the plugin is a port scanner or something like it (e.g.
ping).

– ACT_SETTINGS: just like ACT_INIT, but run after the scanners, once
we are sure that the host is alive (for performance).

– ACT_GATHER_INFO: the plugin identifies services, gather data, parses
banners, etc.

– ACT_ATTACK: the plugin launches a soft attack, e.g. a web directory
traversal.

– ACT_MIXED_ATTACK: the plugin launches an attach that might have
dangerous side effects (crashing the service most of the time).

– ACT_DESTRUCTIVE_ATTACK: the plugin tries to destroy data16 or
launch some dangerous attack (e.g. testing a buffer overflow is likely to
crash a vulnerable service).

– ACT_DENIAL: the plugin tries to crash a service.

– ACT_KILL_HOST: the plugin tries to crash the target host or disable it
(e.g. saturate the CPU, kill some vital service...).

– ACT_FLOOD: the plugin tries to crash the target host or disable it by
flooding it with incorrect packets or requests. It may saturate the network
or kill some routing, switching or filtering device on the way.

• Network constants

– Nessus “encapsulation”

∗ ENCAPS_IP = 1; this is the “transport” value for a pure TCP socket.

∗ ENCAPS_SSLv23 = 2; this is the “transport” value for a SSL con-
nection in compatibility mode. Note that the find_service plugin will
never declare a port with this “encapsulation”, but you may use it in a
script.

∗ ENCAPS_SSLv2 = 3. The old SSL version which only supports
server side certificates.
By the way, there is only one plugin that really tries to destroy data. This is http_methods.nasl
16

∗ ENCAPS_SSLv3 = 4. The new SSL version: it supports server and
client side certificates, more ciphers, and fixes a few security holes.

∗ ENCAPS_TLSv1 = 5; TLSv1 is defined RFC 2246. Some people call
it “SSL v3.1”.

– Sockets options

∗ MSG_OOB, a socket option used to send “out of band data”.
– Raw sockets

∗ IPPROTO_ICMP as defined in the system C include files.

∗ IPPROTO_IGMP

∗ IPPROTO_IP

∗ IPPROTO_TCP

∗ IPPROTO_UDP

∗ pcap_timeout = 5

∗ TH_ACK = 0x10. This TCP flag indicates that the packet contains a
valid acknowledgment.
∗ TH_FIN = 0x01. This TCP flag indicates that the packet negociates
the end of the session.
∗ TH_PUSH = 0x08.
∗ TH_RST = 0x04. This TCP flag indicates that the connection was
refused or “reset by peer”.
∗ TH_SYN = 0x02. This belong to the initial handshake (connection
opening).
∗ TH_URG = 0x20. This TCP flag indicates that the packet contains
urgent data

