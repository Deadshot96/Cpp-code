#include<iostream>
using namespace std;

/*
Total data types:
int
unsigned int
signed int
float 
double
long double
short 
unsigned short
long
unsigned long
wchar_t
char
unsigned char


*/

int main(int argc, char const *argv[])
{
    /* code */

    int intVar = 13230;
    short shortVar = 220;
    unsigned int usVar = 10;
    float fVar = 23434.4;
    double dVar = 23.3;
    long double ldVar = 23.32;
    cout << "int:     " << sizeof(intVar) << endl;
    cout << "short:     " << sizeof(shortVar) << endl;
    cout << "us int:    " << sizeof(usVar) << endl;
    cout << "float:     " << sizeof(fVar) << endl;
    cout << "double:    " << sizeof(dVar) << endl;
    cout << "longdouble:" << sizeof(ldVar) << endl;

    cout << "in Hex: "<< hex << intVar;

    return 0;
}
