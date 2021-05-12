#include"Nurse.h"

class Admin :public Employee {
private:
	TypeAdmin adminType;
	double adminHoursPerWeek;
public:
	Admin();
	Admin(TypeAdmin, double);
	TypeAdmin getAdminType();
	void setAdminType(TypeAdmin);
	double getAdminHoursPerWeek();
	void setAdminHoursPerWeek(double);
	double adminSalaryCalculate();
};

