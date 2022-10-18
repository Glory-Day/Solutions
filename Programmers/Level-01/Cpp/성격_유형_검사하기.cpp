#include <iostream>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";

    string temp[4] = { "RT","CF","JM","AN" };
    map<char, int> mp;
    for (int i = 0; i < 4; i++) {
        mp.insert({ temp[i][0],0 });
        mp.insert({ temp[i][1],0 });
    }

    for (int i = 0; i < survey.size(); i++) {
        switch (choices[i])
        {
            case 1:
                mp[survey[i][0]] += 3;
                break;
            case 2:
                mp[survey[i][0]] += 2;
                break;
            case 3:
                mp[survey[i][0]] += 1;
                break;
            case 5:
                mp[survey[i][1]] += 1;
                break;
            case 6:
                mp[survey[i][1]] += 2;
                break;
            case 7:
                mp[survey[i][1]] += 3;
                break;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (mp[temp[i][0]] < mp[temp[i][1]]) {
            answer.push_back(temp[i][1]);
        }
        else  {
            answer.push_back(temp[i][0]);
        }
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<string> survey;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        survey.push_back(input);
    }

    vector<int> choices;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        choices.push_back(input);
    }

    string answer = solution(survey, choices);

    cout << answer;
}