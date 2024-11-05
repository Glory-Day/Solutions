#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr, int idx) {
    int answer = -1;
    
    for (int i = idx; i < (int)arr.size(); i++)
    {
        if (arr[i] == 1)
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

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int idx;
    cin >> idx;

    int answer = solution(arr, idx);

    cout << answer;

    return 0;
}