#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int,int> PAIR;

// 배열을 오름차순으로 정렬하는 함수.
// left와 right의 first가 같으면, second로 비교하여 내림차순으로 정렬한다.
bool compare(const PAIR& left, const PAIR& right) {
    if(left.second == right.second) {
        return left.first < right.first;
    }
    return left.second > right.second;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    // answers의 숫자들과 일치하는지 확인하는 pattern 배열들이다.
    vector<int> Vector[3];
    Vector[0] = {1, 2, 3, 4, 5};
    Vector[1] = {2, 1, 2, 3, 2, 4, 2, 5};
    Vector[2] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    // pattern 배열들중에서 어떤 pattern이 answers의 숫자들과 가장 많이 일치하는지 저장하는 배열.
    vector<PAIR> result = {{1, 0}, {2, 0}, {3, 0}};
    for(int i = 0; i < answers.size(); ++i)
    {
        if(Vector[0][i % 5] == answers[i]) ++result[0].second;
        if(Vector[1][i % 8] == answers[i]) ++result[1].second;
        if(Vector[2][i % 10] == answers[i]) ++result[2].second;
    }
    
    // pattern 배열들중에서 가장 많이 answers와 일치한 횟수를 저장한다.
    int MAX = max({result[0].second, result[1].second, result[2].second});
    // 가장 많이 일치한 pattern 배열의 index를 저장한다.
    for(auto i: result) {
        if(MAX == i.second) {
            answer.push_back(i.first);
        }
    }
    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<int> answers;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        answers.push_back(input);
    }

    vector<int> answer = solution(answers);

    for (int& i: answer) {
        cout << i << ' ';
    }
}