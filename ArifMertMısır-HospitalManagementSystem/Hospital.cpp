#include"Hospital.h"


Hospital::Hospital() {
	this->TeamSizeHospital = 0;
}


void Hospital::addTeamToHospital(Team& t1) {
	this->teamsHos[this->TeamSizeHospital] = &t1;
	TeamSizeHospital++;
}

void Hospital::printTeamLeaderAndMembers() {
	
	for (int i = 0;i < TeamSizeHospital;i++) {
		cout << "Team Leader is :";
		this->teamsHos[i]->getTeamLeader().printEmployeeDetails();
		cout << endl; 
		cout << endl;
		this->teamsHos[i]->listTeam();
	}
	//return *(this->teamsHos[this->TeamSizeHospital]); //deneme
}

void Hospital::printTeamLeaderAndMembersWithID(int id) {

	for (int i = 0;i < TeamSizeHospital;i++) {
		if (id == this->teamsHos[i]->getTeamID()); {
			cout << "Team Leader is :";
			this->teamsHos[i]->getTeamLeader().printEmployeeDetails();
			cout << endl;
			cout << endl;
			this->teamsHos[i]->listTeam();
		}
	}
	
}

double Hospital::calculateHospitalCost() {
	double totalC=0;
		for (int i = 0;i < TeamSizeHospital;i++) {
			totalC+= this->teamsHos[i]->calculateTeamSalary();
		}
		return totalC;
}

double Hospital::calculateHospitalCostWithID(int id) {
	double totalCH = 0;
	for (int i = 0;i < TeamSizeHospital;i++) {
		if (id == this->teamsHos[i]->getTeamID()); {
			totalCH = this->teamsHos[i]->calculateTeamSalary();
		}
	}
	return totalCH;
}

void Hospital::SearchMemberID(int idd) {
	for (int i = 0;i < TeamSizeHospital;i++) {
		if (idd == this->teamsHos[i]->getMember(i).getEmployeeID()) {
			cout << "It is found in team " << i << "The details are listed below";
			this->teamsHos[i]->getMember(i).printEmployeeDetails();
		}
	}
}