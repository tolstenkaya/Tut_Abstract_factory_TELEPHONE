#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

class Telephone_components
{
public:
	string color;
	string processor_chipset;
	int number_of_cores;
	int RAM;
	int built_in_memory;
	float screen_inch;
	float battery_capacity;
	virtual void input() = 0;
	virtual void info() = 0;
	virtual ~Telephone_components() {};
};
class AndroidTelephone: public Telephone_components
{
public:
	AndroidTelephone()
	{
		color="black";
		number_of_cores=8;
		RAM=12;
		built_in_memory =512;
		screen_inch=7.7;
		battery_capacity=4400;
	}
	void input() override
	{
		cout << "ANDROID\n";
		cout << "Enter color: ";
		cin>>this->color;
		cout << "Enter number of cores: ";
		cin >> this->number_of_cores;
		cout << "Enter RAM (GB): ";
		cin >> this->RAM;
		cout << "Enter built-in memory (GB): ";
		cin >> this->built_in_memory;
		cout << "Enter diagonal/inches: ";
		cin >> this->screen_inch;
		cout << "Enter battery capacity: ";
		cin >> this->battery_capacity;
	}
	void info() override
	{
		cout << "ANDROID\n";
		cout << "Color: " << this->color << "\n";
		cout << "Number of cores: " << this->number_of_cores << "\n";
		cout << "RAM (GB): " << this->RAM << "\n";
		cout << "Built-in memory (GB): " << this->built_in_memory << "\n";
		cout << "Diagonal/inches: " << this->screen_inch << "\n";
		cout << "Battery capacity: "<<this->battery_capacity<<"\n";
	}
};
class iPhoneTelephone: public Telephone_components
{
public:
	iPhoneTelephone()
	{
		color = "grey";
		number_of_cores=6;
		RAM=4;
		built_in_memory =256;
		screen_inch=6.1;
		battery_capacity=3110;
	}
	void input() override
	{
		cout << "iPhone\n";
		cout << "Enter color: ";
		cin>>this->color;
		cout << "Enter number of cores: ";
		cin >> this->number_of_cores;
		cout << "Enter RAM (GB): ";
		cin >> this->RAM;
		cout << "Enter built-in memory (GB): ";
		cin >> this->built_in_memory;
		cout << "Enter diagonal/inches: ";
		cin >> this->screen_inch;
		cout << "Enter battery capacity: ";
		cin >> this->battery_capacity;
	}
	void info() override
	{
		cout << "iPhone\n";
		cout << "Color: " << this->color << "\n";
		cout << "Number of cores: " << this->number_of_cores << "\n";
		cout << "RAM (GB): " << this->RAM << "\n";
		cout << "Built-in memory (GB): " << this->built_in_memory << "\n";
		cout << "Diagonal/inches: " << this->screen_inch << "\n";
		cout << "Battery capacity: " << this->battery_capacity << "\n";
	}
};

class TelephoneFactory
{
public:
	virtual Telephone_components* createTelephone() = 0;
	virtual ~TelephoneFactory() {}
};
class AndroidFactory: public TelephoneFactory
{
public:
	Telephone_components* createTelephone() override
	{
		return new AndroidTelephone;
	}
};
class iPhoneFactory: public TelephoneFactory
{
public:
	Telephone_components* createTelephone() override
	{
		return new iPhoneTelephone;
	}
};

class Telephone_array
{
public:
	vector<Telephone_components*> tc;
	void inputInfo()
	{
		for (int i = 0; i < tc.size(); i++)
		{
			tc[i]->input();
		}
	}
	void displayInfo()
	{
		for (int i = 0; i < tc.size(); i++)
		{
			tc[i]->info();
		}
	}
	~Telephone_array()
	{
		for (int i = 0; i < tc.size(); i++)
		{
			delete[] tc[i];
		}
	}
};

class Telephone_Fabric
{
public:
	Telephone_array* createArrTelephone(TelephoneFactory& factory)
	{
		Telephone_array* p = new Telephone_array;
		p->tc.push_back(factory.createTelephone());
		return p;
	}
};

int main()
{
	Telephone_Fabric TF;
	AndroidFactory tel1;
	iPhoneFactory tel2;
	Telephone_array* t1 = TF.createArrTelephone(tel1);
	Telephone_array* t2 = TF.createArrTelephone(tel2);
	char ch;
	int a = 0;
	int i = 0;
	do {
		system("cls");
		cout << "Create telephone.\n";
		cout << "1 - Android.\n";
		cout << "2 - iPhone.\n";
		cout << "3 - Display created Android.\n";
		cout << "4 - Display created iPhone.\n";
		cout << "Esc - Exit.\n";
		cout << "Your choice: ";
		ch = _getch();
		switch (ch)
		{
		case '1':
		{
			system("cls");
			a = 0;
			char key;
			cout << "1 - Default options.\n";
			cout << "2 - Enter your own parametrs.\n";
			cout << "Your choice: ";
			key = _getch();
			if (key == '1') { system("cls"); t1->displayInfo(); a = 1; }
			if (key == '2') { system("cls"); t1->inputInfo(); a = 1; }
			system("pause");
			break;
		}
		case '2':
		{
			system("cls");
			i = 0;
			char key;
			cout << "1 - Default options.\n";
			cout << "2 - Enter your own parametrs.\n";
			cout << "Your choice: ";
			key = _getch();
			if (key == '1') { system("cls"); t2->displayInfo(); i = 1; }
			if (key == '2') { system("cls"); t2->inputInfo(); i = 1; }
			system("pause");
			break;
		}
		case '3':
		{
			system("cls");
			if (a == 1)
			{
				t1->displayInfo();
			}
			else
			{
				cout << "Android not created.\n";
			}
			system("pause");
			break;
		}
		case '4':
		{
			system("cls");
			if (i == 1)
			{
				t2->displayInfo();
			}
			else
			{
				cout << "iPhone not created.\n";
			}
			system("pause");
			break;
		}
		}
	} while (ch != 27);
}