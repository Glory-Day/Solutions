#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int answer = 0;
        
        int temp = 0;
        for (int i = 0; i < s.size(); i++) {
            switch(s[i]) {
                case 'I':
                    temp = 1;
                    if (i < s.size() - 1) {
                        if (s[i + 1] == 'V') {
                            temp = 5 - temp;
                            i++;
                        }
                        else if (s[i + 1] == 'X') {
                            temp = 10 - temp;
                            i++;
                        }
                    }
                    answer += temp;
                    break;
                case 'V':
                    answer += 5;
                    break;
                case 'X':
                    temp = 10;
                    if (i < s.size() - 1) {
                        if (s[i + 1] == 'L') {
                            temp = 50 - temp;
                            i++;
                        }
                        else if (s[i + 1] == 'C') {
                            temp = 100 - temp;
                            i++;
                        }
                    }
                    answer += temp;
                    break;
                case 'L':
                    answer += 50;
                    break;
                case 'C':
                    temp = 100;
                    if (i < s.size() - 1) {
                        if (s[i + 1] == 'D') {
                            temp = 500 - temp;
                            i++;
                        }
                        else if (s[i + 1] == 'M') {
                            temp = 1000 - temp;
                            i++;
                        }
                    }
                    answer += temp;
                    break;
                case 'D':
                    answer += 500;
                    break;
                case 'M':
                    answer += 1000;
                    break;
            }
        }

        return answer;
    }
};

int main() {
    string s;
    cin >> s;

    int answer = Solution().romanToInt(s);

    cout << answer;
}