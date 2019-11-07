#include <string>
#include <vector>
using namespace std;

int gcd(const int &a, const int &b) {
	if (b == 0)	return a;
	else return gcd(b, a % b);
}

int lcm(const int& n, const int& m) {
	return n * m / gcd(n, m);
}

vector<int> solution(int n, int m) {
	vector<int> answer;
	answer.push_back(gcd(n, m));
	answer.push_back(lcm(n, m));
	return answer;
}