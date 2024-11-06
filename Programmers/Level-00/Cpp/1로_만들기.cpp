#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    for (int i = 0; i < (int)num_list.size(); i++)
    {
        while (num_list[i] != 1)
        {
            if (num_list[i] % 2 == 0)
            {
                num_list[i] /= 2;
            }
            else
            {
                num_list[i] = (num_list[i] - 1) / 2;
            }
            
            answer++;
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