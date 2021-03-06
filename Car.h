// Name: Ritik Bheda
// Student #: 169174182

#pragma once
#ifndef SDDS_Car_H__
#define SDDS_Car_H__
#define _CRT_SECURE_NO_WARNINGS

#include "ReadWritable.h"
#include "Vehicle.h"
#include <iostream>
#include <string>
using namespace std;

namespace sdds {
	class Car : public Vehicle {
		bool carWash;
	public:
		Car();
		Car(const char[], const char*);
		istream& read(istream&);
		ostream& write(ostream&) const;
	};
}
#endif