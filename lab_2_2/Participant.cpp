/*
 * File: Participant.cpp
 */

#include "Participant.h"

Participant::Participant(string n, int cn){
	name = n;
	points = 0;
	card_number = cn;
}

int Participant::GetPoints(){
	return points;
}

void Participant::IncrementPoints(int p){
	points += p;
}

string Participant::GetName(){
	return name;
}

int Participant::GetCardNumber(){
	return card_number;
}

