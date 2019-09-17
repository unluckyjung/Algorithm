#include<bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int arr1[4] = { 1,2,3,4 };

	cout << "==========next permutation==========\n";
	//next_permutation은 범위에 해당하는 사전상으로 큰 다음 순열을 구하고 true를 반환한다.
	//다음순환이 없다면 false를 반환한다.
	do {
		for (int i : arr1)
			cout << i << " ";
		cout << "\n";

	} while (next_permutation(arr1, arr1 + sizeof(arr1) / sizeof(int)));
	//순열의 시작, 순열의 끝을 인자로 받음.

	//1 2 3 4 로시작하고, 사전순으로
	//1 2 4 3.............
	//그리고 4 3 2 1 에 도달했을때 더 이상 사전상으로 큰 수열이 없으므로 false를 리턴후 종료.


	cout << "==========next permutation==========\n\n\n";

	cout << "==========prev permutatoin==========\n";

	vector<int> vec(arr1, arr1 + 4);
	reverse(vec.begin(), vec.end());	//vec : 4 3 2 1

	do {
		for (auto i : vec)
			cout << i << " ";
		cout << "\n";
	} while (prev_permutation(vec.begin(), vec.end()));
	//prev는 사전상으로 더 작은 순열을 찾는다.
	//4 3 2 1
	//4 2 3 1 ............
	//1 2 3 4 도달후 false
	return 0;
}