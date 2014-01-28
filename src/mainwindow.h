#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include "dialogresourcemanager.h"
#include "dialogdatabase.h"
#include "gameproject.h"
#include "tools/QGraphicsPaleteScene.h"
#include "tools/QGraphicsMapWidget.h"
#include "musicplayer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void LoadProject(QString p_path);
    
private slots:
    void on_action_Quit_triggered();

    void on_actionPalete_triggered(bool checked);

    void on_actionMap_Tree_triggered(bool checked);

    void on_actionResource_Manager_triggered();

    void on_actionData_Base_triggered();

    void update_actions();

    void on_action_New_Project_triggered();

    void on_action_Close_Project_triggered();

    void on_action_Open_Project_triggered();
    void on_actionJukebox_triggered(bool disconnect = false);


    void on_actionChipset_triggered();

    void on_action_Lower_Layer_triggered();

    void on_action_Upper_Layer_triggered();

    void on_action_Events_triggered();

private:

    bool removeDir(const QString & dirName, const QString &root);

    Ui::MainWindow *ui;
    DialogResourceManager *dlg_resource;
    DialogDataBase *dlg_db;
    QSettings m_settings;
    QString m_defDir;
    QGraphicsPaleteScene *m_paleteScene;
    QGraphicsMapWidget *m_mapWidget;
};

#endif // MAINWINDOW_H
