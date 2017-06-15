#ifndef __ORDER_H_
#define __ORDER_H_

#include"Item.h"
#include"Customer_R.h"
#include"Date.h"

#include<list>
#include<vector>
#include<fstream>

enum STATUS{INPROCESS,READY,SERVED};

class Order
{
private:
	Date _date,_date_today;
	Date _start_date,_end_date;
	Customer_R _cust;
	Item _item;
	char _st_str[32];
	enum STATUS  _o_status;
	vector<Item> _v_item;
	int _quantity;
	double _total;
public:
	Order();
	Order(STATUS o_status,double total);
	static Order& getInstance();
	Customer_R & getCustomer();
	Item& getItem();
	void otakeOrder();;
	int getQuantity();
	enum STATUS getStatus();
	void setStatus(const enum STATUS& st);
	char* get_st_str();
	void setTotal(double total);
	double getTotal();
	int getTableInOrder();
	void displayOrder();
	void writeOrderToFile(int table_no);
	void readOrderFromFile(int table_no);
	void showReadyOrders();
	void showInprocessOrders();
	void showServedOrders();
	void showAllOrders();
	void showTodayBill();
	void showGivenRangeBill();
	void display();
	void setBill();
};

#endif
