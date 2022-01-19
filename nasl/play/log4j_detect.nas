
if (description) {
#	script_oid();
	script_tag(name: "detection", value: "Log4j using recursive file search");
	script_name("LOG4j Dectection");
	script_description("This script will recursively search for files with a pattern via SSH login");
	script_family("Vulnerability Detection");
	script_dependencies("ssh_authorization.nasl");
	script_mandatory_keys("login/SSH/success");
	exit(0);
}

include("ssh_func.inc");
include("host_details.inc");
include("os_func.inc");
include("version_func.inc");

#cpe = build_cpe(value: "Log4j", exp:"^([0-9.]+[a-z0-9]*)", base:"cpe:/a:apache:log4j:");

# Hardcoded Port 

port = 21; 
sock = ssh_login_or_reuse_connection();

# Check if the socket is ready
if (!sock) {
	exit(0);
}

command = "whoami";

# send the command for execution to ssh

user = ssh_cmd(
	socket: sock,
	cmd: command,
	return_errors: TRUE,
	nosu: TRUE,
	pty: TRUE,
	timeout: 60,
	retry: 30
);

# check if we have got a response

if (!user) {
	exit(0);
}

find_file_command = "fine / -iname 'log4j*'";

# send the command for execution to ssh

file_list = ssh_cmd(
	socket: sock,
	cmd: command,
	return_errors: TRUE,
	nosu: TRUE,
	pty: TRUE,
	timeout: 500,
	retry: 10
);

# check if there is any response

if (!file_list) {
	exit(0);
}

match_pattern = "\/(.*)2\.[1-5]\..+\.jar$";

# match for all the value that ends with .jar

match = egrep(
	icase: TRUE,
	pattern: match_pattern,
	string: file_list
);

# if a match is found it is vulnerable
# set detected attribute based on the match

if (match) {
	set_kb_item(name: "log4j/detected", value: TRUE);
	log_message(data: "Vulnerable.");
	
} else {
	set_kb_item(name: "log4j/detected", value: FALSE);
	log_message(data: "Not sure.");
}

# exit with code

exit(0);
