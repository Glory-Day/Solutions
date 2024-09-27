#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> sums;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sums.push_back(v[i] + v[j]);
        }
    }

    sort(sums.begin(), sums.end());

    int answer = INT_MIN;
    for (int i = 0; i < n; i++) 
    {
        for (int j = i; j < n; j++)
        {
            if (binary_search(sums.begin(), sums.end(), v[j] - v[i]))
            {
                answer = max(answer, v[j]);
            }
        }
    }

    cout << answer;
}