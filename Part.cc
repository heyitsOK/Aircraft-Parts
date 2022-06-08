#include "Part.h"

Part::Part(string name) {
    this->name = name;
}
Part::~Part() {
    //nothing needs to be deallocated
}
//overloading the << operator to make output look like example output
ostream & operator << (ostream &out, Part &p) {
	out << "Part:\t\t\t" << p.getName() << endl;
    out << "Flight hours:\t\t" << p.getHours() << endl;
    out << "Installation Date:\t" << p.getDate() << endl;
    if (p.getFHInspect() != 0) {
        out << "Inspect every:\t\t" << p.getFHInspect() << " flight hours" << endl;
    }
    if (p.getITInspect() != 0) {
        out << "Inspect every:\t\t" << p.getITInspect() << " days installed" << endl;
    }
	return out;
}

//these functions are used to access data when overloading the operator
string Part::getName() const {
    return name;
}
int Part::getHours() const {
    return flighthours;
}
string Part::getDate() const {
    string date = installationDate.getMonthName();
    date += " ";
    date += to_string(installationDate.getDay());
    date += ", ";
    date += to_string(installationDate.getYear());
    return date;
}


void Part::addFlightHours(int num) {
    flighthours += num;
}
void Part::install(Date &newDate) {
    installationDate.setDate(newDate.getYear(), newDate.getMonth(), newDate.getDay());
}

//FH_Part functions
FH_Part::FH_Part(string name, int inspect) : Part(name) {
    this->fh_inspect = inspect;
}
bool FH_Part::inspection(Date& inspect) {
    return (flighthours >= fh_inspect);
}
int FH_Part::getFHInspect() {
    return fh_inspect;
}
//returns 0 because there is no it_inspect member variable in an FH_Part object
int FH_Part::getITInspect() {
    return 0;
}

//IT_Part functions
IT_Part::IT_Part(string name, int inspect) : Part(name) {
    this->it_inspect = inspect;
}
bool IT_Part::inspection(Date &inspect) {
    return ((inspect.toDays() - installationDate.toDays()) >= it_inspect);
}
//returns 0 because there is no fh_inspect member variable in an IT_Part object
int IT_Part::getFHInspect() {
    return 0;
}
int IT_Part::getITInspect() {
    return it_inspect;
}

//FHIT_Part functions
FHIT_Part::FHIT_Part(string name, int fhinspect, int itinspect) : FH_Part(name,fhinspect), IT_Part(name, itinspect), Part(name) { } //no function body as all everything is properly instantiated by parent constructors
bool FHIT_Part::inspection(Date &inspect) {
    return (IT_Part::inspection(inspect) || FH_Part::inspection(inspect));
}
int FHIT_Part::getFHInspect() {
    return fh_inspect;
}
int FHIT_Part::getITInspect() {
    return it_inspect;
}
