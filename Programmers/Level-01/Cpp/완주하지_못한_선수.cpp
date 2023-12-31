#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string,int> Map;
    pair<map<string,int>::iterator,bool> pMap;

    for(auto i: participant) {
        // participant에는 동명이인이 있을 수 있다. 따라서 map에 이미 key가 존재하면 value를 증가시킨다.
        pMap = Map.insert({ i,1 });
        if(pMap.second==false) {
            Map[i]++;
        }
    }

    // completion에 원소들을 map에 key로 넣어, key가 존재하면 value를 1씩 감소시킨다.
    for(auto i: completion) {
        Map[i]--;
    }

    // 만약 value가 0이 아니면 participant에는 있지만, completion에는 없는 인물이다.
    for(auto i: Map) {
        if(i.second) {
            return i.first;
        }
    }

    return "";
}

int main() {
    int n;
    cin >> n;

    vector<string> participant, completion;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        participant.push_back(input);
    }

    for (int i = 0; i < n - 1; i++) {
        string input;
        cin >> input;
        participant.push_back(input);
    }

    cout << solution(participant, completion);
}