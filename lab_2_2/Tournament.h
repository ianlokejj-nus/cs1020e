#ifndef __TOURNAMENT_H_INCLUDED__
#define __TOURNAMENT_H_INCLUDED__

#include<vector>
#include "Participant.h"

using namespace std;

class Tournament{
	public:
		Tournament(int np, int rn);
		void AddParticipant(string n, int p);
		void SetNewPosition();
		void CalculatePoints();
		void GetWinner();

		// Debugging
		void PrintParticipants();

	private:
		Participant* Participants[100];
		int number_of_participants;
		int random_number;
};

#endif
