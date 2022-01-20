
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

script_exclude_key = if its set true, the script doent have to run

script_catagory = 

include('filename'); // include dependencies

update keys using

set_kb_item();

we add modfiled by holm if we modify it

check the logs to find if there is any timeouts 

openvassd.messages -> scanner logs from the scripts

openvassd.dump -> standard out of the script file like eg: display()

openvasmd.log -> manager log from the ui

sqlite3 stores the script decriptions information

scap.db has the cpe, cves nnnd metadata

when you change something in description, we need to rebuild it

we dont have to rebuild if we change just the logic code

thinkpad-t490s



