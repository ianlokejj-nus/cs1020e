#ifndef __PARTICIPANT_H_INCLUDED__
#define __PARTICIPANT_H_INCLUDED__

#include<string>

using namespace std;

class Participant{

	public:
		Participant(string n, int cn);
		int  GetPoints();
		void IncrementPoints(int p);
		int GetCardNumber();
		// Debugging
		string GetName();

	private:
		string name;
		int points;
		int card_number;
};

#endif
