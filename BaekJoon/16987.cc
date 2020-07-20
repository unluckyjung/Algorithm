#include<bits/stdc++.h>
using namespace std;

struct egg {
    int durability;
    int weight;
};

int n, answer;
egg eggs[10];

int HitEgg(int attackEgg, int defenceEgg) {

    int brokenCnt = 0;
    eggs[attackEgg].durability -= eggs[defenceEgg].weight;
    eggs[defenceEgg].durability -= eggs[attackEgg].weight;

    if (eggs[attackEgg].durability <= 0) brokenCnt++;
    if (eggs[defenceEgg].durability <= 0) brokenCnt++;

    return brokenCnt;
}

void RecoveryEgg(int attackEgg, int defenceEgg) {
    eggs[attackEgg].durability += eggs[defenceEgg].weight;
    eggs[defenceEgg].durability += eggs[attackEgg].weight;
}

void SelectEgg(int attackEgg, int brokenCnt) {

    if (attackEgg > n) return;
    answer = max(answer, brokenCnt);

    if (eggs[attackEgg].durability <= 0) {
        SelectEgg(attackEgg + 1, brokenCnt);
        return;
    }

    for (int defenceEgg = 0; defenceEgg < n; ++defenceEgg) {
        if (defenceEgg == attackEgg) continue;
        if (eggs[defenceEgg].durability <= 0) continue;

        SelectEgg(attackEgg + 1, brokenCnt + HitEgg(attackEgg, defenceEgg));
        RecoveryEgg(attackEgg, defenceEgg);
    }
}

void Solve() {
    SelectEgg(0, 0);
    cout << answer << "\n";
}

void Input() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> eggs[i].durability >> eggs[i].weight;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);

    freopen("input.txt", "r", stdin);
    Input();
    Solve();

    return 0;
}