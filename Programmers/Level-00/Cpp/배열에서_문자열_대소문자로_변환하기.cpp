#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    
    for (int i = 0; i < (int)strArr.size(); i++)
    {
        for (int j = 0; j < (int)strArr[i].length(); j++)
        {
            strArr[i][j] = (i % 2 == 1 ? toupper(strArr[i][j]) : tolower(strArr[i][j]));
        }
    }
    
    answer = strArr;
    
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