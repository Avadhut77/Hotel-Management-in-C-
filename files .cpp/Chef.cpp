#include"Chef.h"

#include<iostream>

using namespace std;

Order& Chef::chefGetOrder()
{
	return this->_order;
}

void Chef::chefProcessOrder()
{
		int table_no;
		this->_order.showInprocessOrders();
		cout<<"\nEnter Table No: ";
		cin>>table_no;
		_order.readOrderFromFile(table_no);
		_order.setStatus(READY);
		_order.writeOrderToFile(table_no);
		_order.readOrderFromFile(table_no);
		_order.displayOrder();
}
