#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    for (int i = 0, index = -1; i < (int)number.length() - k; i++)
    {
        char MAX = 0;
        for (int j = index + 1; j <= k + i; j++)
        {
            if (MAX < number[j])
            {
                index = j;
                MAX = number[j];
            }
        }
    
        answer += MAX;
    }
    
    return answer;
}

int main()
{
    string number;
    cin >> number;

    int k;
    cin >> k;

    string answer = solution(number, k);

    cout << answer;

    return 0;
}