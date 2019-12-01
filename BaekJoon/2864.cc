#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int n1_max, n1_min;
int n2_max, n2_min;

string find_max(string str) {
	for (int i = 0; i < (int)str.size(); ++i) {
		if (str[i] == '5')	str[i] = '6';
	}
	return str;
}

string find_min(string str) {
	for (int i = 0; i < (int)str.size(); ++i) {
		if (str[i] == '6')	str[i] = '5';
	}
	return str;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string n1, n2;
	cin >> n1 >> n2;

	n1_max = stoi(find_max(n1));
	n1_min = stoi(find_min(n1));
	n2_max = stoi(find_max(n2));
	n2_min = stoi(find_min(n2));

	cout << n1_min + n2_min << " " << n1_max + n2_max;
	return 0;
}