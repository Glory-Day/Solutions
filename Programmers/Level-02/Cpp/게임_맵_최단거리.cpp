#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int,int> PAIR;
typedef vector<vector<int>> VECTOR;

int width, height;
int visited[101][101];
PAIR direction[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
VECTOR matrix;

int BFS(int y, int x) {
    visited[y][x] = 1;
    queue<PAIR> Queue;
    Queue.push({y,x});
    
    while(!Queue.empty()) {
        int py = Queue.front().first;
        int px = Queue.front().second;
        Queue.pop();
        
        for(auto i : direction) {
            int ny = py + i.first;
            int nx = px + i.second;
        
            if((ny < 0) || (ny >= height) || (nx < 0) || (nx >= width)) continue;
            if(visited[ny][nx] > 0 || matrix[ny][nx] == 0) continue;
            
            Queue.push({ny,nx});
            visited[ny][nx] = visited[py][px] + 1;
        }
    }
    
    return (visited[height-1][width-1] == 0 ? -1 : visited[height-1][width-1]);
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    
    matrix = maps;
    
    width = maps[0].size();
    height = maps.size();
    
    answer = BFS(0, 0);
    
    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> maps(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maps[i][j];
        }
    }

    int answer = solution(maps);

    cout << answer;

    return 0;
}
