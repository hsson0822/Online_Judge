#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> book_time) {
    vector<vector<string>> room;
	sort(book_time.begin(), book_time.end(), [](auto& a, auto&b)
		{
			return a[0] < b[0];
		});

	for (vector<string> v : book_time)
	{
		if (room.empty())
		{
			room.push_back(v);
			continue;
		}
		bool flag = false;

		for (vector<string>& r : room)
		{
			string bookHourStr;
			bookHourStr += v[0][0];
			bookHourStr += v[0][1];

			string bookMinStr;
			bookMinStr += v[0][3];
			bookMinStr += v[0][4];

			string roomHourStr;
			roomHourStr += r[1][0];
			roomHourStr += r[1][1];

			string roomMinStr;
			roomMinStr += r[1][3];
			roomMinStr += r[1][4];

			int bookHour = stoi(bookHourStr);
			int bookMin = stoi(bookMinStr) + bookHour * 60;

			int roomHour = stoi(roomHourStr);
			int roomMin = stoi(roomMinStr) + roomHour * 60 + 10;
			
			if (bookMin >= roomMin)
			{
				r[0] = v[0];
				r[1] = v[1];
				flag = true;
				break;
			}

		}

		if(!flag)
			room.push_back(v);

		sort(room.begin(), room.end(), [](auto& a, auto& b)
			{
				return a[0] < b[0];
			});
	}
    return room.size();
}