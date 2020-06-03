


#if 00
#include<bits/stdc++.h>
using namespace std;

struct music {
    int play_cnt;
    int music_number;
};

bool cmp(const music &a, const music &b) {
    if (a.play_cnt == b.play_cnt) return a.music_number < b.music_number;
    else return a.play_cnt > b.play_cnt;
}



map<string, pair<int, vector<music> > > musics;

vector<int> answer;
vector<int> solution(vector<string> genres, vector<int> plays) {
    int len = plays.size();

    for (int i = 0; i < len; ++i) {
        string type = genres[i];
        int type_cnt = plays[i];
        int uniq_num = i;

        musics[type].first += type_cnt;
        musics[type].second.push_back({ type_cnt, uniq_num });
    }

    map<int, vector<music> > tmp;

    for (auto it = musics.begin(); it != musics.end(); ++it) {
        tmp[it->second.first] = it->second.second;
    }
    
    for (auto it = tmp.rbegin(); it != tmp.rend(); ++it) {
        vector<music> &vec = (it->second);
        sort(vec.begin(), vec.end(), cmp);

        for (int i = 0; i < vec.size() && i < 2; ++i) {
            answer.push_back(vec[i].music_number);
        }
    }

    return answer;
}

#else

#include<bits/stdc++.h>
#define pp pair<int, int>

using namespace std;

unordered_map<string, pair<int, vector<pp> > > musics;

vector<int> answer;
vector<int> solution(vector<string> genres, vector<int> plays) {
    int len = plays.size();

    for (int i = 0; i < len; ++i) {
        string type = genres[i];
        int type_cnt = -plays[i];
        int uniq_num = i;

        musics[type].first += type_cnt;
        musics[type].second.push_back({ type_cnt, uniq_num });
    }

    map<int, vector<pp> > tmp;

    for (auto it = musics.begin(); it != musics.end(); ++it) {
        tmp[it->second.first] = it->second.second;
    }

    for (auto it = tmp.begin(); it != tmp.end(); ++it) {
        vector<pp>& vec = it->second;
        sort(vec.begin(), vec.end());

        for (int i = 0; i < vec.size() && i < 2; ++i) {
            answer.push_back(vec[i].second);
        }
    }
    return answer;
}

#endif

int main() {

    vector<string> ge = { "classic", "pop", "classic", "classic", "pop", "lock" };
    vector<int> p = { 500, 600, 150, 800, 2500, 100 };
    vector<int> ans = solution(ge, p);

    for (auto it : ans) {
        cout << it << " ";
    }

    return 0;
}