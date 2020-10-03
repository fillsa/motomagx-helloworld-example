
// MY
#include "HelloWorld.h"

// EZX
#include <ZApplication.h>

//#define UKAZATEL // motodev studio не использует указать

int main(int argc, char *argv[])
{
    #ifdef UKAZATEL
        ZApplication* app = new ZApplication(argc, argv);
    #else
        ZApplication app(argc, argv);
    #endif

        // Initialize the UI. Most of your implementation
        // code exists in this class.
    //    QWallpaper::setAppWallpaperMode(QWallpaper::Off); // обоина приложения
    #ifdef UKAZATEL
        MainWindow *main = new MainWindow( NULL );
//        app/*qApp*/->setMainWidget(main);
        main->show();
    #else
        MainWindow main( NULL );
//        app.setMainWidget(&main);
        main.show();
    #endif

    #ifdef UKAZATEL
        int ret = app->exec();
        delete main; main = NULL;
    #else
        int ret = app.exec();
    #endif 

    return ret;
}


