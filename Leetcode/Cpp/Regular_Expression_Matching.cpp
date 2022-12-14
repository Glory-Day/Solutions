#include <iostream>
#include <string>
#include <vector>
#include <memory.h>

using namespace std;

class Solution {
public:
    int cache[1000][1000];

    bool isMatch(string s, string p) {
        memset(cache, -1, sizeof(cache));
        return match(0, 0, s, p);
    }

    bool match(int i, int j, string& s, const string& p) {
        if (cache[i][j] != -1) {
            return cache[i][j];
        }

        bool answer;
        if (j == p.size()) {
            answer = (i == s.size());
        }
        else {
            bool chk = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
            if (j + 1 < p.size() && p[j + 1] == '*') {
                answer = match(i, j + 2, s, p) || (chk && match(i + 1, j, s, p));
            }
            else {
                answer = chk && match(i + 1, j + 1, s, p);
            }
        }

        cache[i][j] = answer ? 1 : 0;

        return answer;
    }
};

int main() {
    string s, p;
    cin >> s >> p;

    bool answer = Solution().isMatch(s, p);

    cout << answer;
}