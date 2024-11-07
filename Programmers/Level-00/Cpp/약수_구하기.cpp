#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    for (int i = 1; i * i <= n; i++)
    {
        if (i * i == n)
        {
            answer.push_back(i);
        }
        else if (n % i == 0)
        {
            answer.push_back(i);
            answer.push_back(n / i);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> answer = solution(n);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}