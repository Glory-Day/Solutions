#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> strArr) {
    int answer = 0;
    
    vector<int> caches(31, 0);
    for (int i = 0; i < (int)strArr.size(); i++)
    {
        caches[(int)strArr[i].size()]++;
    }
    
    answer = *max_element(caches.begin(), caches.end());
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> strArr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> strArr[i];
    }

    int answer = solution(strArr);
    
    cout << answer;

    return 0;
}