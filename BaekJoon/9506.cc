#include <bits/stdc++.h>
using namespace std;

//완전수는 약수로 이루어져있다.
//n의 모든 약수의 모든 합이 n와 일치하는지 확인한다
//X*Y에서 X나 Y는 루트 n 보다 클 수 없다.

//X*X 가 n이 되는경우는 예외처리한다.
//자기 자신의 경우를 제외하니 1의 경우 예외처리한다.

//연산자 + 는 약수의 갯수보다 1개 모자르게 출력해야한다.
bool solve(vector<int> &vec, const int &n)
{
    int sum = 0;
    for (int i = 1; i * i < n; ++i)
    {
        if (n % i == 0)
        {
            vec.push_back(i);
            sum += i;
            if (i > 1)
            {
                vec.push_back(n / i);
                sum += n / i;
            }
        }
        if (i * i == n)
        {
            vec.push_back(i);
            sum += i;
        }
    }
    return sum == n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {
        int num;
        cin >> num;
        if (num == -1)
        {
            return 0;
        }
        vector<int> vec;
        if (solve(vec, num))
        {
            sort(vec.begin(), vec.end());
            cout << num << " = ";
            int vec_size = vec.size();
            for (int i = 0; i < vec_size; ++i)
            {
                cout << vec[i];
                if (i < vec_size - 1)
                {
                    cout << " + ";
                }
            }
            cout << "\n";
        }
        else
        {
            cout << num << " is NOT perfect.\n";
        }
    }

    return 0;
}