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
    v.push_back(m);

    if (n == 1) {
        print();
        v.pop_back();
        return;
    }

    for (int i = 1; i <= size; i++) {
        f(size, n - 1, i);
    }

    v.pop_back();
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        f(n, m, i);
    }
}