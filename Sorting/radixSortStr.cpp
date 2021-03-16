# include <iostream>
# include <vector>
using namespace std;

/*
 * Radix sort an array of Strings
 * Assume all are all ASCII
 * Assume all have length bounded by maxLen
*/

void radixSort(vector <string> & arr, int maxLen){
    
    const size_t BUCKETS = 256;

    vector<vector<string>> wordsByLen (maxLen + 1);
    vector<vector<string>> buckets (BUCKETS);
    
    for (auto &s : arr)
        wordsByLen[s.length()].push_back(std::move(s));

    size_t idx = 0;
    



}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
