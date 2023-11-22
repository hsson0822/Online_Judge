#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int leng;
        cin >> leng;
        
        int wordSize;
        cin >> wordSize;
        
        vector<vector<int>> board;
        for(int i = 0 ; i < leng; ++i)
        {
            vector<int> vec;
            for(int j = 0 ; j < leng; ++j )
            {
                int n;
                cin>> n;
                vec.push_back(n);
            }
            board.push_back(vec);
        }
        
        int answer{};
        
        for(int i = 0 ; i < leng; ++i)
        {
            int count{};
            for(int j = 0 ; j < leng; ++j )
            {
                if(board[i][j])
                    ++count;
                else
                {
                    if(count == wordSize)
                    	++answer;
                    count = 0;
                }
            }
            if(count == wordSize)
            	++answer;
        }
        
        for(int i = 0 ; i < leng; ++i)
        {
            int count{};
            for(int j = 0 ; j < leng; ++j )
            {
                if(board[j][i])
                    ++count;
                else
                {
                    if(count == wordSize)
                        ++answer;
                    count = 0;
                }
            }
            if(count == wordSize)
            	++answer;
        }
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}