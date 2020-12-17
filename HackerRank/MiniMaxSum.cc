#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<string> split_string(string);

// Complete the miniMaxSum function below.
void miniMaxSum(vector<int> arr) {
    ll sum = 0;
    for(int num : arr){
        sum += num;
    }
    cout << sum - *max_element(arr.begin(), arr.end()) << " ";
    cout << sum - *min_element(arr.begin(), arr.end());
}
