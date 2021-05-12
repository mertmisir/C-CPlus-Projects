#include"Employee.h"

Employee::Employee() {
	this->employeeID = 0;
	this->eTelehone = 0000;
	this->annualSalary = 0;
	this->eName = new char[25];
	this->eLastName = new char[25];
	this->eAddress = new char[25];
	this->eMail = new char[25];
	strcpy(this->eName, "Undefined");
	strcpy(this->eLastName, "Undefined");
	strcpy(this->eAddress, "Undefined");
	strcpy(this->eMail, "Undefined");
}

Employee::Employee(int id,int phone,int salary, char* name, char* lname, char* adres, char* mail) {
	this->employeeID = id;
	this->eTelehone = phone;
	this->annualSalary = salary;
	this->eName = new char[25];
	this->eLastName = new char[25];
	this->eAddress = new char[25];
	this->eMail = new char[25];
	strcpy(this->eName,name);
	strcpy(this->eLastName, lname);
	strcpy(this->eAddress, adres);
	strcpy(this->eMail, mail);
}

Employee::Employee(Employee& e) {
	this->employeeID = e.employeeID;
	this->eTelehone = e.eTelehone;
	this->annualSalary = e.annualSalary;
	this->eName = new char[25];
	this->eLastName = new char[25];
	this->eAddress = new char[25];
	this->eMail = new char[25];
	strcpy(this->eName, e.eName);
	strcpy(this->eLastName, e.eLastName);
	strcpy(this->eAddress, e.eAddress);
	strcpy(this->eMail, e.eMail);
}
void Employee::setEmployeeID(int id) { this->employeeID = id; }
int Employee::getEmployeeID() { return this->employeeID; }

void Employee::setEmployeePhone(int phone) { this->eTelehone = phone; }
int Employee::getEmployeePhone() { return this->eTelehone; }

void Employee::setEmployeeSalary(int salary) { this->annualSalary= salary; }
int Employee::getEmployeeSalary() { return this->annualSalary; }

void Employee::setEmployeeName(char* name) {strcpy(this->eName, name);}
char* Employee::getEmployeeName() { return this->eName; }

void Employee::setEmployeeLastName(char* lname) { strcpy(this->eLastName, lname);}
char* Employee::getEmployeeLastName() { return this->eLastName; }

void Employee::setEmployeeAddress(char* adres) {strcpy(this->eAddress, adres);}
char* Employee::getEmployeeAddress() { return this->eAddress; }

void Employee::setEmployeeMail(char* mail) {strcpy(this->eMail, mail);}
char* Employee::getEmployeeMail() { return this->eMail; }

void Employee::operator=(Employee& e) {
	this->employeeID = e.employeeID;
	this->eTelehone = e.eTelehone;
	this->annualSalary = e.annualSalary;
	strcpy(this->eName, e.eName);
	strcpy(this->eLastName, e.eLastName);
	strcpy(this->eAddress, e.eAddress);
	strcpy(this->eMail, e.eMail);
}

Employee::~Employee() {
	delete[] eName;
	delete[] eLastName;
	delete[] eAddress;
	delete[] eMail;
}

void Employee::printEmployeeDetails() {
	cout << "Employee ID : " << this->employeeID << endl;
	cout << "Name: " << this->eName << endl;
	cout << "Last Name: " << this->eLastName << endl;
	cout << "Address : " << this->eAddress << endl;
	cout << "Phone Number : " << this->eTelehone << endl;
	cout << "E-mail : " << this->eMail << endl;
	cout << "Annual Salary : " << this->annualSalary << endl;
}

void Employee::addTo(Team& a) {
	a.teams[a.size] = this;
}
////////////////////////////////////////////////////////////////////////////////////////////////////

Team::Team() {
	size = 0;
	teamID = 0;
	//teamLeader = Specialist;
	//teamMember = Practitioner;
	//this->teams = new Employee[25];
}

Team::Team(int a) {
	this->size = 0;
	teamID = a;
}


void Team::setTeamLeader(Employee& c) { 
	teamLeader = c;
	/*teamLeader.setEmployeeID(c.getEmployeeID());
	teamLeader.setEmployeeName(c.getEmployeeName());*/
 }

Employee Team::getTeamLeader() { 
	return teamLeader;
}

void Team::setTeamID(int t) { teamID = t; }
int Team::getTeamID() { return teamID; }

void Team::addNewTeamMember(Employee& e) {
	this->teams[this->size] = &e;
	size++;
}

Team::Team(Team& t) {
	this->size = t.size;
	teamID = t.teamID;
	teamLeader = t.teamLeader;
	teamMember = t.teamMember;
	for (int i = 0; i < this->size; i++)
	{
		this->teams[i] = t.teams[i];
	}

}

void Team::listTeam() {
	cout << "Team leader is : " << teamLeader.getEmployeeName() << endl;
	for (int i = 0; i < this->size; i++)
	{
		cout << this->teams[i]->getEmployeeName() << endl;
	}
}

int Team::getSize() { return size; }

Employee Team::getMember(int s) {
	return *(this->teams[s]);
}

double Team::calculateTeamSalary() {
	double total=0;
	for (int i = 0; i < this->size; i++)
	{
		total += (this->teams[i]->getEmployeeSalary());
	}
	return total;
}

void Team::searchEmployeeInTeam(int idd) {

	for (int i = 0;i < this->getSize();i++) {
		if (this->teams[i]->getEmployeeID() == idd)
		{
			/*cout << "Employee ID : " << this->teams[i]->getEmployeeID() << endl;
			cout << "Name: " << this->teams[i]->getEmployeeName() << endl;
			cout << "Last Name: " << this->teams[i]->getEmployeeLastName << endl;
			cout << "Address : " << this->teams[i]->getEmployeeAddress << endl;
			cout << "Phone Number : " << this->teams[i]->getEmployeePhone << endl;
			cout << "E-mail : " << this->teams[i]->getEmployeeMail << endl;
			cout << "Annual Salary : " << this->teams[i]->getEmployeeSalary << endl;*/
			return this->teams[i]->printEmployeeDetails();
		}
	}
	cout << "Employee cant be found !" << endl;

}

void Team::operator=(Team& t1) { //in order to make setTeamleader i used this operator overloading
	this->size = t1.size;
	this->teamID = t1.teamID;
	this->teamLeader = t1.teamLeader;
	this->teamMember = t1.teamMember;
	this->teams[size] = t1.teams[size];
}

void Team::addTeamHospital(Hospital& h) {

}