# Hotel-Management-in-C-
Implementation of Hotel Managemet System in a C++ console based application.


Objective:
	Implement Hotel Management System in a C++ Console Based Application.
	
Requirements:
	The hotel management system has two major sections:
	1. Restaurant
	2. Lodging
	
	The hotel Cusotmer might have following requirements:
	1.Customer may use Restaurant (i.e. food).
	2.Customer may look for Lodging (i.e. book a room for stay).
	
	Consider following two restrictions during this project implementation:
	1. The restaurant has only 10 tables.
	2. The hotel has only 10 rooms.
	
Design:
	The console application for hotel management is a menu driven program. On first screen it enables user to choose his/her role. User may choose one of the following role:
	1. Manager
	2. Captain
	3. Chef
	4. Receptionist
	
Manager:
	Manager will b resposible for managing food & room charges and review bills. The key functionalities for the manager role will be as follows:
	1. Manage food menu
		a. Add menu item.
		b. View menu items.
		c. Edit menu item.
		d. Delete menu item.
	2. Edit room charges
		a. Edit room charges.
		b. View room charges.
	3. Manage billing
		a. View	bills of given date range.
		b. View today's bills.
	4. Review all order status.
	
Captain:
	Captain will be responsible to take order from customer. The key functionalities for the captain will bw as follws:
	1. Take order
		Take the order from the customer occupying some able in restaurant.
		The order may contain one or more items in single or multiple quantities.
	2. Serve order
		The orders prepared by chef are served to corresponding customer.
		
Chef:
	Chef will be responsible for prepare orders taken by captain. The key functionalities for the chef role will be as follws:
	1. See all pending orders
		Display all pending orders.
	2. Prepare order
		Mark the status of the order to READY.
		
Receptionist:
	The key functionalities for the receptionist will be as the follws:
	1. Register customer
		- Check available tables in restaurant.
		- If no table is empty, customer can wait.
		- If table is available, assign restaurant table to the customer.
	2. Restaurant billing
		- Check all served (finished) orders in restaurnt.
		- Generate bill for selected completed order.
	3. Room booking (Check-in)
		- Check acailable rooms in hotel.
		- If room is available, enter customer details and assign room to the customer.
	4. Room billing (Check-out)
		- calculate number of days for the room and room charges accordingly.
