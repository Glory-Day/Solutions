#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    while (cin >> a >> b)
    {
        while (b.empty() == false)
        {
            if (a.back() == b.back())
            {
                a.pop_back();
            }

            b.pop_back();
        }

        string answer = "No";
        if (a.empty() && b.empty())
        {
            answer = "Yes";
        }

        cout << answer << '\n';
    }

    return 0;
}