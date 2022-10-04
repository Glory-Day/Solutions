#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);

    set<string> cnt(gems.begin(), gems.end());

    int b = 0, e = 0;
    unordered_map<string, int> mp;
    for (auto& i: gems) {
        mp[i]++;
        
        if (mp.size() == cnt.size()) break;
        e++;
    }

    answer = { b + 1,e + 1 };

    int mn = e - b;
    while(e < gems.size()) {
        string k = gems[b];
        mp[k]--, b++;

        if (mp[k] == 0) {
            e++;
            while (e < gems.size()) {
                mp[gems[e]]++;
                if (k == gems[e]) break;
                e++;
            }

            if (e == gems.size()) break;
        }

        if (mn > e - b) {
            answer = { b + 1,e + 1 };
            mn = e - b;
        }
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<string> gems;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        gems.push_back(input);
    }

    vector<int> answer = solution(gems);

    cout << answer[0] << ' ' << answer[1];
}