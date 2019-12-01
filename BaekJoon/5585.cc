#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//500, 100 , 10, 5, 1
int coin_num[] = { 500, 100 ,50, 10, 5, 1 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int money = 1000;
	int price; cin >> price;
	money -= price;

	int coin = 0;
	
	for (int i = 0; i < 6; ++i) {
		coin += money / coin_num[i];
		money %= coin_num[i];
	}

	cout << coin;


	return 0;
}