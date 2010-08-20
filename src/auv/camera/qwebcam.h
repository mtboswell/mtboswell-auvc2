/**
 *  QWebcam camera interface class
 *
 *  
 */

#ifndef Q_WEBCAM_H
#define Q_WEBCAM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <getopt.h>             /* getopt_long() */

#include <fcntl.h>              /* low-level i/o */
#include <unistd.h>
#include <errno.h>
#include <malloc.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

#include <asm/types.h>          /* for videodev2.h */

#include <linux/videodev2.h>

#include <QObject>
#include <QImage>
#include <QThread>

#define CLEAR(x) memset (&(x), 0, sizeof (x))

class QWebcam : public QObject
{
	Q_OBJECT
	public:
		QWebcam(const QString & webcamDevice, QObject* parent = 0);
		~QWebcam();

		int setDevice(const QString & dev);

	signals:
		void frameReady(QImage* frame);

	private:
		typedef enum {
			IO_METHOD_READ,
			IO_METHOD_MMAP,
			IO_METHOD_USERPTR,
		} io_method;

		struct buffer {
			void *                  start;
			size_t                  length;
		};


		char * dev_name;
		io_method io;
		int fd;
		struct buffer * buffers;
		unsigned int n_buffers;

		void errno_exit(const char * s);

		int xioctl(int fd, int request, void *arg);

		void process_image(const void * p);

		int read_frame();
		void capture_loop();
		void stop_capturing();

		void start_capturing();

		void uninit_device();
		void init_read(unsigned int buffer_size);

		void init_mmap();

		void init_userp(unsigned int buffer_size);

		void init_device();
		void close_device();

		void open_device();

};

#endif
