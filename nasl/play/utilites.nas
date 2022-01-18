my_ip = this_host(); # IP address of the host


my_hostname = get_host_name(); # returns the host name of the currently tested host

my_whatip = get_host_ip(); # returns ip of the currently tested host

display(my_ip, " ", my_hostname, " ", my_whatip); 

open_ports = get_host_open_port();

display(open_ports);


a = "version 1.4.5";

b = a - "version "; #remove version space

display(b, "--version");

#crap allows us to create text of given length, we can specify patterns to repeat

data1 = string("HEAD", crap(10), "\r\n");

data2 = string(crap(data: "AB", length: 10));

display(data1, " ", data2);

l = strlen(data2); # length of a string

a = raw_string(65,65,65);

display(a);

#b = strtoint();

#display(b);

k = tolower("teEET"); # convert to lower case

display(k);



 
