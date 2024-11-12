#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0;i < (int)arr1.size(); i++) 
    {
        string bit1 = "";
        string bit2 = "";
        for (int j = 0; j < n; j++) 
        {
            bit1 += (arr1[i] % 2) ? '#' : ' ';
            
            arr1[i] /= 2;
        }
        
        reverse(bit1.begin(), bit1.end());
        
        for (int j = 0; j < n; j++)
        {
            bit2 += (arr2[i] % 2) ? '#' : ' ';
            
            arr2[i] /= 2;
        }
        
        reverse(bit2.begin(),bit2.end());
        
        for (int j = 0; j < n; j++) 
        {
            if (bit1[j] != bit2[j])
            {
                bit1[j] = '#';
            }
        }

        answer.push_back(bit1);
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

    vector<int> arr2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    vector<string> answer = solution(n, arr1, arr2);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}