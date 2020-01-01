#include<bits/stdc++.h>
using namespace std;

list<int> l;
void insert_num() {
    int find_num, num_cnt;
    cin >> find_num >> num_cnt;

    list<int>::iterator it = l.begin();

    while (find_num--) {
        it++;
    }

    while (num_cnt--) {
        int insert_num; cin >> insert_num;
        l.insert(it, insert_num);
    }
}

void delete_num() {
    int find_num, num_cnt;
    cin >> find_num >> num_cnt;
    list<int>::iterator it = l.begin();

    while (find_num--) {
        it++;
    }

    while (num_cnt--) {
        it = l.erase(it);
    }
}

void add_num() {
    int num_cnt;
    cin >> num_cnt;

    while (num_cnt--) {
        int a_num; cin >> a_num;
        l.push_back(a_num);
    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    for (int cnt = 1; cnt <= 10; ++cnt) {
        int n;  cin >> n;

        l.clear();
        while (n--) {
            int num;    cin >> num;
            l.push_back(num);
        }

        int cmd_num;    cin >> cmd_num;
        while (cmd_num--) {
            char cmd;   cin >> cmd;
            if (cmd == 'I') {
                insert_num();
            }
            else if (cmd == 'D') {
                delete_num();
            }
            else if (cmd == 'A') {
                add_num();
            }
        }

        cout << "#" << cnt << " ";
        int N = 0;
        for (list<int>::iterator it = l.begin(); N < 10; ++it, ++N)
        {
            cout << *it << " ";
        }
        cout << "\n";
    }
    return 0;
}