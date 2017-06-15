#include"Captain.h"

#include<iostream>
#include<cstring>

using namespace std;

Order& Captain::captainGetOrder()
{
	return _order;
}

void Captain::captainSetOrder(Order& order)
{
	_order = order;
}

void Captain::captainTakeOrder()
{
	this->_order.otakeOrder();
}

void Captain::captainServeOrder()
{
	int table_no;
	Customer_R cust;
	double total;
	this->_order.showReadyOrders();
	cout<<"\nEnter Table No: ";
	cin>>table_no;
	_order.readOrderFromFile(table_no);
	_order.setStatus(SERVED);
	ofstream outfile("Bill.dat",ios::out|ios::binary|ios::app);
	_date.setSystemTime();
	char name[64];
	cust=_order.getCustomer();
	strcpy(name,cust.getName());
	total=_order.getTotal();
	outfile.write((char*)&_date,sizeof(_date));
	outfile.write((char*)&table_no,sizeof(table_no));
	outfile.write((char*)&name,sizeof(name));
	outfile.write((char*)&total,sizeof(total));
	outfile.close();
	_order.writeOrderToFile(table_no);
	_order.readOrderFromFile(table_no);
	_order.displayOrder();
	outfile.close();
}

