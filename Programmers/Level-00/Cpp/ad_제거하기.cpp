#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    
    for (int i = 0; i < (int)strArr.size(); i++)
    {
        if (strArr[i].find("ad") == string::npos)
        {
            answer.push_back(strArr[i]);
        }
    }
    
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

    vector<string> answer = solution(strArr);
    
    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}