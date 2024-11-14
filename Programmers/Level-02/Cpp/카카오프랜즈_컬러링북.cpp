#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>

using namespace std;
typedef pair<int,int> PAIR;

int N, M;
PAIR direction[4] = {{-1,0},{1,0},{0,-1},{0,1}};
vector<vector<int>> matrix;
vector<vector<bool>> visited;

bool check(int Y, int X) {
    return (Y >= 0 && Y < N) && (X >= 0 && X < M);
}

int DFS(int Y, int X, int count) {
    visited[Y][X] = true;
    
    for(int i=0;i<4;i++) {
        int ny = Y + direction[i].first;
        int nx = X + direction[i].second;
        
        if(check(ny,nx) && !visited[ny][nx] && matrix[ny][nx] == matrix[Y][X]) {
            count = DFS(ny,nx,count + 1);
        }
    }
    
    return count;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    N = picture.size();
    M = picture[0].size();
    visited = vector<vector<bool>>(N,vector<bool>(M,false));
    
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    matrix = picture;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(visited[i][j] == false && picture[i][j]!=0) {
                max_size_of_one_area = max(max_size_of_one_area, DFS(i, j, 1));
                number_of_area++;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> picture(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> picture[i][j];
        }
    }

    vector<int> answer = solution(m, n, picture);

    cout << answer[0] << ' ' << answer[1];

    return 0;
}