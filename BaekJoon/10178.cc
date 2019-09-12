#include <bits/stdc++.h>
using namespace std;

int main()
{
	int count;
	cin >> count;
	while (count--) {
		int candy, people;
		cin >> candy >> people;
		printf("You get %d piece(s) and your dad gets %d piece(s).\n",candy/people, candy%people);
	}

	return 0;
}