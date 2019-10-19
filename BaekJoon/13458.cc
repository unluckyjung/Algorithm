#include<iostream>
using namespace std;

//백준 13458 시험감독
//boj.kr/13458

int n;	//시험장 갯수
int A[1000001];	//시험장마다 있는 사람의 수를 저장할 배열.
int master_check, sub_check;

long long master;
long long sub;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);
	cin >> n;
	master = n;
	for (int i = 0; i < n; ++i) {
		int people; cin >> people;
		A[i] = people;
	}

	cin >> master_check >> sub_check;

	for (int i = 0; i < n; ++i) {
		if (A[i] > master_check) {
			A[i] -= master_check;	sub++;
			while (A[i] > sub_check) {
				A[i] -= sub_check;	sub++;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (A[i] > master_check) {
			//만약 시험장의 사람수가 총 감독자의 능력을 벗어난다면
			A[i] -= master_check;
			sub += A[i] / sub_check;
			//나누어서 구한다, 필요한 부 감독자의 수를 구한다.
			if (A[i] % sub_check) sub++;
			//만약 나머지가 있는경우 부 감독자 를 한명 증가시킨다.
		}
	}

	cout << master + sub;

	return 0;
}