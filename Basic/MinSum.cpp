# include "iostream"
using namespace std;

bool isPrime(int num){
    for (int i = 2; i <= num / 2; i++)
        if (num % i == 0)
            return false;
    return true;
}

int minDays(int input1, int input2){
    int primes[input2];
    int pNum = 2;

    if (input1 % 2 != 0 && input2 < 2)
        return -1;

    if (input1 < 2)
        return -1;


    for (int i = 0; i < input2; i++){
        while (!isPrime(pNum)){
            pNum++;
        }
        primes[i] = pNum++;
    }
    int index = input2 - 1;
    int result = 0;
    
    while (input1 > 0){
        if (input1 <= 3){
            result++;
            break;
        }

        if (input1 >= primes[index]){
            input1 -= primes[index];
            result++;
        }
        else{
            index--;
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    for (int i = 2; i < 100; i++){
        cout << minDays(i, 5) << endl;
    }
    cout << minDays(5, 2) << endl;
    cout << minDays(11, 3) << endl;
    cout << minDays(15, 3) << endl; 
    return 0;
}
