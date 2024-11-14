#include <iostream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int count = 0;
    for(int i = 0; i <= 20; i++) {
        if(n & (1 << i)) count++;
    }
    while(true) {
        int temp = 0;
        n++;
        for(int i = 0; i <= 20; i++) {
            if(n & (1 << i)) temp++;
        }
        if(count == temp) {
            answer = n;
            break;
        }
    }
    return answer;
}

int main()
{
    int n;
    cin >> n;

    int answer = solution(n);

    cout << answer;

    return 0;
}