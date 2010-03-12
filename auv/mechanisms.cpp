#include "mechanisms.h"

void populateMechs(QHash<QString, mechanism>& mechs){
	mechanism DropLeft;
	DropLeft.servo = 5; // all these values are guesses
	DropLeft.positions.insert(0,1500);
	DropLeft.positions.insert(2000,2500);
	mechs.insert("DropLeft", DropLeft);

	mechanism DropRight;
	DropRight.servo = 5; // all these values are guesses
	DropRight.positions.insert(0,1500);
	DropRight.positions.insert(2000,2500);
	mechs.insert("DropRight", DropRight);
}

