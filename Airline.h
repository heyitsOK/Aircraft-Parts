#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <string>
#include "Part.h"
#include "Array.h"
#include "Aircraft.h"
#include "Date.h"

using namespace std;

class Airline {
    private:
        string name; //the name of the airline
        Array<Part*> parts; //an Array of Part* for all the parts in the airline
        Array<Aircraft*> aircrafts; //an Array of Aircraft* for all the aircraft in the airline

        //helper functions
        //takes an aircraft registration and returns an Aircraft* whose registration matches the parameter
        Aircraft* getAircraft(string reg) {
            for (int i = 0; i < aircrafts.getSize(); i++) {
                //cout << aircrafts[i] << endl;
                //cout << "test" << endl;
                if (aircrafts[i]->getRegistration() == reg) {
                    return aircrafts[i];
                }
            }
            return NULL;
        }
        //takes a part name and returns a Part* whose name matches the parameter
        Part* getPart(string name) {
            for (int i = 0; i < parts.getSize(); i++) {
                if (parts[i]->getName() == name) {
                    return parts[i];
                }
            }
            return NULL;
        }
    public:
        //Constructor and destructor
        Airline(const string& name);
        ~Airline();

        //member functions
        void addAircraft(string type, string registration);
        void addPart(const string& part, int fh_inspect, int it_inspect);
        void takeFlight(string reg, int hours);
        void printAircraft();
        void printParts();
        void inspectionReport(string reg, Date& d);
        bool install(string reg, string name, Date&);
};

#endif