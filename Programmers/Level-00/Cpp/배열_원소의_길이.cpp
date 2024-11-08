#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer;
    
    for (int i = 0; i < (int)strlist.size(); i++)
    {
        answer.push_back((int)strlist[i].length());
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> strlist(n);
    for (int i = 0; i < n; i++)
    {
        cin >> strlist[i];
    }

    vector<int> answer = solution(strlist);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}