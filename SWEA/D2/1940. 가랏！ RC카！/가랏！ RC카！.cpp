#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int commandCount;
        cin >> commandCount;
        
        int speed{};
        int meter{};
        
        for(int i = 0 ; i < commandCount ; ++i)
        {
            int command;
            cin >> command;
            
            
			if(command == 1)
            {
                int leng;
                cin >> leng;
                speed += leng;
            }
            else if(command == 2)
            {
                int leng;
                cin >> leng;
                speed -= leng;
            }
            if(speed < 0)
                speed = 0;
            meter += speed;
        }

		cout << "#" << test_case << " " << meter << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}