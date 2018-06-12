#include <iostream>
#include <string>

#include "Enterprise.h"
#include "Employee.h"
#include "Status.h"

using namespace std;

class Menu
{
private:
	Enterprise *EnterpriseObj;
public:
	Menu(Enterprise);
	void infoEmployee();
	void rename();
	void payroll();
};

Menu::Menu(Enterprise EnterpriseObj)
{
	unsigned com;
	this->EnterpriseObj = &EnterpriseObj;
	while (1)
	{
		system("cls");
		cout << "             Компания " << EnterpriseObj.getName() << endl;
		cout.fill('=');
		cout.width(56);
		cout << "" << endl;
		cout << "День " << EnterpriseObj.getDay();
		if (EnterpriseObj.getDay() % 7 &&
			(EnterpriseObj.getDay() % 7 - 6) ||
			!EnterpriseObj.getDay())
			cout << " (Будни)" << endl;
		else
			cout << " (Выходные)" << endl;
		cout.width(56);
		cout << "" << endl;
		cout.fill(' ');
		EnterpriseObj.listEmployee();
		cout.fill('=');
		cout.width(56);
		cout << "" << endl;
		cout.fill(' ');
		cout << "Выберете действие: \n"
			<< "  1 > Информация о сотруднике\n"
			<< "  2 > Переименовать компанию\n"
			<< "  3 > Рассчитать зарплату\n"
			<< "  4 > Следующий день\n";
		cin >> com;
		cin.ignore();
		switch (com)
		{
		case 1:
			infoEmployee();
			break;
		case 2:
			rename();
			break;
		case 3:
			payroll();
			break;
		case 4:
			EnterpriseObj.nextDay();
			break;
		default:exit(0);
		}
	}
}

void Menu::infoEmployee() {
	unsigned num;
	unsigned com;
	Employee *EmployeeObj;
	cout << "Введите № сотрудника > ";
	cin >> num;
	cin.ignore();
	if (num <= EnterpriseObj->getSpace() && num > 0)
	{
		EmployeeObj = EnterpriseObj->getEmployee(num - 1);
		EmployeeObj->getInfo();
		cout << "Действие с сотрудником: \n"
			<< "  1 > Изменить данные\n"
			<< "  2 > Отправить в командировку\n"
			<< "  3 > Уволить\n";
		cin >> com;
		cin.ignore();
		switch (com)
		{
		case 1:
			EmployeeObj->setInfo();
			break;
		case 2:
			EmployeeObj->setStatus(new BussinessTrip());
			break;
		case 3:
			EmployeeObj->~Employee();
			EmployeeObj = nullptr;
			EnterpriseObj->deletePlace(num - 1);
			break;
		default: break;
		}
	}
}

void Menu::payroll() {
	unsigned wage;
	Employee *EmployeeObj;
	cout << "         Имя     Фамилия    Зарплата  " << endl;
	for (unsigned i = 0; i < EnterpriseObj->getSpace(); i++)
	{
		EmployeeObj = EnterpriseObj->getEmployee(i);
		if (EmployeeObj)
		{
			wage = EmployeeObj->getSalary() * EmployeeObj->getWorked() / EmployeeObj->getTimeWork();
			cout << setw(12) << EmployeeObj->getName()
				<< setw(12) << EmployeeObj->getSurname()
				<< setw(12) << wage << endl;
		}
	}
	cin.get();
}

void Menu::rename() {
	string name;
	cout << "Введите новое имя компании > ";
	getline(cin, name);
	EnterpriseObj->setName(name);
}

void main()
{	
	unsigned space;
	unsigned nDepartment;
	string name;

	cout.precision(2);
	cout.setf(ios::fixed);
	cout << "Добро пожаловать в систему учёта рабочего времени!\n\n";
	cout << "Заполните информацию о компании:\n\n"
		<< "Наименование > ";
	getline(cin, name);
	cout << "Число рабочих мест > ";
	cin >> space;
	cin.ignore();

	Enterprise EnterpriseObj(name, space);
	Menu MenuObj(EnterpriseObj);
}