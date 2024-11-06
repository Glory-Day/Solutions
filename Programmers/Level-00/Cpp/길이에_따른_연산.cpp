#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 1;
    
    int l = (int)num_list.size();
    if (l >= 11)
    {
        answer = 0;
    }
    
    for (int i = 0; i < l; i++)
    {
        if (l < 11)
        {
            answer *= num_list[i];
        }
        else
        {
            answer += num_list[i];
        }
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

    int answer = solution(num_list);
    
    cout << answer;

    return 0;
}