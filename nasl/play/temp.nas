display("NASL Script");

# functions with explicit local variables

function fact1(x) {
	local_var i, f;
	f = 1;
	for (i = 1; i <= n; i++) f *= i;
	return f;
}

display("3 != ", fact1(x: 3), "\n");

# functions

function print_values() {
	local_var i, f;
	for (i = 0; i < 5; i++ ) {
		display(_FCT_ANON_ARGS[i]);
	}
}

print_values(1,2,3,4,5);

# variable declarations

a = "Hello\nWorld";
b = string("Hello\nworld");

display(a);

display(b);

# create a packet

temp_packet = forge_ip_packet(ip_hl:5, ip_v:4,ip_p:IPPROTO_TCP,ip_src:"127.0.0.1",ip_dst:"127.0.0.1");

display(temp_packet);

count = 10;

send_packet(temp_packet);
while (count < 10) {
	send_packet(temp_packet);
	count -= 1;
}

# seeing compiler error about user defined function being called recursively

function test(n) {
	if ( (n == 0) || (n == 1) ) {
		return(n);
	} else {
		return (n * fact(n: n-1));
	}
}

display("5! is ", test(n: 5), "\n");

# using x operator to send 10 packets

send_packet(temp_packet) x 10;

# open a socket on TCP


soc1 = open_sock_tcp(80);
soc2 = open_sock_udp(123);




