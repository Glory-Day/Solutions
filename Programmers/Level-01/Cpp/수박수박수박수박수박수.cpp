#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    string A = "수";
    string B = "박";
    for (int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            answer += A;
        }
        else
        {
            answer += B;
        }
    }

    return answer;
}

int main()
{
    int n;
    cin >> n;

    string answer = solution(n);

    cout << answer;

    return 0;
}