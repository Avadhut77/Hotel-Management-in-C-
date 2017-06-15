#ifndef __DATE_H_
#define __DATE_H_

class Date
{
private:
	int _day;
	int _month;
	int _year;
public:
	Date();
	int getDay();
	void setDay(int day);
	int getMonth();
	void setMonth(int month);
	int getYear();
	void setYear(int year);
	void acceptDate();
	void displayDate();
	void setSystemTime();
	int getDuration(Date &date);
};

#endif
