#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int M;

int village[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> village[i][j];
			if (village[i][j] == 1)
				house.push_back(pair(i, j));
			if (village[i][j] == 2)
				chicken.push_back(pair(i, j));
		}
	}

	vector<int> mask;
	for (int i = 0; i < chicken.size() - M; ++i)
		mask.push_back(0);

	for (int i = 0; i < M; ++i)
		mask.push_back(1);


	int MIN = 98765432;
	do
	{
		int result = 0;
		for (int i = 0; i < house.size(); i++) {
			int min_dist = 987654321;
			for (int j = 0; j < chicken.size(); j++) {
				if (mask[j] == 1) {
					int houseDistance = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
					if (houseDistance < min_dist) {
						min_dist = houseDistance;
					}
				}
			}
			result += min_dist;
		}
		if (result < MIN) {
			MIN = result;
		}

	} while (next_permutation(mask.begin(), mask.end()));

	cout << MIN;
	return 0;
}