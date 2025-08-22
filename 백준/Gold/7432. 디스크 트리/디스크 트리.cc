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

struct TrieNode
{
	map<string,struct TrieNode*> children;
	
	TrieNode () : children() {}

	void Insert(vector<string>& str, int index)
	{
		if(str.size() == index)
			return;

		string next = str[index];

		if(children[next] == nullptr)
			children[next] = new TrieNode;

		children[next]->Insert(str, index+1);
	}

	void Print(int index)
	{
		for(auto child : children)
		{
			for(int i = 0 ; i < index ; ++i)
				cout << " ";
			cout << child.first<<'\n';

			string next = child.first;

			if(children[next] == nullptr)
				return;
			
			children[next]->Print(index+1);
		}
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	TrieNode root;

	for(int i = 0 ; i < N ; ++i)
	{
		string str;
		cin >> str;

		istringstream ss (str);
		vector<string> vec;
		string s;

		while(getline(ss,s,'\\'))
		{
			vec.push_back(s);
		}

		root.Insert(vec,0);
	}

	root.Print(0);

	return 0;
}