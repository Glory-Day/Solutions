#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> answer;
    
    for (int i = 0; i < n; i++)
    {
        answer.push_back(num_list[i]);
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> num_list(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num_list[i];
    }

    cin >> n;

    vector<int> answer = solution(num_list, n);
    
    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}