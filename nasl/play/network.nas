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

temp_packet = forge_ip_packet(ip_src: "192.168.59.130", ip_dst: "142.250.193.142", ip_p: IPPROTO_TCP);

display(get_ip_element(element: "ip_src", ip: temp_packet));
display(get_ip_element(element: "ip_dst", ip: temp_packet));

set_ip_elements(ip: temp_packet, ip_dst: "127.0.0.1");

display(get_ip_element(element: "ip_dst", ip: temp_packet));

dump_ip_packet(packet: temp_packet);





