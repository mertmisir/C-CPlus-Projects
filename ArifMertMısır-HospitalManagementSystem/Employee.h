#include<iostream>

using namespace std;
class Hospital;
enum Title{Intern, Practitioner, Assistant, Specialist, Docent, Professor};
enum TypeNurse{General, Midwife};
enum TypeAdmin{Manager,Secretary};

class Team;

class Employee {
private:
	int employeeID;
	char* eName;
	char* eLastName;
	int eTelehone;
	char* eAddress;
	char* eMail;
	int annualSalary;
public:
	Employee();
	Employee(int,int,int, char*, char*, char*,char*);
	int getEmployeeID();
	void setEmployeeID(int);
	char* getEmployeeName();
	void setEmployeeName(char*);
	char* getEmployeeLastName();
	void setEmployeeLastName(char*);
	int getEmployeePhone();
	void setEmployeePhone(int);
	char* getEmployeeMail();
	void setEmployeeMail(char*);
	int getEmployeeSalary();
	void setEmployeeSalary(int);
	char* getEmployeeAddress();
	void setEmployeeAddress(char*);
	void printEmployeeDetails();
	void addTo(Team&); //to use employee in team class
	void operator=(Employee&);
	Employee(Employee&); //copy constructor
	~Employee();
};

class Team {
private:
	int teamID;
	Employee teamLeader;
	Employee teamMember;
	Employee* teams[25];
	int size;
public:
	Team();
	Team(int);
	Employee getTeamLeader();
	void setTeamLeader(Employee&);
	int getTeamID();
	void setTeamID(int);
	Team(Team&);
	int getSize();
	void addNewTeamMember(Employee&);
	friend void Employee::addTo(Team&);  //used friend to get acces to employee private without corrupting encapsulation
	Employee getMember(int);
	void operator=(Team&);
	void listTeam();
	void addTeamHospital(Hospital&);
	double calculateTeamSalary();
	void searchEmployeeInTeam(int);
};




