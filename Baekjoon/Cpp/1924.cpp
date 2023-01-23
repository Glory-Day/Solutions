#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    vector<int> arr(13, 0);
    arr[1] = arr[3] = arr[5] = arr[7] = arr[8] = arr[10] = arr[12] = 31;
    arr[4] = arr[6] = arr[9] = arr[11] = 30;
    arr[2] = 28;
    
    string answer[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };

    int tmp = 0;
    for (int i = 1; i <= 12; i++) {
        for (int j = 1; j <= arr[i]; j++) {
            if (i == a && j == b) {
                cout << answer[tmp];
                return 0;
            }

            tmp = (tmp + 1) % 7;
        }
    }
}