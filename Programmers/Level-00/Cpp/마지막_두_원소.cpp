#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    int l = (int)num_list.size();
    if (num_list[l - 1] > num_list[l - 2])
    {
        num_list.push_back(num_list[l - 1] - num_list[l - 2]);
    }
    else
    {
        num_list.push_back(num_list[l - 1] * 2);
    }
    
    answer = num_list;
    
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

    vector<int> answer = solution(num_list);
    
    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}