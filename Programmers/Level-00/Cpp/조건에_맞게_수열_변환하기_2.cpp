#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    
    int count = 1;
    while (0 < count)
    {
        count = 0;
        
        for (int i = 0; i < (int)arr.size(); i++)
        {
            if (arr[i] < 50 && arr[i] % 2 == 1)
            {
                arr[i] = arr[i] * 2 + 1;
                count++;
            }
            else if (arr[i] >= 50 && arr[i] % 2 == 0)
            {
                arr[i] /= 2;
                count++;
            }
        }
        
        answer++;
    }
    
    answer--;
    
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

    int answer = solution(arr);
    
    cout << answer;

    return 0;
}