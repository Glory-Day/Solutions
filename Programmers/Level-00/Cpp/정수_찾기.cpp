#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> num_list, int n) {
    int answer = 0;
    
    answer = (int)(find(num_list.begin(), num_list.end(), n) != num_list.end());
    
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

    int answer = solution(num_list, n);

    cout << answer;

    return 0;
}