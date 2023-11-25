#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        int Q;
        cin >> N >> Q;

        vector<int> boxes;
        for (int i = 0; i < N; ++i)
        {
            boxes.push_back(0);
        }

        for (int i = 0; i < Q; ++i)
        {
            int L;
            int R;
            cin >> L >> R;

            for (int j = L - 1; j <= R - 1; ++j)
                boxes[j] = i+1;
        }


        cout << "#" << test_case << " ";
        for (int n : boxes)
            cout << n << " ";
        cout << endl;
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}