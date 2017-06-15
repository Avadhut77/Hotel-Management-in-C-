#ifndef __ADDRESS_H_
#define __ADDRESS_H_

#include<fstream>
#include<cstring>

class Address
{
private:
	char _city[128];
public:
	Address();
	Address(char city[100]);
	void setAddress(char city[100]);
	char* getAddress();
	void acceptAddress();
	void displayAddress();
	friend std::ostream& operator<<(std::ostream& out,Address& A);
};

#endif
