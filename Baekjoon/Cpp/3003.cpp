#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr = { 1, 1, 2, 2, 2, 8 };
    for (int i = 0; i < 6; i++) {
        int input;
        cin >> input;
        arr[i] -= input;
    }
    
    for (int& i: arr) {
        cout << i << ' ';
    }
}