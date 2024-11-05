#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = -1;
    
    for (int i = 0; i < (int)num_list.size(); i++)
    {
        if (num_list[i] < 0)
        {
            answer = i;
            
            break;
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