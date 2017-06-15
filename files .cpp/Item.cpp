#include"Item.h"

#include<cstring>

Item::Item()
{
	this->_id=0;
	strcpy(this->_name,"NULL");
	this->_price=0;
	this->_quantity=0;
}

Item::Item(int id,char name[128],double price)
{
	this->_id=id;
	strcpy(this->_name,name);
	this->_price=price;
	this->_quantity=0;
}

int Item::getItemId()
{
	return this->_id;
}

void Item::setItemId(int id)
{
	this->_id=id;
}

char*  Item::getItemName()
{
	return this->_name;
}

void Item::setItemName(char name[128])
{
	strcpy(this->_name,name);
}

double Item::getPrice()
{
	return this->_price;
}

void Item::setPrice(double price)
{
	this->_price=price;
}

int Item::getQuantity()
{
	return this->_quantity;
}

void Item::setQuantity(int quantity)
{
	this->_quantity=quantity;
}

void Item::acceptItem()
{
	cout<<"\nEnter Item ID: ";
	cin>>this->_id;
	cout<<"\nEnter Item Name: ";
	cin>>this->_name;
	cout<<"\nEnter Item Price: ";
	cin>>this->_price;
}

void Item::displayItem()
{
	cout<<"\n"<<this->_id<<"\t"<<this->_name<<"\t\t"<<this->_price<<"\t";
}

void Item::itemWriteToFile(std::ofstream& outfile)
{
	outfile.write((char *)this,sizeof(*this));
}

void Item::itemReadFromFile(std::ifstream& infile)
{
	infile.read((char *)this,sizeof(*this));
}

void addItem()
{
	Item it;
	std::ofstream outfile("Item.dat", std::ios::out | std::ios::binary |std::ios::app);
	if(outfile!=NULL)
	{
		cout<<"\nFile Created Successfully";
		it.acceptItem();
	}
	else
			cout<<"\nItem.dat Not Creates Successfully";
	outfile.write((char*)&it,sizeof(it));
	outfile.close();
}

void renderItem()
{
	std::ifstream infile;
	infile.open("Item.dat",std::ios::in|std::ios::binary);
	if(infile.is_open())
	{
		Item item;
		cout<<"\nItem Id\tItem Name\t\tPrice\n----------------------------------------------------------\n";
		while(!infile.eof())
		{
			infile.read((char*)&item, sizeof(item));
			if(!infile.eof())
			{
					item.displayItem();
			}
		}
		cout<<"\n-------------------------------------------------------";
		infile.close();
	}
	else
		cout<<"\"nItem.dat File Open Failed.... In Render Item Func.";
}

Item searchItem(int id)
{
	Item item;
	std::ifstream infile("Item.dat",std::ios::in|std::ios::binary);
	if(infile.is_open())
	{
		while(!infile.eof())
		{
			infile.read((char*)&item,sizeof(item));
			if(!infile.eof())
			{
				if(item.getItemId()==id)
				{
					break;
				}
			}
		}
	}
	else
		cout<<"\nItem File Opening Error";
	return item;
}

void editItem(int id)
{
	Item item;
	int item_id;
	char name[128];
	double price;
	fstream file("Item.dat",ios::in|ios::binary|ios::out);
	if(file.is_open())
	{
		while(!file.eof())
		{
			file.read((char*)&item,sizeof(item));
			if(!file.eof())
			{
				if(item.getItemId()==id)
				{
					cout<<"\n--** Enter New Details For Item **--";
					cout<<"\nEnter Item Id: ";
					cin>>item_id;
					cout<<"\nEnter Item Name: ";
					cin>>name;
					cout<<"\nEnter Item Price: ";
					cin>>price;
					item.setItemId(item_id);
					item.setItemName(name);
					item.setPrice(price);
				}
				file.seekp(-sizeof(Item),std::ios::cur);
				file.write((char *)&item,sizeof(item));
			}
		}
	}
}

void deleteItem(int id)
{
	Item item;
	ifstream infile("Item.dat",ios::in|ios::binary);
	ofstream outfile("temp.dat",ios::out|ios::app|ios::binary);
	if(infile.is_open())
	{
		while(!infile.eof())
		{
			infile.read((char*)&item,sizeof(item));
			if(!infile.eof())
			{
				if(item.getItemId()!=id)
				{
					outfile.write((char*)&item,sizeof(item));
				}
			}
		}
	}
	infile.close();
	outfile.close();
	rename("temp.dat","Item.dat");
	::renderItem();
}
