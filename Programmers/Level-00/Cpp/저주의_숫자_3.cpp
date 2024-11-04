#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    for (int i = 0; i < n; i++)
    {
        while (answer % 3 == 0 || to_string(answer).find("3") != string::npos)
        {
            answer++;
        }
        
        answer++;
    }

    answer--;
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    int answer = solution(n);

    cout << answer;
}