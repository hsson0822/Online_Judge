#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	string T;
	
    cin >> T;
	
	for(char ch : T)
	{
		cout << ch - 64 << " ";
	}
	return 0;
}