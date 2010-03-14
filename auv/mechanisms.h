/**
 * Mechanisms - defines servo motion to trigger mechanisms
 */
#ifndef MECHANISMS
#define MECHANISMS
#include <QHash>
#include <QString>

typedef struct {
	int servo;
	// int1 = time, int2 = position
	QHash<int, int> positions;
} mechanism;

static QHash<QString, mechanism> mechanisms;

void populateMechs(QHash<QString, mechanism>& mechs);

#endif
