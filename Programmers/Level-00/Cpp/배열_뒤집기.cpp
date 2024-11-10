#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    reverse(num_list.begin(), num_list.end());
    
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