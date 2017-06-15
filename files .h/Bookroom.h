#ifndef __BOOKROOM_H
#define __BOOKROOM_H_

#include"Date.h"
#include"Customer_L.h"
#include"Room.h"

class Book_Room
{
private:
	Room _room_obj;
	Date check_in;
	Date check_out;
	Customer_L _cust_l;
	double _total;
public:
	Book_Room();
	double getTotal() ;
	void setTotal(double total);
	void displayRoomBooking();
	void writeBookroomToFile(std::ofstream& outfile);
	void readBookroomFromFile(std::ifstream& infile);
	void viewRoomBooking();
	void roomBookingCheckIn();
	void roomBookingCheckOut();
	void displayRoomBookingCheckoutBill();
	Book_Room searchBookRoom(int room_no);
};

#endif
