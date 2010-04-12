#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H
#include <QLabel>
#include <QMouseEvent>
#include <QCloseEvent>

class VideoWidget : public QLabel
{
	Q_OBJECT
	public:
	VideoWidget(QWidget* parent = 0):QLabel(parent){
		container = parent;
		setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
		setAlignment(Qt::AlignCenter);
	}

	void mouseDoubleClickEvent(QMouseEvent* event){
		event->accept();
		if(isWindow()){
			if(isFullScreen()) showNormal();
			else showFullScreen();
		}else{
			setWindowFlags(Qt::Window);
			resize(640,480);
			show();
		}
	}
	void closeEvent(QCloseEvent* event){
		event->ignore();
		showNormal();
		setWindowFlags(Qt::Widget);
		setParent(container);
		resize(320,240);
		show();
	}

	QSize sizeHint() {
		if(isWindow()) return QSize(640,480);
		else return QSize(320,240);
	}
	QSize minimumSizeHint() {
		return QSize(320,240);
	}
	
	int heightForWidth(int w) const{return (int)(1.75*(double)w);}

	private:
		QWidget* container;

};

#endif
