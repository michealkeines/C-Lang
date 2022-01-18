if(description)
{
  script_oid("1.3.6.1.4.1.25623.1.0.XXXXXX");                                                 # See "Which OID to apply" in https://community.greenbone.net/t/vt-development/226
  script_version("YYYY-MM-DDTHH:mm:ss+0000");                                                 # FIXME: change on each change according to current date and time: LC_ALL=C date -u +"%Y-%m-%dT%H:%M:%S%z"
  script_tag(name:"last_modification", value:"YYYY-MM-DD HH:mm:ss +0000 (Sat, 14 Oct YYYY)"); # FIXME: change on each change according to current date and time: LC_ALL=C date -u +"%F %T %z (%a, %d %b %Y)"
  script_tag(name:"creation_date", value:"YYYY-MM-DD HH:mm:ss +0000 (Fri, 13 Oct YYYY)");     # FIXME: change according to current date and time only once: LC_ALL=C date -u +"%F %T %z (%a, %d %b %Y)"
  script_tag(name:"cvss_base", value:"FIXME: The CVSS computed from the below vector");       # e.g.: "6.5" for Vulnerability-VTs or "0.0" for Detection-VTs
  script_tag(name:"cvss_base_vector", value:"FIXME: The CVSSv2 base vector");                 # e.g.: "AV:L/AC:L/Au:M/C:C/I:C/A:C" for Vulnerability-VTs or "AV:N/AC:L/Au:N/C:N/I:N/A:N" for Detection-VTs

  # (Added with GVM-21.04. No effect on previous versions)
  # CVSSv3 vector if available:
  script_tag(name:"severity_vector", value:"CVSS:3.1/AV:N/AC:L/PR:L/UI:N/S:C/C:H/I:H/A:H");

  # CVSSv2 otherwise:
  script_tag(name:"severity_vector", value:"AV:N/AC:L/Au:N/C:C/I:C/A:C");

  # the origin of the CVSS vector. Possible values: (Added with GVM-21.04. No effect on previous versions)
  # - NVD: if a CVE is the source
  # - Vendor: if a vendor like Red Hat, Ubuntu, Cisco etc. is the source
  # - Third Party: if a researcher, blogpost , Vulnerability Reporter etc. is the source
  # - Greenbone: if we added the CVSSv3 vector by ourselves without a source
  # Note: If one or more CVEs are assigned to a VT but there was no CVSS score assessment of the NVD done yet one of the other possibilities should be used depending on the origin of the score.
  script_tag(name:"severity_origin", value:"Greenbone");

  # the date the CVSS vector was last modified. Format: LC_ALL=C date -u +"%F %T %z (%a, %d %b %Y)" (Added with GVM-21.04. No effect on previous versions)
  script_tag(name:"severity_date", value:"2020-11-09 00:00:00 +0000 (Mon, 09 Nov 2020)");

  script_cve_id("FIXME");                                                                     # e.g.: ("CVE-2017-12345", "CVE-2016-9392")

  # FIXME: Either assign a QoD type OR alternatively a QoD value, NOT both.
  # See "How to assign a QoD to a VT" in https://community.greenbone.net/t/vt-development/226 for more info
  script_tag(name:"qod_type", value:"remote_banner_unreliable");
  script_tag(name:"qod", value:"30");

  # FIXME: Determine the solution type.
  # See "How to assign a solution type to a VT" and "How to handle VTs with "no solution" for the user" in https://community.greenbone.net/t/vt-development/226
  script_tag(name:"solution_type", value:"VendorFix");

  script_name("FIXME: short name (few words)");                                               # No newlines currently allowed

  script_category(ACT_ATTACK);                                                                # FIXME: select a suitable category, see https://github.com/greenbone/openvas-scanner/blob/main/misc/nvt_categories.h

  script_copyright("Copyright (C) 2021 Greenbone Networks GmbH");                             # Change year according to current year
  script_family("FIXME");                                                                     # Use only one of the predefined ones currently used (see the existing ones in the feed).
  script_dependencies("FIXME.nasl");                                                          # FIXME: Optional, depends on script requirements, e.g.: ("foo_detect.nasl")
  script_require_ports("SERVICE", PORT);                                                      # FIXME: Optional, depends on script requirements, e.g.: ("Services/www", 80)
  script_require_udp_ports("SERVICE", PORT);                                                  # FIXME: Optional, depends on script requirements, e.g.: ("Services/udp/tftp", 69)
  script_require_keys("KB Key");                                                              # FIXME: Optional, depends on script requirements, e.g.: ("foo/installed")
  script_mandatory_keys("KB Key");                                                            # FIXME: Optional, depends on script requirements, e.g.: ("bar/installed")
  script_exclude_keys("KB Key");                                                              # FIXME: Optional, depends on script requirements, e.g.: ("Settings/disable_cgi_scanning")

  # FIXME: Remove tags where you don't have details, except "summary"-tag.
  script_tag(name:"summary", value:"FIXME. !mandatory!");                                     # e.g.: "softwareXYZ is prone to multiple vulnerabilities."

  script_tag(name:"vuldetect", value:"FIXME");                                                # e.g.: "Checks if a vulnerable version is present on the target host."

  script_tag(name:"insight", value:"FIXME");                                                  # e.g.: "The flaw exists due to a buffer over-read error in the 'foo' function in path/to/file script."

  script_tag(name:"impact", value:"FIXME");                                                   # e.g.: "Successful exploitation allows an attacker to obtain sensitive information."

  script_tag(name:"affected", value:"FIXME");                                                 # e.g.: "SoftwareXYZ 1.3.7 and prior."

  script_tag(name:"solution", value:"FIXME");                                                 # e.g.: "Update to version 1.3.8 or later.", see also "How to assign a solution type to a VT" and "How to handle VTs with "no solution" for the user" in https://community.greenbone.net/t/vt-development/226

  # FIXME: URLs related to the script.
  script_xref(name:"URL", value:"http://example.com");
  script_xref(name:"URL", value:"http://example2.com");

  # FIXME: Any additional free-form references.
  script_xref(name:"FIX", value:"FIX-ME");

  exit(0);
}

# include("FIXME.inc"); # in case you want to use a NASL library, commented out to allow a successful syntax check with openvas-nasl-lint

# FIXME: the code.
# Learn from examples (see the existing .nasl scripts in directory "$PREFIX/var/lib/openvas/plugins/".

