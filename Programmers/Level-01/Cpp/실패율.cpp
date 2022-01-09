#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<double,int> PAIR;

// 배열을 내림차순으로 정렬하는 함수
// left와 right의 first가 같으면, second로 비교하여 오름차순으로 정렬한다.
bool compare(const PAIR& left, const PAIR& right) {
    if(left.first == right.first)
        return left.second < right.second;
    return left.first > right.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    // 실패율과 stage 번호를 저장하는 배열
    vector<PAIR> tuples;
    int length = stages.size();
    
    // N + 1은 stages를 전체 클리어한거기 때문에 실패율에 포함되지 않는다.
    // 따라서, 1 ~ N까지의 실패율만 고려하면 된다.
    for (int i = 1; i <= N; i++) {
        // 해당 stage의 개수를 센다.
        int stageCount = count(stages.begin(), stages.end(), i);
        // 해당 stage의 개수와 전체 stages의 개수를 나눈다.
        double percentage = ((stageCount == 0 || length == 0) ? 0 : (double)stageCount / (double)length);

        // 해당 stage의 실패율과 stage 번호를 같이 저장한다.
        tuples.push_back({ percentage,i });

        // 계산한 stage를 제외한 개수를 세기위해 제외한다.
        length -= stageCount;
    }

    // 실패율을 내림차순으로 정렬한다.
    sort(tuples.begin(), tuples.end(), compare);
    
    // 정렬된 stage의 번호만 answer에 저장한다.
    for(auto i: tuples) {
        answer.push_back(i.second);
    }
    
    return answer;
}

int main() {
    int n, length;
    vector<int> stages;
    cin >> n;

    cin >> length;
    for (int i = 0; i < length; i++) {
        int input;
        cin >> input;
        stages.push_back(input);
    }

    vector<int> answer = solution(n, stages);

    for (int& i: answer) {
        cout << i << ' ';
    }
}