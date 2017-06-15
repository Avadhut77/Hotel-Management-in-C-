#include"Customer_L.h"

#include<iostream>
#include<fstream>

using namespace std;

Customer_L::Customer_L()
{
	this->_room_no=0;
}

Customer_L::Customer_L(int room_no)
{
	this->_room_no=room_no;
}

int Customer_L::getRoomNo()
{
	return this->_room_no;
}

void Customer_L::setRoomNo(int room_no)
{
	this->_room_no=room_no;
}

void Customer_L::acceptCustomer()
{
	cout<<"\nEnter Room No: ";
	cin>>_room_no;
	this->Person::acceptPerson();
}

void Customer_L::displayCustomer()
{
	cout<<"\n"<<this->_room_no<<"\t\t"<<this->getName()<<"\t\t"<<this->getCellNo()<<"\n";
}

void Customer_L::writeCustomerToFile(Customer_L c)
{
	std::ofstream outfile;
	outfile.open("Customer.dat", std::ios::out | std::ios::binary | std::ios::app );
	outfile.write((char *)&c,sizeof(c));
	outfile.close();
}

void Customer_L::readCustomerFromFile(Customer_L c)
{
	std::ifstream infile("Customer.dat",std::ios::in | std::ios::binary);
    	infile.seekg(0, std::ios::beg);
    	cout<<"\nRoom No\tCustomer Name\t\tName\n-------------------------------------------------\n";
	while(infile.read((char*)&c, sizeof(c)))
	{
		c.displayCustomer();
	}
   	infile.close();
}

ostream &operator <<(ostream &out,Customer_L &c)
{
	cout<<"\nName of the person is:"<<c.getName();
	cout<<"\nCell no. of the person is:"<<c.getCellNo()<<endl;
	return out;
}
