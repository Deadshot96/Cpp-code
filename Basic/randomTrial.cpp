# include <iostream>
# include <stdlib.h>
# include <time.h>
using namespace std;


int main(int argc, char const *argv[])
{
    /* code */
    srand(time(0));
    cout << time(0) << endl;

    for (short i = 0; i < 10; i++)
    {
        /* code */
        cout << "Random Number: " << rand() << endl;
    }
    
    return 0;
}
