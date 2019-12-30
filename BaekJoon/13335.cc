#include <bits/stdc++.h>
using namespace std;

int t_n, b_w, b_l;
int cur_w, cur_n;

queue<int> truck;
queue<pair<int, int>> cur_bridge;
//t_w, input_t 

void push_truck() {
    for (int i = 0; i < t_n; ++i) {
        int truck_w;
        cin >> truck_w;
        truck.push(truck_w);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    /*제출전 주석처리*/freopen("input.txt", "r", stdin);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t_n >> b_l >> b_w;
    push_truck();

    int time = 0;
    int fin_truck = 0;
    while (1) {
        time++;
        if (!cur_bridge.empty()) {
            auto it = cur_bridge.front();
            int truck_w = it.first;
            int input_t = it.second;

            if (time == input_t + b_l) {
                cur_bridge.pop();
                cur_w -= truck_w;
                cur_n--;
                fin_truck++;
            }
        }

        if (fin_truck == t_n)break;

        if (!truck.empty()) {
            int new_truck = truck.front();
            if (cur_w + new_truck <= b_w && cur_n + 1 <= b_l) {
                cur_w += new_truck;
                cur_n++;
                truck.pop();
                cur_bridge.push({ new_truck, time });
            }
        }
    }

    cout << time << "\n";

    return 0;
}