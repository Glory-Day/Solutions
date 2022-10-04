#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    // board의 길이
    int length = board.size();
    // 인향들을 담을 바구니
    vector<int> bucket;
    // board에 쌓인 인형들을 담은 변수
    vector<deque<int>> Vector(length + 1,deque<int>());

    // boaed에 저장된 인형들을 row형태에서 column형태로 변환해서 저장한다.
    for(int i = 1; i <= length; i++) {
        for(int j = 0; j < length; j++) {
            if(board[j][i - 1] != 0) {
                Vector[i].push_back(board[j][i - 1]);
            }
        }
    }

    // moves에 저장된 column 번호순으로 인형을 bucket에 stack형태로 저장한다.
    for(auto i: moves) {
        // bucket이 비었거나, bucket의 맨 뒤와 선택된 인형의 종류가 같지 않으면, bucket에 넣는다.
        if(bucket.empty() || bucket.back() != Vector[i].front()) {
            if(!Vector[i].empty()) {
                bucket.push_back(Vector[i].front());
                Vector[i].pop_front();
            }
        }
        // bucket이 비지않고, bucket의 맨 뒤와 선택된 인형의 종류가 같으면, bucket의 맨뒤의 인형을 제거한다.
        // answer를 2증가시킨다.
        else {
            answer += 2;
            Vector[i].pop_front();
            bucket.pop_back();
        }
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> board;
    vector<int> moves;

    for (int i = 0; i < n; i++) {
        vector<int> column;
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            column.push_back(input);
        }
        board.push_back(column);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        moves.push_back(input);
    }

    cout << solution(board, moves);
}