#if 00

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		string cmd;
		cin >> cmd;

		int n;
		cin >> n;	//사실상 사용안하는 변수.
		//정해진 수 외에 다른 수가 들어올경우 오류나나 봤는데 그냥 통과됨.

		string str;

		deque<int> vec;
		cin >> str;

		bool numcheck = false;
		int len = str.size();
		for (int i = 0; i < len; ++i) {

			//기존에 stoi 썻을때 초과남. 그런데 그 이유는 아닐듯.
			if (isdigit(str[i]) and numcheck == true) {
				//연속으로 숫자가 나올경우.

				int index = (int)vec.size() - 1;
				vec[index] = vec[index] * 10 + (str[i] - '0');
				//기존의 숫자 * 10 + 새로운숫자.
			}

			else if (isdigit(str[i])) {
				//숫자가 등장한경우. (연속X)
				vec.push_back(str[i] - '0');
				numcheck = true;	//숫자가 등장했음을 기록.
			}
			else {
				numcheck = false;
			}
		}

		bool decflag = true;
		bool flag = true;

		int len2 = cmd.size();
		for (int i = 0; i < len2; ++i) {
			if (cmd[i] == 'R') {
				//reverse(vec.begin(), vec.end());
				//reverse쓰면 안됨 시간초과.

				decflag = !decflag;
				//리버스 명령이 나왔을경우, 뒤부터 숫자를 제거한다.
			}
			else if (cmd[i] == 'D') {
				if (vec.empty()) {
					cout << "error\n";
					flag = false;	//빈 경우에는 에러
					break;
				}

				//문제 해결의 Key부분
				if (decflag) vec.pop_front();
				//만약 R명령어가 짝수번 나왔다면, 앞에서부터 제거한다.
				else vec.pop_back();
				//만약 R명령어가 홀수번 나왔다면, 뒤에서부터 제거한다.
			}
		}

		if (flag) {
			//출력처리.
			cout << "[";

			if (decflag) {
				//R명령어가 짝수로 나왔다면, 앞부터 출력.
				int len3 = vec.size();
				for (int i = 0; i < len3; ++i) {
					cout << vec[i];
					if (i < len3 - 1) cout << ",";
				}
			}

			else if (!decflag) {
				//R명령어가 홀수로 나왔다면, 뒤부터 출력.
				int len3 = vec.size() - 1;
				for (int i = len3; i >= 0; --i) {
					cout << vec[i];
					if (i >= 1) cout << ",";
				}
			}
			cout << "]\n";
		}

	}
	return 0;
}

#else 

#include <bits/stdc++.h>

using namespace std;

string cmds, inputNums;

void solve(string inputNums) {
    deque<int> numsDeque;

    bool isFirstDigits = true;
    int index = 0;
    for (char num : inputNums) {
        if (num == ',' or num == ']') {
            isFirstDigits = true;
            index++;
        }

        if (!isdigit(num)) continue;
        if (isFirstDigits) {
            isFirstDigits = false;
            numsDeque.push_back(num - '0');
        }
        else {
            numsDeque[index] = numsDeque[index] * 10 + (num - '0');
        }
    }

    bool isReverse = false;

    for (const char &cmd : cmds) {
        if (cmd == 'R') isReverse = !isReverse;
        else if (cmd == 'D') {
            if (numsDeque.empty()) {
                cout << "error";
                return;
            }
            if (isReverse) numsDeque.pop_back();
            else numsDeque.pop_front();
        }
    }

    if (isReverse) reverse(numsDeque.begin(), numsDeque.end());

    cout << "[";
    for (int i = 0; i < (int)numsDeque.size(); ++i) {
        cout << numsDeque[i];
        if (i != numsDeque.size() - 1) cout << ",";
    }
    cout << "]";
}

void input() {
    int t;  cin >> t;
    while (t--) {
        int n;
        cin >> cmds;
        cin >> n;
        cin >> inputNums;
        solve(inputNums);
        cout << "\n";
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    input();

    return 0;
}

#endif