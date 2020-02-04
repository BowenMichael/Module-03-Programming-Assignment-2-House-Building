#include <sstream>
#include "House.h"

using namespace std;

House::House()
{
	//stub
}

//return false if room has too low a height, too small an area or the house already is at max for that type of room
bool House::addRoom( const Room& theRoom )
{
	bool toManyRooms = false;
	switch (theRoom.getType()) 
	{
		case 0:
			if (MAX_KITCHENS < getNumKitchens()) {
				toManyRooms = true;
			}
			break;
		case 1:
			if (MAX_BATHROOMS < getNumBathrooms()) {
				toManyRooms = true;
			}
			break;
		case 2:
			if (MAX_LIVINGROOMS < getNumLivingrooms()) {
				toManyRooms = true;
			}
			break;
		case 3:
			if (MAX_BEDROOMS < getNumBedrooms()) {
				toManyRooms = true;
			}
			break;
		default:
			toManyRooms = false;

	}
	if (theRoom.getSquareFootage() < MIN_AREA || theRoom.getHeight() < MIN_HEIGHT || toManyRooms) {
		return false;
	}
	numRooms[theRoom.getType()] += 1;
	//if(nextRoom < )
	rooms[nextRoom] = theRoom;
	nextRoom++;
	return true;
}

int House::getNumBedrooms()
{
	//stub
	return numRooms[3];
}

int House::getNumBathrooms()
{
	//stub
	return numRooms[1];
}

int House::getNumKitchens()
{
	//stub
	return numRooms[0];
}

int House::getNumLivingrooms()
{
	//stub
	return numRooms[2];
}

int House::getTotalSquareFootage()
{
	//stub
	return totalSquareFeet;
}

int House::getTotalVolume()
{
	//stub
	return totalVolume;
}

bool House::isValid()
{
	//stub
	return false;
}

string House::enumerateRooms()
{
	//stub
	string report = "These are the rooms in the house:\n";

	return report;
}

string House::getDescription()
{
	stringstream theStream;

	theStream	
		<< "House has:\n"
		<< getNumBedrooms() << " Bedrooms\n"
		<< getNumBathrooms() << " Bathrooms\n"
		<< getNumKitchens() << " Kitchens\n"
		<< getNumLivingrooms() << " Livingrooms\n\n"
		<< getTotalSquareFootage() << " Square feet total\n"
		<< getTotalVolume() << " Cubic feet total volume\n";

	if( isValid() )
	{
		theStream << "House is Valid!\n\n";
	}
	else
	{
		theStream << "House is not Valid!\n\n";
	}

	return theStream.str();
}