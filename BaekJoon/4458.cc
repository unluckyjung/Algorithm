#include <bits/stdc++.h>
using namespace std;

int main()
{

    //ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
    //getline과 함께쓰면 에러 뿜뿜.
    
	int num;
	cin >> num;
    getchar();  //enter 버퍼 빼줘야함

	int a = 'a' - 'A';

	while (num--) {
		string str;
		getline(cin, str);

		if(str[0] >= 'a' and str[0] <='z') str[0] -= a;
		cout << str <<"\n";
	}

	return 0;
}