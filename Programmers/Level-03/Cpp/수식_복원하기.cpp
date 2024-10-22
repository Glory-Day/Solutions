#include <iostream>
#include <cmath>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split(string input, const string delimiter)
{
    vector<string> results;
    
    int position = 0;
    while ((size_t)(position = input.find(delimiter)) != string::npos)
    {
        results.push_back(input.substr(0, position));
        
        input.erase(0, position + delimiter.length());
    }
    
    results.push_back(input);
    
    return results;
}

const string combine(const vector<string>& v)
{
    return v[0] + " " + v[1] + " " + v[2] + " " + v[3] + " " + v[4];
}

const string add(string a, string b, const int n)
{
    string result = "";
    
    int mx = (int)max(a.size(), b.size());
    for (int i = 0; i < mx - (int)a.size(); i++)
    {
        a = '0' + a;
    }
    
    for (int i = 0; i < mx - (int)b.size(); i++)
    {
        b = '0' + b;
    }
    
    int carry = 0;
    for (int i = mx - 1; i >= 0; i--)
    {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        
        if (sum >= n)
        {
            sum -= n;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        
        result += (sum + '0');
    }
    
    if (carry)
    {
        result += (carry + '0');
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

const string substract(string a, string b, const int n)
{
    string result = "";
    
    int mx = (int)max(a.size(), b.size());
    for (int i = 0; i < mx - (int)a.size(); i++)
    {
        a = '0' + a;
    }
    
    for (int i = 0; i < mx - (int)b.size(); i++)
    {
        b = '0' + b;
    }
    
    int carry = 0;
    for (int i = mx - 1; i >= 0; i--)
    {
        int sum = (a[i] - '0') - (b[i] - '0') - carry;
        
        if (sum < 0)
        {
            sum += n;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        
        result += (sum + '0');
    }
    
    while (result.empty() == false)
    {
        if (result.back() != '0')
        {
            break;
        }
        
        result.pop_back();
    }
    
    reverse(result.begin(), result.end());
    
    return result.empty() ? "0" : result;
}

vector<string> solution(vector<string> expressions)
{
    vector<string> answer;
    
    int mx = 2;
    vector<vector<string>> v;
    vector<vector<string>> w;
    for (int i = 0; i < (int)expressions.size(); i++)
    {
        for (int j = 0; j < (int)expressions[i].length(); j++)
        {
            if ('0' <= expressions[i][j] && expressions[i][j] <= '9')
            {
                mx = max(mx, (expressions[i][j] - '0') + 1);
            }
        }
        
        if (expressions[i].back() != 'X')
        {
            v.push_back(split(expressions[i], " "));
        }
        else
        {
            w.push_back(split(expressions[i], " "));
        }
    }
    
    set<int> s;
    for (int i = mx; i < 10; i++)
    {
        s.insert(i);
    }
    
    for (int i = mx; i < 10; i++)
    {
        for (const auto& j: v)
        {
            bool check;
            switch(j[1][0])
            {
                case '+':
                    check = add(j[0], j[2], i) != j[4];
                    break;
                case '-':
                    check = substract(j[0], j[2], i) != j[4];
                    break;
            }

            if (check && s.find(i) != s.end())
            {
                s.erase(i);
            }
        }
    }
    
    set<string> cache;
    for (auto& i: w)
    {
        for (auto it = s.begin(); it != s.end(); it++)
        {
            switch(i[1][0])
            {
                case '+':
                    cache.insert(add(i[0], i[2], *it));
                    break;
                case '-':
                    cache.insert(substract(i[0], i[2], *it));
                    break;
            }
        }
        
        i[4] = ((int)cache.size() > 1 ? "?" : *cache.begin());
        
        answer.push_back(combine(i));
        
        cache.clear();
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> expressions;
    for (int i = 0; i < n; i++)
    {
        vector<string> expression(5);
        cin >> expression[0] >> expression[1] >> expression[2] >> expression[3] >> expression[4];

        expressions.push_back(combine(expression));
    }

    vector<string> answer = solution(expressions);

    for (const auto& i: answer)
    {
        cout << i << '\n';
    }
}