#include <QApplication>
#include <QScreen>
#include <QStyleHints>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

#include "dialog.h"

int main(int argc, char *argv[])
{
    //QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication app(argc, argv);
    QGuiApplication::setApplicationDisplayName(Dialog::tr("Standard Dialogs"));

    Dialog dialog;
    if (!QGuiApplication::styleHints()->showIsFullScreen() && !QGuiApplication::styleHints()->showIsMaximized()) {
        const QRect availableGeometry = dialog.screen()->availableGeometry();
        dialog.resize(availableGeometry.width() / 3, availableGeometry.height() * 2 / 3);
        dialog.move((availableGeometry.width() - dialog.width()) / 2,
                    (availableGeometry.height() - dialog.height()) / 2);
    }
    dialog.show();

    return app.exec();
}
