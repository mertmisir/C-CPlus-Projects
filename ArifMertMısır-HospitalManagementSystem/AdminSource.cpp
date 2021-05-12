#include"Admin.h"


Admin::Admin() {
	adminType = Secretary;
	adminHoursPerWeek = 0;
}

Admin::Admin(TypeAdmin t,double p) {
	adminType = t;
	adminHoursPerWeek = p;
}

void Admin::setAdminType(TypeAdmin t) { this->adminType = t; }
TypeAdmin Admin::getAdminType() { return this->adminType; }

void Admin::setAdminHoursPerWeek(double t) { this->adminHoursPerWeek = t; }
double Admin::getAdminHoursPerWeek() { return this->adminHoursPerWeek; }

double Admin::adminSalaryCalculate() {
	double total = 0;
	if (this->adminType == Manager)
		total = (this->getEmployeeSalary()) + (50 * this->adminHoursPerWeek * 52);
	if (this->adminType == Secretary)
		total = (this->getEmployeeSalary()) + (20 * this->adminHoursPerWeek * 52);
	return total;
}