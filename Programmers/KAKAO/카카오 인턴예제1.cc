#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<vector<int> > v) {

	map<int, int> nx;
	map<int, int> ny;


	for (int i = 0; i < (int)v.size(); ++i) {
		for (int ii = 0; ii < 2; ++ii) {
			if (ii == 0) nx[v[i][ii]]++;
			else ny[v[i][ii]]++;
		}
	}

	vector<int> ans;


	for (auto it = nx.begin(); it != nx.end(); ++it) {
		if (it->second == 1)	ans.push_back(it->first);
	}

	for (auto it = ny.begin(); it != ny.end(); ++it) {
		if (it->second == 1)	ans.push_back(it->first);
	}

	return ans;
}