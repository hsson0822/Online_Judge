#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string A;
		string B;
		cin >> A >> B;

		if (A.size() == B.size())
		{
			bool flag = true;
			for (int i = 0; i < A.size(); ++i)
			{
				char smallA = A[i];
				char smallB = B[i];
				int Acircle;
				int Bcircle;

				if (smallA == 'B')
					Acircle = 2;
				else if (smallA == 'A' || smallA == 'D' || smallA == 'O' || smallA == 'P' || smallA == 'Q' || smallA == 'R')
					Acircle = 1;
				else
					Acircle = 0;

				if (smallB == 'B')
					Bcircle = 2;
				else if (smallB == 'A' || smallB == 'D' || smallB == 'O' || smallB == 'P' || smallB == 'Q' || smallB == 'R')
					Bcircle = 1;
				else
					Bcircle = 0;

				if (Acircle != Bcircle)
				{
					flag = false;
					break;
				}
			}

			if(flag)
				cout << "#" << test_case << " SAME" << endl;
			else
				cout << "#" << test_case << " DIFF" << endl;

		}
		else
			cout << "#" << test_case << " DIFF" << endl;

		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
