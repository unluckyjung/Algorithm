#include <string>
#include <vector>
#include <iostream>

long long arr[100001] = { 0,1,1 };
const int mod = 1234567;
using namespace std;

int solution(int n) {
	int answer = 0;
	if (n == 0)return 0;
	if (n <= 2)return 1;


	for (int i = 3; i <= n; ++i) {
		//arr[i] = arr[i - 1] % mod + arr[i - 2] % mod;
		arr[i] = (arr[i - 1] + arr[i - 2]) % mod;
	}
	answer = arr[n];
	return answer;
}