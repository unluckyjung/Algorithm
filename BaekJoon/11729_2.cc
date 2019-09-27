#include <bits/stdc++.h>
using namespace std;

int n;

//11729 하노이탑

//	하노이의 핵심 
//	n개의 원판을 목적지 타워에 넣는 규칙이 있다.
//	(0) 옮겨야 되는 원판이 1개인 경우만, 목적지로 바로 이동시킨다.

//	아니라면 아래의 규칙을 따른다.

//	(1) n-1개의 원판을 남는 타워에 넣는다.
//	(2) 그리고 남은 원판 1개(가장 큰 원판)를 목적지 타워로 옮긴다. 
//	(3) 남는 타워에 있던 n-1개의 원판을 목적지 타워로 옮긴다.

void hanoi(int n, int from, int tmp, int to) {
	if (n == 1) {	//	(0)
		cout << from << " " << to << "\n";
		//옮기는것이 1개라면 목적지 타워로 바로 이동시킨다.
		return;
	}
	else {
		hanoi(n - 1, from, to, tmp);	//	(1)
		//n-1개의 원판을 남는 타워에 옮긴다.	
		cout << from << " " << to << "\n";	//	(2)
		//남은 1개의 원판(가장 큰 원판)이 목적지 타워로 이동한 모습을 출력한다.
		hanoi(n - 1, tmp, from, to);	//	(3)
		//남는 타워에 넣었던 n-1개의 원판을 목적지 타워에 옮긴다.

		//결국 출력되는것은, 자기가 해당 재귀에서 가장 큰 원판일 경우.
		//혹은 옮겨져야 되는것이 한개인 경우이다.
		return;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	cout << (int)pow(2, n) - 1 << "\n";
	//최대 이동거리 점화식
	//원판 갯수가 n일때	n^2 -1

	hanoi(n, 1, 2, 3);
	//하노이 재귀를 돌린다. n개의 원판을 1,2,3번 탑으로.
	return 0;
}