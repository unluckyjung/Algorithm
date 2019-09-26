#include <bits/stdc++.h>
using namespace std;

//10814 나이순정렬

vector<pair<int, string>>vec;

bool cmp(const pair<int, string>& a, const pair<int, string>& b)
{
	//if (a.first == b.first)
	//	return a.second < b.second;
	//이게 있다면, 기존의 sort처럼 작동한다.


	//21 Junkyu 21 Dohyun이 들어올경우.
	//21 < 21 이라서 false가 리턴된다.
	//20 < 21이면 true가 리턴된다.

	return a.first < b.first;
	//a가 b보다 작다면 true.
	//부등호를 바꾼다면, 나이가 많은순.
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;
	for (int i = cnt; i > 0; i--) {
		int age;
		string name;
		cin >> age >> name;
		vec.push_back({ age, name });
	}

	//sort(vec.begin(), vec.end());
	//그냥 이렇게 하면, age가 같을경우 name의 사전순선에 따라서 정렬시킨다.

	//sort(vec.begin(), vec.end(), cmp);
	//이 경우에도, 먼저 들어온 순서가 보장 되지 않는다.

	stable_sort(vec.begin(), vec.end(), cmp);
	//stable로_sort로 같은 키값을 가진 원소가 정렬후에도 유지되는것을 보장해야한다.


	for (auto it : vec) {
		cout << it.first << " " << it.second << "\n";
	}

	return 0;
}