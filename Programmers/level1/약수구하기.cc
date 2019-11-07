#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;

	for (int i = 1; i*i <= n; ++i) {
		//3는 4의 약수가 될 수 없음. 
		//4는 9의 약수가 될 수 없음.
		if (i * i == n)	answer += i;
		//3은 9의 약수가 될 수 있음.
		else if (n % i == 0) {
			answer += (i + n / i);
			//6을 이루는건 2와 3. 둘다 더한다.
		}
	}
	return answer;
}