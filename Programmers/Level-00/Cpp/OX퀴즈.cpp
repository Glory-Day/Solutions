#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string& s)
{
    vector<string> result;
    
    string cache = "";
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (s[i] == ' ')
        {
            result.push_back(cache);
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

int to_number(const string& s)
{
    int result = 0;
    bool flag = false;
    for (int i = (int)s.length() - 1, j = 1; i >= 0; i--, j *= 10)
    {
        if (s[i] == '-')
        {
            flag = true;
            
            continue;
        }
        
        result += (s[i] - '0') * j;
    }
    
    if (flag)
    {
        result *= -1;
    }
    
    return result;
}

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    for (int i = 0; i < (int)quiz.size(); i++)
    {
        vector<string> caches = split(quiz[i]);
        
        int a = to_number(caches[0]);
        int b = to_number(caches[2]);
        int c = to_number(caches[4]);
        
        int sum;
        if (caches[1] == "-")
        {
            sum = a - b;
        }
        else
        {
            sum = a + b;
        }
        
        if (sum == c)
        {
            answer.push_back("O");
        }
        else
        {
            answer.push_back("X");
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> quiz(n);
    for (int i = 0; i < n; i++)
    {
        cin >> quiz[i];
    }

    vector<string> answer = solution(quiz);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}