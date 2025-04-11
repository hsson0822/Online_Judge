#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node
{
	int parent;
	int num;
	vector<int> children;
};

struct Node nodes[51];
bool active[51];

void eraseChildren(int num)
{
	for (int i = 0; i < nodes[num].children.size(); ++i)
	{
		active[nodes[num].children[i]] = false;
		eraseChildren(nodes[num].children[i]);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int start = -1;

	for (int i = 0; i < N; ++i)
	{
		struct Node temp;
		nodes[i] = temp;
	}

	for (int i = 0; i < N; ++i)
	{
		int k;
		cin >> k;

		nodes[i].parent = k;
		nodes[i].num = i;
		active[i] = true;

		nodes[nodes[i].parent].children.push_back(i);

		if (k == -1)
			start = i;
	}

	int k;
	cin >> k;
	active[k] = false;

	int parent = nodes[k].parent;

	if (parent == -1)
	{
		cout << 0 << endl;
		return 0;
	}

	auto iter = find(nodes[parent].children.begin(), nodes[parent].children.end(), k);
	if (iter != nodes[parent].children.end())
		nodes[parent].children.erase(iter);

	eraseChildren(k);


	int answer{};

	queue<int> Q;
	Q.push(start);

	while (!Q.empty())
	{
		int num = Q.front();
		Q.pop();

		if (!active[num]) continue;


		if (nodes[num].children.size() == 0)
		{
			++answer;
			continue;
		}

		for (int i = 0; i < nodes[num].children.size(); ++i)
		{

			if (!active[nodes[num].children[i]]) continue;
			Q.push(nodes[num].children[i]);
		}
	}

	cout << answer;

	return 0;
}
