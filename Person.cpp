#include"Person.h"

#include<iostream>
#include<string.h>

using namespace std;

Person::Person()
{
	strcpy(this->_name,"NULL");
	strcpy(this->_cell_no,"NULL");
}

Person::Person(char name[128],char cell_no[12],Address add)
{
	strcpy(this->_name,name);
	strcpy(this->_cell_no,cell_no);
	this->_add=add;
}
Person::Person(char name[128],char cell_no[12],char city[128])
{
	strcpy(this->_name,name);
	strcpy(this->_cell_no,cell_no);
	_add.setAddress(city);
}

Address& Person::getAddress()
{
	return this->_add;
}

void Person::setCellNo(char cell_no[12])
{
	strcpy(this->_cell_no,cell_no);
}

void Person::setName(char name[128])
{
	strcpy(this->_name,name);
}

char* Person::getCellNo()
{
	return this->_cell_no;
}

char* Person::getName()
{
	return this->_name;
}

void Person::acceptPerson()
{
	cout<<"\nEnter Name Of Person: ";
	cin>>_name;
	setName(_name);
	cout<<"\nEnter Cell No: ";
	cin>>_cell_no;
	_add.acceptAddress();
}

void Person::displayPerson()
{
	std::cout<<this->_name<<"\t"<<this->_cell_no;
	_add.displayAddress();
}

ostream& operator<<(ostream &out,Person &p)
{
	out<<"\nName Of Person: "<<p.getName();
	out<<"\nCell No: "<<p.getCellNo()<<endl;
	out<<p.getAddress();
	return out;
}
