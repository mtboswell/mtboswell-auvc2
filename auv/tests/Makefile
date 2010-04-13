# Build AUV code
CC     = g++
CFLAGS = -Wall -lpthread -lcurses
SEROBJS   = uart.o buffer.o
#$(TARGET): $(SEROBJS)
#	$(CC) $(CFLAGS) -o $(TARGET) $(SEROBJS)
all: gorc pidtest
pathfollow: auv.h pathfollow.cpp camread.o alarm.o AUVStateManagement_gate_track_buoy/AUVStateManagement_gate_track_buoy.cpp 
	$(CC) $(CFLAGS) pathfollow.cpp AUVStateManagement_gate_track_buoy/*.cpp pololu.o power.o imu.o uart.o buffer.o adc.o camread.o alarm.o \
	-IAUVStateManagement_gate_track_buoy/ -DRT -o pathfollow
validation: auv.h validation.cpp caminit.o alarm.o ValidationGate/ValidationGate_data.cpp
	$(CC) $(CFLAGS) validation.cpp ValidationGate/*.cpp pololu.o power.o imu.o uart.o buffer.o adc.o caminit.o alarm.o \
	-IValidationGate/ -DRT -o validation
auvsearch: auv.h auvsearch.cpp camread.o caminit.o alarm.o 
	$(CC) $(CFLAGS) auvsearch.cpp AUVstateflow2/*.cpp pololu.o power.o imu.o uart.o buffer.o adc.o camread.o caminit.o alarm.o \
	-IAUVstateflow2/ -DRT -o auvsearch
auvgosee: auv.h auvgosee.cpp camread.o caminit.o alarm.o AUVstateflow/AUVstateflow.cpp
	$(CC) $(CFLAGS) auvgosee.cpp AUVstateflow/*.cpp pololu.o power.o imu.o uart.o buffer.o adc.o camread.o caminit.o alarm.o \
	-IAUVstateflow/ -DRT -o auvgosee
auvgo: auv.h auvgo.cpp caminit.o alarm.o AUVstateflow/AUVstateflow.cpp
	$(CC) $(CFLAGS) auvgo.cpp AUVstateflow/*.cpp pololu.o power.o imu.o uart.o buffer.o adc.o caminit.o alarm.o \
	-IAUVstateflow/ -DRT -o auvgo
auvlog: auv.h auvlog.cpp alarm.o 
	$(CC) $(CFLAGS) auvlog.cpp pololu.o power.o imu.o uart.o buffer.o adc.o caminit.o alarm.o \
	-DRT -o auvlog
pidtest: auv.h pidtest.cpp alarm.o caminit.o StraightLevelControl/StraightLevelControl_data.cpp
	$(CC) $(CFLAGS) pidtest.cpp StraightLevelControl/*.cpp pololu.o power.o imu.o uart.o buffer.o adc.o alarm.o caminit.o \
	-IStraightLevelControl/ -DRT -o pidtest
pidtest-fast: auv.h pidtest-fast.cpp alarm.o caminit.o StraightLevelControl/StraightLevelControl_data.cpp
	$(CC) $(CFLAGS) pidtest-fast.cpp StraightLevelControl/*.cpp pololu.o power.o imu.o uart.o buffer.o adc.o alarm.o caminit.o \
	-IStraightLevelControl/ -DRT -o pidtest-fast
buoytest: auv.h buoytest.cpp Buoy/*.cpp
	$(CC) $(CFLAGS) buoytest.cpp Buoy/*.cpp pololu.o power.o imu.o uart.o buffer.o adc.o caminit.o alarm.o \
	-IBuoy/ -DRT -o buoytest
sim_test: sim_test.cpp
	$(CC) $(CFLAGS) sim_test.cpp ReallySimple/*.cpp -IReallySimple/ -DRT -o sim_test
adctest: adc.o adctest.cpp calibration.h
	$(CC) $(CFLAGS) -o adctest adctest.cpp adc.o uart.o buffer.o
gorc: rc.o gorc.cpp adc.o imu.o caminit.o
	$(CC) $(CFLAGS) -o gorc gorc.cpp rc.o caminit.o pololu.o power.o uart.o buffer.o adc.o imu.o
pololutest: pololu.o pololutest.cpp
	$(CC) $(CFLAGS) -o pololutest pololutest.cpp pololu.o uart.o buffer.o
powertest: power.o powertest.cpp
	$(CC) $(CFLAGS) -o powertest powertest.cpp power.o uart.o buffer.o
imutest: imu.o imu.h imu.cpp $(SEROBJS) imutest.cpp
	$(CC) $(CFLAGS) -o imutest imutest.cpp imu.o uart.o buffer.o
auv.h: pololu.o power.o caminit.o calibration.h ports.h
rc.o: pololu.o power.o rc.cpp rc.h calibration.h ports.h
pololu.o: $(SEROBJS) pololu.h pololu.cpp
power.o: $(SEROBJS) power.h power.cpp
imu.o: $(SEROBJS) imu.h imu.cpp
adc.o: $(SEROBJS) adc.h adc.cpp
uart.o: buffer.o uart.h uart.cpp
buffer.o: buffer.h buffer.cpp
caminit.o: caminit.h caminit.c
camread.o: camread.h camread.c
alarm.o: alarm.c alarm.h
#clean:
#       rm -f *.o *~ core tmp
#exclean: clean
#       rm -f bin/connect4
