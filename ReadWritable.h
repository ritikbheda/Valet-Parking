
// Name: Ritik Bheda
// student #: 169174182
// file name: ReadWritable.h
#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H

#include <iostream>

using namespace std;

namespace sdds
{
	// the class ReadWritable
	class ReadWritable
	{
		bool modeFlag; // bool modeFLag
	public:
		ReadWritable(); // constructor 
		~ReadWritable();  // destructor

		bool isCsv()const; // the function ot return the modeFlag
		void setCsv(bool value); // the function to set the value to the modeFlag
		virtual std::istream& read(std::istream&) = 0; // virtual istream to read
		virtual std::ostream& write(std::ostream&) const = 0; // virtual ostream to write
	};

	std::ostream& operator<<(std::ostream&, const ReadWritable&);	// the operator << to display the details
	std::istream& operator>>(std::istream&, ReadWritable&);	// the operator >> to read the details
}

#endif