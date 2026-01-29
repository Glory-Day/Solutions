#include <iostream>
#include <string>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main()
{
    FAST_IO;

    int n;
    cin >> n;

    string s;
    cin >> s;

    string answer;
    answer.reserve(n * (size_t)s.size());

    while (n--)
    {
        answer += s;
    }

    cout << answer;

    return 0;
}