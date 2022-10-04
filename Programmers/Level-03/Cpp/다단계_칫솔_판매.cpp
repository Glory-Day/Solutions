#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

typedef pair<string, int> psi;
typedef unordered_map<string, vector<string>> ump;

ump map;
unordered_map<string, vector<int>> mp;

int getChange(int change) {
    if (change * 10 < 100) {
        change = 0;
    }
    else {
        change = (change * 10) / 100;
    }

    return change;
}

vector<int> dfs(string name) {
    vector<int> changes;

    vector<int> sum = mp[name];
    for (int i = 0; i < sum.size(); i++) {
        int change = getChange(sum[i]);
        sum[i] -= change;
        changes.push_back(change);
    }

    int change = 0;
    
    for (auto nd: map[name]) {
        vector<int> chs = dfs(nd);
        for (int& j: chs) {
            int c = getChange(j);
            changes.push_back(c);
            change += (j - c);
        }
    }

    sum.push_back(change);

    mp[name] = sum;

    return changes;
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    for (int i = 0; i < seller.size(); i++) {
        mp[seller[i]].push_back(amount[i] * 100);
    }

    mp["-"].push_back(0);
    map["-"] = vector<string>();
    for (string& i: enroll) {
        if (mp.find(i) == mp.end()) mp[i].push_back(0);
        map[i] = vector<string>();
    }

    for (int i = 0; i < referral.size(); i++) {
        map[referral[i]].push_back(enroll[i]);
    }

    dfs("-");

    for (string& i: enroll) {
        int sum = 0;
        for (int& j: mp[i]) sum += j;
        answer.push_back(sum);
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<string> enroll;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        enroll.push_back(input);
    }

    cin >> n;

    vector<string> referral;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        referral.push_back(input);
    }

    cin >> n;

    vector<string> seller;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        seller.push_back(input);
    }

    cin >> n;

    vector<int> amount;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        amount.push_back(input);
    }

    vector<int> answer = solution(enroll, referral, seller, amount);

    for (int& i: answer) {
        cout << i << '\n';
    }
}