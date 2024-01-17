#include <iostream>
#include <set>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(true)
	{
		priority_queue<int, vector<int>, greater<int>> nums;
		set<int> count;
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0 || b == 0 || c == 0)
			break;

		nums.push(a);
		nums.push(b);
		nums.push(c);

		count.insert(a);
		count.insert(b);
		count.insert(c);

		a = nums.top(); nums.pop();
		b = nums.top(); nums.pop();
		c = nums.top(); nums.pop();
		
		if (a + b <= c)
			cout << "Invalid" << endl;
		else if (count.size() == 1)
			cout << "Equilateral" << endl;
		else if (count.size() == 2)
			cout << "Isosceles" << endl;
		else if (count.size() == 3)
			cout << "Scalene" << endl;

	}
}