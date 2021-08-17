# include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
    int n = 10;
    int a = 0, b = 1, c = 1;

    while (c < n){
        b = b * c;
        a = a + (b / c);
        c++;
    }

    cout << a << endl;
    return 0;
}
