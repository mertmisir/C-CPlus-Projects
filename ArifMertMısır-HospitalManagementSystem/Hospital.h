#include"Admin.h"
class Employee;
class Team;
class Hospital{
private:
	Team* teamsHos[20];
	int TeamSizeHospital;
public:
	Hospital();
	void addTeamToHospital(Team&);
	void printTeamLeaderAndMembers();
	void printTeamLeaderAndMembersWithID(int);
	friend void Team::addTeamHospital(Hospital&);
	double calculateHospitalCost();
	double calculateHospitalCostWithID(int);
	void SearchMemberID(int);
};
