// AirlineReservation.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "flight.h"
#include "Reservation.h"
#include "scheduleManager.h"


using namespace std;
using namespace AirlineReservation;

void displayFlightMenuSelected(ScheduleManager& scheduleManager);
int displayMainMenu();
void displaySearchOptionSelected(ScheduleManager& scheduleManager);

int main()
{

	Reservation reservation;
	int reservationId; //for looking up ticket to display and check-in
	ScheduleManager scheduleManager;
	//	scheduler.addDummyFlightInformation();
		//int optionSelectedM;
	while (1) {

		int optionSelectedM = displayMainMenu();
		switch (optionSelectedM) {
		case 1:
			displaySearchOptionSelected(scheduleManager);
			break;
		case 2:
			cout << "Reserving Flight" << endl;
			reservation = ScheduleManager::reserveFlight();
			//display the reservation
			reservation.display();
			break;
		case 3:
			cout << "Enter your reservation number to check-in for your flight: " << endl;
			cin >> reservationId;
			scheduleManager.passengerCheckin(reservationId);
			break;
		case 4:
			cout << "OPtion 3 Selected" << endl;
			break;
		case 5:
			cout << "Option 5 Selected" << endl;
			for (int i = 0; i<5; i++) {
				scheduleManager.dummyFlightInformation();
			}
			displayFlightMenuSelected(scheduleManager);

			break;
		case 6:
			cout << "Enter your reservation number to display your ticket: " << endl;
			cin >> reservationId;

			scheduleManager.displayTicket(reservationId);


			break;
		case 0:
			return 0;
		default:
			cout << "Default Selected" << endl;
			break;
		}
		system("CLS");
		cout<< flush;
	
	}
	return 0;
}
	
	int displayMainMenu() {
		int optionSelected;
		cout << "_____________________________________________________________________" << endl << endl;
		cout << "                       K A L'S    A I R L I N E         " << endl;
		cout << "_____________________________________________________________________" << endl << endl<<endl;
		cout << "	  1.-Search Flight Schedule" << endl;
		cout << "	  2.-Reserve Flight" << endl;
		cout << "	  3.-Flight Check-In " << endl;
		cout << "	  4.-Search Reservation" << endl;
		cout << "	  5.-Flight Information" << endl;
		cout << "	  6.-Display Ticket" << endl;
		cout << "	  0.-Exit" << endl<<endl;
		cout << "_____________________________________________________________________" << endl << endl;
		cout << " Please select an  option >> ";
		cin >> optionSelected;
		return optionSelected;
	}


	void displayFlightMenuSelected(ScheduleManager& scheduleManager) {

		int flightMenuOption;
		int flightId;
		while (true) {
			cout << " ****************Flight Information ****************" << endl;

			cout << " 1 - Add Flight  " << endl;
			cout << " 2 - Delete Flight " << endl;
			cout << " 3 - Display All Flights Details" << endl;
			cout << " 0 - To Go Back to Main Menu" << endl;
			cout << " Please Select Option ";
			cin >> flightMenuOption;

			switch (flightMenuOption) {

			case 1:
				scheduleManager.addFlightInformation();				
				break;
			case 2:
				cout << "Enter the FlightId" << endl;
				cin >> flightId;
				scheduleManager.deleteFlight(flightId);
				break;
			case 3:
				cout << "Displaying All Flights Information " << endl;
				scheduleManager.displayAllFlights();
				break;
			case 0:
				return;

			default:
				cout << " Enter Correct Option" << endl;
				break;
			}
		}
	}

		void displaySearchOptionSelected(ScheduleManager& scheduleManager) {
			system("CLS");
			cout<< flush;
			cout << "_____________________________________________________________________" << endl <<endl;
			cout << "                       K A L'S    A I R L I N E         " << endl;	
			cout << "_____________________________________________________________________" << endl << endl;
			cout << "    S E A R C H      F L I G H T         " << endl<<endl<<endl;
	
			string departure = "";
			string destination = "";
			int departingMonth;
			int departingDay;
			int departingYear;
			string departingDate;
			string arrivingTime;
			string anyStr;
	
			//	std::vector<Flight> FlightsFound;
	
			cout << "Fying from: ";
			getline(cin, departure);
			cout << "Flying to:";
			getline(cin, destination);
			cout << "Fying from:" << departure;
			cout << "Flying to:" << destination;
			cout << "Departing Date(MM/DD/YY):";
			cin >> departingDate;
		}

	

// BOrrame
//
//// AirlineReservation.cpp : Defines the entry point for the console application.
////
//#include "stdafx.h"
//#include "flight.h"
//#include <stdlib.h>
//#include <iostream>
//#include <string>
//#include <sstream>
//
//#include "scheduleManager.h"
//
//
//	using namespace std;
//	using namespace AirlineReservation;
//
//	void displayFlightMenuSelected(ScheduleManager& scheduleManager);
//	int displayMainMenu();
//	void displaySearchOptionSelected(ScheduleManager& scheduleManager);
//
	//int main()
	//

	//	ScheduleManager scheduler;
	//	scheduler.addDummyFlightInformation();



	//	while (true) {
	//		int optionSelected = displayMainMenu();
	//		switch (optionSelected) {
	//		case 1:
	//			displaySearchOptionSelected(scheduler);
	//			break;
	//		case 2:
	//			cout << "Reserve Flight Selected" << endl;
	//			break;
	//		case 3:
	//			cout << "Ticket Information Selected" << endl;
	//			break;
	//		case 4:
	//			cout << "Search Reservation Selected" << endl;
	//			break;
	//		case 5:
	//			cout << "Option 5 Selected" << endl;
	//			cout << " Flight Information" << endl;
	//			//int flightOptionSelected;
	//			displayFlightMenuSelected(scheduler);

	//			/*
	//			sm.addFlightInformation();
	//			sm.addFlightInformation();

	//			sm.displayAllFlights();
	//			*/
	//			break;
	//		case 6:
	//			cout << "Ticket Information Selected" << endl;
	//			break;
	//		case 0:
	//			return 0;

	//		default:
	//			string anyStr;
	//			cout << "   Please select an  option: ";
	//			cerr << "   Enter a Valid option. Press any key to continue" << endl; // need to accept enter as a key.
	//			cin >> anyStr;
	//			break;
	//		}
	//		cout << flush;
	//		system("CLS");
	//	}

	//	return 0;
	//}
//
//

//
//		cin >> anyStr;
//
//
//
//
//}