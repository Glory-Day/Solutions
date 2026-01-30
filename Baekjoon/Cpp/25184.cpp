#include <iostream>
#include <vector>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main()
{
    FAST_IO;

    int n;
    cin >> n;

    vector<int> answer;
    answer.reserve(n);

    for (int i = (n / 2); i >= 1; i--)
    {
        answer.push_back(i);
        answer.push_back(i + (n / 2));
    }

    if (n % 2 == 1)
    {
        answer.push_back(n);
    }

    for (int i = 0; i < n; i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}