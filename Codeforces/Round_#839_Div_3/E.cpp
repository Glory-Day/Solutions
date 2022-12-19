#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;

int arr[500001];

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        int a = 0, b = 0, c = 0;
        for (int i = 1; i <= n; i++) {
            if(arr[i] != i) {
                a++;
            }
			
            if(arr[i] != (n - i + 1)) {
                b++;
            }

			if(arr[i] != i && arr[i] != (n - i + 1)) {
                c++;
            }
        }

        a -= c;
		b -= c;
		
        int mn = (a < b) ? a : b;
		a -= mn;
        b -= mn;

        string answer;
		if (a == 0 && b == 0) {
            answer = (c == 0) ? "First" : "Tie";
		}
		else if(a > 0)
		{
            answer = (a <= c) ? "Tie" : "Second";
		}
		else
		{
            answer = (b < c) ? "Tie" : "First";
		}

        cout << answer << '\n';
    }
}