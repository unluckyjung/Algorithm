#include <string>
#include <vector>
#include <iostream>

using namespace std;

string func1(string str1);
string func2(string str2);
bool is_correct(string str3);
void func4(string& str4);




string func1(string str1) {
	if (str1.size() == 0)	return "";	//1
	else if(is_correct(str1)) return str1;
	else return func2(str1);	//2
}


string func2(string str2) {
	string u;
	string v;

	int num = 0;
	int i;
	//2
	for (i = 0; i < (int)str2.size(); ++i) {

		if (!u.empty() && num == 0) break;

		if (str2[i] == '(') {
			num++;	u.push_back(str2[i]);
		}
		else {
			num--;	u.push_back(str2[i]);
		}
	}
	v = str2.substr(i);	//2
	//하나 큰거까진 괜찮음. 문제 생기면 예외처리

	if (is_correct(u)) {
		return u + func1(v);
	}
	else {
		string tmp = "(";
		tmp = tmp + func1(v);
		tmp = tmp + ")";
		func4(u);
		tmp = tmp + u;
		return tmp;
	}
}



void func4(string& str4) {
	str4.erase(0, 1);
	str4.pop_back();

	for (int i = 0; i < str4.size(); ++i) {
		if (str4[i] == '(') str4[i] = ')';
		else str4[i] = '(';
	}
}

bool is_correct(string str3) {
	int check = 0;
	for (int i = 0; i < (int)str3.size(); ++i) {
		if (str3[i] == '(')	check++;
		else check--;

		if (check < 0)return false;
	}
	return true;
}


string solution(string p) {
	string answer;
	answer = func1(p);


	return answer;
}

int main() {

	cout << solution("()))((()");
	return 0;
}