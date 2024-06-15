#include <string>
#include <vector>

using namespace std;

int N;
int M;
int MAZE[5][5];
    
pair<int,int> redGoal;
pair<int,int> blueGoal;

bool redVisited[5][5];
bool blueVisited[5][5];

bool redEnd;
bool blueEnd;

int dirX[4] {1,0,-1,0};
int dirY[4] {0,1,0,-1};

int miniest = 987654321;

int findGoal(pair<int, int> red, pair<int, int> blue, int result)
{
    if (redEnd && blueEnd)
    {
        if (miniest > result)
            miniest = result;
        return result;
    }
    int answer = 987654321;

    for (int i = 0; i < 4; ++i)
    {
        if (red.first == redGoal.first && red.second == redGoal.second)
            redEnd = true;
        
        pair<int, int> nR;
        nR.first = (!redEnd) ? red.first + dirX[i] : red.first;
        nR.second = (!redEnd) ? red.second + dirY[i] : red.second;

        for (int j = 0; j < 4; ++j)
        {
            if (blue.first == blueGoal.first && blue.second == blueGoal.second)
                blueEnd = true;
            
            pair<int, int> nB;
            nB.first = (!blueEnd) ? blue.first + dirX[j] : blue.first;
            nB.second = (!blueEnd) ? blue.second + dirY[j] : blue.second;

            if (nR.first < 0 || nR.second < 0 || nR.first >= N || nR.second >= M) continue;
            if (nB.first < 0 || nB.second < 0 || nB.first >= N || nB.second >= M) continue;

            if (MAZE[nR.first][nR.second] == 1 || MAZE[nB.first][nB.second] == 1) continue;

            if (!redEnd && redVisited[nR.first][nR.second]) continue;
            if (!blueEnd && blueVisited[nB.first][nB.second]) continue;

            if (nR.first == nB.first && nR.second == nB.second) continue;
            if (nR.first == blue.first && nR.second == blue.second && red.first == nB.first && red.second == nB.second) continue;
      
            redVisited[nR.first][nR.second] = true;
            blueVisited[nB.first][nB.second] = true;

            if (nR.first == redGoal.first && nR.second == redGoal.second)
                redEnd = true;

            if (nB.first == blueGoal.first && nB.second == blueGoal.second)
                blueEnd = true;

            if( miniest > result + 1)
                answer = min(answer, findGoal(nR, nB, result + 1));

            redVisited[nR.first][nR.second] = false;
            blueVisited[nB.first][nB.second] = false;

            redEnd = false;
            blueEnd = false;
        }
    }

    return answer;
}

int solution(vector<vector<int>> maze) {

    N = maze.size();
    M = maze[0].size();

    pair<int, int> red;
    pair<int, int> blue;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (maze[i][j] == 1)
            {
                red.first = i;
                red.second = j;
            }
            else if (maze[i][j] == 2)
            {
                blue.first = i;
                blue.second = j;
            }
            else if (maze[i][j] == 3)
            {
                redGoal.first = i;
                redGoal.second = j;
            }
            else if (maze[i][j] == 4)
            {
                blueGoal.first = i;
                blueGoal.second = j;
            }
            else if (maze[i][j] == 5)
                MAZE[i][j] = 1;
            else
                MAZE[i][j] = 0;
        }
    }

    redVisited[red.first][red.second] = true;
    blueVisited[blue.first][blue.second] = true;

    int answer = findGoal(red, blue, 0);

    if (answer == 987654321)
        return 0;
    else
        return answer;
}