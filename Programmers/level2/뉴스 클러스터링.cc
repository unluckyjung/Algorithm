#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> Amap, Bmap;

int GetUnion() {
    int cnt = 0;

    const auto ANoExist = Amap.end();
    const auto BNoExist = Bmap.end();

    for (auto A : Amap) {
        string AStr = A.first;
        int ACnt = A.second;
        if (Bmap.find(AStr) != BNoExist) cnt += max(ACnt, Bmap[AStr]);
        else cnt += ACnt;
    }

    for (auto B : Bmap) {
        string BStr = B.first;
        int BCnt = B.second;
        if (Amap.find(BStr) != ANoExist) continue;
        else cnt += BCnt;
    }

    return cnt;
}

int GetIntersection() {
    int cnt = 0;
    const auto NoExist = Bmap.end();
    for (auto A : Amap) {
        string AStr = A.first;
        int ACnt = A.second;
        if (Bmap.find(AStr) == NoExist) continue;
        else cnt += min(ACnt, Bmap[AStr]);
    }
    return cnt;
}

void SplitTwoChar(string str, bool flag) {
    for (int i = 0; i < (int)str.size() - 1; ++i) {
        if (!isalpha(str[i]) or !isalpha(str[i + 1])) continue;
        string splitedStr = str.substr(i, 2);
        if (flag) Amap[splitedStr]++;
        else Bmap[splitedStr]++;
    }
}

string ParsingStr(string str) {
    string ret = "";
    for (const char& ch : str) {
        ret += tolower(ch);
    }
    return ret;
}

int solution(string str1, string str2) {
    double JcardSimillar = 0.0;
    str1 = ParsingStr(str1);
    str2 = ParsingStr(str2);

    SplitTwoChar(str1, true);
    SplitTwoChar(str2, false);

    int intersectionCnt = GetIntersection();
    int UnionCnt = GetUnion();

    const int base = 65536;
    if (UnionCnt == 0) JcardSimillar = 1;
    else JcardSimillar = double(intersectionCnt) / double(UnionCnt);

    return JcardSimillar * base;
}
