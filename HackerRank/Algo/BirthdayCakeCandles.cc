#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'birthdayCakeCandles' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY candles as parameter.
 */

int birthdayCakeCandles(vector<int> candles) {
    int maxNumber = 0;
    int count = 0;
    for(int num : candles){
        if(maxNumber < num){
            maxNumber = num;
            count = 1;
        }
        else if(maxNumber == num){
            count++;
        }
    }
    return count;
}