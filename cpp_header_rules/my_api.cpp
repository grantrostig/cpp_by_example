#include "my_api.hpp"       // ME FIRST!! my stuff must be first in this file. // ordering: and all other stuff for the API

//#include "third_party.hpp"  // ordering: and all other stuff for the API // and alphabetical

#include <boost/aligned_storage.hpp> // and all other stuff for the API

#include <string>  // DONT because I control the header.

/* anything <> are headers  mostly std and maybe POSIX ie. OS files
   "" are user includes only.
*/

static std::string s_va_string;

Vendor_api::Vendor_api() {
}
