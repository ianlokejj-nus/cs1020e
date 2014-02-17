#include<iostream>
#include "Tournament.h"

using namespace std;

int main(){
	int number_of_participants;
	int random_number;

	cin >> number_of_participants >> random_number;
	
	Tournament SocTournament(number_of_participants, random_number);
	string name;
	int starting_position;
	for(int p = 0; p < number_of_participants; p++){
		cin >> name >> starting_position;
		SocTournament.AddParticipant(name, starting_position);
	}

//	SocTournament.PrintParticipants();
	for(int i = 0; i < random_number; i++){
		SocTournament.SetNewPosition();
		SocTournament.CalculatePoints();
		
	//SocTournament.PrintParticipants();
	}

	SocTournament.GetWinner();

	return 0;

}
