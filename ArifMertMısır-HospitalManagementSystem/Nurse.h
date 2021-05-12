#include"Doctor.h"

class Nurse :public Employee {
private:
	TypeNurse nurseType;
	double nurseOverTimeHoursPerWeek;
public:
	Nurse();
	Nurse(TypeNurse, double);
	TypeNurse getType();
	void setType(TypeNurse);
	double getNurseOverTimeHoursPerWeek();
	void setNurseOverTimeHoursPerWeek(double);
	double nurseSalaryCalculate();
};
