// Name: Ritik Bheda
// student #: 169174182
// file name: ReadWritable.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ReadWritable.h"

using namespace std;

namespace sdds
{
	// zero argument constructor
	ReadWritable::ReadWritable()
	{
		modeFlag = false;
	}


	// fucntion to return tehe modeFlaag
	bool ReadWritable::isCsv()const
	{
		return this->modeFlag;
	}
	// function to set the value of the modeFag
	void ReadWritable::setCsv(bool input)
	{

		this->modeFlag = input;
	}

	// the ostream operator << to display the details
	std::ostream& operator<<(std::ostream& os, const ReadWritable& src)
	{
		return src.write(os);
	}

	// the istream operator >> to input the value
	std::istream& operator>>(std::istream& is, ReadWritable& src)
	{
		return src.read(is);
	}

	// the destructor
	ReadWritable::~ReadWritable()
	{
		//empty
	}

}