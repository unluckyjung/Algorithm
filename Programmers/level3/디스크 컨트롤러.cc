#include <bits/stdc++.h>
#define pp pair<int,int>

using namespace std;

priority_queue<pp, vector<pp>, greater<pp>> input_pq, job_pq;
int answer;
int cur_time;

void Select_Job() {
    auto job = job_pq.top();    job_pq.pop();

	if (job.second > cur_time) cur_time = job.second;

	int fin_time = cur_time + job.first;
	answer += (fin_time - job.second);
	cur_time = fin_time;
}

void Pq_Check() {
    if (job_pq.empty()) {
        auto job = input_pq.top(); input_pq.pop();
        job_pq.push({ job.second, job.first });
    }

    while (!input_pq.empty() and input_pq.top().first <= cur_time) {
        auto job = input_pq.top(); input_pq.pop();
        job_pq.push({ job.second, job.first });
    }
}

int solution(vector<vector<int>> jobs) {
    for (auto vec : jobs) {
        input_pq.push({ vec[0], vec[1] });
    }

    while (!input_pq.empty() or !job_pq.empty()) {
        Pq_Check();
        Select_Job();
    }

    answer /= jobs.size();
    return answer;
}

int main() {

    vector<vector<int>> jobs{ {0, 3} ,{1, 9},{2, 6} };
    cout << solution(jobs);
    return 0;
}