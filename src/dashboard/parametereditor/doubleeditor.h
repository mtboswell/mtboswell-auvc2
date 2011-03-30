#ifndef DOUBLEEDITORCREATOR_H
#define DOUBLEEDITORCREATOR_H

#include <QDoubleSpinBox>

class QWidget;

class DoubleEditor : public QDoubleSpinBox
{
	Q_OBJECT
	Q_PROPERTY(double value READ value WRITE setValue USER true)

	public:
		DoubleEditor(QWidget *widget = 0);

};

#endif
