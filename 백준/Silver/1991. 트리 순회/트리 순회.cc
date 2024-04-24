#include <iostream>
#include <vector>

using namespace std;

int N;
string pre;
string mid;
string post;
vector<char> tree[27];

void preOrder(char root)
{
	cout << root;

	if (tree[root - 'A'][0] != '.')
		preOrder(tree[root - 'A'][0]);

	if (tree[root - 'A'][1] != '.')
		preOrder(tree[root - 'A'][1]);
}

void midOrder(char root)
{

	if (tree[root - 'A'][0] != '.')
		midOrder(tree[root - 'A'][0]);

	cout << root;

	if (tree[root - 'A'][1] != '.')
		midOrder(tree[root - 'A'][1]);
}

void postOrder(char root)
{

	if (tree[root - 'A'][0] != '.')
		postOrder(tree[root - 'A'][0]);

	if (tree[root - 'A'][1] != '.')
		postOrder(tree[root - 'A'][1]);

	cout << root;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		char root;
		char child1;
		char child2;

		cin >> root >> child1 >> child2;

		tree[root - 'A'].push_back(child1);
		tree[root - 'A'].push_back(child2);
	}

	preOrder('A');
	cout << '\n';
	midOrder('A');
	cout << '\n';
	postOrder('A');
	
	return 0;
}