start openvas - gvm-start
stop openvas - gvm-stop

sudo openvas-nasl -X temp.nas

if plugins needed

sudo openvas-nasl -i /var/lib/openvas/plugins/ temp.nas -X

to run nsal scripts


sudo openvas-nasl -X -i /var/lib/openvas/plugins/ -t 'target' get.nasl

we can set the knowledge base using --kb "attribute=value"

--kb="Services/www=443"

