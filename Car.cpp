// Name: Ritik Bheda
// Student #: 169174182

#include "Vehicle.h"
#include "Car.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

namespace sdds {
	// zero argument constructor
	Car::Car() {
		carWash = false;
	}

	// two argument constructor that calls the Vehicle constructor
	Car::Car(const char lic[], const char* model) : Vehicle(lic, model) {
		carWash = false;
	}

	// the read fucntion to set values to the variables
	istream& Car::read(istream& istr) {
		string temp;
		char kk[10];
		char pp[10] = "\n";
		int num = 0;
		bool flag = true;
		if (isCsv()) {
			Vehicle::read(istr);
			if (istr.getline(pp, 2)) num = stoi(pp);
			carWash = (bool)num;
		}
		else {
			cout << endl << "Car information entry" << endl;
			Vehicle::read(istr);
			cout << "Carwash while parked? (Y)es/(N)o: ";
			istr.getline(kk, 11);
			cin.clear();
			//cin.ignore(2000, '\n');
			while (flag) {
				while (strlen(kk) > 1) {
				here:
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					istr.getline(kk, 11);
					cin.clear();
				}
				if (toupper(kk[0]) == 'Y') {
					carWash = true;
					flag = false;
				}
				else if (toupper(kk[0]) == 'N') {
					cout << endl;
					carWash = false;
					flag = false;
				}
				else {
					goto here;
				}
			}
		}
		return istr;
	}

	// the write function to display the details
	ostream& Car::write(ostream& ostr) const {
		if (isEmpty()) {
			ostr << "Invalid Car Object" << endl;
		}
		else if (isCsv()) {
			ostr << "C,";
			Vehicle::write(ostr);
			ostr << carWash << endl;
		}
		else {
			ostr << "Vehicle type: Car" << endl;
			Vehicle::write(ostr);
			if (carWash) {
				ostr << "With Carwash" << endl;
			}
			else {
				ostr << "Without Carwash" << endl;
			}
		}
		return ostr;
	}

}