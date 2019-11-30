#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n; cin >> n;
	while (n--)
	{
		string s1, s2, s3;
		cin >> s1 >> s2;
		cin.ignore();
		getline(cin, s3);
		cout << s3 << " " << s1 << " " << s2 << "\n";
	}
}