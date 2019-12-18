#include<bits/stdc++.h>
using namespace std;

int arr[10];
int n, m;

void go(int num, int cnt){
    if(cnt == m){
        for(int i = 0 ; i<m; ++i)   cout << arr[i] <<" ";
        cout <<"\n";
        return;
    }
    if(num > n) return;

    arr[cnt] = num;
    go(num+1, cnt+1);
    go(num+1, cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >>m;
    go(1, 0);
	return 0;
}