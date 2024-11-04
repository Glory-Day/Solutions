#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int k) {
    string answer = "";
    
    for (int i = 0; i < k; i++)
    {
        answer.append(my_string);
    }
    
    return answer;
}

int main()
{
    string my_string;
    cin >> my_string;

    int k;
    cin >> k;

    string answer = solution(my_string, k);

    cout << answer;

    return 0;
}