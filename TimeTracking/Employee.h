#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

#include "Enterprise.h"

using namespace std;
class Status;

class Employee
{
private:
	unsigned num;
	unsigned salary;
	unsigned timeWork; //Заданное время в месяц
	double worked; //Количество отработанного времени
	string name;
	string surname;
	string post;
	Status *type;
public:
	Employee();
	~Employee();
	unsigned getNum();
	unsigned getSalary();
	unsigned getTimeWork();
	double getWorked();
	string getName();
	string getSurname();
	Status *getStatus();
	void getInfo();

	void setNum(unsigned);
	void setWorked(unsigned);
	void setStatus(Status *);
	void setInfo();
};

Employee::Employee()
{
	cout << "В компании появился новый сотрудник!" << endl;
	setInfo();
	worked = 0;
}

Employee::~Employee()
{
	delete type;
	cout << "Сотрудник уволен!" << endl;	
	cin.get();
}

unsigned Employee::getNum() {
	return num;
}

unsigned Employee::getSalary() {
	return salary;
}

unsigned Employee::getTimeWork() {
	return timeWork;
}

double Employee::getWorked() {
	return worked;
}

string Employee::getName() {
	return name;
}

string Employee::getSurname() {
	return surname;
}

Status *Employee::getStatus() {
	return type;
}

void Employee::getInfo() {
	cout << "  Имя: " << name << endl;
	cout << "  Фамилия: " << surname << endl;
	cout << "  Должность: " << post << endl;
	cout << "  Оклад (в рублях): " << salary << endl;
	cout << "  Рабочее время за месяц (в часах): " << timeWork << endl;
}

void Employee::setNum(unsigned num) {
	this->num = num;
}

void Employee::setWorked(unsigned arg) {
	if (arg)
	{
		srand(time(0) + arg);

		double s;
		double x;
		double y;
		do
		{
			x = (rand() % 101 - 50) / 50.0;
			y = (rand() % 101 - 50) / 50.0;
			s = x*x + y*y;
			x = x * sqrt(-2 * log(s) / s);
		} while (s > 1 || s == 0);
		worked += x * 1.3 + 8;
	}
	else
		worked = 0;
}

void Employee::setStatus(Status *type) {
	this->type = type;
}

void Employee::setInfo() {
	cout << "  Имя > ";
	getline(cin, name);
	cout << "  Фамилия > ";
	getline(cin, surname);
	cout << "  Должность > ";
	getline(cin, post);
	cout << "  Оклад (в рублях) > ";
	cin >> salary;
	cout << "  Рабочее время за месяц (в часах) > ";
	cin >> timeWork;
}
#endif