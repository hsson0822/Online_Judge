#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <climits>
#include <math.h>

using namespace std;

vector<vector<int>> perm(vector<int> lst, int n)
{
	vector<vector<int>> ret;
	if (n > lst.size())
		return ret;
	if (n == 1)
	{
		for (auto i : lst)
		{
			vector<int> temp(1, i);
			ret.push_back(temp);
		}
	}
	else if (n > 1)
	{
		for (int i = 0; i < lst.size(); ++i)
		{
			vector<int> slice(lst.begin(), lst.end());
			slice.erase(slice.begin() + i);
			for (vector<int> p : perm(slice, n - 1))
			{
				vector<int> temp(1, lst[i]);
				temp.insert(temp.end(), p.begin(), p.end());
				ret.push_back(temp);
			}
		}
	}

	return ret;
}

vector<vector<int>> comb(vector<int> lst, int n)
{
	vector<vector<int>> ret;
	if (n > lst.size())
		return ret;
	if (n == 1)
	{
		for (auto i : lst)
		{
			vector<int> temp(1, i);
			ret.push_back(temp);
		}
	}
	else if (n > 1)
	{
		for (int i = 0; i < lst.size() - n + 1; ++i)
		{
			vector<int> slice(lst.begin() + i + 1, lst.end());
			for (vector<int> c : comb(slice, n - 1))
			{
				vector<int> temp(1, lst[i]);
				temp.insert(temp.end(), c.begin(), c.end());
				ret.push_back(temp);
			}
		}
	}
    return ret;
}

int BFS(vector < vector<int>>& B, int r, int c, int dr, int dc)
{
	int distance = 0;
	vector<vector<bool>> visited(4, vector<bool>(4, false));
	visited[r][c] = true;
	vector<tuple<int, int, int>> queue( 1, {r,c,distance} );
	while (!queue.empty())
	{
		tie(r, c, distance) = queue.front();
		queue.erase(queue.begin());
		if (r == dr and c == dc)
			return distance;

		int Dr[4] = { -1,1,0,0};
		int Dc[4] = { 0,0,-1,1 };
		for (int i = 0; i < 4; ++i)
		{
			int nr = r + Dr[i];
			int nc = c + Dc[i];
			
			if (0 <= nr and nr < 4 and 0 <= nc and nc < 4 and not visited[nr][nc])
			{
				visited[nr][nc] = true;
				queue.push_back({ nr,nc,distance + 1 });
			}
		}

		if (r == 3 and B[2][c] == 0 and B[1][c] != 0 and not visited[1][c])
		{
			visited[1][c] = true;
			queue.push_back({ 1,c,distance + 1 });
		}
		else if (r == 3 and B[2][c] == 0 and B[1][c] == 0 and not visited[0][c])
		{
			visited[0][c] = true;
			queue.push_back({ 0,c,distance + 1 });
		}
		else if (r == 2 and B[1][c] == 0 and not visited[0][c])
		{
			visited[0][c] = true;
			queue.push_back({ 0,c,distance + 1 });
		}

		if (r == 0 and B[1][c] == 0 and B[2][c] != 0 and not visited[2][c])
		{
			visited[2][c] = true;
			queue.push_back({ 2,c,distance + 1 });
		}
		else if (r == 0 and B[1][c] == 0 and B[2][c] == 0 and not visited[3][c])
		{
			visited[3][c] = true;
			queue.push_back({ 3,c,distance + 1 });
		}
		else if (r == 1 and B[2][c] == 0 and not visited[3][c])
		{
			visited[3][c] = true;
			queue.push_back({ 3,c,distance + 1 });
		}


		if (c == 3 and B[r][2] == 0 and B[r][1] != 0 and not visited[r][1])
		{
			visited[r][1] = true;
			queue.push_back({ r,1,distance + 1 });
		}
		else if (c == 3 and B[r][2] == 0 and B[r][1] == 0 and not visited[r][0])
		{
			visited[r][0] = true;
			queue.push_back({ r,0,distance + 1 });
		}
		else if (c == 2 and B[r][1] == 0 and not visited[r][0])
		{
			visited[r][0] = true;
			queue.push_back({ r,0,distance + 1 });
		}

		if (c == 0 and B[r][1] == 0 and B[r][2] != 0 and not visited[r][2])
		{
			visited[r][2] = true;
			queue.push_back({ r,2,distance + 1 });
		}
		else if (c == 0 and B[r][1] == 0 and B[r][2] == 0 and not visited[r][3])
		{
			visited[r][3] = true;
			queue.push_back({ r,3,distance + 1 });
		}
		else if (c == 1 and B[r][2] == 0 and not visited[r][3])
		{
			visited[r][3] = true;
			queue.push_back({ r,3,distance + 1 });
		}

	}
}

int solution(vector<vector<int>> board, int sr, int sc)
{
	map<int, vector<pair<int, int>>> cards;
	for (int r = 0; r < 4; ++r)
		for (int c = 0; c < 4; ++c)
			if (board[r][c] != 0)
				if (cards.find(board[r][c]) != cards.end())
					cards[board[r][c]].push_back({ r,c });
				else
					cards[board[r][c]] = vector<pair<int, int>>{ 1,{r,c} };

	vector<int> lst;
	for (auto it : cards)
		lst.push_back(it.first);
	vector<vector<int>> permList = perm(lst, lst.size());

	int answer = INT_MAX;
	int N = pow(2, lst.size());
	for(auto p :permList)
		for (int j = 0; j < N; ++j)
		{
			vector < vector<int>> B;
			for (int i = 0; i < 4; ++i)
			{
				vector<int> temp(board[i].begin(), board[i].end());
				B.push_back(temp);
			}
			int sum = 0;
			int dr2 = sr;
			int dc2 = sc;
			for (int i = 0; i < p.size(); ++i)
			{
				int index = (j >> i) & 1;
				int dr1, dc1;
				tie(dr1, dc1) = cards[p[i]][index];
				sum += BFS(B, dr2, dc2, dr1, dc1) + 1;
				index = 1 - index;
				tie(dr2, dc2) = cards[p[i]][index];
				sum += BFS(B, dr1, dc1, dr2, dc2) + 1;
				B[dr1][dc1] = 0;
				B[dr2][dc2] = 0;
			}
			answer = min(answer, sum);
		}

	return answer;
}