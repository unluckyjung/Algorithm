#include <bits/stdc++.h>
using namespace std;

//int lcm(int a, int b)
//{
//	return a * b / gcd(a, b);   //A * B = (AB의 최대 공약수 * AB의 최소 공배수)
//}

//C++ 17

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;

	while (count--)
	{
		int n1, n2;
		cin >> n1 >> n2;
		cout << lcm(n1, n2) << "\n";
	}

	return 0;
}