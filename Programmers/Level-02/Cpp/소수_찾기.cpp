#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int N;
vector<bool> visited;
string Vector;
vector<int> result;
vector<char> number;

void DFS(int level, int count) {
    if(level == count) {
        string temp = "";
        for(int i=0;i<number.size();i++)
            temp += number[i];
        result.push_back(stoi(temp));
        return;
    }
    
    for(int i = 0; i < N; i++) {
        if(visited[i] == true) {
            continue;
        }
        visited[i] = true;
        number.push_back(Vector[i]);
        DFS(level + 1, count);
        number.pop_back();
        visited[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    N = numbers.length();
    visited = vector<bool>(numbers.length(),false);
    Vector = numbers;
    for(int i=1;i<=numbers.length();i++) {
        DFS(0,i);
    }
    sort(result.begin(),result.end());
    vector<bool> primeNumber(result.back() + 1,true);
    primeNumber[0] = primeNumber[1] = false;
    for(int i = 2; i <= result.back(); i++) {
        int mult = 2;
        while (i * mult <= result.back() && primeNumber[i] == true) {
			primeNumber[i * mult] = false; mult++;
		}
    }
    for(auto i : result) {
        if(primeNumber[i]) {
            answer++;
            primeNumber[i] = false;
        }
    }
    return answer;
}

int main()
{
    string s;
    cin >> s;

    int answer = solution(s);

    cout << answer;

    return 0;
}