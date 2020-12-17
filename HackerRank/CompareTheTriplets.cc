#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the compareTriplets function below.
vector<int> compareTriplets(vector<int> a, vector<int> b) {
    vector<int> answer(2, 0);
    for(int i = 0; i < (int)a.size(); ++i){
        if(a[i] == b[i]) continue;
        
        if(a[i] > b[i]) answer[0]++;
        else answer[1]++;
    }
    return answer;
}