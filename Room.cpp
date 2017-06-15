#include"Room.h"

#include<iostream>
#include<fstream>
#include<cstring>

Room::Room()
{
	_room_no=0;
	strcpy(_desc,"None");
	_st_r=AVAILABLE;
	_room_charge=0;
}

double Room::getRoomCharge()
{
	return this->_room_charge;
}

void Room::setRoomCharge(double room_charge)
{
	this->_room_charge=room_charge;
}

int Room::getRoomNo()
{
	return this->_room_no;
}

void Room::setRoomNo(int room_no)
{
	this->_room_no=room_no;
}

char* Room::getDesc()
{
	return this->_desc;
}

void Room::setDesc(char desc[64])
{
	strcpy(this->_desc,desc);
}

enum R_STATUS Room::getRoomStatus()
{
	return this->_st_r;
}

char* Room::getRoomStatusSring()
{
	return this->_st_str;
}

void Room::setRoomStatus(enum R_STATUS st_r)
{
	switch(st_r)
	{
		case AVAILABLE:
				strcpy(_st_str,"AVAILABLE");
				break;
		case BOOKED:
				strcpy(_st_str,"BOOKED");
				break;
	}
	this->_st_r=st_r;
}

void Room::acceptRoom()
{
	std::cout<<"\nEnter Room No: ";
	std::cin>>_room_no;
	std::cout<<"\nEnter Room Desc(Name): ";
	std::cin>>_desc;
	std::cout<<"\nEnter Room Charge: ";
	std::cin>>_room_charge;
}

void Room::displayRoom()
{
	std::cout<<"\n"<<_room_no<<"\t\t"<<_desc<<"\t\t"<<_room_charge<<"\t\t"<<this->_st_str;
}

void Room::writeRoomToFile(std::fstream& outfile)
{
	outfile.write((char *)this,sizeof(*this));
}

void Room::readRoomFromFile(std::fstream& infile)
{
	infile.read((char*)this, sizeof(*this));
}

void Room::createRoom()
{
	std::fstream outfile;
	std::cout<<"\n--**Enter Room Details**--";
	this->acceptRoom();
	this->setRoomStatus(AVAILABLE);
	outfile.open("Room.dat", std::ios::out | std::ios::binary | std::ios::app );
	this->writeRoomToFile(outfile);
}

void Room::renderRoom()
{
	std::fstream infile;
	infile.open("Room.dat",std::ios::in | std::ios::binary);
	std::cout<<"\nRoom No\t\tSuit Name\t\tCharge\t\tStatus";
	std::cout<<"\n----------------------------------------------------------------\n";
	while(!infile.eof())
	{
		this->readRoomFromFile(infile);
		if(!infile.eof())
			this->displayRoom();
	}
}

void Room::editRoom(int room_no)
{
	std::fstream fin;
	int status;
	fin.open("Room.dat", std::ios::in | std::ios::out | std::ios::ate | std::ios::binary);
	fin.seekg(0);
	if(!fin)
	{
		std::cout<<"--**File not found**--";
	}
	else
	{

		while(fin.read((char*)this, sizeof(*this)))
		{
			if(this->_room_no==room_no)
			{
				std::cout<<"\nEnter Room Status[AVAILABLE(0)/BOOKED(1)]: ";
				std::cin>>status;
				switch(status)
				{
					case 0:
						this->setRoomStatus(AVAILABLE);
						break;
					case 1:
						this->setRoomStatus(BOOKED);
						fin.seekp(-1*sizeof(*this),std::ios::cur);
						fin.write((char *)this,sizeof(*this));
						break;
				}

			}
		}
	}
	fin.close();
}
