#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int A;
    int B;
    
	cin >> A >> B;
    
    if( A > B)
    {
     	if( A == 3 && B == 1)
            cout << "B";
        else
            cout << "A";
    }
    else
    {
        if( A == 1 && B == 3)
            cout << "A";
        else
            cout << "B";
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}