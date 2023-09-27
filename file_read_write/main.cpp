#include <iostream>
#include <fstream>
#include <arpa/inet.h>
using namespace std;
int main()
{
    ofstream fout { "junk.data", ios_base::out & ios_base::binary & ios_base::trunc };
    fout.exceptions( ios_base::badbit & ios_base::failbit );

    if ( std::endian::big == std::endian::native ) cout << "big\n";
    if ( std::endian::little == std::endian::native ) cout << "little\n";

    uint16_t ui16 = 0xff;
    uint32_t ui32 = 0xff;
    uint16_t ui16n = htons(ui16);
    uint32_t ui32n = htonl(ui32);

    fout.write( (const char *)&ui16, sizeof (ui16) );
    fout.write( (const char *)&ui16n, sizeof (ui16) );
    fout.write( (const char *)&ui32, sizeof (ui32) );
    fout.write( (const char *)&ui32n, sizeof (ui32) );
    fout.flush();

    fout << ui16;
    fout << ui32;
    fout.flush();

    cout << "###" << endl;
    return 0;
}
