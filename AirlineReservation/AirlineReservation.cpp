// AirlineReservation.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

#include "scheduleManager.h"


using namespace std;
using namespace AirlineReservation;

void displayFlightMenuSelected(ScheduleManager& scheduleManager);
int displayMainMenu();
void displaySearchOptionSelected(ScheduleManager& scheduleManager);

int main()
{
	
	ScheduleManager scheduler;
	scheduler.addDummyFlightInformation();

	
	
	while (true) {			
		int optionSelected = displayMainMenu();
		switch (optionSelected) {
		case 1:
			displaySearchOptionSelected(scheduler);
			break;
		case 2:
			cout << "OPtion 2 Selected" << endl;
			break;
		case 3:
			cout << "OPtion 3 Selected" << endl;
			break;
		case 4:
			break;
		case 5:
			cout << "Option 5 Selected" << endl;
			cout << " Flight Information" << endl;
			//int flightOptionSelected;
			displayFlightMenuSelected(scheduler);
			
			/*
			sm.addFlightInformation();
			sm.addFlightInformation();
			
		    sm.displayAllFlights();
			*/
			break;
		case 0:
			return 0;
		
		default:
			string anyStr;
			cout << "   Please select an  option: ";
			cerr << "   Enter a Valid option. Press any key to continue" << endl; // need to accept enter as a key.
			cin >> anyStr;
			break;
		}		
		cout<< flush;
		system("CLS");
	}
	
	return 0;
}

int displayMainMenu() {
	int optionSelected;
	cout << "*********************************************************************" << std::endl;
	cout << "            W E L C O M E     T O   K A L'S    A I R L I N E         " << endl;
	cout << "*********************************************************************" << endl << endl;
	cout << "   Please select an  option:" << endl;
	cout << "	  1.-Search Flight Schedule" << endl;
	cout << "	  2.-Reserve Flight" << endl;
	cout << "	  3.-Check-In " << endl;
	cout << "	  4.-Search Reservation" << endl;
	cout << "	  5.-Flight Information" << endl;
	cout << "	  0.-Exit" << endl;
	cout << "   Please select an  option: ";
	cin >> optionSelected;
	return optionSelected;
}

void displayFlightMenuSelected(ScheduleManager& scheduleManager) {
	int flightMenuOption;
	while (true) {
		cout << " ****************Flight Information ****************" << endl;

		cout << " 1 - Add Flight  " << endl;
		cout << " 2 - Delete Flight " << endl;
		cout << " 3 - Display All Flights Details" << endl;
		cout << " 0 - To Go Back to Menu" << endl;
		cout << " Please Select Option ";
		cin >> flightMenuOption;

		switch (flightMenuOption) {
			int flightId;

		case 1:
			scheduleManager.addFlightInformation();
			cout << " Added Flight Details" << endl;
			break;
		case 2:
			cout << "Enter the FlightId" << endl;
			cin >> flightId;
			scheduleManager.deleteFlight(flightId);
			break;
		case 3:
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
	
	string departure = "";
	string destination = "";
	int departingMonth;
	int departingDay;
	int departingYear;
	string departingTime;
	string arrivingTime;
	string anyStr;

	cout << "Fying from: ";
	cin >> departure;
	cout << "Flying to:";
	cin >> destination;
	cout << "Departing Date(MM/DD/YY):";
	//cin >> departingDate;

	std::cin >> departingMonth;
	std::cin.get();
	std::cin >> departingDay;
	std::cin.get();
	std::cin >> departingYear;
	std::cout << "input date: " << departingDay << "/" << departingMonth << "/" << departingYear << "\n";
	cin >> anyStr;
	//int d;
	//int m;
	//int y;
	//string anyStr;

	//std::cin >> d; // read the day
	//if (std::cin.get() != '/') // make sure there is a slash between DD and MM
	//{
	//	std::cout << "expected /\n";
	//	cerr << "   Enter a Valid option. Press any key to continue" << endl; // need to accept enter as a key.
	//	cin >> anyStr;
	//	return ;
	//}
	//std::cin >> m; // read the month
	//if (std::cin.get() != '/') // make sure there is a slash between MM and YYYY
	//{
	//	std::cout << "expected /\n";
	//	return ;
	//}
	//std::cin >> y; // read the year
	//std::cout << "input date: " << d << "/" << m << "/" << y << "\n";
	

}