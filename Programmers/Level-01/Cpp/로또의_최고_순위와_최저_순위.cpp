#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    // 정답 번호의 개수.
    int win_nums_count = win_nums.size();
    // lottos에서 0의 개수.
    int zero_count = 0;
    // lottos의 번호와 win_nums의 번호가 일치하는 횟수.
    int win_count = 0;

    // lottos에서 0의 개수를 세어 zero_count에 저장한다.
    for (int& lotto: lottos) {
        zero_count += ((lotto == 0) ? 1 : 0);
    }

    // lottos의 번호와 win_nums의 번호가 일치하는만큼 win_count에 1씩 증가시킨다.
    for(int i = 0; i < lottos.size(); i++) {
        auto iter = find(win_nums.begin(), win_nums.end(), lottos[i]);
        win_count += ((iter != win_nums.end()) ? 1 : 0);
    }

    // win_nums의 개수에 win_count를 뺀다.
    // lottos의 번호와 win_nums의 번호가 일치하는 번호는 0에 들어갈 수 없기 때문이다.
    win_nums_count -= win_count;

    // 최소로 win_nums와 일치하는 횟수.
    int min_win_count = win_count;
    // 최대로 win_nums와 일치하는 횟수.
    // zero_count가 win_nums_count보다 작거나 같으면, 모든 zero_count에 win_nums의 번호를 넣을 수 있다.
    // zero_count가 win_nums_count보다 크면, 모든 win_nums의 번호들이 들어가고 나머지 번호들이 0에 들어간다.
    int max_win_count = ((zero_count <= win_nums_count) ? zero_count : win_nums_count) + win_count;

    // rank를 반환하는 lambda식
    auto get_rank = [](int count) {
        return ((7 - count) < 6) ? (7 - count) : 6;
    };

    // answer를 저장하고 반환한다.
    vector<int> answer = { get_rank(max_win_count),get_rank(min_win_count) };
    return answer;
}

int main() {
    vector<int> lottos, win_nums;

    for(int i = 0; i < 6; i++) {
        int input;
        cin >> input;
        lottos.push_back(input);
    }

    for(int i = 0; i < 6; i++) {
        int input;
        cin >> input;
        win_nums.push_back(input);
    }

    vector<int> answer = solution(lottos, win_nums);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }

    return 0;
}