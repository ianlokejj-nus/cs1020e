/*
 * File: Tournament.cpp
 */
#include<iostream>
#include "Tournament.h"
#include "Participant.h"

Tournament::Tournament(int np, int rn){
	number_of_participants = np;
	random_number = rn;
}

void Tournament::AddParticipant(string n, int cn){
///  decide if i should use new or just send the person
	Participants[cn] = new Participant(n, cn);
}

void Tournament::SetNewPosition(){
	Participant* tmp[100];
	int new_position;
	for(int i = 0; i < number_of_participants; i++){
		new_position = (i * random_number);
	        if(new_position >= number_of_participants)
			new_position %= number_of_participants;
		tmp[new_position] = Participants[i];
	}

	for(int i =0; i < number_of_participants; i++){
		Participants[i] = tmp[i];
	}
}

void Tournament::CalculatePoints(){
	int points = 0;
	int left_participant_points;
	int right_participant_points;
	for(int i = 0; i < number_of_participants; i++){
		if(i == 0)
			left_participant_points = Participants[number_of_participants - 1]->GetCardNumber();
		else
			left_participant_points = Participants[i - 1]->GetCardNumber();

		if(i == number_of_participants - 1)
			right_participant_points = Participants[0]->GetCardNumber();
		else
			right_participant_points = Participants[i+1]->GetCardNumber();

		points = left_participant_points + right_participant_points;
		Participants[i]->IncrementPoints(points);
	}
}

void Tournament::GetWinner(){
	int max = -1;
	Participant* winner;
	for(int i = 0; i < number_of_participants; i++){
		if(Participants[i]->GetPoints() > max){
			max = Participants[i]->GetPoints();
			winner = Participants[i];
		}
	}

	cout << winner->GetName() << " " << winner->GetPoints() << endl;

}

void Tournament::PrintParticipants(){
	for(int i = 0; i < number_of_participants; i++){

		cout << Participants[i]->GetName() << " " << Participants[i]->GetPoints()  <<  endl;
	}
}
