#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
    cin>> test_case;
	int sum{};
    
	for(int i = 1; i <= test_case; ++i)
	{
        sum += i;
	}
    cout << sum;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}