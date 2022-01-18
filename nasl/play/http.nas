include("http_func.inc");
include("http_keepalive.inc");
include("port_service_func.inc");
include("host_details.inc");


#port = http_get_port(default: 8443);
port = 8443;


url = '/index.html';
buf = http_get_cache( item:url, port:port );


