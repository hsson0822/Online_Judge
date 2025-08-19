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

const int AlphaNum = 75;
int charToInt(char ch) {
	//cout <<ch-'a'<<endl;
	return ch - '0'; }


struct TrieNode
{
	struct TrieNode *children[AlphaNum];
	int cnt;

	TrieNode() : children(), cnt(0) {}

	void Insert(string &str, int index, bool made)
	{
		if (str.size() == index)
		{
			++cnt;
			if (!made)
			{
				string name{};
				for (int i = 0; i < index; ++i)
				name += str[i];
				
				if(cnt != 1)
				name += to_string(cnt);
				

				cout << name << "\n";
			}
			return;
		}

		int next = charToInt(str[index]);

		if (children[next] == nullptr)
		{
			children[next] = new TrieNode;

			if (!made)
			{
				string name{};
				for (int i = 0; i <= index; ++i)
					name += str[i];

				cout << name << "\n";
				made = true;
			}
		}

		children[next]->Insert(str, index + 1, made);
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	TrieNode root;

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		root.Insert(str, 0, false);
	}

	return 0;
}