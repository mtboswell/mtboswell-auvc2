#include <QtGui>

#include "doubleeditor.h"

DoubleEditor::DoubleEditor(QWidget *widget) : QDoubleSpinBox(widget)
{
	setSingleStep(0.01);
	setRange(-1000,1000);
	//setDecimals(2);
}
