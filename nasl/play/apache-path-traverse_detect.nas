if (description)
{
  script_oid("1.3.6.1.4.1.25623.1.0.117710");
  script_cve_id("CVE-2021-42013");
  script_tag(name:"qod_type", value:"remote_banner_unreliable");
  script_name("Apache HTTP Server 2.4.49 - 2.4.50 Directory Traversal / RCE Vulnerability - Linux");
  script_category(ACT_GATHER_INFO);
  script_family("Web Servers");
  script_mandatory_keys("apache/http_server/detected", "Host/runs_unixoide");
  exit(0);
}

include("http_func.inc");
include("http_keepalive.inc");
include("port_service_func.inc");
include("host_details.inc");
include("version_func.inc");

port = 8080;

url = "/index.html";

buf = http_get_cache( item: url, port: port );

#display(buf);

version = eregmatch(string: buf, multiline: TRUE, pattern: "Apache(.*)2\.4\.(49|50)");
#display(version);

if (!version) {
	exit(0);
}

if (version[0]) {
  report = report_fixed_ver(installed_version: version[0], fixed_version: "2.4.51", install_path: location);
  security_message(port: port, data: report);
  exit(0);
}

exit(99);
