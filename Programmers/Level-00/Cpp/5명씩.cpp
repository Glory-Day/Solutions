#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> names) {
    vector<string> answer;
    
    for (int i = 0; i < (int)names.size(); i += 5)
    {
        answer.push_back(names[i]);
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> names(n);
    for (int i = 0; i < n; i++)
    {
        cin >> names[i];
    }

    vector<string> answer = solution(names);
    
    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}