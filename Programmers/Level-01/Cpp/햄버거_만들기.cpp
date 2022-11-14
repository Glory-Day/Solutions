#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;

    int sum = 0;
    vector<int> arr;
    for (int i = 0; i < ingredient.size(); i++) {
        sum = 0;
        arr.push_back(ingredient[i]);
        
        if (arr.size() >= 4) {
            if (arr[arr.size() - 1] == 1) {
                sum++;
            }

            if (arr[arr.size() - 2] == 3) {
                sum++;
            }

            if (arr[arr.size() - 3] == 2) {
                sum++;
            }

            if (arr[arr.size() - 4] == 1) {
                sum++;
            }
            
            if (sum == 4) {
                arr.pop_back();
                arr.pop_back();
                arr.pop_back();
                arr.pop_back();

                sum = 0;
                answer++;
            }
        }
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    vector<int> ingredient;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        ingredient.push_back(input);
    }

    int answer = solution(ingredient);

    cout << answer;
}