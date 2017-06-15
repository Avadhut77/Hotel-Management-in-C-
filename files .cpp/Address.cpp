#include"Address.h"

#include<iostream>
#include<cstring>

Address::Address()
{
	strcpy(this->_city,"NULL");
}

Address::Address(char city[100])
{
	strcpy(this->_city,city);
}

char* Address::getAddress()
{
	return this->_city;
}

void Address::setAddress(char city[128])
{
	strcpy(this->_city,city);
}

void Address::acceptAddress()
{
	std::cout<<"\nEnter Address: ";
	std::cin>>this->_city;
}

void Address::displayAddress()
{
	std::cout<<"\t"<<_city;
}

std::ostream& operator<<(std::ostream &out,Address &a)
{
	out<<a.getAddress();
	return out;
}
