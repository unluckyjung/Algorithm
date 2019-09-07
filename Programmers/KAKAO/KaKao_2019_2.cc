#include <bits/stdc++.h>
using namespace std;

void change_u(string& u) {
	int len = u.size();
	u.pop_back();
	//u.erase(len - 1, len - 1);
	u.erase(0, 1);	//(0, 0)하면 틀림
	if (u.empty() != 1) {
		int u_size = u.size();
		for (int i = 0; i < u_size; ++i) {
			if (u[i] == '(') {
				u[i] = ')';
			}
			else {
				u[i] = '(';
			}
		}
	}
}

bool valid(string s)
{
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			cnt += 1;
		else
			cnt -= 1;

		if (cnt < 0)
			return false;
	}
	if (cnt == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string edit(const string& s)
{
	string answer;

	if (s.empty() == 1)
	{
		return s;
	}
	int count = 0;

	int len = s.size();
	for (int i = 0; i < len; ++i)
	{
		if (s[i] == '(')
		{
			count++;
		}
		else if (s[i] == ')')
		{
			count--;
		}
		if (count == 0)
		{
			string u = s.substr(0, i+1);
			string v;
			if (i < len - 1)
			{
				v = s.substr(i + 1, len - 1);
			}
			if (valid(u) == true)
			{
				v= edit(v);
				answer += u + v;
				break;
			}
			else
			{
				string new_string = "(";
				new_string += v;
				new_string += ")";
				change_u(u);
				new_string += u;
				return new_string;
			}
		}
	}
	return answer;
}

string solution(string s)
{
	int cnt = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
			cnt += 1;
		else
			cnt -= 1;

		if (cnt < 0)
		{
			return edit(s);
			//return s;
		}
	}
	if (cnt == 0)
	{
		return s;
	}
	else
	{
		return edit(s);
		//return s;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	cout << solution(s) << "\n";

	return 0;
}