#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int canMove;
		cin >> canMove;

		vector<int> boxes;

		for (int i = 0; i < 100; ++i)
		{
			int n;
			cin >> n;
			boxes.push_back(n);
		}

		for (int i = 0; i < canMove; ++i)
		{
			sort(boxes.begin(), boxes.end());
			++boxes[0];
			--boxes[boxes.size() - 1];
		}
		sort(boxes.begin(), boxes.end());


		cout << "#" << test_case << " " << boxes[boxes.size() - 1] - boxes[0] << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}