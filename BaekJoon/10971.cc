#include <bits/stdc++.h>
using namespace std;

int w[11][11];
int n;
int answer = INT_MAX;
vector<int> seq;

void input(){
    cin >> n;
    for(int i = 0 ; i<n; ++i){
        for(int ii = 0 ; ii<n; ++ii){
            cin >> w[i][ii];
        }
        seq.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    do{
        int sum = 0;
        bool can_go = true;

        for(int i = 0 ; i< n-1 ;++i){
            int cur = seq[i];
            int next = seq[i+1];
            if(w[cur][next] == 0){
                can_go = false;
                break;
            }
            sum += w[cur][next];
        }

        int start = seq[0];
        int last = seq[n-1];

        if(can_go && w[last][start] != 0){
            sum += w[last][start];
            answer = min(sum, answer);
        }

    }while(next_permutation(seq.begin(), seq.end()));

    cout << answer << "\n";
    return 0;
}