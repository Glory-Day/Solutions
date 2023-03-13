#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    map<string, double> mp = {
        { "A+",4.5 },
        { "A0",4.0 },
        { "B+",3.5 },
        { "B0",3.0 },
        { "C+",2.5 },
        { "C0",2.0 },
        { "D+",1.5 },
        { "D0",1.0 },
        { "F",0.0 }
    };

    double tmp1 = 0;
    double tmp2 = 0;
    for (int i = 0; i < 20; i++) {
        string a;
        double b;
        string c;

        cin >> a >> b >> c;

        if (c != "P") {
            tmp1 += (b * mp[c]);
            tmp2 += b;
        }
    }

    double answer = tmp1 / tmp2;

    cout << fixed;
    cout.precision(6);
    
    cout << answer;
}