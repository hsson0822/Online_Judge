#include <string>
#include <vector>
#include <tuple>

using namespace std;

int solution(vector<vector<int>> board)
{
	int N = board.size();
	int r = 0;
	int c = 0;
	int direction = 0;
	int distance = 0;

	vector<vector<bool>> visited0(N, vector<bool>(N,false));
	vector<vector<bool>> visited1(N, vector<bool>(N,false));
	vector<tuple<int, int, int>> path(1, { r,c,direction });
	vector<tuple<int, int, int, int, vector<tuple<int, int, int>>>> queue(1, { r,c,direction,distance,path });

	while (!queue.empty())
	{
		tie(r, c, direction, distance, path) = queue.front();
		queue.erase(queue.begin());
		if (direction == 0)
		{
			if (r == N - 1 and c == N - 2)
				return distance;

			//상
			if (r > 0 and board[r - 1][c] == 0 and board[r - 1][c + 1] == 0 and not visited0[r - 1][c])
			{
				visited0[r - 1][c] = true;
				vector<tuple<int, int, int>> temp(path.begin(), path.end());
				temp.push_back({ r - 1,c,0 });
				queue.push_back({ r - 1,c,0,distance + 1, temp });
			}

			//하
			if (r < N-1 and board[r + 1][c] == 0 and board[r + 1][c + 1] == 0 and not visited0[r + 1][c])
			{
				visited0[r + 1][c] = true;
				vector<tuple<int, int, int>> temp(path.begin(), path.end());
				temp.push_back({ r + 1,c,0 });
				queue.push_back({ r + 1,c,0,distance + 1, temp });
			}

			//좌
			if (c > 0 and board[r][c - 1] == 0  and not visited0[r][c - 1])
			{
				visited0[r][c - 1] = true;
				vector<tuple<int, int, int>> temp(path.begin(), path.end());
				temp.push_back({ r ,c - 1,0 });
				queue.push_back({ r,c - 1,0,distance + 1, temp });
			}

			//우
			if (c < N - 2 and board[r][c + 2] == 0 and not visited0[r][c + 1])
			{
				visited0[r][c + 1] = true;
				vector<tuple<int, int, int>> temp(path.begin(), path.end());
				temp.push_back({ r ,c + 1,0 });
				queue.push_back({ r,c + 1,0,distance + 1, temp });
			}

			//회전
			if (r < N - 1 and board[r + 1][c] == 0 and board[r + 1][c + 1] == 0 and not visited1[r][c])
			{
				visited1[r][c] = true;
				vector<tuple<int, int, int>> temp(path.begin(), path.end());
				temp.push_back({ r,c,1 });
				queue.push_back({ r,c,1, distance + 1, temp });
			}

			if (r > 0 and board[r - 1][c] == 0 and board[r - 1][c + 1] == 0 and not visited1[r-1][c])
			{
				visited1[r-1][c] = true;
				vector<tuple<int, int, int>> temp(path.begin(), path.end());
				temp.push_back({ r-1,c,1 });
				queue.push_back({ r-1,c,1, distance + 1, temp });
			}

			if (r > 0 and board[r - 1][c] == 0 and board[r - 1][c + 1] == 0 and not visited1[r-1][c+1])
			{
				visited1[r-1][c+1] = true;
				vector<tuple<int, int, int>> temp(path.begin(), path.end());
				temp.push_back({ r-1,c+1,1 });
				queue.push_back({ r-1,c+1,1, distance + 1, temp });
			}

			if (r < N-1 and board[r + 1][c] == 0 and board[r + 1][c + 1] == 0 and not visited1[r][c+1])
			{
				visited1[r][c+1] = true;
				vector<tuple<int, int, int>> temp(path.begin(), path.end());
				temp.push_back({ r,c+1,1 });
				queue.push_back({ r,c+1,1, distance + 1, temp });
			}

		}
		else
		{
			if (r == N - 2 and c == N - 1)
				return distance;

			//상
			if (r > 0 and board[r - 1][c] == 0 and not visited1[r - 1][c])
			{
				visited1[r - 1][c] = true;
				vector<tuple<int, int, int>> temp(path.begin(), path.end());
				temp.push_back({ r - 1,c,1 });
				queue.push_back({ r - 1,c,1,distance + 1, temp });
			}

			//하
			if (r < N - 2 and board[r + 2][c] == 0 and not visited1[r + 1][c])
			{
				visited1[r + 1][c] = true;
				vector<tuple<int, int, int>> temp(path.begin(), path.end());
				temp.push_back({ r + 1,c,1 });
				queue.push_back({ r + 1,c,1,distance + 1, temp });
			}

			//좌
			if (c > 0 and board[r][c - 1] == 0 and board[r+1][c - 1] == 0 and not visited1[r][c - 1])
			{
				visited1[r][c - 1] = true;
				vector<tuple<int, int, int>> temp(path.begin(), path.end());
				temp.push_back({ r ,c - 1,1 });
				queue.push_back({ r,c - 1,1,distance + 1, temp });
			}

			//우
			if (c < N - 1 and board[r][c + 1] == 0 and board[r+1][c + 1] == 0 and not visited1[r][c + 1])
			{
				visited1[r][c + 1] = true;
				vector<tuple<int, int, int>> temp(path.begin(), path.end());
				temp.push_back({ r ,c + 1,1 });
				queue.push_back({ r,c + 1,1,distance + 1, temp });
			}

			//회전
			if (c > 0 and board[r][c-1] == 0 and board[r + 1][c - 1] == 0 and not visited0[r][c-1])
			{
				visited0[r][c-1] = true;
				vector<tuple<int, int, int>> temp(path.begin(), path.end());
				temp.push_back({ r,c-1,0 });
				queue.push_back({ r,c-1,0, distance + 1, temp });
			}

			if (c < N-1 and board[r][c+1] == 0 and board[r + 1][c + 1] == 0 and not visited0[r][c])
			{
				visited0[r][c] = true;
				vector<tuple<int, int, int>> temp(path.begin(), path.end());
				temp.push_back({ r,c,0 });
				queue.push_back({ r,c,0, distance + 1, temp });
			}

			if (c < N - 1 and board[r][c+1] == 0 and board[r + 1][c + 1] == 0 and not visited0[r + 1][c])
			{
				visited0[r + 1][c] = true;
				vector<tuple<int, int, int>> temp(path.begin(), path.end());
				temp.push_back({ r + 1,c,0 });
				queue.push_back({ r + 1,c ,0, distance + 1, temp });
			}

			if (c > 0 and board[r][c-1] == 0 and board[r + 1][c - 1] == 0 and not visited0[r+1][c - 1])
			{
				visited0[r+1][c - 1] = true;
				vector<tuple<int, int, int>> temp(path.begin(), path.end());
				temp.push_back({ r+1,c - 1,0 });
				queue.push_back({ r+1,c - 1,0, distance + 1, temp });
			}
		}

	}

	return 0;
}