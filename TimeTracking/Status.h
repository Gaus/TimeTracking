#ifndef STATUS_H
#define STATUS_H

#include <string>
#include <ctime>

#include "Employee.h"

using namespace std;

class Status
{
protected:
	string name;
	int probability;
public:
	virtual string getName();
	virtual void change(Employee*) = 0;
};

class Working : public Status
{
public:
	Working() {
		name = "Работает";
	}
	void change(Employee*);
};

class BussinessTrip : public Status
{
private:
	unsigned travelDay;
public:
	BussinessTrip();
	unsigned changeTravelDay();
	void change(Employee*);
};

class Absence : public Status
{
public:
	Absence() {
		name = "Неявка";
	}
	void change(Employee*);
};

class Holiday : public Status
{
public:
	Holiday() {
		name = "Отпуск";
	}
	void change(Employee*);
};

class Sick : public Status
{
public:
	Sick() {
		name = "Больничный";
	}
	void change(Employee*);
};

string Status::getName() {
	return name;
}

void Working::change(Employee *EmployeeObj) {
	srand(time(0));
	probability = rand() % 100;
	if (!probability)
		EmployeeObj->setStatus(new Absence);
	if (probability > 0 && probability < 4)
		EmployeeObj->setStatus(new Holiday);
	if (probability > 3 && probability < 10)
		EmployeeObj->setStatus(new Sick);
}

BussinessTrip::BussinessTrip()
{
	name = "Командировка";
	cout << "Длительность командировки (рабочие дни) > ";
	cin >> travelDay;
	travelDay++;
}

unsigned BussinessTrip::changeTravelDay() {
	travelDay--;
	return travelDay;
}

void BussinessTrip::change(Employee *EmployeeObj) {
	srand(time(0));
	probability = rand() % 100;
	if (probability > 3 && probability < 10)
		EmployeeObj->setStatus(new Sick);
}

void Absence::change(Employee *EmployeeObj) {
	srand(time(0));
	probability = rand() % 2;
	if (!probability)
		EmployeeObj->setStatus(new Working);
}

void Holiday::change(Employee *EmployeeObj) {
	srand(time(0));
	probability = rand() % 8;
	if (!probability)
		EmployeeObj->setStatus(new Working);
}

void Sick::change(Employee *EmployeeObj) {
	srand(time(0));
	probability = rand() % 5;
	if (!probability)
		EmployeeObj->setStatus(new Working);
}
#endif