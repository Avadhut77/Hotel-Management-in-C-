#include"Address.h"
#include"Customer_L.h"
#include"Person.h"
#include"Date.h"
#include"Room.h"
#include"Bookroom.h"
#include"Item.h"
#include"Order.h"
#include"Captain.h"
#include"Chef.h"

#include<fstream>
#include<iostream>
#include<stdlib.h>

int main()
{
	int ch;
	Book_Room _book_room;
	Room _room;
	Order _order;
	Captain _captain;
	Chef _chef;
	while(1)
	{
		main:
		std::cout<<"\n**********MAIN MENU*********\n0.Exit\n1.Manager\n2.Caption\n3.Chef\n4.Receptionist\nEnter YOur Choice: ";
		std::cin>>ch;
		system("clear");
		switch(ch)
		{
			case 0:
				system("clear");
				exit(0);
			case 1:
				manager:
				std::cout<<"\n*****Manager Menu******\n0.Exit\n1.Manage Food Menu\n2.Manage Room Charges\n3.Manage Billing\n4.Review All Order Status\nEnter Your Choice: ";
				std::cin>>ch;
				system("clear");
				switch(ch)
				{
					case 0:
						system("clear");
						goto main;
					case 1:
						again1:
						std::cout<<"\n*****Manage Food Menu*****\n0.Exit\n1.Add Menu Item\n2.View Menu Item\n3.Edit Menu Item\n4.Delete Menu Item\nEnter Your Choice: ";
						std::cin>>ch;
						system("clear");
						switch(ch)
						{
							case 0:
								system("clear");
								goto manager;
							case 1:
								::addItem();
								break;
							case 2:
								::renderItem();
								break;
							case 3:
								::renderItem();
								cout<<"\nEnter Item Id You Want To Edit: ";
								cin>>ch;
								::editItem(ch);
								break;
							case 4:
								::renderItem();
								cout<<"\nEnter Item Id You Want To Delete: ";
								cin>>ch;
								::deleteItem(ch);
								break;
						}
						goto again1;
					case 2:
						again2:
						std::cout<<"\n*****Manage Rooom Charges*****\n0.Exit\n1.Edit Room Charges(Create)\n2.View Room Charges\nEnter Your Choice: ";
						std::cin>>ch;
						switch(ch)
						{
						case 0:
							system("clear");
							goto manager;
						case 1:
							_room.createRoom();
							break;
						case 2:
							_room.renderRoom();
							break;
						}
						goto again2;
					case 3:
						again3:
						std::cout<<"\n*****Manage Billing*****\n0.Exit\n1.View Bills Of Given Date Range\n2.View Todays Bills\nEnter Your Choice: ";
						std::cin>>ch;
						system("clear");
						switch(ch)
						{
							case 0:
								system("clear");
								goto manager;
							case 1:
								_order.showGivenRangeBill();
								break;
							case 2:
								_order.showTodayBill();
								break;
						}
						goto again3;
					case 4:
						cout<<"\n--**You Are In Review All Order Status Section";
						_order.showAllOrders();
						break;
				}
				goto manager;
			case 2:
				captain:
				std::cout<<"\n*****Captain Menu*****\n0.Exit\n1.Take Order\n2.Serve Order\nEnter Your Choice: ";
				std::cin>>ch;
				system("clear");
				switch(ch)
				{
					case 0:
						system("clear");
						goto main;
					case 1:
						_captain.captainTakeOrder();
						break;
					case 2:
						_captain.captainServeOrder();
						break;
				}
				goto captain;
			case 3:
				chef:
				std::cout<<"\n*****Chef Menu*****\n0.Exit\n1.See All Pending Orders\n2.Prepare Order\nEnter Your Choice: ";
				std::cin>>ch;
				system("clear");
				switch(ch)
				{
					case 0:
						system("clear");
						goto main;
					case 1:
						_order.showInprocessOrders();
						break;
					case 2:
						_chef.chefProcessOrder();
						break;
				}
				goto chef;
			case 4:
				receptionist:
				std::cout<<"\n*****Receptionist Menu*****\n0.Exit\n1.Register Customer\n2.Restaurant Billing\n3.Room Booking(Check-In)\n4.Room Biing(Check-Out)\nEnter Your Choice: ";
				std::cin>>ch;
				system("clear");
				switch(ch)
				{
					case 0:
						system("clear");
						goto main;
					case 1:
						::addCustomer();
						break;
					case 2:
						std::cout<<"\n2.Restaurant Billing";
						_order.showServedOrders();
						break;
					case 3:
						std::cout<<"\n3.Room BOoking(Check-In)";
						_book_room.roomBookingCheckIn();
						break;
					case 4:
						std::cout<<"\nRoom Billing(Check-Out)";
						_book_room.roomBookingCheckOut();
						break;
				}
				goto receptionist;
		}
	}
	return 0;
}
