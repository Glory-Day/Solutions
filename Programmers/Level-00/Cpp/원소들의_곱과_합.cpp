#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    int a = 1;
    int b = 0;
    for (int i = 0; i < (int)num_list.size(); i++)
    {
        a *= num_list[i];
        b += num_list[i];
    }
    
    answer = (int)(a < b * b);
    
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