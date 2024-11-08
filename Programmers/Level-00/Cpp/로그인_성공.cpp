#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    
    unordered_map<string, string> ump;
    for (int i = 0; i < (int)db.size(); i++)
    {
        ump[db[i][0]] = db[i][1];
    }
    
    if (ump.find(id_pw[0]) == ump.end())
    {
        answer = "fail";
    }
    else if (ump[id_pw[0]] != id_pw[1])
    {
        answer = "wrong pw";
    }
    else
    {
        answer = "login";
    }
    
    return answer;
}

int main()
{
    vector<string> id_pw(2);
    cin >> id_pw[0] >> id_pw[1];

    int n;
    cin >> n;

    vector<vector<string>> db(n, vector<string>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> db[i][0] >> db[i][1];
    }

    string answer = solution(id_pw, db);

    cout << answer;

    return 0;
}