#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

int getTimeToInt(string t) {
    string time[2];
    time[0] = time[1] = "";

    int j = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == ':') {
            j++;
            continue;
        }

        time[j] += t[i];
    }

    int h = stoi(time[0]) * 60;
    int m = stoi(time[1]);

    return h + m;
}

string getTimeToString(int t) {
    int h = t / 60;
    int m = t % 60;

    string time = "";

    if (h == 0) time += "00:";
    else if (h < 10) time += "0" + to_string(h) + ":";
    else time += to_string(h) + ":";

    if (m == 0) time += "00";
    else if (m < 10) time += "0" + to_string(m);
    else time += to_string(m);

    return time;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    map<int, vector<int>> mp;
    deque<int> ts;

    for (string& i: timetable) {
        ts.push_back(getTimeToInt(i));
    }

    sort(ts.begin(), ts.end());

    int b = getTimeToInt("09:00");
    for (int i = 0; i < n; i++) {
        mp[b + (t * i)] = vector<int>();
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        for (int i = 0; i < m && !ts.empty(); i++) {
            if (ts.front() <= (*it).first) {
                (*it).second.push_back(ts.front());
                ts.pop_front();
            }
            else break;
        }
    }

    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        if ((*it).second.size() == m) {
            // int idx = lower_bound((*it).second.begin(), (*it).second.end(), (*it).first) - (*it).second.begin();
            
            // idx = (idx == 0) ? 0 : idx - 1;
            
            int mx = (*it).second.back();
            answer = getTimeToString(mx - 1);
            break;
        }
        else if ((*it).second.size() < m) {
            answer = getTimeToString((*it).first);
            break;
        }
    }

    return answer;
}

int main() {
    int n, t, m;
    cin >> n >> t >> m;

    int l;
    cin >> l;

    vector<string> timetable;
    for (int i = 0; i < l; i++) {
        string input;
        cin >> input;
        timetable.push_back(input);
    }

    string answer = solution(n, t, m, timetable);

    cout << answer;
}