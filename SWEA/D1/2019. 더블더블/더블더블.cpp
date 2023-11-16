#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int T;
	cin>>T;
	
    int num = 1;
    cout << num << " ";
	for(int i = 1; i <= T; ++i)
	{
        num *= 2;
        cout << num << " ";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}