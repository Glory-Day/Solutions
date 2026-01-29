#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (n % 2 == 1)
    {
        cout << "NO";

        return 0;
    }

    string temp = "PAUL";
    int index = 0;
    for (int i = 0; i < n && index < 4; i++)
    {
        if (s[i] == temp[index] && (i % 2) == (index % 2))
        {
            index++;
        }
    }

    string answer = (index == 4 ? "YES" : "NO");

    cout << answer;

    return 0;
}