#include <bits/stdc++.h>

using namespace std;

int nMax, mMax;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    for(auto vec : sizes){
        int n = max(vec[0], vec[1]);
        int m = min(vec[0], vec[1]);
        
        nMax = max(nMax, n);
        mMax = max(mMax, m);
    }
    
    return nMax * mMax;
}