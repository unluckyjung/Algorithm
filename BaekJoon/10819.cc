#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int n;
int answer;

int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0 ; i <n; ++i){
        int num;    cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());

    do
    {
        int sum = 0;
        for (int i = 0; i + 1 < n; ++i)
        {
            sum += abs(vec[i] - vec[i + 1]);
        }
        answer = max(answer, sum);
    } while (next_permutation(vec.begin(), vec.end()));

    cout << answer << "\n";
    return 0;
}