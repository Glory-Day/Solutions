#include <iostream>
#include <vector>
#include <set>

using namespace std;

int getValue(string cmd) {
    string s = "";
    for (int i = 2; i < cmd.size(); i++) {
        s += cmd[i];
    }

    return stoi(s);
}

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'O');

    vector<int> prev;
    vector<int> next;
    for (int i = 0; i < n + 2; i++) { 
        prev.push_back(i - 1); 
        next.push_back(i + 1); 
    } 

    k++;

    vector<int> idxs;

    int v = 0;
    for (string& i: cmd) {
        switch (i[0]) {
            case 'U':
                v = stoi(i.substr(2));
                while (v--) k = prev[k];
                break;
            case 'D':
                v = stoi(i.substr(2));
                while (v--) k = next[k];
                break;
            case 'C':
                idxs.push_back(k); 
                next[prev[k]] = next[k]; 
                prev[next[k]] = prev[k]; 
                if (next[k] == n + 1) k = prev[k]; 
                else k = next[k];
                break;
            case 'Z':
                int idx = idxs.back(); 
                next[prev[idx]] = idx; 
                prev[next[idx]] = idx; 
                idxs.pop_back();
                break;
        }
    }

    while (!idxs.empty()) {
        answer[idxs.back() - 1] = 'X';
        idxs.pop_back(); 
    }

    return answer;
}

int main() {
    int n, k;
    cin >> n >> k;

    int m;
    cin >> m;
    cin.ignore();

    vector<string> cmd;
    for (int i = 0; i < m; i++) {
        string input;
        getline(cin, input);
        cmd.push_back(input);
    }

    string answer = solution(n, k, cmd);

    cout << answer;
}