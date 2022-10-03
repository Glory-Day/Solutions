#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    unordered_map<string, set<string>> mp;
    for (string& i: id_list) {
        mp[i] = set<string>();
    }

    for (int i = 0; i < report.size(); i++) {
        string s[2];
        for (int j = 0, k = 0; j < report[i].size(); j++) {
            if (report[i][j] == ' ') {
                k++;
                continue;
            }

            s[k].push_back(report[i][j]); 
        }

        mp[s[0]].insert(s[1]);
    }

    unordered_map<string, int> cnt1, cnt2;
    for (string& i: id_list) {
        cnt1[i] = cnt2[i] = 0;
    }

    for (string& i: id_list) {
        for (auto it = mp[i].begin(); it != mp[i].end(); it++) {
            cnt1[*it]++;
        }
    }

    for (auto it1 = mp.begin(); it1 != mp.end(); it1++) {
        int sum = 0;
        for (auto it2 = (*it1).second.begin(); it2 != (*it1).second.end(); it2++) {
            if (cnt1[*it2] >= k) sum++;
        }
        cnt2[(*it1).first] = sum;
    }

    for (string& i: id_list) {
        answer.push_back(cnt2.find(i)->second);
    }

    return answer;
}

int main() {
    int n, k;
    cin >> n;

    vector<string> id_list;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        id_list.push_back(input);
    }

    cin >> n;
    cin.ignore();

    vector<string> report;
    for (int i = 0; i < n; i++) {
        string input;
        getline(cin, input);
        report.push_back(input);
    }

    cin >> k;

    vector<int> answer = solution(id_list, report, k);

    for (int& i: answer) {
        cout << i << '\n';
    }
}