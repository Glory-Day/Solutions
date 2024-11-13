#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, vector<int>> PAIR;

vector<int> memo(100001, 0);
vector<PAIR> Vector;

vector<int> solution(string s) {
    vector<int> answer;

    string temp = "";

    vector<int> Array;
    bool check = false;
    int index = 0;
    for (int i = 1; i < (int)s.size() - 1; i++) {
        if (s[i] == '{')
        {
            check = true;
        }
        else if (s[i] == '}')
        {
            check = false;
            
            Array.push_back(stoi(temp));
            Vector.push_back({ Array.size(), Array });
            
            temp.clear();
            Array.clear();
        }

        if (check)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                temp += s[i];
            }
            else
            {
                if (temp[0] >= '0' && temp[0] <= '9')
                {
                    int number = stoi(temp);
                    Array.push_back(number);
                }

                temp.clear();
            }
        }
    }

    sort(Vector.begin(), Vector.end());

    for (auto v: Vector)
    {
        for (auto i: v.second)
            if (memo[i] == 0)
            {
                answer.push_back(i);
                
                memo[i]++;
            }
    }
    
    return answer;
}

int main()
{
    string s;
    cin >> s;

    vector<int> answer = solution(s);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}