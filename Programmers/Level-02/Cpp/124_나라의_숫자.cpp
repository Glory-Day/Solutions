#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n > 0){
        int share = n / 3;
        int remainder = n % 3;
        
        if(remainder == 0) {
            share--;
            remainder = 3;
        }
        
        switch(remainder) {
            case 1:
                answer += '1';
                break;
            case 2:
                answer += '2';
                break;
            case 3:
                answer += '4';
                break;
        }
        
        n = share;
    }
    
    reverse(answer.begin(),answer.end());
    
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