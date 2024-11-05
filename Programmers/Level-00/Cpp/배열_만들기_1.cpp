#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int k) {
    vector<int> answer;
    
    for (int i = k; i <= n; i += k)
    {
        answer.push_back(i);
    }
    
    return answer;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> answer = solution(n, k);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}