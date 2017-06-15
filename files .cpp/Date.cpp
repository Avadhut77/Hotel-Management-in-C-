#include"Date.h"

#include<iostream>
#include<ctime>

using namespace std;

Date::Date()
{
		this->_day=0;
		this->_month=0;
		this->_year=0;
}

int Date::getDay()
{
	return this->_day;
}

void Date::setDay(int day)
{
	this->_day=day;
}

int Date::getMonth()
{
	return this->_month;
}

void Date::setMonth(int month)
{
	this->_month=month;
}

int Date::getYear()
{
	return this->_year;
}

void Date::setYear(int year)
{
	this->_year=year;
}

void Date::acceptDate()
{
	again:
	std::cin>>this->_day>>this->_month>>this->_year;
	if(_day>31)
	{
		std::cout<<"\nEnter Correct Date: ";
		goto again;
	}
	if(_month>12)
	{
		std::cout<<"\nEnter Correct Date: ";
		goto again;
	}
	if(_year%4==0)
	{
		if(_month==2)
		{
			if(_day>29)
			{
				std::cout<<"\nEnter Correct Date: ";
				goto again;
			}
		}
	}
	if(_year%4!=0)
	{
		if(_month==2)
		{
			if(_day>28)
			{
				std::cout<<"\nEnter Correct Date: ";
				goto again;
			}
		}
	}
}

void Date::displayDate()
{
	std::cout<<_day<<"/"<<_month<<"/"<<_year<<"\t";
}

void Date::setSystemTime()
{
	time_t current_time;
	tm *_localtime;
	time(&current_time);
	_localtime = localtime(&current_time);
	this->_day=_localtime->tm_mday;
	this->_month=_localtime->tm_mon+1;
	this->_year=_localtime->tm_year+1900;
}

int Date::getDuration(Date &date)
{
	return (date._day - this->_day);
}
