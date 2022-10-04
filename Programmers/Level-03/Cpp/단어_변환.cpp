#include <iostream>
#include <climits>
#include <string>
#include <vector>

using namespace std;

bool visited[50];

int dfs(string begin, string target, vector<string>& words, int lv) {
    int answer = INT_MAX;

    if (begin == target) return lv;

    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words[i].size(); j++) {
            string temp = begin;
            temp[j] = words[i][j];

            if (temp == words[i] && !visited[i]) {
                visited[i] = true;
                answer = min(answer, dfs(words[i], target, words, lv + 1));
                visited[i] = false;
            }
        }
    }

    return answer;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    answer = dfs(begin, target, words, 0);

    if (answer == INT_MAX) answer = 0;

    return answer;
}

int main() {
    string begin, target;
    cin >> begin >> target;

    int n;
    cin >> n;

    vector<string> words;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        words.push_back(input);
    }

    int answer = solution(begin, target, words);

    cout << answer;
}