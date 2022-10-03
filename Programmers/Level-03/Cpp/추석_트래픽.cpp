#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getEnd(string t) {
    string h, m, s, ms;
    h = m = s = ms = "";

    h += t[0], h += t[1];
    m += t[3], m += t[4];
    s += t[6], s += t[7];
    ms += t[9], ms += t[10], ms += t[11];

    int sum = stoi(h) * 3600;
    sum += stoi(m) * 60;
    sum += stoi(s);

    return (sum * 1000) + stoi(ms);
}

int getBegin(int ms, string t) {
    t.pop_back();

    string s = "";
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '.') {
            continue;
        }

        s += t[i];
    }

    int len = 4 - s.size();
    for (int i = 0; i < len; i++) {
        s += '0';
    }

    return ms - stoi(s) + 1;
}

int solution(vector<string> lines) {
    int answer = 0;

    vector<int> bs, es;
    for (int i = 0; i < lines.size(); i++) {
        string t[3];
        t[0] = t[1] = t[2] = "";

        int j = 0;
        for (int k = 0; k < lines[i].size(); k++) {
            if (lines[i][k] == ' ') {
                j++;
                continue;
            }

            t[j] += lines[i][k];
        }

        int end = getEnd(t[1]);
        bs.push_back(getBegin(end, t[2]));
        es.push_back(end);
    }

    for (int i = 0; i < lines.size(); i++) {
        int end = es[i] + 1000;
        int mx = 0;

        for (int j = i; j < lines.size(); j++) {
            if (bs[j] < end) {
                mx++;
            }
        }

        answer = max(answer, mx);
    }

    return answer;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<string> lines;
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        lines.push_back(s);
    }

    int answer = solution(lines);

    cout << answer;
}