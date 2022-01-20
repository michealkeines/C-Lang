sudo openvas-nasl -X -B -d -i /var/lib/openvas/plugins/ --kb="Secret/SSH/login=ubuntu" --kb="Secret/SSH/password=ubuntu" find_service.nasl httpver.nasl global_settings.nasl ssh_authorization.nasl gather-package-list.nasl -t 192.168.59.133

get the package list using ssh from remote machine

sudo openvas-nasl -X -B -d -i /var/lib/openvas/plugins/ --kb="Secret/SSH/login=ubuntu" --kb="Secret/SSH/password=ubuntu" find_service.nasl httpver.nasl global_settings.nasl ssh_authorization.nasl gather-package-list.nasl 2021/ubuntu/gb_ubuntu_USN_5131_1.nasl -t 192.168.59.133

see if installed firefox packge is vunerable

https://community.greenbone.net/t/gvm-10-gvmd-rebuild-missing/2168


create a empty, static config and select the plugins you need


The gvm daemon automatically detects new SCAP and CERT data as well as when new
NVTs are available from the OpenVAS Scanner and will load/update the database
accordingly. Therefore the --rebuild, --update and --progress options have
been removed.

You need to use a OID out of a special range to prevent collision and you should place them into the “private/” directory to not let it be removed during feed sync.

openvas -u to rebuild all the scripts and update the list

1、you should build directory private into plugins/ directory .
2、put your private nasl into private directory .
3、use “openvas -u” command rebuild the redis cache
4、use “gvmd --rebuild” command rebuild Postgres database(This may take a lot of time )

everytime we start using gvm-start,

openvas --update-vt-info is run in background, we can see the status using

ps -aux | grep Reloaded









