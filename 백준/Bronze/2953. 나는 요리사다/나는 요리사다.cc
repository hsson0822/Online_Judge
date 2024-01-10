#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> score;
	for (int i = 0; i < 5; ++i)
	{
		int sum{};
		for (int j = 0; j < 4; ++j)
		{
			int n;
			cin >> n;
			sum += n;
		}
		score.push_back(sum);
	}

	cout << distance(score.begin(),max_element(score.begin(), score.end()))+1 << " " << *max_element(score.begin(), score.end());
	return 0;
}