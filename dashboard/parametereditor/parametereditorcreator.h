#ifndef PARAMETEREDITOR_H
#define PARAMETEREDITOR_H

#include <QDoubleSpinBox>

class QWidget;

class ParameterEditor : public QDoubleSpinBox
{
	Q_OBJECT
	Q_PROPERTY(double value READ value WRITE setValue USER true)

	public:
		ParameterEditor(QWidget *widget = 0);

};

#endif
