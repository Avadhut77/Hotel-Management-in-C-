#ifndef __ITEM_H_
#define __ITEM_H_

#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>

using namespace std;

class Item
{
private:
	int _id;
	char _name[128];
	double _price;
	int _quantity;
public:
		Item();
		Item(int id,char name[128],double price);
		int getItemId();
		void setItemId(int id);
		char*  getItemName();
		void setItemName(char name[128]);
		double getPrice();
		void setPrice(double price);
		int getQuantity();
		void setQuantity(int quantity);
		void acceptItem();
		void displayItem();
		void itemWriteToFile(std::ofstream& outfile);
		void itemReadFromFile(std::ifstream& infile);
};

void addItem();
void renderItem();
Item searchItem(int i);
void editItem(int id);
void deleteItem(int id);

#endif
