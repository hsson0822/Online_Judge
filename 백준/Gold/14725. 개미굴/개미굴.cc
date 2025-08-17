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
int charToNum(char ch) { return ch - '0'; }
char numToChar(int n) { return n + '0'; }

struct TrieNode
{
	map<string, struct TrieNode*> children;
	string str;
	bool isEnd;

	TrieNode() : children(), str(), isEnd(false) {}

	void Insert(int K)
	{
		if (K == 0)
			isEnd = true;
		else
		{
			string s;
			cin >> s;
			//cout << s <<endl;

			if(children.find(s) == children.end())
			{
				//cout <<"NEW"<<endl;
				TrieNode* temp = new TrieNode();
				temp->str = s;
				
				children[s] = temp;
				children[s]->Insert(K-1);
			}
			else
			{
				//cout <<"EXIST"<<endl;
				children[s]->Insert(K-1);
			}
		}
	}

	void Print(int index)
	{
		for (auto m : children)
		{
			for (int t = 0; t < index; ++t)
				cout << "--";
			cout << m.second->str << endl;


			m.second->Print(index + 1);
			
		}
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
		int K;
		cin >> K;

		root.Insert(K);
	}

	root.Print(0);

	return 0;
}