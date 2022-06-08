#include "Airline.h"

Airline::Airline(const string& name) {
    this->name = name;
}

//deletes all the Aircraft pointers and Part pointers stored in the Arrays 
Airline::~Airline() {
    for (int i = 0; i < aircrafts.getSize(); i++) {
        delete aircrafts[i];
    }
    for (int i = 0; i < parts.getSize(); i++) {
        delete parts[i];
    }
}

//takes a string type and a string registration, creates a new Aircraft, and adds it to the Aircraft Array
void Airline::addAircraft(string type, string registration) {
    //printAircraft();
    Aircraft *air = new Aircraft(type, registration);
    aircrafts.add(air);
}
//takes a string name, an int for flight hours, another int for installed time and then creates the appropriate Part object then adds it to the Part Array
void Airline::addPart(const string& part, int fh_inspect, int it_inspect) {
    if (fh_inspect == 0) {
        IT_Part *newPart = new IT_Part(part, it_inspect);
        parts.add(newPart);
    } else if (it_inspect == 0) {
        FH_Part *newPart = new FH_Part(part, fh_inspect);
        parts.add(newPart);
    } else {
        FHIT_Part *newPart = new FHIT_Part(part, fh_inspect, it_inspect);
        parts.add(newPart);
    }
}

//makes the aircraft whose registration matches the parameter take a flight of length `hours`
void Airline::takeFlight(string reg, int hours) {
    getAircraft(reg)->takeFlight(hours);
}

//printing the elements from the Aircraft and Part Arrays
void Airline::printAircraft() {
    for (int i = 0; i < aircrafts.getSize(); i++) {
        Aircraft* print = aircrafts[i];
        cout << *print;
    }
}
void Airline::printParts() {
    for (int i = 0; i < parts.getSize(); i++) {
        Part* print = parts[i];
        cout << *print << endl;
    }
}

//prints a list of all the parts that require inspection on the aircraft whose registration matches the parameter
void Airline::inspectionReport(string reg, Date& d) {
    Aircraft *aircraft = getAircraft(reg);
    cout << "The following parts from " << aircraft->getRegistration() << " require inspection:" << endl;
    Array<Part*> *toBeInspected;
    aircraft->inspectionReport(d, &toBeInspected);
    if ((*toBeInspected).getSize() == 0) {
        cout << "\t" << "No parts require inspection." << endl;
    } else {
        for (int i = 0; i < (*toBeInspected).getSize(); i++) {
            Part* print = (*toBeInspected)[i];
            cout << *print << endl;
        }
    }
    delete toBeInspected;
}
//installs the part whose name matches the parameter onto the aircraft whose registration matches the parameter on the Date passed in as an argument
bool Airline::install(string reg, string name, Date& d) {
    Aircraft *aircraft = getAircraft(reg);
    Part *part = getPart(name);
    if (aircraft == NULL || part == NULL) {
        return false;
    } else {
        aircraft->install(part, d);
        return true;
    }
}