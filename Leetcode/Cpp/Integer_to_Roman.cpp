#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>

using namespace std;

typedef pair<string, int> psi;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> keys = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
        vector<string> values = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };

        map<int, string> mp;
        vector<int> arr;
        for (int i = 0; i < keys.size(); i++) {
            mp.insert({ keys[i],values[i] });

            while (keys[i] <= num) {
                arr.push_back(keys[i]);
                num -= keys[i];
            }
        }

        string answer = "";
        for (auto& i: arr) {
            answer += mp[i];
        }

        return answer;
    }
};

int main() {
    int num;
    cin >> num;

    string answer = Solution().intToRoman(num);

    cout << answer;
}