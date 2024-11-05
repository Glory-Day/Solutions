#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts) {
    string answer = "";
    
    for (int i = 0; i < (int)parts.size(); i++)
    {
        answer += my_strings[i].substr(parts[i][0], parts[i][1] - parts[i][0] + 1);
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> my_strings;
    for (int i = 0; i < n; i++)
    {
        cin >> my_strings[i];
    }

    int m;
    cin >> m;

    vector<vector<int>> parts(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> parts[i][0] >> parts[i][1];
    }

    string answer = solution(my_strings, parts);

    cout << answer;

    return 0;
}