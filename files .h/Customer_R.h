#ifndef __CUSTOMER_R_H_
#define __CUSTOMER_R_H_

#include"Person.h"
#include"Address.h"

#include<fstream>

using namespace std;

class Customer_R:public Person
{
private:
	int _table_no;
public:
	Customer_R();
	Customer_R(int table_no);
	int getTableNo();
	void setTableNo(int table_no);
	void acceptCustomer();
	void displayCustomer();
	void writeCustomerToFile(std::ostream& outfile);
	void readCustomerFromFile(std::istream& infile);
	friend ostream& operator<<(ostream &outfile,Customer_R& c);
};

void addCustomer();
void renderCustomer();
Customer_R searchCustomer(int table_no);

#endif
