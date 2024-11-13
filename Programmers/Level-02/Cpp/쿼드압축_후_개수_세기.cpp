#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<vector<int>> VECTOR;
typedef pair<int ,int> PAIR;

int caches[2];
VECTOR Array;

void DivideAndConque(int yBegin, int xBegin, int length) {
    //cout << "Y: " << Y.first << ' ' << Y.second << endl;
    //cout << "X: " << X.first << ' ' << X.second << endl;
    bool check = true;
    int compare = Array[yBegin][xBegin];
    for(int y = yBegin; y < yBegin + length; y++) {
        for(int x = xBegin; x < xBegin + length; x++) {
            if(compare != Array[y][x]) {
                check = false;
                break;
            }
        }
        if(!check) break;
    }
    
    if(check) caches[compare]++;
    else {
        length /= 2;
        
        DivideAndConque(yBegin, xBegin, length);
        DivideAndConque(yBegin, xBegin + length, length);
        DivideAndConque(yBegin + length, xBegin, length);
        DivideAndConque(yBegin + length, xBegin + length, length);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    Array = arr;
    int length = arr.size();
    
    DivideAndConque(0, 0, length);
    
    answer.push_back(caches[0]);
    answer.push_back(caches[1]);
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(4));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }

    vector<int> answer = solution(arr);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}