#include"Hospital.h"
#include<string>
#include <iostream>

std::istream& operator>>(std::istream& is, Title& type)
{
    int a;
    is >> a;
    type = static_cast<Title>(a);

    return is;
}
using namespace std;
int main()
{

        Hospital hos1;
        Employee e1;
        Title ty1;
        int option;
        int id_team;
        Team t1;
        int emID;
        char* emName = new char[25];
        char* emLastName = new char[25];
        int emTelehone;
        char* emAddress = new char[25];
        char* emMail = new char[25];
        int emannualSalary;
        char answer='Y';
        Employee e2;
        int ty;
        Doctor d1;
        Admin a1;
        Nurse n1;
        int choice;
        int ids;


        do {
        cout << "-------Welcome to the Hospital Management System---------" << endl;
        cout << "\n1. Create a team\n" <<"2. Search a member by ID\n" << "3. List all members\n" << "4. List total annual salary\n" << "5. List all members of a given team\n" << "6. List total annual salary of a given team\n" << "7. Exit\n" << endl;
        cout << " Enter your selection :";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter Team ID:" << endl;
            cin >> id_team;
            t1.setTeamID(id_team);
            cout << "Enter the details of the team leader:" << endl;
            cout << "ID:";
            cin >> emID;
            cout << "First Name:";
            cin >> emName;
            cout << "Last name:";
            cin >> emLastName;
            cout << "Telephone number:";
            cin >> emTelehone;
            cout << "Address:";
            cin >> emAddress;
            cout << "Email:";
            cin >> emMail;
            cout << "Salary:";
            cin >> emannualSalary;
            cout << "Doctor Type: (3) SPECIALIST (4) DOCENT (5) PROFESSOR" << endl;
            cin >> ty1;
            e1.setEmployeeID(emID);
            e1.setEmployeeAddress(emAddress);
            e1.setEmployeeLastName(emLastName);
            e1.setEmployeeMail(emMail);
            e1.setEmployeeName(emName);
            e1.setEmployeeSalary(emannualSalary);
            e1.setEmployeePhone(emTelehone);
            t1.setTeamLeader(e1);
            t1.addNewTeamMember(e1);
            cout << "The team leader has been added to the team successfully!" << endl;
            cout << "Would you like to add a new member to your team(Y / N)";
            cin >> answer;
            cout << "1. Doctor" << endl;
            cout << "2. Nurse" << endl;
            cout << "3. Admin" << endl;
            cin >> choice;
            while (answer == 'Y') {
                if (choice == 1) {
                    cout << endl;
                    cout << "ID:";
                    cin >> emID;
                    cout << "First Name:";
                    cin >> emName;
                    cout << "Last name:";
                    cin >> emLastName;
                    cout << "Telephone number:";
                    cin >> emTelehone;
                    cout << "Address:";
                    cin >> emAddress;
                    cout << "Email:";
                    cin >> emMail;
                    cout << "Salary:";
                    cin >> emannualSalary;
                    d1.setEmployeeID(emID);
                    d1.setEmployeeAddress(emAddress);
                    d1.setEmployeeLastName(emLastName);
                    d1.setEmployeeMail(emMail);
                    d1.setEmployeeName(emName);
                    d1.setEmployeeSalary(emannualSalary);
                    d1.setEmployeePhone(emTelehone);
                    t1.addNewTeamMember(d1);
                }
                else if (choice == 2) {
                    cout << endl;
                    cout << "ID:";
                    cin >> emID;
                    cout << "First Name:";
                    cin >> emName;
                    cout << "Last name:";
                    cin >> emLastName;
                    cout << "Telephone number:";
                    cin >> emTelehone;
                    cout << "Address:";
                    cin >> emAddress;
                    cout << "Email:";
                    cin >> emMail;
                    cout << "Salary:";
                    cin >> emannualSalary;
                    n1.setEmployeeID(emID);
                    n1.setEmployeeAddress(emAddress);
                    n1.setEmployeeLastName(emLastName);
                    n1.setEmployeeMail(emMail);
                    n1.setEmployeeName(emName);
                    n1.setEmployeeSalary(emannualSalary);
                    n1.setEmployeePhone(emTelehone);
                    t1.addNewTeamMember(n1);
                }
                else if (choice == 3) {
                    cout << endl;
                    cout << "ID:";
                    cin >> emID;
                    cout << "First Name:";
                    cin >> emName;
                    cout << "Last name:";
                    cin >> emLastName;
                    cout << "Telephone number:";
                    cin >> emTelehone;
                    cout << "Address:";
                    cin >> emAddress;
                    cout << "Email:";
                    cin >> emMail;
                    cout << "Salary:";
                    cin >> emannualSalary;
                    a1.setEmployeeID(emID);
                    a1.setEmployeeAddress(emAddress);
                    a1.setEmployeeLastName(emLastName);
                    a1.setEmployeeMail(emMail);
                    a1.setEmployeeName(emName);
                    a1.setEmployeeSalary(emannualSalary);
                    a1.setEmployeePhone(emTelehone);
                    t1.addNewTeamMember(a1);
                }
                else cout << "Wrong choice !!!";
                cout << "Would you like to add a new member to your team(Y / N)";
                cin >> answer;
            }
            hos1.addTeamToHospital(t1);
            cout << "The team member has been added to the team successfully!" << endl;
            break;
        
        case 2:
            cout << "Enter member ID: ";
            cin >> ids;
            hos1.SearchMemberID(ids);
           // t1.searchEmployeeInTeam(ids);
        break;

        case 3:
            //t1.listTeam();
            hos1.printTeamLeaderAndMembers();
            
        break;
           
        case 4:
            //t1.calculateTeamSalary();
            cout<<hos1.calculateHospitalCost();
        break;

        case 5:
            //t1.listTeam();
            int s;
            cout << "Enter Team ID :";
            cin >> s;
            hos1.printTeamLeaderAndMembersWithID(s);
        break;

        case 6:
            //t1.calculateTeamSalary();
            int f;
            cout << "Enter Team ID :";
            cin >> f;
            cout<<hos1.calculateHospitalCostWithID(f);
        break;
        case 7:
        cout << "Goodbye!" << endl;
        break;
        }

        }

        while (option != 7); 

    return 0;

}

