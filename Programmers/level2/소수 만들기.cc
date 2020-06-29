#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int answer;
const int MAX = 50002;

int prime[MAX];

void MakePrime() {
    for (int i = 2; i < MAX; ++i) {
        for (int ii = i; ii < MAX; ii += i) {
            prime[ii]++;
        }
    }
}

vector<int> oneIsSelect;

int solution(vector<int> nums) {

    MakePrime();

    oneIsSelect.resize(3, 1);
    oneIsSelect.resize((int)nums.size(), 0);
    
    do {
        int sum = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (oneIsSelect[i] == 0) continue;
            sum += nums[i];
        }
        if (prime[sum] == 1) answer++;
    } while (prev_permutation(oneIsSelect.begin(), oneIsSelect.end()));

    return answer;
}

int main() {
    vector<int> vec{ 1,2,7,6,4 };
    cout << solution(vec);
    return 0;
}