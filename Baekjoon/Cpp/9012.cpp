#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        bool check = true;
        int count = 0;
        for(char& j: s)
        {
            if (j == '(')
            {
                count++;
            }
            else
            {
                if (count == 0)
                {
                    check = false;
                    break;
                }
                else
                {
                    count--;
                }
            }
        }

        if (check && count == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}