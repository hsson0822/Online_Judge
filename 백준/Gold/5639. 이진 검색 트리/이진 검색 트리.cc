#include <iostream>
#include <algorithm>
using namespace std;

int K;
int tree[10001];

void postOrder(int root, int size)
{
	if (size - root <= 0)
		return;

	int frontRoot = root + 1;
	int backRoot = size;

	backRoot = distance(tree, upper_bound(tree + root, tree + size, tree[root]));

	postOrder(frontRoot, backRoot);
	postOrder(backRoot, size);

	cout << tree[root] << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	while (cin >> n)
	{
		tree[K++] = n;
	}
	
	postOrder(0, K);

	return 0;
}