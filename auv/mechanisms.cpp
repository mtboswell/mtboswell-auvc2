#include "mechanisms.h"

void populateMechs(QMap<QString, mechanism>& mechs){
	mechanism DropLeft;
	DropLeft.servo = 7; // all these values are guesses
	DropLeft.positions.insert(0,4000);
	DropLeft.positions.insert(2000,2800);
	mechs.insert("DropLeft", DropLeft);

	mechanism DropRight;
	DropRight.servo = 7; // all these values are guesses
	DropRight.positions.insert(0,2000);
	DropRight.positions.insert(2000,2800);
	mechs.insert("DropRight", DropRight);
}

