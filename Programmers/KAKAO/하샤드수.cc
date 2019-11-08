#include <string>
#include <vector>

using namespace std;

int ret(int n) {
	int sum = 0;
	while (n) {
		sum += n % 10;
		n = n / 10;
	}
	return sum;
}

bool solution(int x) {
	//int tmp = ret(x);
	return x % ret(x) == 0 ? true : false;
}