#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    vector<int> cache(26, -1);
    for (int i = 0; i < s.size(); i++) {
        int tmp = s[i] - 'a';
        if (cache[tmp] != -1) {
            answer.push_back(i - cache[tmp]);
        }
        else {
            answer.push_back(cache[tmp]);
        }
        
        cache[tmp] = i;
    }

    return answer;
}

int main() {
    string s;
    cin >> s;

    vector<int> answer = solution(s);

    for (auto& i: answer) {
        cout << i << ' ';
    }
}