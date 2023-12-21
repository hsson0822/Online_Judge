#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int aCount;
	int bCount;
	cin >> aCount >> bCount;

	set<int> A;
	for (int i = 0; i < aCount; ++i)
	{
		int n;
		cin >> n;
		A.insert(n);
	}
	for (int i = 0; i < bCount; ++i)
	{
		int n;
		cin >> n;
		if (A.find(n) != A.end())
			A.erase(n);
	}

	cout << A.size() << endl;
	for (int n : A)
		cout << n << " ";
	cout << endl;
    
    return 0;
}