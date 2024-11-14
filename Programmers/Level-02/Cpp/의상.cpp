#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> map;
    for(auto i : clothes) {
        map[i[1]]++;
    }
    for(auto iter = map.begin(); iter != map.end(); iter++) {
        answer *= (iter->second + 1);
    }
    return answer - 1;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<string>> clothes(n, vector<string>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> clothes[i][0] >> clothes[i][1];
    }

    int answer = solution(clothes);

    cout << answer;

    return 0;
}