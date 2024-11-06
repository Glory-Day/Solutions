#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    int answer = 0;
    
    int len1 = (int)arr1.size();
    int len2 = (int)arr2.size();
    if (len1 < len2)
    {
        answer = -1;
    }
    else if (len1 > len2)
    {
        answer = 1;
    }
    else 
    {
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < len1; i++)
        {
            sum1 += arr1[i];
            sum2 += arr2[i];
        }
        
        if (sum1 < sum2)
        {
            answer = -1;
        }
        else if (sum1 > sum2)
        {
            answer = 1;
        }
        else
        {
            answer = 0;
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    vector<int> arr2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    int answer = solution(arr1, arr2);
    
    cout << answer;

    return 0;
}