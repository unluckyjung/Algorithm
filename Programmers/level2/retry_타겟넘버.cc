#include <string>
#include <vector>

using namespace std;

vector<int>num;
int answer, tg, Size;

void solve(int index, int sum) {
	if (index >= Size) {
		if (sum == tg)answer++;
		return;
	}
	solve(index + 1, sum + num[index]);
	solve(index + 1, sum - num[index]);
}

int solution(vector<int> numbers, int target) {
	Size = numbers.size();
	tg = target;
	for (int it : numbers)	num.push_back(it);
	solve(0, 0);

	return answer;
}