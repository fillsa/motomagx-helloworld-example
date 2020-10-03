#ifndef HELLOWORLD_H_
#define HELLOWORLD_H_


#include <ZApplication.h>
#include <ZKbMainWidget.h>

class MainWindow : public ZKbMainWidget
{
Q_OBJECT

public:
	MainWindow(QWidget *parent);
	virtual ~MainWindow();

public slots:
	void slot_JumpBox();
	void slot_WaitCursor();
	void slot_resize();
	void slot_showFullScreen();
	void slot_4();
	
    virtual void slotReturnToIdle( int reason );
    virtual void slotClickAppIcon();

};

#endif /*HELLOWORLD_H_*/
