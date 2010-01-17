#ifndef UART_H_
#define UART_H_

#include <pthread.h>
#include <termios.h>
#include <iostream>
#include <queue>
#include <vector>

/**
 * Class UART
 * @author Kevin Stefanik for the Virginia Tech AUVT (stefanik@vt.edu)
 * @version Oct. 7, 2006
 */
class UART
{
	public:
    /**
     * This is the constructor.  
     * @param dev is the device file name for the desired serial 
     * port.
     */
	UART(const char* dev = 0, int baud = 9600, int pcktSize = 255);
    /**
     * This is the destructor.
     */
	~UART();
    /**
     * useDev(char* dev) - allows the user to set the device to use
     * (i.e. change serial port on-the-fly)
     * @param dev is the string containing the device filename
     */
	bool useDev(const char* dev, int baud = 9600);

    /**
     * isGood()
     * @return whether the port has been successfully opened
     */
    bool isGood();
    
    bool write(const char* data, int len=-1);
    
    int read(char* data, int len);
    
    class UARTList
    {
    	public:
    	virtual ~UARTList() { }
    	virtual void process(const char* data, int len) = 0;
    };
    
    void addUARTList(UARTList* list);
    
	private:
	/**
     * start() - starts a thread which continually updates 
     * temperature and gyro-stabilized angles, rates and 
     * accelerations.
     */
	void start();
    /**
     * stop() - stops the updating thread
     */
	void stop();
	bool isRunning();
	
	int run();
	pthread_t myPthread;
	pthread_mutex_t dataMutex, portMutex, listMutex;
	bool running, bad_port;
	int fd;
	int pcktSize;
	static void* runUART(void* handle)
    {
        ((UART*)handle)->run();
        pthread_exit(NULL);
        return 0;
    }
    
    typedef struct
    {
    	char* msg;
    	int len;
    } message;
    std::queue<message> messages;
    std::vector<UARTList*> lists;
    
};

#endif /*ADC_H_*/
