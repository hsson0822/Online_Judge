#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Student
{
public:
	string name;
	int gook;
	int young;
	int soo;

	Student(string n, int g, int y, int s) : name(n), gook(g), young(y), soo(s) {}

	string getName() { return name; }
	int getGook() { return gook; }
	int getYoung() { return young; }
	int getSoo() { return soo; }
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int count;
	cin >> count;

	vector<Student> students;

	for (int i = 0; i < count; ++i)
	{
		string name;
		int gook;
		int young;
		int soo;

		cin >> name >> gook >> young >> soo;

		Student temp(name, gook, young, soo);
		students.push_back(temp);
	}

	sort(students.begin(), students.end(), [](Student& a, Student& b)
		{
			return a.name < b.name;
		});

	stable_sort(students.begin(), students.end(), [](const Student& a, const Student& b)
		{
			return a.soo > b.soo;
		});

	stable_sort(students.begin(), students.end(), [](const Student& a, const Student& b)
		{
			return a.young < b.young;
		});

	stable_sort(students.begin(), students.end(), [](const Student& a, const Student& b)
		{
			return a.gook > b.gook;
		});

	for (Student& s : students)
	{
		cout << s.getName() << "\n";
	}
}