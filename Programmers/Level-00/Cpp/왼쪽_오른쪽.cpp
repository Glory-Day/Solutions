#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> str_list) {
    vector<string> answer;
    
    auto a = find(str_list.begin(), str_list.end(), "l");
    auto b = find(str_list.begin(), str_list.end(), "r");
    
    int c = (a == str_list.end() ? (int)str_list.size() : a - str_list.begin());
    int d = (b == str_list.end() ? (int)str_list.size() : b - str_list.begin());
    
    if (c < d)
    {
        for (int i = 0; i < c; i++)
        {
            answer.push_back(str_list[i]);
        }
    }
    else if (c > d)
    {
        for (int i = (int)str_list.size() - 1; i > d; i--)
        {
            answer.push_back(str_list[i]);
        }
        
        reverse(answer.begin(), answer.end());
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

    vector<string> answer = solution(str_list);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}