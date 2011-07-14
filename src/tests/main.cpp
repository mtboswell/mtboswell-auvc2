#include "../sid.h"
#include "../state.h"

int main(){
	QStringList headers;
	header << "ID" << "Value";
	TreeModel state(header);

	sensorValue testValue;
	testValue.datumID = "stuff";
	testValue.value = 10;

	state["AUV.Sensor.Test"] = testValue;

	qDebug(state["AUV.Sensor.Test"]);
}
