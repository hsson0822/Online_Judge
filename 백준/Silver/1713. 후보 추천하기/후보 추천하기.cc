#include <iostream>
#include <queue>
#include <vector>

using namespace std;
	
int N;
int K;
int student[1001];
bool init[1001];

struct Compare1
{
	bool operator()(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b)
	{
		if (a.second.first == b.second.first)
			return a.second.second > b.second.second;
		return a.second.first > b.second.first;
	}
};

struct Compare2
{
	bool operator()(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b)
	{
		return a.first> b.first;
	}
};

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare1> PQ;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;


	for (int i = 0; i < K; ++i)
	{
		int n;
		cin >> n;

		if (init[n] == true)
		{
			priority_queue < pair<int, pair<int, int>>> temp;
			while (!PQ.empty())
			{
				auto t = PQ.top();
				PQ.pop();

				if (t.first == n)
				{
					t.second.first++;
				}

				temp.push(t);
			}

			while (!temp.empty())
			{
				auto t = temp.top();
				temp.pop();

				PQ.push(t);
			}

		}
		else
		{
			if (PQ.size() < N)
			{
				PQ.push(pair(n, pair(1, i)));
				init[n] = true;
				continue;
			}

			auto t = PQ.top();
			PQ.pop();
			init[t.first] = false;

			init[n] = true;
			t.first = n;
			t.second.first = 1;
			t.second.second = i;
			PQ.push(t);
		}
	}

	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare2> PQ2;
	while (!PQ.empty())
	{
		auto t = PQ.top();
		PQ.pop();
		PQ2.push(t);
	}

	while (!PQ2.empty())
	{
		auto t = PQ2.top();
		PQ2.pop();
		cout << t.first << " ";
	}
	return 0;
}