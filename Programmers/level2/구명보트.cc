#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int boat_w = 0;

    deque<int> p{ people.begin(), people.end() };
    sort(p.begin(), p.end());

    while (!p.empty()) {
        answer++;
        boat_w = 0;
        boat_w += p.back(); p.pop_back();
        
        if (p.empty()) continue;
        if (boat_w + p.front() <= limit) p.pop_front();
    }

    return answer;
}