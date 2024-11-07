#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    
    if (A != B)
    {
        for (int i = 0; i < (int)A.length(); i++)
        {
            A = A.back() + A;
            A.pop_back();
            answer++;
            
            if (A == B)
            {
                break;
            }
        }
        
        if (answer == (int)A.length())
        {
            answer = -1;
        }
    }
    
    return answer;
}

int main()
{
    string A, B;
    cin >> A >> B;

    int answer = solution(A, B);
    
    cout << answer;

    return 0;
}