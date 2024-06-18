#include <iostream>
#include <map>
#include <set>

using namespace std;

int N;
multiset<pair<int, int>> question;
multiset<pair<int, int>>::iterator q_iter;
multiset<pair<int, int>>::reverse_iterator q_rev_iter;
map<int, int> diction;

int M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int P;
		int L;
		cin >> P >> L;
		
		question.insert(pair(L,P));
		diction[P] = L;

	}

	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		string command;
		cin >> command;

		if (command == "recommend")
		{
			int x;
			cin >> x;

			if (x == -1)
			{
				q_iter = question.begin();
				cout << q_iter->second << endl;
			}
			else
			{
				q_rev_iter = question.rbegin();
				cout << q_rev_iter->second << endl;
			}

		}
		else if (command == "add")
		{
			int P;
			int L;
			cin >> P >> L;

			question.insert(pair(L,P));
			diction[P] = L;
		}
		else if (command == "solved")
		{
			int P;
			cin >> P;

			int L = diction[P];
			auto it = question.find(pair(L, P));
			question.erase(it);
		}

	}
		
	return 0;
}