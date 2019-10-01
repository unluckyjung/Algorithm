#include<bits/stdc++.h>
using namespace std;

int n;

bool buy;
bool flag = true;
map<string, int> m;

int MIN = INT_MAX;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		m[str]++;
		//해당 문자열이 몇번이나 등장하는지 기록함.
	}

	int start = m.begin()->second;
	//start 지점을 하나 잡음.
	//어차피 들어오는게 1이상이라서 null을 가르키는 경우는 존재 X

	for (auto it = m.begin(); it != m.end(); ++it) {
		//문자열 등장 빈도를 확인
		if (abs(start - it->second) >= 2) {
			//차이가 2이상 날 경우
			flag = false;
			//카드를 추가해도 쌍을 완성시키지 못하므로 flag를 false로 표시
			MIN = min(MIN, it->second);
			//가장 적게 등장하는 문자열을 저장해둠.
		}
		else if (abs(start - it->second) == 1) {
			//차이가 1인경우.
			if (buy == false) {
				//카드 구매를 한적이 없다면 구매함.
				buy = true;
				MIN = min(MIN, it->second);
			}
			else {
				//카드를 이전에 이미 구매했다면, 쌍을 완성시키지 못함.
				flag = false;
				MIN = min(MIN, it->second);
			}

		}
		else {
			//차이가 없는경우 
			MIN = min(MIN, it->second);
		}
	}

	if (flag == false) {
		//카드 쌍 완성이 불가능한 경우.
		cout << "N\n";
		cout << n << "\n";
		int pair = 0;
		//카드 종류를 받는 변수
		for (auto it = m.begin(); it != m.end(); ++it) {
			//가장 적은 문자열 등장 수를 찾음.
			if (it->second >= MIN)	pair++;
			//A가 1개 B가 2개라면, MIN은 1일것이고
			//A일때 B일때 한번씩 증가해서 총 2개의 카드 종류가 있다고 알림.
		}
		cout << pair << "\n";
	}

	else {
		cout << "Y\n";
		if (buy) {
			//카드를 구매해서 완전쌍을 완성한경우.
			cout << n + 1 << "\n";
			//기존수 + 1개 출력.
			cout << (n + 1) / (MIN + 1) << "\n";
			//카드 쌍 총합은 카드수 + 1 / 최저쌍 + 1개임.
		}
	
		else {
			cout << n << "\n";
			if (m.size() == 1)	cout << n << "\n";
			//이 부분때문에 불합인듯.
			//만약 같은 카드만 계속 해서 등장했다면, 해당 카드의 수를 출력.
			else cout << n / MIN << "\n";
		}
	}

	return 0;
}