/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author: Ritik Bheda
Revision History
-----------------------------------------------------------
Date	 Reason
2020/14/3 Preliminary release
2020/14/3 Built code
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"

namespace sdds
{
	// No argument constructor
	MenuItem::MenuItem()
	{
		itemTitle = nullptr;
	}

	// onr argument constructor
	MenuItem::MenuItem(const char* name)
	{
		itemTitle = nullptr;
		if (name != nullptr)
		{
			itemTitle = new char[strlen(name) + 1];
			strcpy(itemTitle, name);
		}
	}

	//  ostream to display the contents
	std::ostream& MenuItem::display(std::ostream& os) const
	{
		if (itemTitle != nullptr && strlen(itemTitle) > 0)
			os << itemTitle << endl;
		return os;
	}

	// destuctor
	MenuItem::~MenuItem()
	{
		delete[] itemTitle;
		itemTitle = nullptr;
	}

	// no argument constructor
	Menu::Menu()
	{
		title = nullptr;
		menuItem = nullptr;
		indentation = 0;
		size = 0;
	}

	// two argument constructor
	Menu::Menu(const char* name, int indent)
	{
		menuItem = nullptr;
		title = nullptr;
		indentation = indent;
		size = 0;
		setTitle(name);
	}

	// one argument constructr that takes the class instance
	Menu::Menu(const Menu& src)
	{
		indentation = 0;
		size = 0;
		menuItem = nullptr;
		title = nullptr;
		add_4arg(src.title, src.menuItem, src.indentation, src.size);
	}

	// the function to set the title
	void Menu::setTitle(const char* name)
	{
		if (title != nullptr)
		{
			delete[] title;
			title = nullptr;
		}

		if (name != nullptr && name[0] != '\0')
		{
			title = new char[strlen(name) + 1];
			strcpy(title, name);
		}
	}

	void Menu::setIndent(const int ind) {
		indentation = ind;
	}

	// the function to set the item name
	void Menu::setItems(const MenuItem* vastu, int size)
	{
		if (menuItem != nullptr)
		{
			delete[] menuItem;
			menuItem = nullptr;
		}

		if (vastu != nullptr && size > 0)
		{
			menuItem = new MenuItem[size];
			for (int i = 0; i < size; i++)
			{
				int len = strlen(vastu[i].itemTitle) + 1;
				menuItem[i].itemTitle = new char[len];
				strcpy(menuItem[i].itemTitle, vastu[i].itemTitle);
			}
		}
	}

	// the operator overload to assign
	Menu& Menu::operator= (const Menu& src)
	{
		add_4arg(src.title, src.menuItem, src.indentation, src.size);
		return *this;
	}

	// a function that takes 4 arguments to copy the class instance
	void Menu::add_4arg(const char* name, const MenuItem* vastu, int indent, int siz)
	{
		indentation = indent;
		size = siz;
		setTitle(name);
		setItems(vastu, siz);
	}

	// cast overload  
	Menu::operator bool() const
	{
		return (!isEmpty()) ? true : false;
	}

	// function to check if the object is empty or not 
	bool Menu::isEmpty() const
	{
		return (title == nullptr && menuItem == nullptr && size <= 0) ? true : false;
	}

	// the display function
	void Menu::display() const
	{
		if (isEmpty())
		{
			cout << "Invalid Menu!" << endl;
		}
		else if (size <= 0 || menuItem == nullptr)
		{
			indent(cout, 2);
			cout << title << endl;
			cout << "No Items to display!" << endl;
		}
		else
		{
			indent(cout, indentation);
			cout << title << endl;
			for (int i = 0; i < size; i++)
			{
				indent(cout, indentation);
				cout << (i + 1) << "- ";
				menuItem[i].display(cout);
			}
			indent(cout, indentation);
			cout << "> ";
		}
	}

	// operator overload to set new title
	Menu& Menu::operator=(const char* name)
	{
		setTitle(name);
		return *this;
	}

	// add function to add a new menuItem
	void Menu::add(const char* name)
	{
		if (name != nullptr && name[0] != '\0' && size < MAX_NO_OF_ITEMS && title != nullptr)
		{

			MenuItem* temp = new MenuItem[size + 1];
			for (int i = 0; i < size; i++)
			{
				temp[i].itemTitle = new char[strlen(menuItem[i].itemTitle) + 1];
				strcpy(temp[i].itemTitle, menuItem[i].itemTitle);
			}

			temp[size].itemTitle = new char[strlen(name) + 1];
			strcpy(temp[this->size].itemTitle, name);

			if (menuItem != nullptr)
			{
				delete[] menuItem;
				menuItem = nullptr;
			}
			size++;
			menuItem = temp;


		}
		else if (name == nullptr)
		{
			delete[] title;
			delete[] menuItem;
			title = nullptr;
			menuItem = nullptr;
			indentation = 0;
			size = 0;
		}
	}

	// operator overload to add new elements
	Menu& Menu::operator<<(const char* name)
	{
		add(name);
		return *this;
	}

	// run function 
	int Menu::run() const
	{
		int select;
		bool flag = false;
		display();
		if (size > 0)
		{

			while (flag == false)
			{
				if (!(cin >> select)) cout << "Invalid Integer, try again: ";
				else if (select <= 0 || select > size) cout << "Invalid selection, try again: ";
				else flag = true;
				cin.clear();
				cin.ignore(2000, '\n');
			}

		}
		else select = 0;
		return select;
	}

	Menu::operator int() const
	{
		return run();
	}

	// the destructor 
	Menu::~Menu()
	{
		delete[] title;
		title = nullptr;


		delete[] menuItem;
		menuItem = nullptr;
	}


	// a function to indent 
	void indent(std::ostream& os, int size)
	{
		int leng = size * 4;
		for (int i = 0; i < leng; i++)
		{
			os << " ";
		}
	}

}