#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vehiclelog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_addVehiclepushButton_clicked();

    void on_searchVehiclepushButton_clicked();

    void on_rentpushButton_clicked();

    void on_returnpushButton_clicked();

    void on_removepushButton_clicked();

    void on_vehicleTypeComboBox_currentTextChanged(const QString &arg1);



private:
    Ui::MainWindow *ui;
    vehicleLog log;

    void updatevehicleTable();

    void updateSummary();
};
#endif // MAINWINDOW_H
