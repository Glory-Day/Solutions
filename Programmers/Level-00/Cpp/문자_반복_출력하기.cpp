#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    
    for (int i = 0; i < (int)my_string.size(); i++)
    {
        answer += string(n, my_string[i]);
    }
    
    return answer;
}

int main()
{
    string my_string;
    cin >> my_string;

    int n;
    cin >> n;

    string answer = solution(my_string, n);

    cout << answer;

    return 0;
}