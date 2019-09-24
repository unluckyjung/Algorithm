#include <bits/stdc++.h>
using namespace std;
//2054 괄호의 값
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	string s;

	int tmp = 1;
	int ans = 0;

	for (int i = 0; i < (int)str.size(); ++i) {
		if (str[i] == '(') {
			s.push_back(str[i]);
			tmp *= 2;	//( 괄호가 등장할경우 *2 를 해줌.
		}
		else if (str[i] == ')') {
			if (s.empty() or s.back() != '(') {
				//닫는 괄호 ) 가 나왔는데 s 스택이 비어있거나,
				//s의 top(back)이 여는것 ( 이 아니면, 잘못된 괄호.
				cout << 0; return 0;
			}
			else {
				//닫는 괄호가 등장했고,
				if(str[i-1] == '(') ans += tmp;
				//s가 아닌 str의 이전 괄호가 대칭된다면 값을 더해줌.
				tmp /= 2;	//tmp는 다시 나누어줌.
				s.pop_back();	//s에 들어가있던 ( 괄호를 제거함.
			}
		}
		if (str[i] == '[') {
			s.push_back(str[i]);
			tmp *= 3;
		}
		else if (str[i] == ']') {
			if (s.empty() or s.back() != '[') {

				cout << 0; return 0;
			}
			else {
				if (str[i - 1] == '[') ans += tmp;
				tmp /= 3;
				s.pop_back();
			}
		}
	}

	if (!s.empty()) {	// (()()[] 의 경우, 스택에 (가 남아있음.
		//잘못된 괄호에 대한 예외처리.
		cout << 0;
		return 0;
	}
	cout << ans;

	return 0;
}