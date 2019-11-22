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



void dfs(int cnt , int sum, const vector<int> &num) {
	if (cnt >= Size) {
		if(sum == tg)answer++;
		return;
	}

	dfs(cnt + 1, sum + num[cnt], num);
	dfs(cnt + 1, sum - num[cnt], num);
	return;
}

int solution2(vector<int> numbers, int target) {
	tg = target;
	Size = numbers.size();
	dfs(0, 0, numbers);
	return answer;
}