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
    
    for (string &s : arr)
        wordsByLen[s.length()].push_back(std::move(s));

    size_t idx = 0;

    for (auto & i : wordsByLen)
        for (string & s: i)
            arr[idx++] = std::move(s);

    int startingIdx = arr.size();

    for (int pos = maxLen - 1; pos >= 0; pos--)
    {
        startingIdx -= wordsByLen[pos + 1].size();

        for (int i = startingIdx; i < arr.size(); i++)
            buckets[arr[i][pos]].push_back(std::move(arr[i]));

        idx = startingIdx;

        for (auto & thisBucket : buckets)
        {
            for (string & s : thisBucket)
                arr[idx++] = std::move(s);

            thisBucket.clear();    
        }
    }
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}
