// AirlineReservation.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <ostream> 
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iomanip> 
#include "flight.h"
#include "Reservation.h"
#include "scheduleManager.h"
#include "Utils.h"



using namespace std;
using namespace AirlineReservation;

void displayFlightMenuSelected(ScheduleManager& scheduleManager);
int displayMainMenu();
int displaySearchOptionSelected(ScheduleManager& scheduleManager,bool forReservation);
void displayFlights(vector<Flight> & flights, ScheduleManager& scheduleManager);
void displayHeadersForTableFlights(string tableHeader);
void displayAllFlights(ScheduleManager& scheduleManager,string tableHeader);
string inputDate();
void pauseAndClear();
void checkCin();

int main()
{

	Reservation reservation;
	int reservationId; //for looking up ticket to display and check-in
	ScheduleManager scheduleManager;
	////add dummy flights
	//for (int i = 0; i<5; i++) {
	//	scheduleManager.dummyFlightInformation();
	//}

	scheduleManager.uploadFlightsFromSource();

	while (1) {

		int optionSelectedM = displayMainMenu();
		
		switch (optionSelectedM) {
		case 1:
			displaySearchOptionSelected(scheduleManager, false);
			break;
		case 2:
			if (displaySearchOptionSelected(scheduleManager, true) == 1) {
			reservation = scheduleManager.reserveFlight();
			//display the reservation
			reservation.display();
			pauseAndClear();
			}
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
			cout << "Flight Schedule" << endl;
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
			if (cin.fail())
			{
				cout << "ERROR -- You did not enter a Valid Option"<<endl;
				cin.clear();		
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			pauseAndClear();
			break;
		}
	}
	return 0;
}

//View Headers

void displayTitle() {
	cout << "_____________________________________________________________________" << endl << endl;
	cout << "                       K A L'S    A I R L I N E         " << endl;
	cout << "_____________________________________________________________________" << endl << endl;
}

void displayHeader1(string text) {
	cout << "    "<<text <<"       " << endl << endl ;
}

void displayFooterSelectAnOption() {
	cout << "_____________________________________________________________________" << endl << endl;
	cout << " Please select an  option >> ";
}

void displayHeadersForTableFlights(string tableHeader) {
	
	displayHeader1(tableHeader);
	cout << "___________________________________________________________________________________________________________________" << endl << endl;
	cout << setw(8) << "NUMBER" << setw(8) << "DATE" << setw(17) << "DEPART TIME"
		<< setw(15) << "ARRIVAL TIME" << setw(13) << "DEPARTURE" << setw(10) << "ARRIVAL" << setw(20) << "DEPART AIRPORT" << setw(22) << "ARRIVAL AIRPORT\n";
	cout << "___________________________________________________________________________________________________________________" << endl << endl;
}

int displayMainMenu() {
	int optionSelected=-1;	
	displayTitle();
	cout << endl;
	cout << "	  1.-Search Flight Schedule" << endl;
	cout << "	  2.-Reserve Flight" << endl;
	cout << "	  3.-Flight Check-In " << endl;
	cout << "	  4.-Search Reservation" << endl;
	cout << "	  5.-Flight Information" << endl;
	cout << "	  6.-Display Ticket" << endl;
	cout << "	  0.-Exit" << endl << endl;
	displayFooterSelectAnOption();
	cin >> optionSelected;
	return optionSelected;
}

void displayFlightMenuSelected(ScheduleManager& scheduleManager) {
	int flightMenuOption;
	int flightId;
	system("CLS");
	cout << flush;
	while (true) {
		displayTitle();
		displayHeader1("F L I G H T  I N F O R M A T I O N");
		cout << " 1 - Add Flight  " << endl;
		cout << " 2 - Delete Flight " << endl;
		cout << " 3 - Display All Flights Details" << endl;
		cout << " 0 - To Go Back to Main Menu" << endl;
		displayFooterSelectAnOption();
		cin >> flightMenuOption;

		switch (flightMenuOption) {

		case 1:
			scheduleManager.addFlightInformation();
			break;
		case 2:
			cout << "Enter the Flight Number" << endl;
			cin >> flightId;
			scheduleManager.deleteFlight(flightId);
			break;
		case 3:
			cout << endl;
			displayAllFlights(scheduleManager,"A L L    F L I G H T S    I N F O R M A T I O N");
			pauseAndClear();
			break;
		case 0:
			system("CLS");
			return;
		default:
			if (cin.fail())
			{
				cout << " You did not enter a Valid Option" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			pauseAndClear();
			break;
		}
	}
}

int displaySearchOptionSelected(ScheduleManager& scheduleManager, bool forReservation) {
	system("CLS");
	cout << flush;
	scheduleManager.uploadFlightsFromSource();	
	string departure = "";
	string destination = "";
	string departingDate;	

	displayTitle();
	displayHeader1("S E A R C H      F L I G H T");
	try {
		cout << "    Fying from: >>  ";
		cin >> departure;
		cout << endl << "    Flying to: >>  ";
		cin >> destination;
	
		departingDate=inputDate();
			vector<Flight> FlightsFound = scheduleManager.searchFlights(departingDate, Utils::toUpper(departure), Utils::toUpper(destination));
			displayFlights(FlightsFound,scheduleManager);
			if(!forReservation)
				pauseAndClear();
			

			return 1;
	}
	catch (const std::logic_error& exception) {
		cerr << "     " << exception.what() << endl;
		pauseAndClear();
		return 0;
	}
}

void displayAllFlights(ScheduleManager& scheduleManager,string tableHeader)  {
	
	displayHeadersForTableFlights(tableHeader);
	for (const auto& flight : scheduleManager.getAllFlights()) {
		flight.displayFlight();
	}
	cout << endl << "___________________________________________________________________________________________________________________" << endl << endl;
}

void displayFlights(vector<Flight> &flights, ScheduleManager& scheduleManager) {
	cout << endl << endl;
	displayHeadersForTableFlights("F L I G H T S");
	for (const auto& flight : flights) {
		flight.displayFlight();
	}
	cout << endl << "___________________________________________________________________________________________________________________" << endl << endl;
}

string inputDate() {
	int month;
	int day;
	int year;
	
	try {
		cout <<endl<< "    Departing Year:  >>  ";
		cin >> year;
		if (year<2018 || year >2099)
			throw logic_error("Year is not valid");

		cout << endl<<endl<<"    M O N T H S" << endl << endl;
		cout << setw(12)<< "1 JANUARY" 
			 << setw(15) << "2 FEBRUARY"
			 << setw(14) << "3 MARCH" << endl;
		cout << setw(10) << "4 APRIL" 
			<< setw(12) << "5 MAY" 
			<< setw(18) << "6 JUNE" << endl;
		cout << setw(9) << "7 JULY" 
			<< setw(16) << "8 AUGUST"
			<< setw(20) << "9 SEPTEMBER" << endl;
		cout << setw(13) << "10 OCTOBER"
			<< setw(15) << "11 NOVEMBER"
			<< setw(17) << "12 DECEMBER" << endl << endl;
		
		cout <<endl << "   Number Departing Month:  >>  ";
		cin >> month;
		if (month <1 || month>12)
			throw logic_error("Month is not valid");
		
		Utils::printCalendar(year, month-1);
		cout <<endl << "    Departing Day:  >>  ";
		cin >> day;
		Utils::isValidDate(month, day, year - 2000);
		return Utils::toString(month,day,year-2000);

	}
	catch (const std::logic_error& exception) {
		throw exception;
	
	}
}

void pauseAndClear() {
	cin.clear();	
	system("PAUSE");
	cout << endl <<endl << "    Press any key to continue...";
	cout<<flush;
	system("CLS");
}

void checkCin() {
	//From Stack OverFlow
	if (cin.fail())
	{		
		
		// get rid of failure state
		cin.clear();
		// discard 'bad' character(s) 
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		throw logic_error("    You did not enter a Valid Data");
	}
}
