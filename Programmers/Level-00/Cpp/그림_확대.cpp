#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    
    for (int i = 0; i < (int)picture.size(); i++)
    {
        string cache = "";
        for (int j = 0; j < (int)picture[i].length(); j++)
        {
            cache += string(k, picture[i][j]);
        }
        
        for (int j = 0; j < k; j++)
        {
            answer.push_back(cache);
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> picture(n);
    for (int i = 0; i < n; i++)
    {
        cin >> picture[i];
    }

    int k;
    cin >> k;

    vector<string> answer = solution(picture, k);
    
    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}