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

const int NUM_ALPHA = 26;
int toIndex(char ch) { return ch - 'a'; }

struct TrieNode
{
	struct TrieNode *children[NUM_ALPHA];
	bool isEnd;

	TrieNode() : children(), isEnd(false) {}

	void Insert(string &str, int index)
	{
		if (index == str.length())
			isEnd = true;
		else
		{
			int next = toIndex(str[index]);

			if (children[next] == nullptr)
				children[next] = new TrieNode;

			children[next]->Insert(str, index + 1);
		}
	}

	bool Find(string &str, int depth)
	{
		if (depth == str.length())
			return true;
		
		int next= toIndex(str[depth]);

		if(children[next] == nullptr)
			return false;

		return children[next]->Find(str, depth+1);
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	TrieNode root;

	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		root.Insert(str, 0);
	}

	int answer{};
	for(int i = 0 ; i < M ; ++i)
	{
		string str;
		cin >> str;

		if(root.Find(str, 0))
			++answer;
	}

	cout << answer;

	return 0;
}