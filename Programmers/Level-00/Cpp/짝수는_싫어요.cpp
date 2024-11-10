#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    for (int i = 1; i <= n; i += 2)
    {
        answer.push_back(i);
    }
    
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