#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;

typedef pair<int,int> PAIR;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    // 키패드의 버튼의 좌표를 저장하는 변수.
    PAIR keyButton[13];
    
    int index = 1;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            // 번호 '1 ~ 9'에 해당하는 죄표를 저장한다.
            keyButton[index++] = { i,j };
        }
    }

    // '*', 0, '#'에 해당하는 죄표를 저장한다.
    keyButton[11] = { 3,0 };
    keyButton[0] = { 3,1 };
    keyButton[12] = { 3,2 };
    
    // 현재 왼쪽, 오른쪽 엄지손가락의 위치를 저장하는 변수를 생성하고 초기화한다.
    int currentLeft = 11;
    int currentRight = 12;

    for(auto i: numbers) {
        switch(i) {
            // 1, 4, 7을 입력할 떄는 왼쪽 엄지손자락을 사용한다.
            case 1:
            case 4:
            case 7:
                currentLeft = i;
                answer += 'L';
                break;
            // 3, 6, 9을 입력할 떄는 오른쪽 엄지손자락을 사용한다.
            case 3:
            case 6:
            case 9: 
                currentRight = i;
                answer += 'R';
                break;
            // 2, 5, 8, 0을 입력할 때는 두 엄지손가락의 현재 키패드의 위치에서 더 가까운 엄지손가락을 사용한다.
            case 2:
            case 5:
            case 8:
            case 0:
                // 왼쪽 엄지손가락과 오른쪽 엄지손가락의 거리를 비교하기 위해 거리를 구한다.
                // Manhattan Distance를 이용해 구한다.
                // |x1 - x2| + |y1 - y2|
                int left = abs(keyButton[i].first - keyButton[currentLeft].first) +
                    abs(keyButton[i].second - keyButton[currentLeft].second);
                int right = abs(keyButton[i].first - keyButton[currentRight].first) +
                    abs(keyButton[i].second - keyButton[currentRight].second);
                
                // 거리를 비교해서 가장 가까운 엄지손가락을 사용해 입력한다.
                if(left < right) {
                    currentLeft = i;
                    answer += 'L';
                }
                else if(left > right) {
                    currentRight = i;
                    answer += 'R';
                }
                // 만약 두 엄지손가락의 거리가 같다면, 오른손잡이는 오른손 엄지손가락, 왼손잡이는 왼손 엄지손가락을 사용한다.
                else {
                    if(hand == "left") {
                        currentLeft = i;
                        answer += 'L';
                    }
                    else {
                        currentRight = i;
                        answer += 'R';
                    }
                }
                break;
        }
    }
    return answer;
}

int main() {
    int length = 0;
    vector<int> numbers;
    string hand = "";

    cin >> length;
    for (int i = 0; i < length; i++) {
        int input;
        cin >> input;
        numbers.push_back(input);
    }

    cin >> hand;

    cout << solution(numbers, hand);
}