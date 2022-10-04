#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    map<string, bool> mp;
    string before = "";

    int cnt = 1, index = 0;
    int length = words.size();
    bool check = true;
    while (check) {
        for (int i = 1; i <= n; i++, index++, length--) {
            if (length == 0) {
                answer = { 0,0 };
                check = false;
                break;
            }

            if (mp.count(words[index])) {
                answer = { i,cnt };
                check = false;
                break;
            }
            else {
                mp.insert({ words[index],true });

                if (before == "") {
                    before = words[index];
                    continue;
                }
                else if (before.back() != words[index].front()) {
                    answer = { i,cnt };
                    check = false;
                    break;
                }

                before = words[index];
            }
        }

        cnt++;
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<string> words;
    for (int i = 0; i < m; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    vector<int> answer = solution(n, words);

    cout << answer[0] << ' ' << answer[1];
}