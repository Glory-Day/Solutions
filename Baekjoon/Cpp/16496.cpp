#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const bool compare(const string& a, const string& b)
{
    return a + b > b + a;
}

int main()
{
    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += (int)(v[i] == "0");
    }

    string answer;
    if (count == n)
    {
        answer = "0";
    }
    else
    {
        sort(v.begin(), v.end(), compare);

        for (int i = 0; i < n; i++)
        {
            answer += v[i];
        }
    }

    cout << answer;

    return 0;
}