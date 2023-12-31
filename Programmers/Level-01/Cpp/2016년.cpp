#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    // 2016년의 각 월의 전체 일 수를 저장하는 배열이다.
    int month[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    // 2016년 1월 1일은 금요일이므로, 요일들을 금요일이 처음으로 오게 저장한다.
    string day[7] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
    
    // day 배열의 index.
    int dayIdx = 0;
    // 2016년 전체의 요일을 저장하는 배열.
    vector<string> Vector[13];
    // 2016년 전체의 요일을 저장한다.
    for (int i = 0; i < 13; i++) {
        Vector[i] = vector<string>(month[i],"");
        for (int j = 0; j < Vector[i].size(); j++) {
            Vector[i][j] = day[dayIdx%7];
            dayIdx++;
        }
    }

    return Vector[a][b-1];
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << solution(a, b);
}