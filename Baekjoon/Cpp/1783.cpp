#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int answer;
    switch (n)
    {
        case 1: 
            answer = 1; 
            break;
        case 2: 
            answer = min(4, (m + 1) / 2);
            break;
        default:
            if (m <= 6) answer = min(4, m);
            else answer = m - 2;
            break;
    }

    cout << answer;
}