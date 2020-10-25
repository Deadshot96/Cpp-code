# include <iostream>
# include <stdlib.h>
using namespace std;


int main(int argc, char const *argv[])
{
    /* code */
    srand(20);

    for (short i = 0; i < 10; i++)
    {
        /* code */
        cout << "Random Number: " << rand() << endl;
    }
    
    return 0;
}
