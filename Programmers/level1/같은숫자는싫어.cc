#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
	//vector<int> answer;
	//answer.push_back(arr[0]);
	//for (int i = 1; i < (int)arr.size(); ++i) {
	//	if (arr[i] != arr[i - 1]) answer.push_back(arr[i]);
	//}

	arr.erase(unique(arr.begin(), arr.end()),arr.end());
	vector<int> answer(arr);

	return answer;
}