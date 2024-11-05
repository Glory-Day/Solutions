#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
    string answer = "";
    
    for (int i = 0; i < (int)numLog.size() - 1; i++)
    {
        switch (numLog[i] - numLog[i + 1])
        {
            case -1:
                answer.push_back('w');
                
                break;
            case 1:
                answer.push_back('s');
                
                break;
            case -10:
                answer.push_back('d');
                
                break;
            case 10:
                answer.push_back('a');
                
                break;
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> num_list(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num_list[i];
    }

    string answer = solution(num_list);

    cout << answer;

    return 0;
}