#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>
#include <math.h>
#include <cstring>

using namespace std;

int charToInt(char ch) {return ch-'0';}

struct TrieNode
{
	struct TrieNode *children[10];
	bool isEnd;

	TrieNode() : children(), isEnd(false) {}

	void Insert(string &str, int index)
	{
		if(index == str.size())
			isEnd = true;
		else
		{
			int next = charToInt(str[index]);

			if(children[next] == nullptr)
				children[next] = new TrieNode;

			children[next]->Insert(str, index+1);

		}
	}

	bool Find(string &str, int index)
	{
		if(index == str.size())
			return true;

		int next = charToInt(str[index]);

		if(children[next] == nullptr)
			return false;

		return children[next]->Find(str, index+1);

	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int t = 0; t < T; ++t)
	{
		TrieNode root;

		int N;
		cin >> N;

		vector<string> vec;

		for (int i = 0; i < N; ++i)
		{
			string str;
			cin >> str;
			vec.push_back(str);
		}

		sort(vec.begin(), vec.end(), [](string &a, string &b)
			 { return a.size() > b.size(); });

		bool flag = false;
		for(string str : vec)
		{
			if(!(root.Find(str,0)))
			{
				root.Insert(str, 0);
			}
			else
			{
				flag = true;
				break;
			}
		}
		
		if(flag)
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}