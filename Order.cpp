#include"Order.h"

#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>

using namespace std;

Order::Order()
{
	_o_status=INPROCESS;
	_total=0;
	_quantity=0;
}

Order::Order(STATUS o_status,double total)
{
	this->_o_status=o_status;
	this->_total=total;
	this->_quantity=0;
}

Order& Order::getInstance()
{
	static Order obj;
	return obj;
}

int Order::getTableInOrder()
{
	return this->_cust.getTableNo();
}

Customer_R & Order::getCustomer()
{
	return this->_cust;
}

Item& Order::getItem()
{
	return this->_item;
}

int Order::getQuantity()
{
	return this->_quantity;
}

enum STATUS Order::getStatus()
{
	return this->_o_status;
}

void Order::setStatus(const enum STATUS& o_status)
{
	switch(o_status)
	{
		case INPROCESS:
			strcpy(this->_st_str,"InProcess..!");
			break;
		case READY:
			strcpy(this->_st_str,"Ready..!");
			break;
		case SERVED:
			strcpy(this->_st_str,"Served..!");
			break;
	}
	this->_o_status=o_status;
}

char* Order::get_st_str()
{
	return this->_st_str;
}

void Order::setTotal(double total)
{
	this->_total=total;
}

double Order::getTotal()
{
	return this->_total;
}

void Order::otakeOrder()
{
	int table_no,ch,item_no,quantity;
	this->_v_item.clear();
	::renderCustomer();
	cout<<"\nEnter Table No: ";
	cin>>table_no;
	do
	{
		::renderItem();
		std::cout<<"\nEnter Item Id: ";
		std::cin>>item_no;
		this->_item=searchItem(item_no);
		cout<<"\nEnter Quantity: ";
		cin>>quantity;
		_item.setQuantity(quantity);
		this->setStatus(INPROCESS);
		this->_v_item.push_back(this->_item);
		cout<<"\nWant To Give Another Order(If Yes Enter Any Non-Zero Value): ";
		cin>>ch;
	}while(ch!=0);
	this->writeOrderToFile(table_no);
}

void Order::writeOrderToFile(int table)
{
	char str[32]="order_";
	char number[10][5]={"1","2","3","4","5","6","7","8","9","10"};
	strcat(str,number[table-1]);
	ofstream out;
	ifstream in;
	out.open(str,ios::out|ios::binary);
	in.open("Cust.dat",ios::in|ios::binary);
	while(in.read((char *)&_cust,sizeof(_cust)))
	{
		if(_cust.getTableNo()==table)
		{
			out.write((char*)&_cust,sizeof(_cust));
		}
	}
	in.close();
	out.write((char*)&_st_str,sizeof(_st_str));
	int item_cnt;
	item_cnt=this->_v_item.size();
	out.write((char*)&item_cnt,sizeof(item_cnt));
	vector<Item> ::iterator _itr;
	for(_itr=this->_v_item.begin();_itr!=_v_item.end();_itr++)
	{
		_itr->itemWriteToFile(out);
	}
	out.close();
}

void Order::readOrderFromFile(int table)
{
	int item_cnt;
	char str[32]="order_";
	char number[10][5]={"1","2","3","4","5","6","7","8","9","10"};
	strcat(str,number[table-1]);
	ifstream in;
	in.open(str,ios::in|ios::binary);
	in.read((char*)&_cust,sizeof(_cust));
	in.read((char*)&_st_str,sizeof(_st_str));
	in.read((char*)&item_cnt,sizeof(item_cnt));
	this->_v_item.clear();
	for(int index=0;index<item_cnt;index++)
	{
		_item.itemReadFromFile(in);
		this->_v_item.push_back(_item);
	}
	in.close();
}

void Order::displayOrder()
{
	cout<<"\n---------------------------------------------------\n";
	cout<<"Order Id: "<<this->_cust.getTableNo();
	cout<<"\tName: "<<this->_cust.getName();
	cout<<"\tStatus: "<<this->get_st_str();
	this->_total=0;
	vector<Item> ::iterator _itr;
	cout<<"\n================================================================\n";
	cout<<"Item Id\t\tName\t\tPrice\t\tQuantity\n";
	for(_itr=this->_v_item.begin();_itr!=this->_v_item.end();_itr++)
	{
		cout<<_itr->getItemId()<<"\t\t"<<_itr->getItemName()<<"\t\t"<<_itr->getPrice()<<"\t\t"<<_itr->getQuantity()<<endl;
		_total=_total+_itr->getQuantity()*_itr->getPrice();
	}
	this->setTotal(_total);
}

void Order::showServedOrders()
{
	this->_total=0;
	for (int i=0;i<10;i++)
	{
		char str[32]="order_";
		char number[10][5]={"1","2","3","4","5","6","7","8","9","10"};
		strcat(str,number[i]);
		ifstream in(str,ios::in|ios::binary);
		if(in.is_open())
		{
			this->_v_item.clear();
			in.read((char*)&_cust,sizeof(_cust));
			in.read((char*)&this->_st_str,sizeof(this->_st_str));
			if((strcmp(_st_str,"Served..!"))==0)
			{
					int item_cnt;
					in.read((char*)&item_cnt,sizeof(item_cnt));
					for(int i=0;i<item_cnt;i++)
					{
						Item item;
						item.itemReadFromFile(in);
						this->_v_item.push_back(item);
					}
					this->displayOrder();
					cout<<"\n================================================================\n";
					cout<<"Total: "<<this->_total;
					cout<<"\n================================================================\n";
			}
		}
		in.close();
	}
}

void Order::showReadyOrders()
{
	this->_total=0;
	for (int i=0;i<10;i++)
	{
		char str[32]="order_";
		char number[10][5]={"1","2","3","4","5","6","7","8","9","10"};
		strcat(str,number[i]);
		ifstream in(str,ios::in|ios::binary);
		if(in.is_open())
		{
			this->_v_item.clear();
			in.read((char*)&_cust,sizeof(_cust));
			in.read((char*)&this->_st_str,sizeof(this->_st_str));
			if((strcmp(_st_str,"Ready..!"))==0)
			{
					int item_cnt;
					in.read((char*)&item_cnt,sizeof(item_cnt));
					for(int i=0;i<item_cnt;i++)
					{
						Item item;
						item.itemReadFromFile(in);
						this->_v_item.push_back(item);
					}
					this->displayOrder();
			}
		}
		in.close();
	}
}

void Order::showInprocessOrders()
{
	this->_total=0;
	for (int i=0;i<10;i++)
	{
		char str[32]="order_";
		char number[10][5]={"1","2","3","4","5","6","7","8","9","10"};
		strcat(str,number[i]);
		ifstream in(str,ios::in|ios::binary);
		if(in.is_open())
		{
			this->_v_item.clear();
			in.read((char*)&_cust,sizeof(_cust));
			in.read((char*)&this->_st_str,sizeof(this->_st_str));
			if((strcmp(_st_str,"InProcess..!"))==0)
			{
					int item_cnt;
					in.read((char*)&item_cnt,sizeof(item_cnt));
					for(int i=0;i<item_cnt;i++)
					{
						Item item;
						item.itemReadFromFile(in);
						this->_v_item.push_back(item);
					}
					this->displayOrder();
			}
		}
		in.close();
	}
}

void Order::showAllOrders()
{
	for (int i=0;i<10;i++)
	{
		char str[32]="order_";
		char number[10][5]={"1","2","3","4","5","6","7","8","9","10"};
		strcat(str,number[i]);
		ifstream in(str,ios::in|ios::binary);
		if(in.is_open())
		{
			this->_v_item.clear();
			in.read((char*)&_cust,sizeof(_cust));
			in.read((char*)&this->_st_str,sizeof(this->_st_str));
			int item_cnt;
			in.read((char*)&item_cnt,sizeof(item_cnt));
			for(int i=0;i<item_cnt;i++)
			{
				Item item;
				item.itemReadFromFile(in);
				this->_v_item.push_back(item);
			}
			this->displayOrder();
			if((strcmp(_st_str,"Served..!"))==0)
			{
				cout<<"================================================================\n";
				cout<<"Total: "<<this->_total;
			}
		}
		in.close();
	}
}

void Order::showTodayBill()
{
	_date_today.setSystemTime();
	int table_no,flag=0,display_flag=0;
	char name[64];
	ifstream infile("Bill.dat",ios::in|ios::binary);
	while(!infile.eof())
	{
			infile.read((char*)&_date,sizeof(_date));
			infile.read((char*)&table_no,sizeof(table_no));
			infile.read((char*)&name,sizeof(name));
			infile.read((char*)&_total,sizeof(_total));
			if(!infile.eof())
			{
				if(_date.getDay()==_date_today.getDay() && _date.getMonth() == _date_today.getMonth() && _date.getYear() == _date_today.getYear())
				{
					if(display_flag==0)
					{
						cout<<"\n-------------------------------------------------------------";
						cout<<"\n                     Today's Bills                           ";
						cout<<"\n-------------------------------------------------------------";
						cout<<"\nDate\tRoom No/Table No\tCustomer Name\tToday Bill\n";
						cout<<"\n-------------------------------------------------------------";
						display_flag=1;
					}
					cout<<"\n";
					_date.displayDate();
					cout<<"\t"<<table_no<<"\t\t"<<name<<"\t"<<_total;
					flag=1;
				}
			}
	}
	infile.close();
	if(flag==0)
	{
		cout<<"\n--**There Are No Bills Of Givan Date Range**--";
	}
}

void Order::showGivenRangeBill()
{
	int table_no,flag=0,display_flag=0;
	char name[64];
	cout<<"\nEnter Starting Date: ";
	_start_date.acceptDate();
	cout<<"\nEnter End Date: ";
	_end_date.acceptDate();
	ifstream infile("Bill.dat",ios::in|ios::binary);
	while(!infile.eof())
	{
			infile.read((char*)&_date,sizeof(_date));
			infile.read((char*)&table_no,sizeof(table_no));
			infile.read((char*)&name,sizeof(name));
			infile.read((char*)&_total,sizeof(_total));
			if(!infile.eof())
			{
				//comparisons like X<=Y<=Z do not have their mathematical meaning so taken multiple and(&&) to check
				if(((_start_date.getDay() <= _date.getDay()) && (_date.getDay() <= _end_date.getDay()))
						&& ((_start_date.getMonth() <= _date.getMonth()) && (_date.getMonth()<= _end_date.getMonth()))
						&& ((_start_date.getYear() <= _date.getYear()) && (_date.getYear()<= _end_date.getYear())))
					{
						if(display_flag==0)
						{
							cout<<"\n-------------------------------------------------------------";
							cout<<"\n                 Bills Of Given Date Range                   ";
							cout<<"\n-------------------------------------------------------------";
							cout<<"\nDate\tRoom No/Table No\tCustomer Name\tToday Bill\n";
							cout<<"\n-------------------------------------------------------------";
							display_flag=1;
						}
						cout<<"\n";
						_date.displayDate();
						cout<<"\t"<<table_no<<"\t\t"<<name<<"\t"<<_total;
						flag=1;
					}
			}
	}
	infile.close();
	if(flag==0)
	{
		cout<<"\n--**There Are No Bills Of Given Date Range**--";
	}
}

