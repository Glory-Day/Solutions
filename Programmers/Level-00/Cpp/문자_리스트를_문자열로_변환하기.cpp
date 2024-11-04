#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> arr) {
    string answer = "";
    
    for (int i = 0; i < (int)arr.size(); i++)
    {
        answer.push_back(arr[i][0]);
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    string answer = solution(arr);

    cout << answer;

    return 0;
}