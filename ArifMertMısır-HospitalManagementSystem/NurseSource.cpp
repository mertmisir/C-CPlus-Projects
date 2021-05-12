#include"Nurse.h"


Nurse::Nurse() {
	nurseType = General;
	nurseOverTimeHoursPerWeek = 0;
}

Nurse::Nurse(TypeNurse n, double s) {
	nurseType = n;
	this->nurseOverTimeHoursPerWeek = s;
}

void Nurse::setType(TypeNurse n) {
	nurseType = n;
}

TypeNurse Nurse::getType() { return this->nurseType; }

void Nurse::setNurseOverTimeHoursPerWeek(double h) {
	nurseOverTimeHoursPerWeek = h;
}

double Nurse::getNurseOverTimeHoursPerWeek() { return this->nurseOverTimeHoursPerWeek; }

double Nurse::nurseSalaryCalculate() {
	double total=0;
	if (this->nurseType == General)
		total = (this->getEmployeeSalary()) + (20 * nurseOverTimeHoursPerWeek * 52);
	if (this->nurseType == Midwife)
		total = (this->getEmployeeSalary()) + (30 * nurseOverTimeHoursPerWeek * 52);
	return total;
}