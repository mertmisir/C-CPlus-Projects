#include"Doctor.h"


Doctor::Doctor() {
	eTitle = Docent;
	this->setEmployeeID(1);
}

Doctor::Doctor(Title t) {
	this->eTitle = t;
}

Title Doctor::getTitle() {
	return eTitle;
}

void Doctor::setTitle(Title t) {
	this->eTitle = t;
}

