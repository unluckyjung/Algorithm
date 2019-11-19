#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	//int answer = 0;

	int time = 0 , q_max = 0;
	int truck_num = truck_weights.size();
	int truck_index = 0;
	int finished_truck = 0;
	queue<pair<int, int>> q;

	while (1) {
		time++;

		if (!q.empty()) {
			auto first_truck = q.front();
			if (time - first_truck.second == bridge_length) {
				q_max -= truck_weights[first_truck.first];
				q.pop();	finished_truck++;
			}
		}
		if (finished_truck == truck_num) break;

		if (truck_index < truck_num && truck_weights[truck_index] + q_max <= weight) {
			q.push({ truck_index, time });
			q_max += truck_weights[truck_index];
			truck_index++;
		}

	}
	

	return time;
}