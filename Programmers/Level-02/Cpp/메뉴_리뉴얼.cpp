#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<string, int> psi;

bool cmp(psi& a, psi& b) {
    return a.second < b.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (auto& i: orders) {
        sort(i.begin(), i.end());
    }

    for (int& i: course) {
        unordered_map<string, int> mp;
        for (string& j: orders) {
            vector<int> idxs;

            if (j.size() < i) continue;

            for(int k = 0; k < j.size() - i; k++){
                idxs.push_back(0);
            }

            for(int k = 0; k < i; k++){
                idxs.push_back(1);
            }

            do {
                string s = "";
                for (int k = 0; k < j.size(); k++) {
                    if (idxs[k]) {
                        s += j[k];
                    }
                }

                if (mp.find(s) != mp.end()) {
                    mp[s]++;
                }
                else {
                    mp[s] = 1;
                }
            } while (next_permutation(idxs.begin(), idxs.end()));
        }

        if (mp.empty()) continue;

        vector<psi> vs;
        for (auto& it: mp) vs.emplace_back(it);

        sort(vs.begin(), vs.end(), cmp);        

        int cnt = vs.back().second;
        if (cnt < 2) continue;

        for (auto it = vs.rbegin(); it != vs.rend(); it++) {
            if (cnt == it->second) answer.push_back(it->first);
            else break;
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<string> orders;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        orders.push_back(input);
    }

    cin >> n;

    vector<int> course;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        course.push_back(input);
    }

    vector<string> answer = solution(orders, course);

    for (string& i: answer) {
        cout << i << '\n';
    }
}