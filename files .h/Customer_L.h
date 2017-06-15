#ifndef __CUSTOMER_L_H_
#define __CUSTOMER_L_H_

#include"Person.h"
#include"Address.h"

#include<fstream>

using namespace std;

class Customer_L:public Person
{
private:
	int _room_no;
public:
	Customer_L();
	Customer_L(int room_no);
	int getRoomNo();
	void setRoomNo(int room_no);
	void acceptCustomer();
	void displayCustomer();
	void writeCustomerToFile(Customer_L);
	void readCustomerFromFile(Customer_L);
	friend ostream& operator<<(ostream &output , Customer_L&);
};

void addCustomer();
void renderCustomer();
Customer_L takeCustomer(int _room_no);

#endif
