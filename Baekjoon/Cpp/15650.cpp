#include <iostream>
#include <vector>

using namespace std;

bool visited[9];
vector<int> v;

void print() {
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] > v[i + 1]) {
            return;
        }
    }

    for (int& i: v) {
        cout << i << ' ';
    }
    cout << '\n';
}

void f(int size, int n, int m) {
    if (visited[m]) return;

    visited[m] = true;
    v.push_back(m);
    for (int i = 1; i <= size; i++) {
        if (!visited[i]) {
            f(size, n - 1, i);
        }
    }

    if (n == 1) {
        print();
    }

    visited[m] = false;
    v.pop_back();
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        f(n, m, i);
        visited[i] = true;
    }
}