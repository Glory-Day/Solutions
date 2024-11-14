#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> Vector;
    string temp = "";
    for(auto i : s) {
        if(i == ' ') {
            Vector.push_back(stoi(temp));
            temp = "";
        }
        else {
            temp += i;
        }
    }
    Vector.push_back(stoi(temp));
    for(auto i : Vector) {
        cout << i << ' ';
    }
    sort(Vector.begin(),Vector.end());
    return to_string(Vector.front()) + " " + to_string(Vector.back());
}

int main()
{
    string s;
    cin >> s;

    string answer = solution(s);

    cout << answer;

    return 0;
}