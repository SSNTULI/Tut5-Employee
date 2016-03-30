#include<iostream>
#include<string>

using namespace std;

class EMPLOYEE
{
protected:
	string name;
	int staffNumber;
	int static numberOfEmployees;
public:
	EMPLOYEE();
	EMPLOYEE(string, int);
	virtual float salary();
	int getNumberOfEmployees();
	~EMPLOYEE();
};
//definitions of class EMPLOYEE

int EMPLOYEE::numberOfEmployees = 0;
EMPLOYEE::EMPLOYEE()
{

}
EMPLOYEE::EMPLOYEE(string s, int n)
{
	name = s;
	staffNumber = n;
	numberOfEmployees++;
}
float EMPLOYEE::salary()
{
	return (0.0);
}
int EMPLOYEE::getNumberOfEmployees()
{
	return(numberOfEmployees);
}
EMPLOYEE::~EMPLOYEE()
{
	numberOfEmployees--;
}

/**************************************************************/
//DERIVED CLASS 1 SALARYEMPLOYEE

class SalaryEmployee :public EMPLOYEE
{
	float payment;
public:
	SalaryEmployee(string, int);
	void setSalary(float);
	float salary();
	~SalaryEmployee();
};

// DEFINITION OF CLASS SALARYEMPLOYEE
SalaryEmployee::SalaryEmployee(string d, int i)
{
	name = d;
	staffNumber = i;
	numberOfEmployees++;

}
void SalaryEmployee::setSalary(float s)
{
	if (s < 0)
		cout << "The salary entered is invalid" << endl;
	else
		payment = s;
}
float SalaryEmployee::salary()
{
	return (payment);
}
SalaryEmployee::~SalaryEmployee()
{
	numberOfEmployees--;

}


/************************************************************/
//DERIVED CLASS 2
class HourlyEmployee :public EMPLOYEE
{
	float hourlyRate;
	int hours;
public:
	HourlyEmployee(string, int);
	void setHourRate(float);
	void setHourWorked(int);
	float salary();
	~HourlyEmployee();
};
// DEFINITION OF HOUR WORKED
HourlyEmployee::HourlyEmployee(string nam, int num)
{
	name = nam;
	staffNumber = num;
	numberOfEmployees++;

}
void HourlyEmployee::setHourRate(float m)
{
	if (m < 0)
		cout << "invalid entry of rate" << endl;
	else
		hourlyRate = m;
}
void HourlyEmployee::setHourWorked(int h)
{
	hours = h;
}
float HourlyEmployee::salary()
{
	return(hours*hourlyRate);
}
HourlyEmployee::~HourlyEmployee()
{
	numberOfEmployees--;

}
/**************************************************************/
//DERIVED CLASS 3 COMMISSIONEM[PLOYEE
class CommissionEmployee :public EMPLOYEE
{
	float BaseSalary;
	float Rate;
	float revenueperc;
public:
	CommissionEmployee(string, int);
	void setBaseSalary(float);
	void setRate(float);
	void setRevenue(float);
	float salary();
	~CommissionEmployee();
};
//	DEFINITION OF CLASS COMMISSIONEMPLOYEE
CommissionEmployee::CommissionEmployee(string na, int nu)
{
	name = na;
	staffNumber = nu;
	numberOfEmployees++;

}

//added a comment
void CommissionEmployee::setBaseSalary(float b)
{
	if (b < 0)
		cout << "invalid base salary" << endl;
	else
		BaseSalary = b;
}
void CommissionEmployee::setRate(float r)
{
	if (r < 0)
		cout << "invalid entry of rate" << endl;
	else
		Rate = r;
}
void CommissionEmployee::setRevenue(float rev)
{
	if (rev < 0)
		cout << "invalid entry of revenue percentage" << endl;
	else
		revenueperc = rev;
	revenueperc = Rate*BaseSalary;
}
float CommissionEmployee::salary()
{
	return(BaseSalary + revenueperc);
}
CommissionEmployee::~CommissionEmployee()
{
	numberOfEmployees--;

}
/**************************************************************/
//main testing function

void main()
{
	float total_salary = 0.0;
	EMPLOYEE *employee;
	CommissionEmployee E1("MSHANA", 21353);
	HourlyEmployee E2("NTULI", 25467);
	SalaryEmployee E3("NSUNDWANE", 21456);
	cout << E3.getNumberOfEmployees() << endl;
	E1.setBaseSalary(5000);
	E1.setRate(0.3);
	E1.setRevenue(0.6);
	E2.setHourRate(0.4);
	E2.setHourWorked(8);
	E3.setSalary(6000);
	employee = &E1;
	total_salary += employee->salary();
	employee = &E2;
	total_salary += employee->salary();
	employee = &E3;
	total_salary += employee->salary();
	cout << "R" << total_salary << endl;
	system("pause");
}