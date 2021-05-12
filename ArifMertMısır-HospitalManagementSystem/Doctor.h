#include"Employee.h"

class Doctor :public Employee {
private:
	Title eTitle;
public:
	Doctor();
	Doctor(Title);
	Title getTitle();
	void setTitle(Title);
};
