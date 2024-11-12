#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

vector<int> solution(LL n) {
    vector<int> answer;
    
    string number = to_string(n);
    for (int i = (int)number.size() - 1; i >= 0; i--)
    {
        answer.push_back(number[i] - '0');
    }
    
    return answer;
}

int main()
{
    long long n;
    cin >> n;

    vector<int> answer = solution(n);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i];
    }

    return 0;
}