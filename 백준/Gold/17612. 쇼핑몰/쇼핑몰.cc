#include <bits/stdc++.h>

using namespace std;

int N, K;
bool stands[100'001];
queue<pair<int, int>> karts;
long long answer{};

struct Stand
{
	int k;
	int id;
	int w;
};

struct cmp
{
	bool operator()(Stand &A, Stand &B)
	{
		return A.w > B.w;
	}
};

struct outCmp
{
	bool operator()(Stand &A, Stand &B)
	{
		if(A.w == B.w)
			return A.k < B.k;

		return A.w > B.w;
	}
};

void Pay()
{
	priority_queue<Stand, vector<Stand>, cmp> PQ;
	long long cnt = 1;

	int k = 1;
	while (PQ.size() < K && !karts.empty())
	{
		int id = karts.front().first;
		int w = karts.front().second;
		karts.pop();

		stands[k] = true;
		PQ.push({k++, id, w});
	}

	//cout << PQ.size() << endl;

	priority_queue<Stand, vector<Stand>, outCmp> outNum;

	while (PQ.size() >= K)
	{
		queue<Stand> temp;
		Stand thisOut = PQ.top();
		stands[thisOut.k] = false;
		outNum.push({thisOut.k, thisOut.id, thisOut.w});
		PQ.pop();

		//cout << "Out : " << thisOut.k << " , " << thisOut.id << endl;

		int size = PQ.size();

		while (size--)
		{
			Stand cur = PQ.top();
			PQ.pop();

			if (cur.w == thisOut.w)
			{
				stands[cur.k] = false;
				outNum.push({cur.k, cur.id, cur.w});

				//cout << "Out : " << cur.k << " , " << cur.id << endl;
			}
			else
			{
				temp.push({cur.k, cur.id, cur.w - thisOut.w});
			}
		}

		while (!temp.empty())
		{
			PQ.push(temp.front());
			temp.pop();
		}

		while (PQ.size() < K && !karts.empty())
		{
			int id = karts.front().first;
			int w = karts.front().second;
			karts.pop();

			int i = 1;
			for (; i <= N; ++i)
				if (!stands[i])
					break;

			stands[i] = true;
			PQ.push({i, id, w});

			//cout << "In : " << i << " , " << id << endl;

			if (karts.empty())
				break;
		}

		while (!outNum.empty())
		{
			//cout << "answer *= " << cnt << "*" << outNum.top().id<<endl;
			answer += cnt++ * (long long)outNum.top().id;
			outNum.pop();
		}

		//cout <<answer << endl;

		if (karts.empty())
			break;
	}

	//cout << "-------------------" << endl;
	//cout << answer << endl;
	while (!PQ.empty())
	{
		outNum.push(PQ.top());
		PQ.pop();
	}

	while(!outNum.empty())
	{
		//cout << cnt << ", " << outNum.top().id << " ," << outNum.top().w << endl;
		//cout << "answer *= " << cnt << "*" << outNum.top().id<<endl;
		answer += cnt++ * (long long)outNum.top().id;
		//cout << "Out : " << outNum.top().k << " , " << outNum.top().id << endl;
		outNum.pop();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; ++i)
	{
		int id, w;
		cin >> id >> w;

		karts.push({id, w});
	}

	Pay();

	cout << answer;

	return 0;
}