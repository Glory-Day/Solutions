#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;

    string cache[4] = { "aya","ye","woo","ma" };

    for (int i = 0; i < (int)babbling.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            size_t pos = 0;
            while ((pos = babbling[i].find(cache[j], pos)) != string::npos)
            {
                babbling[i].replace(pos, cache[j].length(), "*");
                pos += 2;
            }
        }

        answer++;

        for (int j = 0; j < (int)babbling[i].size(); j++)
        {
            if (babbling[i][j] != '*')
            {
                answer--;
                
                break;
            }
        }
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<string> babbling;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        
        babbling.push_back(input);
    }

    int answer = solution(babbling);

    cout << answer;
    
    return 0;
}