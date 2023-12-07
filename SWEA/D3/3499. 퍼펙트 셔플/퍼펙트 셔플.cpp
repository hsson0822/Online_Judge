#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int cardCount;
		cin >> cardCount;

		vector<string> cards;
		for (int i = 0; i < cardCount; ++i)
		{
			string s;
			cin >> s;
			cards.push_back(s);
		}

		vector<string> newCards;
		int next = ceil((double)cardCount / 2);
		
		for (int i = 0; i < next; ++i)
		{

			newCards.push_back(cards[i]);
			if(i+next < cardCount)
				newCards.push_back(cards[i+next]);
		}

		
		cout << "#" << test_case << " ";
		for (string s : newCards)
			cout << s << " ";
		cout << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}