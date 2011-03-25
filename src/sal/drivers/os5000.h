#ifndef OS5000_H
#define OS5000_H

#include "../state.h"
#include "serialdevice.h"
#include <QRegExp>
#include <QDebug>

class OS5000 : public SerialDevice
{
        Q_OBJECT
        public:
                OS5000(const QString & serialPort);
                HALdata* produceHALData(double roll, double pitch, double yaw);
                double yaw();
                double pitch();
                double roll();

        public slots:
                void calibrate();

        signals:
                //generic signal for alerting when data from a sensor is ready
                void compassDataReady(QList<sensorValue> newCompassData);

                //following is the old version (used by Mike V.?) of the emit signal
                //void compassData(double currentYaw, double currentPitch, double currentRoll);

                void status(QString msg);
                void error(QString msg);
                void startingCalibration();
                void calibrationComplete();

        private slots:
                void processData(QByteArray data);

        private:
                double m_yaw, m_pitch, m_roll, m_temp;
};

#endif
