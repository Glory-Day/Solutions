#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    map<int, int> mp;
    for(string& i: operations) {
        int v = stoi(i.substr(2));

        if (i[0] == 'I') {
            if (mp.find(v) != mp.end()) mp[v]++;
            else mp[v] = 0;
        }
        else if (i[0] == 'D' && !mp.empty()) {
            map<int, int>::iterator it;

            if (v == -1) it = mp.begin();
            else it = --mp.end();

            if ((*it).second == 0) mp.erase(it);
            else (*it).second--;
        }
    }

    vector<int> arr;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        for (int i = 0; i <= (*it).second; i++) {
            arr.push_back((*it).first);
        }
    }

    if (arr.empty()) answer = { 0,0 };
    else answer = { arr.back(),arr.front() };

    return answer;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<string> operations;
    for (int i = 0; i < n; i++) {
        string input;
        getline(cin, input);
        operations.push_back(input);
    }

    vector<int> answer = solution(operations);

    cout << answer[0] << ' ' << answer[1];
}