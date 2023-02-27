#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int answer = n * m;
    if (n % 2 == 1 && m % 2 == 1) {
        answer--;
    }
    
    cout << answer;
}