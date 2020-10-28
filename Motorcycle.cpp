// Name: Ritik Bheda
// student #: 169174182
	
#include "Vehicle.h"
#include "Motorcycle.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

namespace sdds {
	// zero argument constructor
	Motorcycle::Motorcycle() {
		sideCar = false;
	}

	// two argument constructor that calls the Vehicle constructor
	Motorcycle::Motorcycle(const char lic[], const char* model) : Vehicle(lic, model) {
		sideCar = false;
	}

	// the read fucntion to set values to the variables
	istream& Motorcycle::read(istream& istr) {
		char kk[10];
		char pp[10];
		int num;
		bool flag = true;
		if (isCsv()) {
			Vehicle::read(istr);
			if (istr.getline(pp, 2)) num = stoi(pp);
			sideCar = (bool)num;
		}
		else {

cout << endl << "Motorcycle information entry" << endl;
			Vehicle::read(istr);
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			istr.getline(kk, 11);
			cin.clear();
			while (flag) {
				while (strlen(kk) > 1) {
				here:
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					istr.getline(kk, 11);
					cin.clear();
				}
				if (toupper(kk[0]) == 'Y') {
	cout<<endl;
					sideCar = true;
					flag = false;
				}
				else if (toupper(kk[0]) == 'N') {
					cout << endl;
					sideCar = false;
					flag = false;
				}
				else {
					goto here;
				}
			}//cout<<endl;
		}
		return istr;
	}

	// the write function to display the details
	ostream& Motorcycle::write(ostream& ostr) const {

		if (isEmpty()) {
			ostr << "Invalid Motorcycle Object" << endl;

		}
		else if (isCsv()) {
			ostr << "M,";
			Vehicle::write(ostr);
			if (sideCar) ostr << sideCar << endl;
			else ostr << sideCar << endl;

		}
		else {
			ostr << "Vehicle type: Motorcycle" << endl;
			Vehicle::write(ostr);
			if (sideCar) ostr << "With Sidecar" << endl;

		}

		return ostr;
	}

}

