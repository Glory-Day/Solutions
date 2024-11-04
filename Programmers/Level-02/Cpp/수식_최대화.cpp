#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split(const string& s)
{
    vector<string> result;
    
    string cache = "";
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (isdigit(s[i]) == false)
        {
            result.push_back(cache);
            result.push_back(string(1, s[i]));
            cache.clear();
            
            continue;
        }
        
        cache.push_back(s[i]);
    }
    
    if (cache.empty() == false)
    {
        result.push_back(cache);
    }
    
    return result;
}

long long solution(string expression) {
    long long answer = 0;
    
    vector<char> ops = { '*','+','-' };
    vector<string> v = split(expression);
    
    do
    {
        vector<string> copy(v.begin(), v.end());
        
        for (int i = 0; i < (int)ops.size(); i++)
        {
            for (int j = 0; j < (int)copy.size() - 2; j++)
            {
                if (copy[j + 1][0] == ops[i])
                {
                    string cache;
                    switch (ops[i])
                    {
                        case '+': cache = to_string(stoll(copy[j]) + stoll(copy[j + 2])); break;
                        case '-': cache = to_string(stoll(copy[j]) - stoll(copy[j + 2])); break;
                        case '*': cache = to_string(stoll(copy[j]) * stoll(copy[j + 2])); break;
                    }
                    
                    copy.erase(copy.begin() + j, copy.begin() + j + 3);
                    copy.insert(copy.begin() + j, cache);

                    j--;
                }
            }
            
            for (int j = 0; j < (int)copy.size(); j++)
            {
                cout << copy[j];
            }
            cout << '\n';

            answer = max(answer, abs(stoll(copy.front())));
        }
    }
    while (next_permutation(ops.begin(), ops.end()));
    
    return answer;
}

int main()
{
    string expression;
    cin >> expression;

    long long answer = solution(expression);

    cout << answer;
}