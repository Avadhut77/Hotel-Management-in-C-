#ifndef __PERSON_H_
#define __PERSON_H_

#include"Address.h"

using namespace std;

class Person
{
private:
	char _name[128];
	char _cell_no[12];
	Address _add;
public:
	Person();
	Person(char name[128],char cell_no[12],Address add);
	Person(char name[128],char cell_no[12],char city[128]);
	char* getName();
	Address& getAddress();
	char* getCellNo();
	void setName(char name[128]);
	void setCellNo(char cell[12]);
	void acceptPerson();
	void displayPerson();
	friend ostream& operator<<(ostream &output , Person& p);
};

#endif
