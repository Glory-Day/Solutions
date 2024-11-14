#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string name) {
    int answer = 0;
    int N = name.length();
    int move = 0, turn = N - 1;
    for(int i = 0; i < N; i++) {
        int begin = name[i] - 'A';
        int end = 'Z' - name[i] + 1;
        
        if(begin > end) move += end;
        else move += begin;
        
        int next = i + 1;
        while(next < N && name[next] == 'A') next++;
        
        turn = min(turn, i + N - next + min(i, N - next));
    }
    
    move += turn;
    answer = move;
    
    return answer;
}

int main()
{
    string name;
    cin >> name;

    int answer = solution(name);

    cout << answer;

    return 0;
}