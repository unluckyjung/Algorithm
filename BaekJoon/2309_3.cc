#include<iostream>
#include<algorithm>
using namespace std;

int arr[9];
int sum;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    for(int i = 0; i <9; ++i){
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr+9);

    for(int fake1 = 0 ; fake1 < 9; ++fake1){
        for(int fake2 = 0 ; fake2 < 9; ++fake2){
            if((sum - arr[fake1] - arr[fake2]) == 100){
                
                for(int ans : arr){
                    if(ans == arr[fake1] || ans == arr[fake2])continue;
                    cout << ans <<"\n";
                }
                return 0;
            }
        }
    }
    return 0;
}