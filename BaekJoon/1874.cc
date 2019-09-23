#include <bits/stdc++.h>
using namespace std;
//1874 스택수열
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vec;
	string str;

	int cnt;
	cin >> cnt;
	int sn = 1;	//추가되는 순열의 숫자
	while (cnt--) {
		int num;
		cin >> num;
		while (1) {

			if (!vec.empty() and vec.back() > num) {
				//비어있을때 back()으로 참조할경우 오류난다.

				//만약 차있는게 1,2,3 이고
				//이번에 찾는게 2라면?
				//3을 반드시 뽑아야한다. 즉, 원하는 결과값이 나오지 못한다.
				cout << "NO";
				return 0;
			}

			if (!vec.empty()) {
				if (num == vec.back()) {
					//찾는것이 맨뒤에 있었다면?
					vec.pop_back();
					str += "-\n";
					break;
				}
			}

			//찾는게 없다면, 증가된 snn값을 푸쉬한다.
			//1,2,3
			//find 5
			//1,2,3,4,5까지 늘려가야한다.
			vec.push_back(sn);
			str += "+\n";
			sn++;
		}
	}

	cout << str;
	return 0;
}