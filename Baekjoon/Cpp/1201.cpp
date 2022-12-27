#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; 
    cin >> n >> m >> k;

    if (m + k - 1 <= n && n <= m * k) {
		vector<int> arr;
		for (int i = 1; i <= n; i++) {
            arr.push_back(i);
        }

		vector<int> indexes;
		indexes.push_back(0);
		indexes.push_back(k);

		m -= 1;
        n -= k;

		int a = m == 0 ? 1 : n / m;
		int b = n % m == 0 ? 0 : n % m;
		for (int i = 0; i < m; i++) {
			indexes.push_back(indexes.back() + a + (b > 0 ? 1 : 0));
			if (b > 0) {
				b -= 1;
			}
		}

		for (int i = 0; i < indexes.size() - 1; i++) {
			reverse(arr.begin() + indexes[i], arr.begin() + indexes[i + 1]);
		}

		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << ' ';
		}
	}
	else {
		cout << -1;
	}
}