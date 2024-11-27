#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int count = 0;
        stack<char> st;
        for (int i = 0; i < (int)s.length(); i++)
        {
            switch (s[i])
            {
                case ')':
                {
                    if (st.empty() == false && st.top() == '(')
                    {
                        st.pop();
                    }

                    count--;

                    break;
                }
                case '}':
                {
                    if (st.empty() == false && st.top() == '{')
                    {
                        st.pop();
                    }

                    count--;

                    break;
                }
                case ']':
                {
                    if (st.empty() == false && st.top() == '[')
                    {
                        st.pop();
                    }

                    count--;

                    break;
                }
                default:
                {
                    st.push(s[i]);

                    count++;

                    break;
                }
            }
        }

        return st.empty() && count == 0;
    }
};

int main()
{
    string s;
    cin >> s;

    bool answer = Solution().isValid(s);

    cout << answer;
}