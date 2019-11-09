#include <string>
#include <vector>
#include <cmath>

using namespace std;

int score[3];

int solution(string dart) {
	int answer = 0;
	int cnt = 0;	//숫자가 몇번 등장했는지 기록, 그리고 동시에 score의 index역할.

	for (int i = 0; i < (int)dart.size(); ++i) {
		if (dart[i] >= '0' && dart[i] <= '9') {
			if (dart[i] == '1' && dart[i + 1] == '0') {
				score[cnt] = 10;	cnt++;	i++;	//숫자가 등장했으면 cnt를 증가시켜둔다.
			}
			else {
				score[cnt] = dart[i] - '0'; cnt++;
			}
		}
		else if (dart[i] == 'S') continue;
		else if (dart[i] == 'D') score[cnt-1] = pow(score[cnt-1], 2);	//변경되어야 하는건 현재의 숫자이기때문에 cnt-1로 계산한다.
		else if (dart[i] == 'T') score[cnt-1] = pow(score[cnt-1], 3);	//그냥 cnt는 다음 숫자이다. 생각해보면 3일때 index[3]에 접근하면 에러난다.

		else if (dart[i] == '*') { 
			if (cnt == 1) {
				score[cnt -1] *= 2;
			}
			else {
				score[cnt - 1] *= 2;
				score[cnt - 2] *= 2;
			}
		}
		else if (dart[i] == '#') {
			score[cnt-1] *= -1;
		}

	}

	for (int i = 0; i < 3; ++i) answer += score[i];

	return answer;
}