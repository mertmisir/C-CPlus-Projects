#include"Header.h"
#include<time.h>

Resources::Resources() {
    this->resourceSize = 0;
    this->resourceType = NULL;
    this->checkFlag = 0;
}
int Resources::getCheckFlag() { return this->checkFlag; }
int Resources::getResourceSize() { return this->resourceSize; }
char Resources::getResourceType() { return this->resourceType; }
void Resources::setCheckFlag(int c) { this->checkFlag = c; }
void Resources::setResourceSize(int r) { this->resourceSize = r; }
void Resources::setResourceType(char t) { this->resourceType = t; }

Resources::Resources(Resources& r) {
    this->resourceSize = r.resourceSize;
    this->resourceType = r.resourceType;
    this->checkFlag = r.checkFlag;
}

void Resources::operator=(Resources& r) {
    this->resourceSize = r.resourceSize;
    this->resourceType = r.resourceType;
    this->checkFlag = r.checkFlag;
}


Archeologist::Archeologist() {
    this->diceValue = 0;
    this->sizeOfGatheredFood = 0;
    this->playerEnegy = 0.0;
    this->totalScore = 0.0;
    this->sizeOfGatheredResources = 0;
}

void Archeologist::setPlayerEnegery(double p) { this->playerEnegy = p; }
void Archeologist::setTotalScore(double t) { this->totalScore = t; }
void Archeologist::setsizeOfGatheredFood(int g) { this->sizeOfGatheredFood = g; }
void Archeologist::setSizeOfGatheredResources(int e) { this->sizeOfGatheredResources = e; }

double Archeologist::getPlayerEnergy() { return this->playerEnegy; }
double Archeologist::getTotalScore() { return this->totalScore; }
int Archeologist::getsizeOfGatheredFood() { return this->sizeOfGatheredFood; }
int Archeologist::getSizeOfGatheredResources() { return this->sizeOfGatheredResources; }
int Archeologist::getDiceValue() { return this->diceValue; }
void Archeologist::setDiceValue(int d) { this->diceValue = d; }



Resources Archeologist::getListOfGatheredResources(int i) { return this->listOfGatheredResources[i]; }

void Archeologist::setListOfGatheredResources(Resources& a) {
    int medicalFlag=0;
    int trapFlag = 0;
    
    this->listOfGatheredResources[this->getSizeOfGatheredResources()] = a;
    for (int i = 0;i < this->sizeOfGatheredResources;i++) {
         medicalFlag = 0;
        if (this->listOfGatheredResources[i].getResourceType() == 'M') {
            medicalFlag++;
            break;
        }
            
    }
    for (int i = 0;i < this->sizeOfGatheredResources;i++) {
         trapFlag = 0;
        if (this->listOfGatheredResources[i].getResourceType() == 'T') {
            trapFlag++;
            break;
        }
            
    }
    if (medicalFlag == 0 && trapFlag >0 ) {
        this->setPlayerEnegery(this->getPlayerEnergy() - 0.25);
    }

    if (a.getResourceType() == 'F')
        this->setTotalScore(this->getTotalScore() + 100);
    if (a.getResourceType() == 'S')
        this->setTotalScore(this->getTotalScore() + 50);
    if (a.getResourceType() == 'O')
        this->setTotalScore(this->getTotalScore() + 20);
    if (a.getResourceType() == 'B')
        this->setPlayerEnegery(this->getPlayerEnergy() + 4);
    if (a.getResourceType() == 'N')
        this->setPlayerEnegery(this->getPlayerEnergy() + 3);
    if (a.getResourceType() == 'C')
        this->setPlayerEnegery(this->getPlayerEnergy() + 2);
    if (a.getResourceType() == 'W')
        this->setPlayerEnegery(this->getPlayerEnergy() + 1);
    if (a.getResourceType() == 'T') {
        if (this->getDiceValue() != 1)
            this->setPlayerEnegery(this->getPlayerEnergy() - 1);
    }
    if(a.getResourceType() != NULL)
        this->sizeOfGatheredResources += 1;
}


Archeologist::Archeologist(Archeologist& a) {
    this->diceValue = a.diceValue;
    this->sizeOfGatheredFood = a.sizeOfGatheredFood;
    this->playerEnegy =a.playerEnegy;
    this->totalScore = a.totalScore;
    this->sizeOfGatheredResources = a.sizeOfGatheredResources;
    for (int i = 0;i < sizeOfGatheredResources;i++) {
        this->listOfGatheredResources[i] = a.listOfGatheredResources[i];
    }
}

Grid::Grid(int size) {
    this->gridSize = size;
    for (int o = 0;o < size;o++) {
        for (int m = 0;m < size;m++) {
            this->boardPlay[o][m].setResourceType(NULL);
        }
    }

}

Grid::Grid(Grid& g) {
    this->gridSize = g.gridSize;
    for (int o = 0;o < gridSize;o++) {
        for (int m = 0;m < gridSize;m++) {
            this->boardPlay[o][m].setResourceType(NULL);
        }
    }
    for (int o = 0;o < gridSize;o++) {
        for (int m = 0;m < gridSize;m++) {
            this->boardPlay[o][m]=g.boardPlay[o][m];
        }
    }
}

