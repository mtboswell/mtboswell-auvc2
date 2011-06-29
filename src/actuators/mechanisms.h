#ifndef MECHANISMS
#define MECHANISMS
#include <QMap>
#include <QString>

/**
 * Contains a servo motion used to trigger mechanisms.
 * \ingroup AUV
 */
typedef struct {
	int servo;
	// int1 = time, int2 = position
	QMap<int, int> positions;
} mechanism;

/**
 * Database of the mechanism scripts available to be activated.
 * \ingroup AUV
 */
static QMap<QString, mechanism> mechanisms;

/**
 * Initialize the mechanisms database.
 */
void populateMechs(QMap<QString, mechanism>& mechs);

#endif
