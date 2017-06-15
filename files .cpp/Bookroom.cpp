#include"Bookroom.h"
#include<iostream>
#include<fstream>
#include<cstring>

Book_Room::Book_Room()
{
	_total=0;
}

double Book_Room::getTotal()
{
	return this->_total;
}

void Book_Room::setTotal(double total)
{
	this->_total=total;
}

void Book_Room::displayRoomBooking()
{
	cout<<"\n==============================================================================";
	std::cout<<"\nRoom No: "<<_room_obj.getRoomNo()<<"\tRoom Suit: "<<_room_obj.getDesc()<<"\tRoom Charge: "<<_room_obj.getRoomCharge()<<"\tRoom status: "<<_room_obj._st_str<<"\nCustomer Name: "<<_cust_l.getName()<<"\tCheck-In Time: "<<check_in.getDay()<<"/"<<check_in.getMonth()<<"/"<<check_in.getYear();
	cout<<"\n==============================================================================";
}

void Book_Room::writeBookroomToFile(std::ofstream& outfile)
{
	outfile.write((char *)this,sizeof(*this));
}

void Book_Room::readBookroomFromFile(std::ifstream& infile)
{
	infile.read((char*)this, sizeof(*this));
}

void Book_Room::viewRoomBooking()
{
	string temp;
	std::ifstream infile;
	infile.open("BookRoom.dat",std::ios::in | std::ios::binary);
	while(!infile.eof())
	{
		this->readBookroomFromFile(infile);
		if(!infile.eof())
		{
			if(this->_room_obj.getRoomStatus()==BOOKED)
			{
				this->displayRoomBooking();
			}
		}
	}
}

void Book_Room::roomBookingCheckIn()
{
	this->_room_obj.renderRoom();
	std::fstream infile;
	infile.open("Room.dat",std::ios::in|std::ios::out|std::ios::binary);
	std::ofstream outfile;
	outfile.open("BookRoom.dat", std::ios::out | std::ios::binary | std::ios::app );
	_cust_l.acceptCustomer();
	std::cout<<"\nEnter Date(Check-In): ";
	this->check_in.acceptDate();
	_room_obj.editRoom(_cust_l.getRoomNo());
	while(infile.read((char *)&_room_obj,sizeof(_room_obj)))
	{
		if(_room_obj.getRoomNo()==_cust_l.getRoomNo())
			outfile.write((char *)this,sizeof(*this));
	}
	infile.close();
	outfile.close();
}

void Book_Room::roomBookingCheckOut()
{
	Book_Room b;
	int room_no,_day_diff;
	this->viewRoomBooking();
	cout<<"\nEnter Room No For Chceck Out: ";
	cin>>room_no;
	b=this->searchBookRoom(room_no);
	b.check_out.setSystemTime();
	_day_diff=b.check_in.getDuration(b.check_out);
	b.setTotal((_day_diff)*(b._room_obj.getRoomCharge()));
	b.displayRoomBookingCheckoutBill();
}

void Book_Room::displayRoomBookingCheckoutBill()
{
	cout<<"\n=======================================================================================";
	std::cout<<"\nRoom No: "<<_room_obj.getRoomNo()<<"\tRoom Suit: "<<_room_obj.getDesc()<<"\tRoom Charge: "<<_room_obj.getRoomCharge()<<"\tRoom status: "<<_room_obj._st_str;
	std::cout<<"\nCustomer Name: "<<_cust_l.getName()<<"\tCheck-In Time: "<<check_in.getDay()<<"/"<<check_in.getMonth()<<"/"<<check_in.getYear()<<"\tTotal Bill: "<<getTotal();
	cout<<"\n=======================================================================================";
}

Book_Room Book_Room::searchBookRoom(int room_no)
{
	std::ifstream infile("BookRoom.dat",std::ios::in | std::ios::binary);
	infile.seekg(0, std::ios::end);
	int count = infile.tellg() / sizeof(Book_Room);
	Book_Room BK;
	infile.seekg(0, std::ios::beg);
	for(int i=0;i<count;i++)
	{

		infile.read((char*)&BK, sizeof(Book_Room));
		if(BK._room_obj.getRoomNo()==room_no)
		{
			BK._room_obj.displayRoom();
			break;
		}
	}
   	infile.close();
   	return BK;
}

