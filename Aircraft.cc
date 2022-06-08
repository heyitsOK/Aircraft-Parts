#include "Aircraft.h"

Aircraft::Aircraft(string t, string r) {
    this->type = t;
    this->registration = r;
}

//destructor deletes (deallocates) all the parts in the Array<Part*>
Aircraft::~Aircraft() {
    for (int i = 0; i < parts.getSize(); i++) {
        delete parts[i];
    }
}

//getters
string Aircraft::getRegistration() {
    return registration;
}
//this function is used primarily for the operator overload to look as it does in the example output
string Aircraft::getType() {
    return type;
}


void Aircraft::install(Part* p, Date& d) {
    p->install(d);
    parts.add(p);
}
void Aircraft::takeFlight(int hours) {
    flighthours += hours;
    for (int i = 0; i < parts.getSize(); i++) {
        parts[i]->addFlightHours(hours);
    }
}
//returns a list of parts which require inspection
void Aircraft::inspectionReport(Date& d, Array<Part*> **inspectionList) {
    Array<Part*> *iL = new Array<Part*>();
    for (int i = 0; i < parts.getSize(); i++) {
        if (parts[i]->inspection(d)) {
            iL->add(parts[i]);
        }
    }
    *inspectionList = iL;
    
}

//<< operator overload
ostream & operator<<(ostream &out, Aircraft &a) {
    out << "Aircraft:\t" << a.getType() << endl;
    out << "Registration:\t" << a.getRegistration() << endl;

    return out;
}