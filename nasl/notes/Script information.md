
if (description) check, it is parsed for the first time and then set 0 for the other times


OID is genrated for every script


the actual detection vt should result a CPE code for the product.

namming conventions

CPE = 'cpe:/a:openssl:openssl'

/gb_openssl_http_detect.nasl - detect?

/gb_openssl_consolidation.nasl - final script or version?

/gb_openssl_CVE-2011-1945_lin.nasl - exploit?


script_dependencies = the scripts that should ran before current script?

script_mandatory_key = the scripts will be refernceing these keys for sure?

include('filename'); // include dependencies

update keys using

set_kb_item();

we add modfiled by holm if we modify it

