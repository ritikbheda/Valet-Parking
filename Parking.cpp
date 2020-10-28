/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Parking.cpp
Version 1.0
Author: Ritik Bheda
Revision History
-----------------------------------------------------------
Date	 Reason

2020/4/13 Built code
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include "Parking.h"
#include "Car.h"
#include "Motorcycle.h"
#include <fstream>
#include <iomanip>

using namespace std;

namespace sdds {

	// one argument constructoe that sets the title of the file
	Parking::Parking(const char* datafile, int noOfSpots) {

		if (noOfSpots < 10 || noOfSpots > MAX_PARKING_SPOTS){
			park_capacity = 0;
		}
		else {
			park_capacity = noOfSpots ;
		}		
		parked = 0;

		for (int i = 0; i < MAX_PARKING_SPOTS; i++) {
			Vehicle_pointer[i] = nullptr;
		}

		if (datafile == nullptr || strlen(datafile) == 0) {
			filename = nullptr;
		}
		else {
			filename = new char[strlen(datafile) + 1];
			strcpy(filename, datafile);
		}
//		delete[] datafile;
		if (loadDataFile()) {

			Menu_obj.setTitle("Parking Menu, select an action:");
			Menu_obj << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";
			Vehicle_obj.setTitle("Select type of the vehicle:");
			Vehicle_obj.setIndent(1);
			Vehicle_obj << "Car" << "Motorcycle" << "Cancel";
		}
		else {
			cout << "Error in data file" << endl;
		}
	}

	// the function to check wheater the object is empty or not. returns true if it is empty, false otherwise
	bool Parking::isEmpty() {
		if (filename == nullptr)
			return true;
		return false;
	}

	// the function used to display the required output
	void Parking::Parkingstatus() {
		cout << "****** Seneca Valet Parking ******" << endl;
		cout << "*****  Available spots: ";
		cout << left << setw(4) << (park_capacity - parked) << " *****" << endl;
	}

	// the function for the Vehicle object to display, get user input and do accordingly
	void Parking::VehicleFunction() {

		if (parked == park_capacity) {
			cout << "Parking is full" << endl;
		}
		else {
			int i = 0;
			int select;
			select = Vehicle_obj.run();
			switch (select) {
			case 1:
				while (Vehicle_pointer[i] != nullptr) {
					i++;
				}
				Vehicle_pointer[i] = new Car;
				cin >> *Vehicle_pointer[i];
				parked++;
				Vehicle_pointer[i]->setParkingSpot(i+1);
				cout << "Parking Ticket"<<endl;
				cout << *Vehicle_pointer[i] << endl;
				break;
			case 2:
				while (Vehicle_pointer[i] != nullptr) {
					i++;
				}
				Vehicle_pointer[i] = new Motorcycle;
				cin >> *Vehicle_pointer[i];
				parked++;
				Vehicle_pointer[i]->setParkingSpot(i + 1);
				cout << "Parking Ticket" << endl;
				cout << *Vehicle_pointer[i] << endl;
				break;
			case 3:
				cout << "Parking cancelled" << endl;
				break;
			default:
				cout << "Sorry no such";
			}
		}
	}

	// the function for " Returning the Vehicle "
	void Parking::ReturningVehicle() {
		char lic[10];
		bool done = false;
		cout << "Return Vehicle" << endl;
		
		cout << "Enter Licence Plate Number: ";
		cin.getline(lic,11);
		cin.clear();
		
		while (strlen(lic) > 8 || strlen(lic) < 1) {
			cout << "Invalid License Plate, try again: ";
			cin.getline(lic, 11);
			cin.clear();
		}
		cout << endl;
		for (int i = 0; i < parked; i++) {
			if (Vehicle_pointer[i] != nullptr) {
				if (*Vehicle_pointer[i] == lic) {
					cout << "Returning: " << endl << *Vehicle_pointer[i] << endl;
					Vehicle_pointer[i]->~Vehicle();
					Vehicle_pointer[i] = nullptr;
					parked--;
					done = true;
					break;
				}
			}
		}

		if (!done) {
			cout << "License plate " << lic << " Not found" << endl;
		}
	}

	// the function to print the " parked vehicles"
	void Parking::PrintParked() {
		cout << "*** List of parked vehicles ***" << endl;

		for (int i = 0; i < park_capacity; i++) {
			if (Vehicle_pointer[i] != nullptr) {
				cout << *Vehicle_pointer[i] << "-------------------------------" << endl;
			}
		}
	}

	// the function to close the parking 
	bool Parking::closeParking() {
		bool allEmpty = true;
		//cout << "Closing Parking" << endl;
		for (int i = 0; i < park_capacity; i++) {
			if (Vehicle_pointer[i] != nullptr) {
				allEmpty = false;
			}
		}
		char ch[10];
		bool flag = false;
		bool result = false;
		if (!allEmpty) {
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			cin >> ch;
			cin.clear();		
			//cout << endl;
			while (!flag) {
				if (!strcmp(ch, "y")) {
					cout << "Closing Parking" << endl<<endl;
					for (int i = 0; i < park_capacity; i++) {
						if (Vehicle_pointer[i] != nullptr) {
							cout << "Towing request" << endl;
							cout << "*********************" << endl;

							cout << *Vehicle_pointer[i];
if(i<parked-1){cout<<endl;}
							Vehicle_pointer[i]->~Vehicle();
							Vehicle_pointer[i] = nullptr;
						}
					}
//cin.clear();
					result = false;
//cout << "\x1b[A";
					flag = true;
				}
				else if (!strcmp(ch, "n")) {
					cout << "Aborted!" << endl;
					flag = true;
					result = true;
				}
				else {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					cin >> ch;
					cin.ignore(2000, '\n');
				}
			}
		}
		return result;
	}

	// the function to exit the app
	bool Parking::exitApp() {
		char ch[10];
		bool flag = false;
		bool result = false;
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		cin >> ch;
		cin.ignore(2000, '\n');
		while (!flag) {
			if (!strcmp(ch, "y") || !strcmp(ch, "Y")) {
				cout << "Exiting program!" << endl;
				result = true;
				flag = true;
			}
			else if (!strcmp(ch, "n")) {
				flag =  true;
				result = false;
			}
			else {
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				cin >> ch;
				cin.ignore(2000, '\n');
			}
		}
		return result;		
	}

	// the function checks wheather filename is loaded or not
	bool Parking::loadDataFile() {
		bool position = false;
		if (!isEmpty()) {
			ifstream datafile(filename);
			if (datafile.is_open() || datafile.good()) {
				position = true;
				for (int i = 0; i < park_capacity; i++) {
					char read = '\0';
					datafile >> read;
					datafile.ignore(1, ',');
					if (read == 'C') {
						Vehicle_pointer[i] = new Car();
						Vehicle_pointer[i]->setCsv(true);
						datafile >> *Vehicle_pointer[i];
						parked++;
						Vehicle_pointer[i]->setCsv(false);
					}
					else if (read == 'M') {
						Vehicle_pointer[i] = new Motorcycle();
						Vehicle_pointer[i]->setCsv(true);
						datafile >> *Vehicle_pointer[i];
						parked++;
						Vehicle_pointer[i]->setCsv(false);
					}
				}
			}
			else {
				position = true;
			}
			datafile.close();
		}
		return position;
	}

	// the function check weather the function is empty or not 
	void Parking::saveDataFile() {
		if (!isEmpty()) {
			ofstream output(filename);
			if (output) {
				for (int i = 0; i < park_capacity; i++) {
					if (Vehicle_pointer[i] != nullptr) {
						Vehicle_pointer[i]->setCsv(true);
						Vehicle_pointer[i]->write(output);
					}
				}
			}
		}
		//while ((getchar()) != '\n');
	}   

	// the run function defined as per the problem statment
	int Parking::run() {
		bool flag = true;
		if (!isEmpty()) {
			int select;
			while (flag) {
				Parkingstatus();
				select = Menu_obj.run();
				switch (select) {
				case 1:
					// CALL the Park Vehicle
					VehicleFunction();
					break;
				case 2:
					ReturningVehicle();
					break;
				case 3:
					// List parked vehicles
					PrintParked();
					break;
				case 4:
					// close parking
					flag = closeParking();
					if(!flag) cin.ignore(2000,'\n');
		//flag = false;
					break;
				case 5:
					// exit app
					bool exitornot;
					exitornot = exitApp();
					flag = !exitornot;
					
				//	flag = true;
					break;
				default:
					cout << "something good";
				}
			}
		}
		return flag;
	}
}
