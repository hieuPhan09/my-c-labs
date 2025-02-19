#include"BaseballPlayers.h"

BaseBallPlayers::BaseBallPlayers() {
	jerseyNumber = 0;
	isAvailable = false;
	firstName = "";
}
BaseBallPlayers::BaseBallPlayers(int jerseyNumPar, bool isAvailablePar, std::string namePar) {
	jerseyNumber = jerseyNumPar;
	isAvailable = isAvailablePar;
	firstName = namePar;

}
void BaseBallPlayers::setJerseyNumber(int jerseyNumPar) {
	if (jerseyNumPar > 0)
		jerseyNumber = jerseyNumPar;
	
}
void BaseBallPlayers::setIsAvailable(bool isAvailablePar) {
	isAvailable = isAvailablePar;
}
void BaseBallPlayers::setName(std::string namePar) {
	firstName = namePar;
}

int BaseBallPlayers::getJerseyNumber() {
	return jerseyNumber;
}
bool BaseBallPlayers::getIsAvailable() {
	return isAvailable;
}
std::string BaseBallPlayers::getName() {
	return firstName;
}
void BaseBallPlayers::changeJersey(int newJerseyNumberPar, std::string firstNamePar) {
	//jersey num = new jersey num
	if (firstName == firstNamePar)
		setJerseyNumber(newJerseyNumberPar);
}
void BaseBallPlayers::changeName(std::string newPlayerNamePar, std::string firstNamePar) {
	//player name = new player name
	if (firstName == firstNamePar)
		setName(newPlayerNamePar);
}
void BaseBallPlayers::changeAvailability(bool newAvailability, std::string firstNamePar) {
	//isAvailable = new availability 
	if (firstName == firstNamePar)
		setIsAvailable(newAvailability);
}