#ifndef __CHEF_H_
#define __CHEF_H_

#include"Order.h"
#include"Item.h"

class Chef
{
private:
	Order _order;
public:
	Order& chefGetOrder();
	void chefProcessOrder();
};

#endif
