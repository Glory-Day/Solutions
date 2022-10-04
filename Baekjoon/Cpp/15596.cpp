#include <iostream>
#include <vector>

using namespace std;

long long sum(vector<int> &a) {
    long long answer = 0;
    for (int& i: a) {
        answer += i;
    }

    return answer;
}