/**
 * Mechanisms - defines servo motion to trigger mechanisms
 */
#ifndef MECHANISMS
#define MECHANISMS
#include <QMap>
#include <QString>

typedef struct {
	int servo;
	// int1 = time, int2 = position
	QMap<int, int> positions;
} mechanism;

static QMap<QString, mechanism> mechanisms;

void populateMechs(QMap<QString, mechanism>& mechs);

#endif
