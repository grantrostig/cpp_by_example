#include <iostream>
#include <cctype>
#include <locale>

using namespace std;

int main()
{
    unsigned char 	non_breaking_space 	= '\xa0'; 	 // the non-breaking space in ISO-8859-1
    wchar_t 		trademark_sign 		= L'\u2122'; // trademark sign  // todo: what is the L?  why make this wide? especially since there is a iswprint() exists??;
    //wchar_t 		trademark_sign_no_L	= '\u2122'; // todo: we need the above L. ??

    std::locale locale_GB ("en_GB.iso88591");
    std::locale locale_US ("en_US.UTF-8");
    std::locale locale__C ("C");
    std::locale locale__1 ("C");

    //std::locale locale__4 (std::locale(), "C");  // todo: strange link error in "id". ??
    std::locale locale__2 (std::locale(), new std::ctype<char>);  // todo: what is this doing? ??
    // std::locale locale__3 (std::locale());  // why am I passing a function declaration (disambiguated) according to compiler warning, and not on prior two lines ??

    std::cout << "The default locale is " << std::locale().name() << '\n'
              << "The user's locale is " << std::locale("").name() << '\n'
              << "A nameless locale is " << locale__2.name() << '\n';

    std::setlocale(LC_CTYPE, "en_GB.iso88591");
    std::setlocale(LC_CTYPE, locale_GB.name().c_str());

    cout << "c      :" <<isprint('c')<<":"<<"c      :"<<isprint('	')<<":"<<"c      :"<< isprint('\n')<<":\n";
    cout << "locale1:" <<isprint('c', locale__1)<<":"<< "locale1:" << isprint('	', locale__1) 	<<":"<<"locale1:" << isprint('\n', locale__1) 	<<":\n";
    cout << "\n###" << endl;
    return 0;
}
