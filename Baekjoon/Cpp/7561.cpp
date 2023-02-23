#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

#define FastInput cin.tie(nullptr)->sync_with_stdio(false);
#define FastOutput cout.tie(nullptr)->sync_with_stdio(false);

using namespace std;

int det(const vector<vector<int>>& u) {
    const int a = u[0][0] * (u[1][1] * u[2][2] - u[2][1] * u[1][2]);
    const int b = u[1][0] * (u[2][1] * u[0][2] - u[0][1] * u[2][2]);
    const int c = u[2][0] * (u[0][1] * u[1][2] - u[1][1] * u[0][2]);
    return a + b + c;
}

string convert(double a) {
    if (-0.0005 < a && a < 0.0005) {
        return "0.000";
    }
    
    if (a < 0) {
        return "-" + convert(-a);
    }

    stringstream outstream;
    outstream << fixed << setprecision(3) << a;
    return outstream.str();
}

int main() {
    FastInput;
    FastOutput;

    int t;
    cin >> t;

    while (t--) {
        vector<vector<int>> u(3, vector<int>(4)), v(3, vector<int>(3));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> u[i][j];
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                v[i][j] = u[i][j];
            }
        }

        int d = det(v);
        int answer[3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    v[j][k] = u[j][k];
                }
            }

            for (int j = 0; j < 3; j++) {
                v[j][i] = u[j][3];
            }

            answer[i] = det(v);
        }

        for (int i = 0; i < 3; i++) {
            cout << answer[i] << ' ';
        }
        cout << d << '\n';

        if (d) {
            cout << "Unique solution: ";
            cout << convert(1. * answer[0] / d) << ' ';
            cout << convert(1. * answer[1] / d) << ' ';
            cout << convert(1. * answer[2] / d) << '\n';
        }
        else {
            cout << "No unique solution" << '\n';
        }
        cout << '\n';
    }
}