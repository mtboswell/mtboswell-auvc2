#ifndef V4L2CAMERA_H
#define V4L2CAMERA_H

class V4L2Camera : public QThread
{
	Q_OBJECT
	public:
		V4L2Camera(QString videoDevice = "/dev/video", camfmt outputFormat = HSV);

		struct hsvFrame {
			unsigned char H[];
			unsigned char S[];
			unsigned char V[];
		};

		struct frame {
			hsvFrame HSV;
			QImage img;
		};

	signals:
		void frameReady(frame newframe);

	private slots:
		void run();

	private:
		frame decodeYUYV(unsigned char input[]);


		camera i/o method (read-write/streaming)
		camera color space
		camera output format (YUY2/YU12)

		buffers
		output frames?
		mutexes
		etc.

};

#endif
