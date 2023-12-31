#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    // 학생의 수만큼 배열을 초기화한다. 각 학생당 한 벌의 체육복은 가지고있다.
    // reserve에 있는 학생들은 여벌의 체육복이 있는 학생들이다. 그러므로 reserve에 있는 학생들은 체육복은 총 2개씩이다.
    // lost에 있는 학생들은 체육복을 도난당한 학생들이다. 이떄 reserve에 있는 학생도 포함된다.
    // 따라서, reserve의 학생들의 체육복의 개수를 먼저 설정해주고, lost의 핵생들의 체육복의 수를 저장해야한다.
    vector<int> Vector(n, 1);
    for (auto i: reserve) {
        Vector[i - 1]++;
    }
    for (auto i: lost) {
        Vector[i - 1]--;
    }

    // 비둘기집의 원리이다. reserve의 학생의 수가 lost의 학생 수보다 많으면 lost의 학생 전부 체육복을 빌려줄수 있다.
    // 반대로, reserve의 학생 수가 lost보다 적으면 reserve의 학생 수만큼만 체육복을 빌려줄 수 있다.
    for (int i = 0; i < Vector.size(); i++) {
        if (Vector[i] == 0) {
            if (i != 0 && Vector[i - 1] == 2) {
                Vector[i - 1]--;
                Vector[i]++;
            }
            else if (i != Vector.size() - 1 && Vector[i + 1] == 2) {
                Vector[i + 1]--; 
                Vector[i]--;
            }
        }
    }

    // 체육복의 개수가 1인 학생만 개수를 세어준다.
    for (auto i: Vector) {
        answer += (i != 0) ? 1 : 0;
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    int m;
    vector<int> lost, reserve;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        lost.push_back(input);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        reserve.push_back(input);
    }

    cout << solution(n, lost, reserve);
}