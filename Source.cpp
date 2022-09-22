#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <fstream>
using namespace std;


class ConcreteTask
{
public:
	ConcreteTask(){}
	virtual void info() = 0;
	virtual void input() = 0;
	virtual string get() = 0;
	virtual ~ConcreteTask() {}
};
class Priority
{
public:
	Priority(){}
	virtual void info() = 0;
	virtual void input() = 0;
	virtual int get() = 0;
	virtual ~Priority() {}
};
class Date
{
public:
	Date() {}
	virtual void info() = 0;
	virtual void input() = 0;
	virtual string get() = 0;
	virtual ~Date() {}
};
class Tag
{
public:
	Tag() {}
	virtual void info() = 0;
	virtual void input() = 0;
	virtual string get() = 0;
	virtual ~Tag() {}
};


class PersonConcreteTask: public ConcreteTask
{
	string task;
public:
	void input() override
	{
		cout << "Enter your task: ";
		getline(cin, task);
	}
	void info() override
	{
		cout << "Task: " << task << "\n";
	}
	string get() override { return task; }
};

class PersonPriority: public Priority
{
	int pr;
public:
	void input() override
	{
		cout << "Enter priority: ";
		cin>>pr;
		cin.ignore();
	}
	void info() override
	{
		cout << "Priority: " << pr << "\n";
	}
	int get() override { return pr; }
};
class PersonDate: public Date
{
	string date;
public:
	void input() override
	{
		cout << "Enter date: ";
		getline(cin,date);
	}
	void info() override
	{
		cout << "Date: " << date << "\n";
	}
	string get() override { return date; }
};
class PersonTag: public Tag
{
	string tag;
public:
	void input() override
	{
		cout << "Enter tag: ";
		getline(cin, tag);
	}
	void info() override
	{
		cout << "Tag: " << tag << "\n";
	}
	string get() override { return tag; }
};


class TaskFactory
{
public:
	virtual ConcreteTask* createTask() = 0;
	virtual Priority* createPriority() = 0;
	virtual Date* createDate() = 0;
	virtual Tag* createTag() = 0;
	virtual ~TaskFactory(){}
};

class PersonTaskFactory: public TaskFactory
{
public:
	ConcreteTask* createTask() override
	{
		PersonConcreteTask* PCT = new PersonConcreteTask;
		PCT->input();
		return PCT;
	}
	Priority* createPriority() override
	{
		PersonPriority* PP = new PersonPriority;
		PP->input();
		return PP;
	}
	Date* createDate() override
	{
		PersonDate* PD = new PersonDate;
		PD->input();
		return PD;;
	}
	Tag* createTag() override
	{
		PersonTag* PT = new PersonTag;
		PT->input();
		return PT;
	}
};

class Scheduler
{
public:
	vector<ConcreteTask*>CT;
	vector<Priority*>P;
	vector<Date*>D;
	vector<Tag*>T;
	~Scheduler()
	{
		for (int i = 0; i < CT.size(); i++)
		{
			delete CT[i];
		}
		for (int i = 0; i < P.size(); i++)
		{
			delete P[i];
		}
		for (int i = 0; i < D.size(); i++)
		{
			delete D[i];
		}
		for (int i = 0; i < T.size(); i++)
		{
			delete T[i];
		}
	}
	void displayTask()
	{
		int f = 0;
		cout << "____________________________\n";
		for (int i = 0; i < CT.size(); i++)
		{
			f = 1;
			CT[i]->info();
			P[i]->info();
			D[i]->info();
			T[i]->info();
			cout << "____________________________\n";
		}
		if (f == 0) { cout << "There are no created task!\n"; }
	}
	void deleteTask()
	{
		string del_deal;
		cout << "Enter task you want to delete: ";
		getline(cin, del_deal);
		int f = 0;
		for (int i = 0; i < CT.size(); i++)
		{
			if (del_deal == CT[i]->get());
			{
				f = 1;
				auto begin = CT.begin();
				CT.erase(begin + i);
			}
		}
		if (f == 0) { cout << "Entered task does not exist!\n"; }
		else { cout << "Selected task deleted.\n"; }
	}
	void changeTask()
	{
		string change_deal;
		cout << "Enter task you want to change: ";
		getline(cin, change_deal);
		int f = 0;
		for (int i = 0; i < CT.size(); i++)
		{
			if (change_deal == CT[i]->get())
			{
				f = 1;
				CT[i]->input();
				P[i]->input();
				D[i]->input();
				T[i]->input();
			}
		}
		if (f == 0) { cout << "Entered task does not exist!\n"; }
	}
	void searchDate()
	{
		string search_date;
		cout << "Enter the date of search task: ";
		getline(cin, search_date);
		int f = 0;
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i]->get()==search_date)
			{
				f = 1;
				CT[i]->info();
				P[i]->info();
				T[i]->info();
			}
		}
		if (f == 0) { cout << "Task no exist for entered date!\n"; }
	}
	void searchTag()
	{
		string search_tag;
		cout << "Enter the tag you are looking for: ";
		getline(cin, search_tag);
		int f = 0;
		for (int i = 0; i < T.size(); i++)
		{
			if (T[i]->get() == search_tag)
			{
				f = 1;
				CT[i]->info();
				P[i]->info();
				D[i]->info();
			}
		}
		if (f == 0) { cout << "Tasks no exist for entered priority!\n"; }
	}
	void searchPriority()
	{
		int search_priority;
		cout << "Enter the priority you are looking for: ";
		cin>>search_priority;
		int f = 0;
		for (int i = 0; i < P.size(); i++)
		{
			if (P[i]->get() == search_priority)
			{
				f = 1;
				CT[i]->info();
				D[i]->info();
				T[i]->info();
			}
		}
		if (f == 0) { cout << "Task no exist for entered tag!\n"; }
	}
	void saveToFile()
	{
		ofstream file("To do list.txt");
		if (file.is_open())
		{
			file << CT.size() << "\n";
			for (int i = 0; i < CT.size(); i++)
			{
				file <<"Task: "<< CT[i]->get() << "\n";
				file <<"Priority: " << P[i]->get() << "\n";
				file << "Date: " << D[i]->get() << "\n";
				file << "Tag: " << T[i]->get() << "\n";
			}
		}
		file.close();
	}
	void readFromFile()
	{
		int size_vector_CT1;
		vector <string> CT1(100);
		vector <string> P1(100);
		vector <string> D1(100);
		vector <string> T1(100);
		ifstream file("To do list.txt");
		if (file.is_open())
		{
			file >> size_vector_CT1;
			cout << "Count of concrete tasks: " << size_vector_CT1;
			for (auto i = 0; i <=size_vector_CT1; i++)
			{
				getline(file, CT1[i]);
				cout << CT1[i] << "\n";
				getline(file, P1[i]);
				cout << P1[i] << "\n";
				getline(file, D1[i]);
				cout << D1[i] << "\n";
				getline(file, T1[i]);
				cout << T1[i] << "\n";
			}
		}
		file.close();
	}
};

class Day
{
public:
	void createDeals(Scheduler* p, PersonTaskFactory& factory)
	{
		p->CT.push_back(factory.createTask());
		p->P.push_back(factory.createPriority());
		p->D.push_back(factory.createDate());
		p->T.push_back(factory.createTag());
	}
};

int main()
{
	Day day;
	Scheduler* sch = new Scheduler;
	PersonTaskFactory PTF;
	int key;
	do {
		system("cls");
		cout << "1 - Add task.\n";
		cout << "2 - Delete selected task.\n";
		cout << "3 - Change selected task.\n";
		cout << "4 - Save to-do list to file.\n";
		cout << "5 - Read to-do list from file.\n";
		cout << "6 - Search for date.\n";
		cout << "7 - Search for tag.\n";
		cout << "8 - Search for priority.\n";
		cout << "9 - Display all task.\n";
		cout << "Esc - Exit.\n";
		cout << "Your choice: ";
		cin >> key;
		cin.ignore();
		switch (key)
		{
		case 1:
		{
			system("cls");
			day.createDeals(sch, PTF);
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			sch->deleteTask();
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			sch->changeTask();
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			sch->saveToFile();
			cout << "Tasks list saved!\n";
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			sch->readFromFile();
			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			sch->searchDate();
			system("pause");
			break;
		}
		case 7:
		{
			system("cls");
			sch->searchTag();
			system("pause");
			break;
		}
		case 8:
		{
			system("cls");
			sch->searchPriority();
			system("pause");
			break;
		}
		case 9:
		{
			system("cls");
			sch->displayTask();
			system("pause");
			break;
		}
		}
	} while (key != 27);
}