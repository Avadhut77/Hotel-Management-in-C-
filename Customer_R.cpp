#include"Customer_R.h"

#include<iostream>
#include<fstream>

using namespace std;

Customer_R::Customer_R()
{
	this->_table_no=0;
}

Customer_R::Customer_R(int table_no)
{
	this->_table_no=table_no;
}

int Customer_R::getTableNo()
{
	return this->_table_no;
}

void Customer_R::setTableNo(int table_no)
{
	this->_table_no=table_no;
}

void Customer_R::acceptCustomer()
{
	cout<<"\nEnter Empty Table No To Allocate: ";
	cin>>this->_table_no;
	this->acceptPerson();
}

void Customer_R::displayCustomer()
{
	cout<<"\n"<<this->_table_no<<"\t";
	this->displayPerson();
}

void Customer_R::writeCustomerToFile(std::ostream& outfile)
{
	outfile.write((char *)this,sizeof(*this));
}

void Customer_R::readCustomerFromFile(std::istream& infile)
{
	while(infile.read((char*)this, sizeof(*this)))
	{
		this->displayCustomer();
	}
}

void addCustomer()
{
	Customer_R c;
	std::ofstream outfile;
	c.acceptCustomer();
	outfile.open("Cust.dat",std::ios::out|std::ios::binary|std::ios::app);
	if(outfile!=NULL)
		cout<<"\nFile Creates Successfully";
	else
		cout<<"\"nFile Creation Error";
	outfile.write((char*)&c,sizeof(c));
	outfile.close();
}

void renderCustomer()
{
	std::ifstream infile;
	infile.open("Cust.dat",std::ios::in|std::ios::binary);
	if(infile.is_open())
	{
		Customer_R c;
		cout<<"\nTable No\tCustomer Name\t\tCell  No\t\tAddress\n-------------------------------------------------\n";
		while(!infile.eof())
		{
			infile.read((char*)&c, sizeof(c));
			if(!infile.eof())
			{
					c.displayCustomer();
			}
		}
		infile.close();
	}
	else
		cout<<"\"nFile Open Failed";
}

Customer_R searchCustomer(int table_no)
{
	Customer_R cust;
	std::ifstream infile("Cust.dat", std::ios::in | std::ios::binary );
	if(infile.is_open())
	{
		while(!infile.eof())
		{
			infile.read((char*)&cust,sizeof(cust));
			if(!infile.eof())
			{
				if(cust.getTableNo()==table_no)
				{
					break;
				}
			}
		}
	}
	else
		std::cout<<"\nCustomer Not Found"<<endl;
	return cust;
}

ostream &operator <<(ostream& outfile,Customer_R& c)
{
	cout<<"\t"<<c.getTableNo()<<"\t"<<c.getName()<<"\t"<<c.getCellNo()<<"\t"<<c.getAddress();
	return outfile;
}

