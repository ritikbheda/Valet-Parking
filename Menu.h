/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author: Ritik Bheda
Revision History
-----------------------------------------------------------
Date Reason
2020/14/3 Preliminary release
2020/14/3 Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
using namespace std;

namespace sdds
{
	class Menu;
	class MenuItem
	{
		friend Menu;
	private:
		char* itemTitle;
		MenuItem();
		MenuItem(const char*);
		MenuItem(const MenuItem&);
		MenuItem& operator=(const MenuItem&);
		~MenuItem();
		ostream& display(std::ostream&) const;
	};

	class Menu
	{
		const int MAX_NO_OF_ITEMS = 10;
		char* title;
		MenuItem* menuItem;
		int indentation;
		int size;
	public:
		Menu();
		Menu(const char*, int inden = 0);
		Menu(const Menu&);
		Menu& operator=(const Menu&);
		~Menu();
		void setTitle(const char*);
		void setIndent(const int);
		void setItems(const MenuItem*, int);
		void add_4arg(const char*, const MenuItem*, int, int);
		operator bool() const;
		operator int() const;
		bool isEmpty() const;
		void display() const;
		void add(const char*);
		int run() const;
		Menu& operator=(const char*);
		Menu& operator<<(const char*);
	};
	void indent(std::ostream&, int);
}

#endif // !SDDS_MENU_H
