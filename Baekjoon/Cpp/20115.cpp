#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    double answer = v.back();
    for (int i = 0; i < n - 1; i++)
    {
        answer += (double)v[i] / 2;
    }

    cout << fixed;
    cout.precision(5);
    cout << answer;

    return 0;
}