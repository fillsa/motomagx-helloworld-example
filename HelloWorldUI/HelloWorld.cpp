// #define QT_NO_DRAGANDDROP
// #define QT_NO_PROPERTIES

#include "HelloWorld.h"

#include <qwindowsystem_qws.h>

//#include <ZApplication.h>
//#include <ZKbMainWidget.h>
#include <ZSoftKey.h>
#include <ZOptionsMenu.h>
#include <ZNavTabWidget.h>
#include <ZScrollPanel.h>
#include <ZFormContainer.h>
#include <ZListBox.h>
#include <ZDetailView.h>
#include <ZComboBox.h>
#include <ZExhibitButton.h>
#include <ZCheckBox.h>
#include <ZFormItem.h>
#include <ZRadioButton.h>
#include <ZBaseButtonGroup.h>
#include <ZMessageDlg.h>
#include <ZAppInfoArea.h>
#include <ZPanel.h>
#include <ZIconView.h>
#include <ZMeter.h>
#include <qcursor.h>
#include <qwindowsystem_qws.h>
#include <RES_ICON_Reader.h>
#include <ZColorPickerDlg.h>
//#include <ZColorControl.h>
//#include <ZListBoxClipper.h>
#include <ZCalendarEvent.h>
#include <ZNumPicker.h>
#include <ZJumpBox.h>
#if 0 // ZSplitPane и ZFiveWayButton и ZDateModule есть во всех магиксах и эмуле, но нету заголовочных файлов
	#include <ZSplitPane.h>
	#include <ZFiveWayButton.h>
	#include <ZMediaController.h>
	#include <ZDateModule.h>
#endif
	#include "ZFiveWayButton.h"




#define qDebug(x) fprintf(stderr, QString("\033[01;31mDebug:\e[0m ")+ x + QString("\n")) // эмулятор не выводин qDebug в терминал

MainWindow::MainWindow(QWidget *parent) 
	: ZKbMainWidget((ZHeader::HEADER_TYPE)3/*ZHeader::CLI_HEADER*/, parent, "MainWindow", 0)
{
	qDebug("Start");
	
 	RES_ICON_Reader iconReader; 
 	
 	this->setAppTitle(QString("AppTitle!"));

	this->setMainWidgetTitle(QString("MainWidgetTitle!"));
	this->setIcon(iconReader.getIcon("gen_accelerator_1_small" ));
	
//	this->setActiveDisplay(AllDisplay);


 //   header->changeStatus(ZHeader::WIFI, 1)
	
	connect( qApp, SIGNAL(askReturnToIdle(int)), this, SLOT(slotReturnToIdle(int)) ); // сигнал по нажатию красной кнопки
	connect( qApp, SIGNAL(clickAppIcon()), this, SLOT(slotClickAppIcon()) ); // сигнал при запуске программы
	
	
	
	ZAppInfoArea * aia = new ZAppInfoArea(this);
#if !defined(EZX_ZN5) && !defined(EZX_U9) && !defined(EZX_Z6W) 
	this->setTitleBarWidget(aia);	
#else // чтобы aia панель неставилась выше заголовка
	QVBoxLayout* layout = getVBoxLayout();
	layout->addWidget(aia);//добвим aia панель на layout
#endif
	aia->appendText(
			#if defined(EZX_E2) || defined(EZX_Z6) || defined(EZX_V8)
			ZAppInfoArea::activity
			#else
			ZAppInfoArea::ACTIVITY
			#endif
						,  "ZAppInfoArea panel text", "patchText");
	
	ZNavTabWidget * tabWidget = new ZNavTabWidget(this);
	this->setContentWidget(tabWidget);
	
//	( ( ZApplication* ) qApp )->showMainWidget ( this );


	
#ifndef MOTODEV_STUDIO 
	ZPanel * p1  = new ZPanel();
	ZLabel * l = new ZLabel(QString("Label on zmeter"), p1, "mainlabel", 0, (ZSkinService::WidgetClsID)4);
//	spanel->addChild(p1, 5 , 120); // библиотеки в эмуляторе неподдерживает добавление ZPanel в ZFormContainer
#endif
	
#if 0 // ZSplitPane есть во всех магиксах и эмуле, но нету заголовочных файлов
	ZSplitPane * sp = new ZSplitPane();
/*	
	aa->setPixmap(QPixmap(iconReader.getIcon("gen_accelerator_1_small" )));
	aa->setPane( p1,tabWidget);
*/
#endif

///************************************************* TAB1 *********************************************************************///	
	qDebug("tab 1");
	
	// ZFormContainer в отличии от ZScrollPanel все виджеты сами выстраиваются друг за другом и занимают полную ширину экрана.
	// Но добавлять можно только определенные виджеты
	ZFormContainer * fc = new ZFormContainer();
	tabWidget->addTab(fc, QIconSet(iconReader.getIcon("gen_accelerator_1_small" )), "FCont");


	ZComboBox * combobox = new ZComboBox( false, fc , "zcmb"); 
	fc->addChild(combobox);
	combobox->setTitle( "ComboBox1 Titile:");
	combobox->insertItem( iconReader.getIcon("gen_accelerator_0_small" ), "ComboBox item text");


	ZComboBox * combobox2 = new ZComboBox( false, fc , "zcmb2"); 
	fc->addChild(combobox2);	
// NO TITLE 	combobox2-combobox2->setTitle( "ComboBox2 Titile:");
	combobox2->setTitlePosition(ZButton::TitleTop);
	combobox2->insertItem( iconReader.getIcon("gen_accelerator_1_small" ), "ComboBox item2 text");	
	
	
#if ! defined(EZX_AURA)// крошится на ауре
	ZFormItem * FormItem = new ZFormItem(); 
	FormItem->setBackgroundColor(QColor(255,225,120)); // без раскраски ZFormItem просто пустой виджет, вероятно аналог QFormы
	#if defined(MOTODEV_STUDIO) || defined(EZX_EM35) || defined(EZX_VE66)
		FormItem->setTitle("FormItem title"); // FormItem->setTitle есть только в эмуляторе и EM35 и VE66 .
	#endif
	FormItem->setFocusPolicy(QWidget::StrongFocus); // управление политекой фокуса виджета, ZFormItem по умолчанию не может принимать фокус.
	fc->addChild(FormItem);
//	fc->addChild((ZFormItem*)dv);
#endif
	
	ZLineEdit * line = new ZLineEdit(this);
	fc->addChild(line);
	line->setTitle("LineEdit Titile:");	

	ZMultiLineEdit *medit = new ZMultiLineEdit();
	fc->addChild(medit);
	medit->setTitle("MultiLineEdit Titile:");
	medit->setTitlePosition(ZMultiLineEdit::TitleTop);
	medit->setFixedHeight(100);
//	medit->setUnderline(4);


	
	
///************************************************* TAB2 *********************************************************************///	
	qDebug("tab 2");
	
	// ZScrollPanel аналог QScrollPanel
	// все дочерние виджеты добавляются в строго указанное положение
	// и с размером по умолчанию, для растягивания на всю ширину используйте setFixedWidth(this->width()-10).
	ZScrollPanel * spanel = new ZScrollPanel();
	tabWidget->addTab(spanel, QIconSet(iconReader.getIcon("gen_accelerator_2_small" )), "SPanel");
	spanel->setVScrollBarMode(ZScrollPanel::AlwaysOn);
	
//	spanel->resize(this->width(),this->height());
	spanel->setGeometry(0,0,240,500);
	spanel->setKeyScrollWrap(true);
	spanel->setAutoExpandInNestMode(true);

	
	
	ZCheckBox * chkb = new ZCheckBox( "CheckBox1" , spanel);
	chkb->setFixedWidth(this->width()-10);
	spanel->addChild(chkb, 5 , 1);

	
#ifndef MOTODEV_STUDIO	// в эмуле почему-то не нашелся ZLabel
	ZLabel * mainlabel = new ZLabel(QString("Label text right"), this, "mainlabel", 0, (ZSkinService::WidgetClsID)4);
	mainlabel->setFixedWidth(this->width()-10);
	mainlabel->setPreferredWidth(this->width());
	mainlabel->setAutoResize(true);
	spanel->addChild(mainlabel, 100, 38);
#endif

	
	ZExhibitButton * exb = new ZExhibitButton(spanel, "name");
	exb->setGeometry(0,0,200,50);
//	exb->resize(230, 20);
//	exb->setTitle("title");
	exb->setButtonText("text");
//  exb->setNumRows(3);
	spanel->addChild(exb, 5 , 58);

	
//	ZButton * but = new ZButton( this );
//	spanel->addChild(but, 5 , 100);


	ZMeter * meter = new ZMeter(7 ); // библиотеки в эмуляторе неподдерживает добавление ZMeter в ZFormContainer
	spanel->addChild( meter , 5 , 103); 

	
	ZWidget * gg = new ZWidget();
	gg->setGeometry(0,0,70,70);
	spanel->addChild(gg, 5 , 125);
	gg->setFocusPolicy(QWidget::StrongFocus);
	gg->setBackgroundColor (QColor(255,200,120)); // без раскраски ZWidget просто пустой виджет
	
	
/******************************* 5 Way Button Navigation(joystik) ************************/	
	// на ауре сходу крошится 
#if 1 // ZFiveWayButton есть во всех магиксах и эмуле, но нету заголовочных файлов
	ZFiveWayButton * joyst = new ZFiveWayButton(gg); // вероятно может распологаться только на ZWidget, на ZScrollPanel крошится
	joyst->setGeometry(0,0,gg->width(),gg->height()); // по умолчанию ZFiveWayButton на ZWidget будет иметь корявый размер

//	joyst->setFocusPolicy(QWidget::StrongFocus);
//	joyst->setBackgroundColor (QColor(255,200,120));
	
//	joyst->setParentBackground(true); // true - можно установить фон, как дочерний виджет(например как у камеры)
	
	joyst->setNormalPixmap( iconReader.getIcon("fiveway_std" ));  // значок в обычном состояни
	joyst->setActiveBgPixmap( 0, iconReader.getIcon("fiveway_down_sel" ));  // значок при нажатой кнопке
	joyst->setActiveBgPixmap( 1, iconReader.getIcon("fiveway_left_sel" ));
	joyst->setActiveBgPixmap( 2, iconReader.getIcon("fiveway_right_sel" ));
	joyst->setActiveBgPixmap( 3, iconReader.getIcon("fiveway_up_sel" ));
	joyst->setActiveBgPixmap( 4, iconReader.getIcon("fiveway_center_sel" ));

	joyst->setPixmap(4, ZFiveWayButton::ACTIVE, iconReader.getIcon("alarm_clock_small" ));
	joyst->setPixmap(1, ZFiveWayButton::ACTIVE, iconReader.getIcon("mp_zoom_out_unp_nav" ));
	joyst->setPixmap(2, ZFiveWayButton::ACTIVE, iconReader.getIcon("mp_zoom_in_unp_nav" ));

/*
     connect(joyst,SIGNAL(2keyPressed(int)),this,SLOT(1slot5WayPressed(int)));
     connect(joyst,SIGNAL(2keyReleased(int)),this,SLOT(1slot5WayReleased(int)));
     connect(joyst,SIGNAL(2keyPressedAndHold(int)),this, SLOT(1slot5WayPressedAndHold(int)));
*/
#endif 

	ZSeparator * separator = new ZSeparator( );
	separator->setLength(50);
	separator->setFixedWidth(this->width()-10);
	spanel->addChild(separator, 5 , 200);
	
#if ! defined(EZX_AURA)	// крошится на ауре
	ZDetailView * dlv = new ZDetailView();
	dlv->setGeometry(0,0,this->width(),this->height());
	spanel->addChild(dlv, 5 , 210);

	ZDetailItem * dtitem1 = new ZDetailItem( "Detail item1");
	dlv->addItem(dtitem1);
	ZDetailItem * dtitem2 = new ZDetailItem( ZDetailItem::ItemTypeSeparator , "Detail item2");
	dlv->addItem(dtitem2);
#endif

	
///************************************************* TAB3 *********************************************************************///	
	qDebug("tab 3");	
	
	ZGroupBox * GroupBox = new ZGroupBox( );
	GroupBox->setTitle("GroupBox title:");
	GroupBox->resize(this->width(),this->height()); // по умолчанию не занимает весь  tabWidget // Но на ауре размер забивает софткнопки
	tabWidget->addTab(GroupBox, QIconSet(iconReader.getIcon("gen_accelerator_3_small" )), "FormItem");
	
	
	ZRadioButton * rb = new ZRadioButton("RadioButton text 1" , spanel, "rb");
	rb->setPixmap(QPixmap(iconReader.getIcon("gen_accelerator_0_small" )));
	GroupBox->insert(rb);	
	
	ZRadioButton * rb1 = new ZRadioButton("RadioButton text1" , spanel, "rb1");
	rb1->setPixmap(QPixmap(iconReader.getIcon("gen_accelerator_1_small" )));
	GroupBox->insert(rb1);
	
	ZCheckBox * cb = new ZCheckBox("CheckBox text 1" ,spanel, "chkb" );
	GroupBox->insert(cb);
	
	ZCheckBox * cb2 = new ZCheckBox("CheckBox text 2" ,spanel, "chkb" );
	GroupBox->insert(cb2);		

//    ZNumPicker * nump = new ZNumPicker( 100 );
//	GroupBox->insert(cb2);		

	
///************************************************* TAB4 *********************************************************************///
	qDebug("tab 4");	
	
	ZIconView * IconView = new ZIconView(/*this, NULL, 0, 200, ZSkinService::clsZIconView2*/);
	IconView->setFixedWidth(this->width());
#if ! defined(EZX_AURA) // на ауре крошится добавление и с this и c NULL И с пустотой
	tabWidget->addTab(IconView, QIconSet(iconReader.getIcon("gen_accelerator_4_small" )), "IView");
#endif	
	
/*	
	for (int idxs ; ; idxs++ )
	{
	ZIconViewItem * item = new ZIconViewItem(IconView);
//	NO TEXT	item2->setText( "IconView item2" );
	item->setPixmap(iconReader.getIcon("gen_accelerator_2_small" ));
	}
	
	for (int idxs ; ; idxs++ )
	{
		ZIconViewItem * item = new ZIconViewItem(IconView);
		item->setText( "IconView item" );	
		item->setPixmap(iconReader.getIcon("gen_accelerator_1_small" ));	
	}
	
*/

	ZIconViewItem * item = new ZIconViewItem(IconView);
	item->setText( "IconView item1" );
	item->setPixmap(iconReader.getIcon("wap_btton_0_small" ));
	
	ZIconViewItem * item2 = new ZIconViewItem(IconView);
//	NO TEXT	item2->setText( "IconView item2" );
	item2->setPixmap(iconReader.getIcon("wap_btton_1_small" ));
	
	ZIconViewItem * item3 = new ZIconViewItem(IconView);
	item3->setText( "IconView item3" );	
	item3->setPixmap(iconReader.getIcon("wap_btton_2_small" ));
	
	ZIconViewItem * item4 = new ZIconViewItem(IconView);
	item4->setText( "IconView item4" );
	item4->setPixmap(iconReader.getIcon("wap_btton_3_small" ));

	ZIconViewItem * item5 = new ZIconViewItem(IconView);
	item5->setText( "IconView item5" );
	item5->setPixmap(iconReader.getIcon("wap_btton_4_small" ));


	

///************************************************* TAB5 *********************************************************************///	
	qDebug("tab 5");
	
	ZListBox * ListBox = new ZListBox( /* "%r%M" , tabWidget , 0*/  );
	// aura  = new ZListBox((QString)0xc8,*(QWidget **)(pQParm1 + 0x10c),0,0x28);
#if ! defined(EZX_AURA)  // на ауре крошится добавление и с this и c NULL И с пустотой
	tabWidget->addTab(ListBox, QIconSet(iconReader.getIcon("gen_accelerator_5_small" )), "List");
#endif // ! defined(EZX_AURA)	
	
	ZListBoxItem * listitem = new ZListBoxItem ( ListBox, QString ( "%I%M%I" ) );
	listitem->setPixmap (  0, iconReader.getIcon(/*"info_pop"*/"wap_btton_0_small"));
	listitem->appendSubItem ( 1, "List Item text", false, 0);
	listitem->appendSubItem ( 1, "List SubItem text", false , 0 );	
	ListBox->insertItem ( listitem, 0, true );

	ZListBoxItem * listitem2 = new ZListBoxItem ( ListBox, QString ( "%I%M%I" ) );
	listitem2->setPixmap ( 0 , iconReader.getIcon(/*"in_progress_ani_pop"*/"wap_btton_1_small") );
	listitem2->appendSubItem ( 1, "List Item text2", false, 0);
	listitem2->appendSubItem ( 1, "List SubItem text2", false , 0 );	
	ListBox->insertItem ( listitem2, 1, true );

	ZListBoxItem * listitem3 = new ZListBoxItem ( ListBox, QString ( "%I%M%I" ) );
	listitem3->setPixmap ( 0, iconReader.getIcon(/*"link_pop"*/"wap_btton_2_small") );
	listitem3->appendSubItem ( 1, "ListItem text3", false, 0);
	listitem3->appendSubItem ( 1, "List SubItem text3", false , 0 );	
	ListBox->insertItem ( listitem3, 2, true );
	
// ***************************************** menu *****************************************************//
	qDebug("menu");
	
	QRect rect(0,0,this->width()-10,this->height()); // поле видимости меню, дабы не перекрвать весь экран.
	QPixmap *pm;
	
	// showPopupMenu
	ZOptionsMenu * showPopupMenu = new ZOptionsMenu ( rect, /*softKey*/NULL, "", 0
#if defined(EZX_AURA) || defined(EZX_U9) || defined(EZX_Z6W)
																			, ZSkinService::clsZOptionsMenu, "", ""
#endif																			
																			);   
  	int idx2 = 0;
  	++idx2;	
//	pm->load( iconReader.getIcon("gen_accelerator_1_small" ));
  	showPopupMenu->insertItem ( "ZColorModule", NULL, NULL , true , idx2 , idx2 );
  	showPopupMenu->connectItem ( idx2, this, SLOT ( slot_4( ) ) ); 
  	
//  	++idx2;	
//	pm->load( iconReader.getIcon("gen_accelerator_2_small" ));
//  	showPopupMenu->insertItem ( "ZMessageDlg", NULL, NULL , true , idx2 , idx2 );
//  	showPopupMenu->connectItem ( idx2, this, SLOT ( slot_ZMessageDlg( ) ) ); 
  	
// 	++idx2;	
//	pm->load( iconReader.getIcon("gen_accelerator_3_small" ));
//  	showPopupMenu->insertItem ( "ZPopUp", NULL, NULL , true , idx2 , idx2 );
//  	showPopupMenu->connectItem ( idx2, this, SLOT ( slot_ZMessageDlg( ) ) ); 
		
  	

	// OknoMenu
	ZOptionsMenu *windMenu = new ZOptionsMenu ( rect, /*softKey*/NULL, "", 0
#if defined(EZX_AURA) || defined(EZX_U9) || defined(EZX_Z6W)
																			, ZSkinService::clsZOptionsMenu, "", ""
#endif																			
																			);   
  	int idx3 = 0;
  	++idx3;	
//	pm->load( iconReader.getIcon("gen_accelerator_3_small" ));
  	windMenu->insertItem ( "showFullScreen", NULL, NULL , true , idx3 , idx3 );
  	windMenu->connectItem ( idx3, this, SLOT ( slot_showFullScreen( ) ) ); 

  	++idx3;	
//	pm->load( iconReader.getIcon("gen_accelerator_2_small" ));
  	windMenu->insertItem ( "resize", NULL, NULL , true , idx3 , idx3 );
  	windMenu->connectItem ( idx3, this, SLOT ( slot_resize( ) ) ); 
  	  		
  	
	// MainMenu
	ZOptionsMenu * MainMenu = new ZOptionsMenu ( rect, /*softKey*/NULL, "", 0
#if defined(EZX_AURA) || defined(EZX_U9) || defined(EZX_Z6W)
																			, ZSkinService::clsZOptionsMenu, "", ""
#endif																			
																			);  
  	int idx = 0;
  	++idx;	
//	pm->load( iconReader.getIcon("gen_accelerator_1_small" ))
    MainMenu->insertItem ( "Popup Exmple", showPopupMenu, NULL , true , idx, idx );
  	++idx;	
//	pm->load( iconReader.getIcon("gen_accelerator_2_small" ));
	MainMenu->insertItem ( "JumpBox Expl", NULL, NULL , true , idx , idx );
	MainMenu->connectItem ( idx, this, SLOT ( slot_JumpBox( ) ) );
  	++idx;	
//	pm->load( iconReader.getIcon("gen_accelerator_3_small" ))
    MainMenu->insertItem ( "window", windMenu, NULL , true , idx, idx );
    
  	MainMenu->insertSeparator(idx, idx);
  	
  	++idx;	
//	pm->load( iconReader.getIcon("gen_accelerator_2_small" ));
	MainMenu->insertItem ( "Set Cursor", NULL, NULL , true , idx , idx );
	MainMenu->connectItem ( idx, this, SLOT ( slot_WaitCursor( ) ) ); 

  	
// ***************************************** KNOPKI *****************************************************//
  	qDebug("KNOPKI");

  	
#if defined(MOTODEV_STUDIO) || defined(EZX_EM35) || defined(EZX_VE66) 
  	ZCLISoftKey * cliSoftKey = getCLISoftKey(true); // и все равно может крошиться
//	setCLISoftKey(cliSoftKey);
#endif
  		
  	
  	ZSoftKey * softKey = new ZSoftKey(/*NULL*/"CST_2" , this , this);
  	setSoftKey ( softKey );

  	 
// кнопки нарошно поменяны местами, дабы показать, что меню может быть и справа.
// Но лучше делать по привычному слева.
	softKey->setText(ZSoftKey::LEFT, QString("Quit"), (ZSoftKey::TEXT_PRIORITY)0); 
	softKey->setClickedSlot(ZSoftKey::LEFT, qApp, SLOT(quit()));
	softKey->setText(ZSoftKey::MID, QString("Mid"), (ZSoftKey::TEXT_PRIORITY)0);
	softKey->setClickedSlot(ZSoftKey::MID, this, SLOT(JumpBox()));
	softKey->setText(ZSoftKey::RIGHT, QString("MainMenu"), (ZSoftKey::TEXT_PRIORITY)0); 
	softKey->setOptMenu(ZSoftKey::RIGHT, MainMenu);// LSK assing to menu    


	

}


MainWindow::~MainWindow()
{

}

void MainWindow::slotReturnToIdle( int reason )
{
	qDebug(QString("slotReturnToIdle() reason:%1").arg(reason) );
	
}

void MainWindow::slotClickAppIcon( )
{
	qDebug("slotClickAppIcon()");
	
	ZMessageDlg* msg =  new ZMessageDlg ( "slotClickAppIcon ", "slotClickAppIcon"
#if ! defined(EZX_E2) || ! defined(EZX_Z6) || ! defined(EZX_V8) || defined(MOTODEV_STUDIO)
			, ZMessageDlg::TypeOK
#else
			, ZMessageDlg::just_ok
#endif
			, 0, NULL, "ZMessageDlg", true, 0 );
	

	 msg->exec();
}

void MainWindow::slot_JumpBox()
{
	qDebug("slot_JumpBox");

	ZJumpBox* JumpBox = new ZJumpBox(this);
	JumpBox->setLabelText("JumpBox LabelText:");
	JumpBox->setFixedWidth(this->width());
	JumpBox->show();
}

void MainWindow::slot_WaitCursor()
{
	qDebug("slot_WaitCursor");
	
	// разновидности курсоров CrossCursor, IbeamCursor, WaitCursor, ForbiddenCursor
//	this->setCursor (QCursor( IbeamCursor  ) ); // на эмуле не работает 
	QApplication::setOverrideCursor(QCursor( IbeamCursor  )); // работает


	
	
	
	
	

	
	qDebug( QString("Cursor Pos: %1 %2").arg( QCursor::pos().x() ).arg( QCursor::pos().y() ) );
	int i = 0;
	ZMessageDlg* msg =  new ZMessageDlg ( "Cursor position "+ QString::number( i ) , " Cursor Pos:" + QString::number( QCursor::pos().x() ) + " " + QString::number( QCursor::pos().y() )
#if ! defined(EZX_E2) || ! defined(EZX_Z6) || ! defined(EZX_V8) || defined(MOTODEV_STUDIO)
			, ZMessageDlg::TypeOK
#else
			, ZMessageDlg::just_ok
#endif
			, 0, NULL, "ZMessageDlg", true, 0 );
	

	while ( msg->exec() == 0 )
	{
	msg->setInstructText( "Cursor Pos:" + QString::number( QCursor::pos().x() ) + " " + QString::number( QCursor::pos().y() ) );
	i++;
	}
	
	
}

void MainWindow::slot_resize()
{
	qDebug("slot_resize");

#if defined(EZX_AURA)
	if ( this->height() == 170  && this->width() == 200 )
		this->resize( 480, 480 );
	else
		this->resize( 200, 170 );
#else
	if ( this->height() == 160  && this->width() == 128 )
		this->resize( 240, 320 );
	else
		this->resize( 128, 160 );
#endif	
}

void MainWindow::slot_showFullScreen()
{
	qDebug("slot_showFullScreen");
	
	if ( ! getFullScreenMode() )
		this->setFullScreenMode(true); // virtual 3.0
	else
		this->setFullScreenMode(false); // virtual 3.0
//	setFullScreen();
//    showNormal();	

}

void MainWindow::slot_4()
{
	qDebug("ZColorModule Popup");
	

//	ZColorControl * cc = new ZColorControl( QColor(255,255,255),"title"  );
	
	QColor color;
	color.setNamedColor("red");

#ifndef MOTODEV_STUDIO
	ZColorPickerDlg * dlg = new ZColorPickerDlg(color,NULL,0,this);
	if ( dlg->exec() == QDialog::Accepted )
	{
				qDebug(dlg->getColor().name());
	}
#endif

}






/*
int main(int argc, char *argv[])
{
    ZApplication* app = new ZApplication(argc, argv);

    MainWindow *mainWin = new MainWindow(NULL);
//    app->setMainWidget(mainWin);
    mainWin->show();
    int ret = app->exec();
    delete mainWin; mainWin = NULL;
    delete app; app = NULL;
    return ret;
}


#include "moc_hello_all.cpp"
*/
