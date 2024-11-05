#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = "";
    
    for (int i = 0; i < (int)queries.size(); i++)
    {
        reverse(my_string.begin() + queries[i][0], my_string.begin() + queries[i][1] + 1);
    }
    
    answer = my_string;
    
    return answer;
}

int main()
{
    string my_string;
    cin >> my_string;

    int n;
    cin >> n;

    vector<vector<int>> queries(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }

    string answer = solution(my_string, queries);

    cout << answer;

    return 0;
}