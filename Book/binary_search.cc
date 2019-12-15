#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false) ; cin.tie(NULL);

    int arr[] = {1,3,3,4,5,5,6,9,10,12,12,15};
    int n = sizeof(arr)/sizeof(int);
    int a = 0, b = n-1;
    int x = 9;
    while(a<=b){
        int k = (a+b)/2;
        if(arr[k] == x){
            cout << k <<"\n";
            return 0;
        }
        
        if(arr[k] < x) a= k+1;
        else b= k-1;
    }

    return 0;
}