#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int n, int s)
{
    vector<int> answer;

    if (s < n)
    {
        answer.push_back(-1);

        return answer;
    }

    int q = s / n;
    int r = s % n;

    for (int i = 0; i < n - r; i++)
    {
        answer.push_back(q);
    }

    for (int i = 0; i < r; i++)
    {
        answer.push_back(q + 1);
    }

    return answer;
}

int main()
{
    int n, s;
    cin >> n >> s;

    vector<int> answer = solution(n, s);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}