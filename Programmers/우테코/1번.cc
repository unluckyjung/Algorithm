#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(vector<int> restaurant, vector<vector<int>> riders, int k) {
	int answer = 0;
	double res_nx = restaurant[0], res_ny = restaurant[1];
	for (int i = 0; i < (int)riders.size(); ++i) {
		int rider_nx = riders[i][0] , rider_ny = riders[i][1];
		int dis = sqrt(pow(res_nx - rider_nx, 2) + pow(res_ny - rider_ny, 2));

		if (k > dis) {
			cout << rider_nx << " " << rider_ny << "\n";
			answer++;
		}
	}
	return answer;
}

int main() {

	vector<int> vec1{ 0,0 };
	vector<vector<int>>vec2{ {-700, 0},{150, 180},{500, 500},{150, -800},{800, 800},{-900, 500},{-1100, 900} };
	cout << solution(vec1, vec2, 1000);
	return 0;
}