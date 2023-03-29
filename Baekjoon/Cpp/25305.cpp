#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    
    sort(arr.begin(), arr.end(), greater<int>());
    
    cout << arr[m - 1];
}