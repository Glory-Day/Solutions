#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int N) {
    vector<int> answer;

    int matrix[1001][1001];
	int count = N;
    int index = 1;
    int Y = 0, X = 0;
	for (int i = 0; i < N; i++) 
    {
		switch (i % 3)
		{
            case 0:
                for (int j = 0; j < count; j++, index++)
                {
                    matrix[Y++][X] = index;
                }
                
                Y--;
                X++;
                
                count--;
                
                break;
            case 1:
                for (int j = 0; j < count; j++, index++)
                {
                    matrix[Y][X++] = index;
                }
                
                Y--;
                X -= 2;
                
                count--;
                
                break;

            case 2:
                for (int j = 0; j < count; j++, index++)
                {
                    matrix[Y--][X--] = index;
                }
                
                Y += 2,
                X++;
                
                count--;
                
                break;
            default:
                break;
		}
	}

	for (int i = 0; i < N; i++)
    {
		for (int j = 0; j <= i; j++)
        {
			answer.push_back(matrix[i][j]);
		}
	}

    return answer;
}

int main()
{
    int N;
    cin >> N;

    vector<int> answer = solution(N);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}