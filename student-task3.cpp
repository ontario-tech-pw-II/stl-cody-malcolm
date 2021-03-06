// Student class is implemented based on string and do not need any change

#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

// ----------------------------- Base class

class Person{
	protected:
		string name;

	public:
		void setname(char const *);
		string getname();


		Person(); 				// default constructor
		Person(const char *);
		Person(const Person &); 		// copy constructor

		Person(const string &);

		virtual ~Person();

};

void Person::setname(char const *n)
{
	name = n;
}

string Person::getname()
{
	return name;
}


Person::Person()
{
	name = "";
}

Person::Person(char const *n)
{
	setname(n);
}

Person::Person(const string & n)
{
	name = n;
}

Person::~Person()
{
}

Person::Person(const Person &t):name(t.name)
{
}

// -----------------------------  Student class

class Student : public Person{
	private:
		double grade;

	public:

      	void setgrade(double);
      	double getgrade();

      	Student();    // default constructor
		Student(char const *, double);
		Student(const Student &);  // copy constructor

		~Student();

	friend ostream & operator<<(ostream &, const Student &);

};

void Student::setgrade(double g)
{
	grade =g;
}

double Student::getgrade()
{
	return grade;
}

ostream & operator<<(ostream & out, const Student & s)
{
		out << s.name << "," << s.grade;
		return out;

}

Student::Student(): grade(0)
{
}

Student::Student(char const *n, double g): Person(n)
{
	setgrade(g);
}

Student::Student(const Student &t):Person(t.name)
{
	grade = t.grade;
}

Student::~Student()
{
}

int main()
{

	map<string, int> m;
  map<string, int>::iterator i;

	// Write your code for Task 3
	ifstream fin("students2.txt");

	if (fin.fail()) {
		cerr << "Unable to open the file." << endl;
		return 1;
	}

	char* name = new char[20];
	double grade;

	while(fin>>name) {
		fin >> grade;

    if (m.find(name) == m.end()) {
      m[name] = 0;
    }

		if (grade < 50) {
      m[name]++;
    }

		delete name;
	}

	fin.close();

	for (i = m.begin(); i != m.end(); ++i) {
		cout << i->first << " " << i->second << endl;
	}

}
