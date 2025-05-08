#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

int solution(string s)
{
    int answer = 0;

    int caches[3] = { 0,0,0 };
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '(' || s[i] == ')')
        {
            caches[0]++;
        }
        else if (s[i] == '{' || s[i] == '}')
        {
            caches[1]++;
        }
        else if (s[i] == '[' || s[i] == ']')
        {
            caches[2]++;
        }
    }

    int cnt = 0;
    for (int i = 0; i < 3; i++)
    {
        if (caches[i] % 2 == 1)
        {
            cnt++;
        }
    }

    if (cnt == 0)
    {
        int n = (int)s.size();

        deque<char> dq;
        for (int i = 0; i < n; i++)
        {
            dq.push_back(s[i]);
        }

        for (int i = 0; i < n; i++)
        {
            string temp = "";
            for (int j = 0; j < n; j++)
            {
                temp.push_back(dq[j]);
            }

            stack<char> stk;
            while (temp.empty() == false)
            {
                if (temp.back() == '(')
                {
                    if (stk.empty())
                    {
                        break;
                    }
                    else if (stk.top() == ')')
                    {
                        stk.pop();
                    }
                }
                else if (temp.back() == '{')
                {
                    if (stk.empty())
                    {
                        break;
                    }
                    else if (stk.top() == '}')
                    {
                        stk.pop();
                    }
                }
                else if (temp.back() == '[')
                {
                    if (stk.empty())
                    {
                        break;
                    }
                    else if (stk.top() == ']')
                    {
                        stk.pop();
                    }
                }
                else
                {
                    stk.push(temp.back());
                }

                temp.pop_back();
            }

            if (temp.empty() && stk.empty())
            {
                answer++;
            }

            dq.push_back(dq.front());
            dq.pop_front();
        }
    }

    return answer;
}

int main()
{
    string s;
    cin >> s;

    int answer = solution(s);

    cout << answer;

    return 0;
}