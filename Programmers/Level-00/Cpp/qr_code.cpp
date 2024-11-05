#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int q, int r, string code) {
    string answer = "";
    
    for (int i = 0; i < (int)code.length(); i++)
    {
        if (i % q == r)
        {
            answer.push_back(code[i]);
        }
    }
    
    return answer;
}

int main()
{
    int q, r;
    cin >> q >> r;

    string code;
    cin >> code;

    string answer = solution(q, r, code);

    cout << answer;

    return 0;
}