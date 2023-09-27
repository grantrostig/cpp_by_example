#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float value_f { 1.09 };
    float precision { 2 };
    cout << value_f*pow(10.0f,precision)-trunc(value_f*pow(10.0f,precision))<<endl;
    cout << std::fmod(value_f*pow(10,precision),1)<<endl;

    cout << -value_f*pow(10.0f,precision)-trunc(-value_f*pow(10,precision))<<endl;
    cout << std::fmod(-value_f*pow(10,precision),1)<<endl;
    cout << "Hello World!" << endl;
    return 0;
}
