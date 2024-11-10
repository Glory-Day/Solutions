#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money) {
    vector<int> answer(2);
    answer[0] = money / 5500;
    answer[1] = money % 5500;
    
    return answer;
}

int main()
{
    int money;
    cin >> money;

    vector<int> answer = solution(money);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}