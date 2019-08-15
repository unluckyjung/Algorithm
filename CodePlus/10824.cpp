#include<bits/stdc++.h>
using namespace std;

int main() {
	char arr1[20];
	char arr2[20];
	char arr3[20];
	char arr4[20];
	
	scanf("%s %s %s %s", arr1, arr2, arr3, arr4);
	sprintf(arr1, "%s%s", arr1, arr2);
	sprintf(arr2, "%s%s", arr3, arr4);

	printf("%lld",atoll(arr1) + atoll(arr2));

	//int a, b, c, d;
	//cin >> a >> b >> c >> d;
	//string s1 = to_string(a) + to_string(b);
	//string s2 = to_string(c) + to_string(d);

	//long long l1 = stoll(s1);
	//long long l2 = stoll(s2);
	//cout << l1 + l2;


	return 0;
}