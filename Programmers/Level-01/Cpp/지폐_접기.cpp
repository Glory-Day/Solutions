#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    while (true)
    {
        int a = max(bill[0], bill[1]);
        int b = min(bill[0], bill[1]);
        int c = max(wallet[0], wallet[1]);
        int d = min(wallet[0], wallet[1]);
        if (a <= c && b <= d)
        {
            break;
        }
        
        if (bill[0] > bill[1])
        {
            bill[0] /= 2;
        }
        else
        {
            bill[1] /= 2;
        }
        
        answer++;
    }
    
    return answer;
}

int main() {
    vector<int> wallet(2);
    for(int i = 0; i < 2; i++) 
    {
        cin >> wallet[i];   
    }

    vector<int> bill(2);
    for(int i = 0; i < 2; i++) 
    {
        cin >> bill[i];    
    }

    int answer = solution(wallet, bill);

    cout << answer;

    return 0;
}