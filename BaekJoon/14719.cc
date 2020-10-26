#include <bits/stdc++.h>
using namespace std;

int n, worldLen;
int height, heightIndex;
int world[502];

int rightFill() {
    int rightHeight = 0;
    int sum = 0;
    for (int i = worldLen - 1; i > heightIndex; --i) {
        rightHeight = max(rightHeight, world[i]);
        sum += rightHeight;
    }
    return sum;
}

int leftFill(){
    int leftHeight = 0;
    int sum = 0;
    for (int i = 0; i < heightIndex; ++i) {
        leftHeight = max(leftHeight, world[i]);
        sum += leftHeight;
    }
    return sum;
}

void solve() {
    cin >> n >> worldLen;

    int beforeWaterFill = 0;
    for (int i = 0; i < worldLen; ++i) {
        cin >> world[i];
        if (world[i] > height) {
            height = world[i];
            heightIndex = i;
        }

        beforeWaterFill += world[i];
    }

    int afterWaterFill = rightFill() + leftFill() + height;
    cout << afterWaterFill - beforeWaterFill << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    solve();

    return 0;
}