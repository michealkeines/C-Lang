start = 80;
end = 90;

for(i = start; i < end; i = i + 1) {
	soc = open_sock_tcp(i);
	if (soc) {
		display("Port ", i, " is open\n");
		close(soc);
	}
}

# get banner of ftp server

ftp_sock = open_sock_tcp(2121);

data = recv_line(socket: ftp_sock, length: 1024);
display("The remote FTP banner is: \n", data, "\n");
close(ftp_sock);

# get & set elements from ip element

temp_packet = forge_ip_packet(ip_src: "192.168.59.130", ip_dst: "127.0.0.1", ip_p: IPPROTO_TCP);

display(get_ip_element(element: "ip_src", ip: temp_packet));
display(get_ip_element(element: "ip_dst", ip: temp_packet));

display("update ip destination");
# ip_dst will be ignored for some reason
temp_packet2 = set_ip_elements(ip: temp_packet, ip_src:"127.0.0.12");

display(get_ip_element(element: "ip_dst", ip: temp_packet));

dump_ip_packet(temp_packet);
dump_ip_packet(temp_packet2);

udp = forge_udp_packet(ip: temp_packet, uh_sport: 80, uh_dport: 80);

send_packet(udp, pcap_active: FALSE); # will not wait for a response

reply = pcap_next(); # will read the next packet from the last interface you used

reply = send_packet(udp); # will wait for a response






