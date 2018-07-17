#include "stdafx.h"
#include "flight.h"
#include<iostream>
using namespace std;
namespace AirlineReservation {
	/*Flight::Flight(const int id, const std::string date, const std::string departureTime, const std::string arrivalTime, const std::string departureGate,
		const std::string arrivalGate)
	{
		mflightId = id;
		mdate = date;
		mdepartureTime = departureTime;
		marrivalTime = arrivalTime;
		mdepartureGate = departureGate;
		marrivalGate = arrivalGate;
		//mdepartureAirport = departureAirport;
		//mairrvalAirport = airrvalAirport;
	}*/

	/*Flight::Flight(const int id, const std::string date, const std::string departureTime, const std::string arrivalTime, const std::string origin,
		const std::string destination, const std::string departureAirport, const std::string airrvalAirport)
	{
		mflightId = id;
		mdate = date;
		mdepartureTime = departureTime;
		marrivalTime = arrivalTime;
		morigin = origin;
		mdestination = destination;
		mdepartureAirport = departureAirport;
		mairrvalAirport = airrvalAirport;
	}*/

	void Flight::displayFlight() const
	{
		const char airport[][10]={ "SEA", "HYD", "DEL","DWT", "KOL","LA" };
		cout << "Flight Id         :" << mflightId << endl;
		cout << "Date              :" << mdate << endl;
		cout << "DepartureTime     :" << mdepartureTime << endl;
		cout << "ArrivalTime       :" << marrivalTime << endl;
		cout << "Origin            :" << morigin << endl;
		cout << "Destination       :" << mdestination << endl;
		cout << "Departure Airport :" << mdepartureAirport << endl;
		cout << "Arrival Airport   :" << mairrvalAirport << endl;
	}
	void Flight::addFlight() const
	{
		/*cout << "Enter Depature Date";
		cin >> mdate;
		cout<<"Enter Depature Time"
		*/
		
	}
	

	void Flight::setFlightId(int id)
	{
		mflightId = id;
	}

	int Flight::getFlightId() const
	{
		return mflightId;
	}
	
	void Flight :: setAirplaneName(std::string& airplaneName) {
		mAirplaneName = airplaneName;
	}
	string& Flight :: getAirplaneName() {
		return mAirplaneName;
	}

	void Flight :: setFlightNumber(std::string& flightNumber) {
		mFlightNumber = flightNumber;
	}
	string& Flight :: getFlightNumber() {
		return mFlightNumber;
	}
	

	void Flight::setDate(const std::string date)
	{
		mdate = date;
	}

	const std::string Flight::getDate() const
	{
		return mdate;
	}

	void Flight::setDepartureTime(const std::string departureTime)
	{
		mdepartureTime = departureTime;
	}

	const std::string Flight::getDepartureTime() const
	{
		return mdepartureTime;
	}

	void Flight::setArrivalTime(const std::string arrivalTime)
	{
		marrivalTime = arrivalTime;
	}

	const std::string Flight::getArrivalTime() const
	{
		return marrivalTime;
	}

	void Flight::setOrigin(const string& departureGate)
	{
		morigin = departureGate;
	}

	const string& Flight::getOrigin() const
	{
		return morigin;
	}

	void Flight::setDestination(const string& arrivalGate)
	{
		mdestination = arrivalGate;
	}

	const string& Flight::getDestination() const
	{
		return mdestination;
	}

	void Flight::setdepartureAirport(const std::string& departureAirport)
	{
		mdepartureAirport = departureAirport;
	}

	const std::string&  Flight::getDepartureAirport() const
	{
		return mdepartureAirport;
	}

	void Flight::setAirrvalAirport(const std::string& airrvalAirport)
	{
		mairrvalAirport = airrvalAirport;
	}

	const std::string& Flight::getAirrvalAirpot() const
	{
		return mairrvalAirport;
	}

	void Flight::setFlightStatus(const flightstatusEnum flightStatus)
	{
		mflightStatus = flightStatus;
	}

	const flightstatusEnum Flight::getFlightStatus()
	{
		return mflightStatus;
	}

}

