#ifndef  __ROOM_H
#define  __ROOM_H

#include<fstream>

enum R_STATUS{AVAILABLE,BOOKED};

class Room
{
private:
	int _room_no;
	char _desc[64];
	enum R_STATUS _st_r;
	double _room_charge;
public:
	char _st_str[64];
	Room();
	double getRoomCharge() ;
	void setRoomCharge(double roomCharge);
	int getRoomNo();
	void setRoomNo(int roomNo);
	char* getDesc();
	void setDesc(char desc[64]);
	enum R_STATUS getRoomStatus();
	void setRoomStatus(enum R_STATUS st_r);
	char* getRoomStatusSring();
	void acceptRoom();
	void displayRoom();
	void writeRoomToFile(std::fstream& outfile);
	void readRoomFromFile(std::fstream& infile);

	void createRoom();
	void renderRoom();
	void editRoom(int room_no);
};

Room search_Room(int i);

#endif
