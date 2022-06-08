#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <iostream>
#include <string>
#include "Part.h"
#include "Array.h"
#include "Date.h"

using namespace std;

class Aircraft {

    private:
        string type; //the type of aircraft
        string registration; //this is the unique identifier of the aircraft (it is the string of letters and numbers generally seen close to the tail of the aircraft)
        int flighthours; //the number of hours this aircraft has flown
        Array<Part*> parts; //an array of part pointers which keeps track of the aircrafts installed parts
    public:
        //constructor and destructor
        Aircraft(string, string);
        ~Aircraft();

        //getters
        string getRegistration();
        string getType();

        //other
        void install(Part*, Date&);
        void takeFlight(int hours);
        void inspectionReport(Date&, Array<Part*>**);

        //<< operator overloading
        friend ostream & operator<<(ostream &out, Aircraft &a);
};

#endif