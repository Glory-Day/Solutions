#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    
    auto it = find(seoul.begin(), seoul.end(), "Kim");
    answer = "김서방은 " + to_string(it - seoul.begin()) + "에 있다";
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> seoul(n);
    for (int i = 0; i < n; i++)
    {
        cin >> seoul[i];
    }

    string answer = solution(seoul);

    cout << answer;

    return 0;
}