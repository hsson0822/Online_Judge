#include <string>
#include <vector>
#include <limits.h>

using namespace std;

void postorder_traversal(int number, vector<vector<int>>& Tree, vector<int>& visited)
{
	for (int child : Tree[number - 1])
	{
		postorder_traversal(child, Tree, visited);
	}
	visited.push_back(number);
}

int solution(vector<int> sales, vector<vector<int>> links) {
	int answer = 0;

	vector<vector<int>> Tree(sales.size());
	for (auto l : links)
	{
		Tree[l[0] - 1].push_back(l[1]);
	}

	vector<vector<int>> d(sales.size(), vector<int>(2, 0));


	vector<int> visited;
	postorder_traversal(1, Tree, visited);

	for (int i : visited)
	{
		i--;

		int sum_child = 0;
		bool flag = false;
		int Min;
		if (Tree[i].size() > 0)
		{
			Min = INT_MAX;
			for (int k : Tree[i])
			{
				sum_child += min(d[k - 1][0], d[k - 1][1]);
				if (d[k - 1][0] > d[k - 1][1])
					flag = true;
				Min = min(Min, d[k - 1][1] - d[k - 1][0]);
			}
		}
		else
			Min = 0;

		d[i][1] = sales[i] + sum_child;
		if (flag)
			d[i][0] = sum_child;
		else
			d[i][0] = sum_child + Min;

	}

	return min(d[0][1], d[0][0]);
}