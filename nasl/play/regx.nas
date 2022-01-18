#ftp_sock = open_sock_tcp(2121);

#banner = recv(socket: ftp_sock, length: 1024);

#display(banner);
#test = ereg(pattern: "py.* 1\.5\..* ",string: banner);

#display(test);

#if(ereg(pattern: "py.* 1\.5\..* ",string: banner)) {
#	display("Python FTP server 1.5.x is running on the host.");
#}

http_sock = open_sock_tcp(8080);
str = string("HEAD /index.html HTTP/1.1\r\n\r\n");
send(socket: http_sock, data: str);

r = recv(socket: http_sock, length: 1024);

display("\n",r);

server = egrep(pattern: "^Server: (.*) P", string: r);

if (server) {
	display("\n", server);
}
