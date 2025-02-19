#include<iostream>
#include <vector>
#include <string>
#include "BaseballPlayers.h"

using namespace std;

//function prototypes
int findIndexOfRecord(vector<BaseBallPlayers> playersPar, string playerNamePar);

int main() {
	//declarations
	BaseBallPlayers player;
	vector<BaseBallPlayers> players;

	int userChoice = 1;
	int playerJerseyNum;
	int indexOfRecord;
	bool isPlayerAvailable;
	char wantToContinue = 'y';
	char playerAvailableYesOrNo = 'n';
	string playerName = "";
	string strPlayerAvailable = "";
	string replacementName = "";

	//get user input
	while (wantToContinue == 'y' || wantToContinue == 'Y') {
		cout << "1 - add a player to the team" << endl;
		cout << "2 - remove a player from the team" << endl;
		cout << "3 - change a player's jersey number" << endl;
		cout << "4 - change a player's availability" << endl;
		cout << "5 - change a player's name" << endl;
		cout << "6 - display team" << endl;
		cout << "7 - quit" << endl;
		cout << "========================================" << endl;
		cout << "Enter your choice: ";
		cin >> userChoice;

		switch (userChoice) {
		case 1://add a player

			cout << "What is the player name: ";
			cin >> playerName;
			cout << "What is " << playerName << "'s jersey number:";
			cin >> playerJerseyNum;
			cout << "Is " << playerName << " available to play today (y/n)? ";
			cin >> playerAvailableYesOrNo;

			if (playerAvailableYesOrNo == 'y')
				isPlayerAvailable = true;
			else
				isPlayerAvailable = false;

			player.setName(playerName);
			player.setJerseyNumber(playerJerseyNum);
			player.setIsAvailable(isPlayerAvailable);

			players.push_back(player);
			break;

		case 2://remove a player

			cout << "What is the name of the player you want to remove? ";
			cin >> playerName;
			indexOfRecord = findIndexOfRecord(players, playerName);

			if (indexOfRecord >= 0) {
				players.erase(players.begin() + indexOfRecord);
				cout << playerName << "'s record has been removed" << endl;
			}
			else
				cout << playerName << "'s record does not exist" << endl;
			break;
		
		case 3://change jersey number
			cout << "Enter the name of the player whose jersey you want to change: ";
			cin >> playerName;
			cout << "What is " << playerName << "'s new jersey number? ";
			cin >> playerJerseyNum;

			indexOfRecord = findIndexOfRecord(players, playerName);
			if (indexOfRecord >= 0) {
				players[indexOfRecord].setJerseyNumber(playerJerseyNum);
				cout << playerName << "'s jersey number now is " << playerJerseyNum << endl;
			}
			else
				cout << playerName << "'s record does not exist" << endl;
			break;

		case 4://change a player's availability
			cout << "Enter the name of the player who's availability you want to change: ";
			cin >> playerName;
			cout << "Is " << playerName << " available to play (y/n): ";
			cin >> playerAvailableYesOrNo;
			if (playerAvailableYesOrNo == 'y' || playerAvailableYesOrNo == 'Y') {
				isPlayerAvailable = true;
			}
			else
				isPlayerAvailable = false;
			indexOfRecord = findIndexOfRecord(players, playerName);
			if (indexOfRecord >= 0) {
				players[indexOfRecord].setIsAvailable(isPlayerAvailable);
				if (isPlayerAvailable)
					cout << playerName << "'s status is now set to available" << endl;
				else
					cout << playerName << "'s status is now set to not available" << endl;
			}
			break;
			
		case 5: //change a player's name
			cout << "Enter the name of the player who's name you want to change: ";
			cin >> playerName;
			cout << "What is the updated replacement name: ";
			cin >> replacementName;
			indexOfRecord = findIndexOfRecord(players, playerName);
			if (indexOfRecord >= 0) {
				players[indexOfRecord].setName(replacementName);
				cout << playerName << "'s has now been updated to " << replacementName;
			}
			else
				cout << playerName << "'s record does not exist" << endl;
			break;

		case 6://display team
			cout << "Name\tJersey's Number\tAvailability" << endl;
			for (int i = 0; i < players.size(); i++)
			{
				cout << players[i].getName() << "\t" << players[i].getJerseyNumber() << "\t\t";
				if (players[i].getIsAvailable() == true)
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
			}
			break;
			
		case 7://quit
			wantToContinue = 'n';

		default:
			break;
		}//switch (userChoice)
		
		cout << endl;
		cout << "";

	}//while (wantToContinue == 'y' || wantToContinue == 'Y')

	return 0;
}

//function definition
int findIndexOfRecord(vector<BaseBallPlayers> playersPar, string playerNamePar) {

	for (int i = 0; i < playersPar.size(); i++)
	{
		if (playersPar[i].getName() == playerNamePar)
			return i; //record found
	}
	return -1; //record is not existed
}

