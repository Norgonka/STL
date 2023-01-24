#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Person
{
public:

	Person(string name, double score)
	{
		this->Name = name;
		this->Score = score;
	}
	
	bool operator () (const Person& p)
	{
		return p.Score > 180;
	}

	string Name;
	int Score;
};

void SortPeopleByName(vector<Person> people)
{

	sort(people.begin(), people.end(), [](Person& p1, Person& p2)
	{
			return p1.Name < p2.Name;
	});

	for (auto element : people)
	{
		cout << "Name:\t" << element.Name << "\tScore:\t" << element.Score << endl;
	}
}

vector<Person> ReturnPassedStudents(vector<Person> people)
{
	vector<Person> passedStudents;
	copy_if(people.begin(), people.end(), back_inserter(passedStudents), people.front());
	return passedStudents;
}

void ShowPassedStudents(vector<Person> people)
{

	auto result = find_if(people.begin(), people.end(), people.front());

	if (result == people.end())
	{
		cout << "Noone passed" << endl;
	}
	else
	{
		cout << "List of students that passed:" << endl;

		for (auto it : ReturnPassedStudents(people))
		{
			cout << it.Name << endl;
		}
	}
}

int main()
{
	vector<Person> people
	{	Person("Peter", 200),
		Person("Marry", 181),
		Person("John", 145),
		Person("Glenn", 181),
		Person("Martin", 122),
		Person("Linda", 169),
		Person("Victor", 193),
		Person("Stan", 184),
		Person("Bruce", 199),
		Person("Sydney", 179)
	};

	SortPeopleByName(people);
	cout << "===========================================================" << endl;

	cout << "Count of students that passed:\t" << count_if(people.begin(), people.end(), people.front()) << endl;

	ShowPassedStudents(people);
}