#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer, _size;
vector<string> cache;


void CacheHit(const string &city){
    answer ++;
    auto it = find(cache.begin(), cache.end(), city);
    cache.erase(it);
    cache.push_back(city);
}

bool IsCacheHaveCity(const string &city){
    auto it = find(cache.begin(), cache.end(), city);
    return it != cache.end();
}

void CacheMiss(const string &city){
    answer += 5;
    if(!cache.empty() and (int)cache.size() == _size) cache.erase(cache.begin());
    cache.push_back(city);
}

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize == 0){
        return 5 * (int)cities.size();
    }
    _size = cacheSize;

    for(string city : cities){
        for(char &c : city){
            c = tolower(c);
        }
            
        if (cache.empty()) {
            CacheMiss(city);
            continue;
        }
        
        if(IsCacheHaveCity(city)) CacheHit(city);
        else CacheMiss(city);
    }

    return answer;
}