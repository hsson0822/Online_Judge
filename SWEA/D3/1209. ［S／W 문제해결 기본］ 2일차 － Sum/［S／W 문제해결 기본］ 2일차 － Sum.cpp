#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	for (test_case = 1; test_case <= 10; ++test_case)
    {
        int test;
        cin >> test;

        vector<vector<int>> nums;
        for (int i = 0; i < 100; ++i)
        {
            vector<int> vec;
            for (int j = 0; j < 100; ++j)
            {
                int n;
                cin >> n;
                vec.push_back(n);
            }
            nums.push_back(vec);
        }

        int max = INT_MIN;
        int cross{};
        int crossReverse{};

        for (int i = 0; i < 100; ++i)
        {
            int wid{};
            int hei{};

            for (int j = 0; j < 100; ++j)
            {
                if (i == j)
                    cross += nums[i][j];

                if (i + j == 99)
                    crossReverse += nums[i][j];

                wid += nums[i][j];
                hei += nums[j][i];
            }

            if (max < wid)
                max = wid;
            
            if (max < hei)
                max = hei;
        }

        if (max < cross)
            max = cross;

        if (max < crossReverse)
            max = crossReverse;

        cout << "#" << test_case << " " << max << "\n";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}