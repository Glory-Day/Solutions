#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int start_num, int end_num) {
    vector<int> answer;
    
    for (int i = start_num; i <= end_num; i++)
    {
        answer.push_back(i);
    }
    
    return answer;
}

int main()
{
    int start_num, end_num;
    cin >> start_num >> end_num;

    vector<int> answer = solution(start_num, end_num);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}