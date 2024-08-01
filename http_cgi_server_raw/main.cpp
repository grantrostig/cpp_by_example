/* Copyright Grant Rostig
   License: Boost 1.0

# SCRIPT to serve c++ from webserver
# grostig
sudo dnf install httpd mod_fcgid httpd-devel gcc-c++ mod_fcgid fcgi-devel
sudo dnf install mod_ssl -y
sudo cat "
# grostig
<IfModule mod_fcgid.c>
 AddHandler fcgid-script .fcgi
 FcgidConnectTimeout 20
</IfModule>
" >> /etc/httpd/conf.d/fcgid.conf

sudo cat >> /etc/httpd/conf.d/fcgid.conf << EOF
# grostig
<IfModule mod_fcgid.c>
 AddHandler fcgid-script .fcgi
 FcgidConnectTimeout 20
</IfModule>
EOF

sudo systemctl enable httpd.service
sudo systemctl start httpd.service
sudo systemctl restart httpd.service

#sudo apachectl reload
#sudo systemctl restart httpd.service

cd /var/www/html/cgi-bin
# upload a.out here with 755

Browse to: http://your_vps_ip/cgi-bin/hello.cgi

# FOR: Debian
# sudo apt update
# sudo apt install build-essential apache2 libapache2-mod-fcgid
# sudo mkdir /var/www/html/cgi-bin
# sudo chown www-data:www-data /var/www/html/cgi-bin
# sudo cat "
# <Directory "/var/www/html/cgi-bin">
#   Options +ExecCGI
#   AddHandler cgi-script .cgi
# </Directory>
# " >>  /etc/apache2/conf-available/cgi-enabled.conf
# sudo a2enmod cgi
# sudo a2enconf cgi-enabled
# sudo systemctl restart apache2
*/

#include <iostream>
using namespace std;

int
main() {
    cout << "Content-type: text/html\r\n\r\n"
         << "<!DOCTYPE html>" //
         << "<html lang=\"en\">"
         << "<head>"
         << "<meta charset=\"UTF-8\" />"
         << "<title>C++ CGI</title>"
         << "</head> "
         << "<body>"
         << "<h1>Hello from C++ CGI!</h1>"
         << "Enter info below:";

    char *query_string = getenv("QUERY_STRING");
    std::string name;
    if(query_string != nullptr) {
        std::string qs{query_string};
        size_t      itr{qs.find("name=")};
        if(itr != std::string::npos) { name = qs.substr(itr + 5); }
    }
    cout << "<form method='get'>"
         << "   <label for= 'nameid'>Name (44 or more characters):</label>"
         << "   <input type= 'text' id= 'nameid' name= 'name' "
         << "       value= '" << name << "'"
         << "       required minlength= '44' maxlength= '999' size= '44' />"

         << "   <input type= 'submit' value= 'Submit'>"
         << "</form>" << endl;

    if(!name.empty()) {
        cout << "<p>$$ Hello, " << name << "!</p>";
    } else {
        cout << "<p>$$ Got no input from you.</p>";
    }

    cout << "</body></html>" << endl;
    return 0;
}
