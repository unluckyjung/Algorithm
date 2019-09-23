#include <bits/stdc++.h>
using namespace std;

int card[21];

void swap_card(int n1, int n2) {

	for(int i = 0 ; i<(n2-n1)/2+1 ; ++i){
		swap(card[n1 + i], card[n2-i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i < 21; ++i) card[i] = i;

	int cnt = 10;

	while (cnt--) {

		int n1, n2;
		cin >> n1 >> n2;
		swap_card(n1, n2);
	
	}

	for (int i : card) {
		if (i == 0) continue;
		cout << i << " ";
	}
	return 0;
}