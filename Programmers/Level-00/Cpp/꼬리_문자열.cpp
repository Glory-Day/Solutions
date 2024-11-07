#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> str_list, string ex) {
    string answer = "";
    
    for (int i = 0; i < (int)str_list.size(); i++)
    {
        auto iter = str_list[i].find(ex);
        if (iter == string::npos)
        {
            answer += str_list[i];
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> str_list(n);
    for (int i = 0; i < n; i++)
    {
        cin >> str_list[i];
    }

    string ex;
    cin >> ex;

    string answer = solution(str_list, ex);

    cout << answer;

    return 0;
}