#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    while (n != 1)
    {
        answer.push_back(n);
        
        n = (n % 2 == 0 ? n / 2 : 3 * n + 1);
    }
    
    answer.push_back(1);
    
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