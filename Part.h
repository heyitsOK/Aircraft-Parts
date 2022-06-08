#ifndef PART_H
#define PART_H

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

//The Part abstract parent class
class Part {
    protected:
        string name;
        Date installationDate;
        int flighthours;

    public:
        //Constructor and destructor
        Part(string);
        virtual ~Part();
        //Getters
        string getName() const;
        int getHours() const;
        string getDate() const;
        //other functions
        void addFlightHours(int);
        void install(Date&);
        //virtual functions for child classes
        virtual bool inspection(Date&) = 0;
        virtual int getFHInspect() = 0;
        virtual int getITInspect() = 0;
        //<< operator overload
        friend ostream & operator<<(ostream &out, Part& p);

};

//FH_Part class which inherits the Part abstract class
class FH_Part: virtual public Part {
    protected:
        int fh_inspect;
    public:
        //constructor
        FH_Part(string, int);
        //virtual functions
        virtual bool inspection(Date&);
        //both getFHInspect() and getITInspect() are required functions as
        // not defining one of them makes it a pure virtual function and the class abstract
        virtual int getFHInspect();
        virtual int getITInspect();
};

class IT_Part: virtual public Part {
    protected:
        int it_inspect;
    public:
        //constructor
        IT_Part(string, int);
        //virtual functions
        virtual bool inspection(Date&);
        //both getFHInspect() and getITInspect() are required functions as
        // not defining one of them makes it a pure virtual function and the class abstract
        virtual int getFHInspect();
        virtual int getITInspect();
};

class FHIT_Part: public FH_Part, public IT_Part {
    public:
        //constructor
        FHIT_Part(string, int, int);
        bool inspection(Date&);
        int getFHInspect();
        int getITInspect();

};

#endif