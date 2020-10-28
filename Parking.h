/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Parking.h
Version 1.0
Author: Ritik Bheda
Revision History
-----------------------------------------------------------
Date	 Reason
2020/25/3 Built code
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H

#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Vehicle.h"

using namespace std;

namespace sdds {

	const int MAX_PARKING_SPOTS = 100;

	class Parking {
		char* filename;
		Menu Menu_obj;
		Menu Vehicle_obj;
		
		// <MS6>
		int park_capacity;
		Vehicle* Vehicle_pointer[MAX_PARKING_SPOTS];
		int parked;
		// </MS6>

		bool isEmpty();
		void Parkingstatus();
		void VehicleFunction();
		void ReturningVehicle();
		void PrintParked();
		bool closeParking();
		bool exitApp();
		bool loadDataFile();
		void saveDataFile();

	//setEmpty: deallocate memory first
		// Modified later, corrected by ma'am
		void setEmpty() {
			delete[] filename;
			filename = nullptr;
			for(int i = 0;i<park_capacity;i++)
delete Vehicle_pointer[i];
		}


	public:
		Parking(const char* datafile, int noOfSpots);

		int run();

		//	  Use save() and setEmpty() in the destructor.
		// Modified later, corrected by ma'am
		~Parking() {
			saveDataFile();
			setEmpty();
		}


	};

}

#endif // !SDDS_PARKING_H
