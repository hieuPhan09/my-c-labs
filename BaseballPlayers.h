#include <string>
class BaseBallPlayers {

public:
	BaseBallPlayers(); //default constructor
	BaseBallPlayers(int jerseyNumPar, bool isAvailablePar, std::string namePar); //overload constructor

	void setJerseyNumber(int jerseyNumPar);
	void setIsAvailable(bool isAvailablePar);
	void setName(std::string namePar);

	int getJerseyNumber();
	bool getIsAvailable();
	std::string getName(); //std:: - string lives in namespace std
	
	void changeJersey(int newJerseyNumberPar, std::string firstNamePar);
	void changeName(std::string newPlayerNamePar, std::string firstNamePar);
	void changeAvailability(bool newAvailability, std::string firstNamePar);

private:
	int jerseyNumber;
	bool isAvailable;
	std::string firstName;
};

