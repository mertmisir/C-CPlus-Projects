#include<iostream>
using namespace std;

class Resources{
private:
	int resourceSize;
	char resourceType;
	int checkFlag;
public:
	Resources();
	void setResourceSize(int);
	void setResourceType(char);
	void setCheckFlag(int);
	int getResourceSize();
	char getResourceType();
	int getCheckFlag();
	Resources(Resources&);
	void operator=(Resources&);
};

class Archeologist {
private:
	Resources listOfGatheredResources[65];
	int sizeOfGatheredResources;
	int sizeOfGatheredFood;
	double playerEnegy;
	double totalScore;
	int diceValue;
public:
	Archeologist();
	void setSizeOfGatheredResources(int);
	int getSizeOfGatheredResources();
	void setsizeOfGatheredFood(int);
	int getsizeOfGatheredFood();
	void setPlayerEnegery(double);
	double getPlayerEnergy();
	void setTotalScore(double);
	double getTotalScore();
	Resources getListOfGatheredResources(int i);
	void setListOfGatheredResources(Resources&);
	Archeologist(Archeologist&);
	void setDiceValue(int);
	int getDiceValue();
};


class FullBodyBone:  public Resources{
public:
	FullBodyBone() {
		int score = 100;
		this->setResourceType('F');
	}
	//char getType() { return resourceType; }
};
class SkullBone : public Resources {
public:
	SkullBone() {
		int score = 50;
		this->setResourceType('S');
	}
	//char getType() { return resourceType; }
};
class OrdinaryBone : public Resources {
public:
	OrdinaryBone() {
		int score = 20;
		this->setResourceType('O');
	}
	//char getType() { return resourceType; }
};
class BurgerFood : public Resources {
public:
	BurgerFood() {
		int score = 4;
		this->setResourceType('B');
	}
	//char getType() { return resourceType; }
};
class NuggetFood : public Resources {
public:
	NuggetFood() {
		int score = 3;
		this->setResourceType('N');
	}
	//char getType() { return resourceType; }
};
class ChipsFood : public Resources {
public:
	ChipsFood() {
		int score = 2;
		this->setResourceType('C');
	}
	//char getType() { return resourceType; }
};
class Water : public Resources {
public:
	Water() {
		int score = 1;
		this->setResourceType('W');
	}
	//char getType() { return resourceType; }
};
class MedicalSupplies : public Resources {
public:
	MedicalSupplies() {
		//int score = 100;
		this->setResourceType('M');
	}
	//char getType() { return resourceType; }
};
class Trap : public Resources {
public:
	Trap() {
		int score = 1;
		this->setResourceType('T');
		//cout << "Bad News!!!" << endl;
	}
	//char getType() { return resourceType; }
};

class Grid {
public:
	int gridSize;
	Resources boardPlay[100][100];
	Grid(int);
	Grid(Grid&);
	
};
