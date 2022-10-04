#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

pii nums[8001];

bool compare(pii& a, pii& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main() {
    int n;
    cin >> n;

    double sum = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
        nums[input + 4000].first++;
        nums[input + 4000].second = input;
        sum += input;
    }

    sort(nums, nums + 8001, compare);
    sort(v.begin(), v.end());

    double avg = sum / (double)v.size();
    int answer1 = (avg < 0) ? avg - 0.5 : avg + 0.5;
    int answer2 = v[v.size() / 2];
    int answer3 = (nums[0].first == nums[1].first) ? nums[1].second : nums[0].second;
    int answer4 = v.back() - v.front();

    cout << answer1 << '\n';
    cout << answer2 << '\n';
    cout << answer3 << '\n';
    cout << answer4;
}