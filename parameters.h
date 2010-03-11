#ifndef PARAMETERS
#define PARAMETERS
#include "brain/brain.h"
#include <QHash>
#include <QString>

static QHash<QString, double*> parameters;

void init_params();

#endif
