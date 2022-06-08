Name: Omar Khan
Student Number: 101168124

File list:
    defs.h - defines a few constants to be used throughout the program
    main.cc - contains the main function which creates and launches the control object
    Control.h - Provides a test framework for the Airline
    Control.cc - implements the functions for the control class
    View.h - Collects user input an provides system output
    View.cc - implements the functions declared in the View class
    Date.h - Stores information of a date
    Date.cc - implements the functions declared in the Date class
    Part.h - contains the virtual base class of all Parts as well as FH_Part, IT_Part, and FHIT_Part classes
    Part.cc - implements the functions declared in the Part classes 
    Array.h - contains a simple (templated) data structure
    Aircraft.h - contains Aircraft data as well as a container for the installed Parts
    Aircraft.cc - implements the functions declared in the Aircraft class and manages the installed Parts container
    Airline.h - contains the control class which tracks parts, Aircrafts, installations, flights, etc.
    Airline.cc - implements the functions defined in the control class
    Makefile - makes compiling and linking all the files as easy as one command: "make"

Compilation and Execution commands: 
    - use command "make" to compile and link all the files to create ./a4 executable
    - use command "./a4" to run the program

Notes:
    The program should run fine, however there is a segmentation fault at the end which I believe is caused by an error in my destructors
