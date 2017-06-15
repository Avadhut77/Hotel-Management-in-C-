#ifndef __CAPTAIN_H_
#define __CAPTAIN_H_

#include"Order.h"
#include"Date.h"
class Captain
{
private:
	Order _order;
	Date _date,_date1;
public:
	Order& captainGetOrder();
	void captainSetOrder(Order& order);
	void captainTakeOrder();
	void captainServeOrder();
};

#endif
