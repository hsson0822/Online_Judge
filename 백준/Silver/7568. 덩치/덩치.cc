#include <iostream>
#include <vector>

using namespace std;

class Student
{
public:
	int weight;
	int height;
	int level;

	Student(int w, int h, int l) : weight(w), height(h), level(l)
	{}
};

int N;
vector<Student> stu;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int a;
		int b;
		cin >> a >> b;
		Student temp(a, b, 1);
		stu.push_back(temp);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i == j) continue;

			if (stu[i].weight < stu[j].weight && stu[i].height < stu[j].height)
			{
				++(stu[i].level);
			}
		}
	}

	for (auto s : stu)
		cout << s.level << " ";

	return 0;
}