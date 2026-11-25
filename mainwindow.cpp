#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "templates.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addVehiclepushButton_clicked()
{

    QString id = ui->idEdit->text();
    QString brand = ui->brandEdit->text();
    QString model = ui->modelEdit->text();
    bool priceOk;
    double price = ui->priceEdit->text().toDouble(&priceOk);
    int doors = ui->doorsEdit->text().toInt();
    int seats = ui->seatsEdit->text().toInt();
    int cc= ui->ccEdit->text().toInt();


    QString type = ui->vehicleTypeComboBox->currentText();


    if(id.isEmpty()){ //empty slots
        QMessageBox::warning(this, "INVALID INPUT", "please enter valid ID");
        return;
    }

    if(log.id_check(id)){//duplucate id check
        QMessageBox::warning(this, "INVALID INPUT", "ID already exists");
        return;
    }

    if(brand.isEmpty() || model.isEmpty()){
        QMessageBox::warning(this, "INVALID INPUT", "Enter vehicle brand and model");
        return;
    }
    if(!priceOk || price <=0){
        QMessageBox::warning(this, "INVALID INPUT", "please enter a valid price ");
        return;
    }

    if(type =="CAR"){
        if(doors <=0 || seats <=0){
            QMessageBox::warning(this, "INVALID INPUT", "please enter valid number of seats or doors. ");
            return;
        }
        car* newCar =new car(
            id,
            brand,
            model,
            price,
            false,
            doors,
            seats
            );
        log.add_vehicle(newCar);
        updatevehicleTable();
        updateSummary();

        QMessageBox::information(this, "success!", "car added");
    }

    else if(type == "MOTORCYCLE"){
        if(cc<=0){
            QMessageBox::warning(this, "INVALID INPUT", "capacity must be greater than 0");
            return;
        }

        motorcycle* newMotorcycle = new motorcycle(
            id,
            brand,
            model,
            price,
            false,
            cc
            );

        log.add_vehicle(newMotorcycle);
        updatevehicleTable();
        updateSummary();

        QMessageBox::information(this, "success!", "motocycle added");
    }
    QMessageBox::information(
        this,
        "Vehicle Information",
        "ID: " + id +
            "\nBrand: " + brand +
            "\nModel: " + model +
            "\nPrice: " + QString::number(price) +
            "\nType: " + type
        );
}


void MainWindow::updatevehicleTable()
{

    ui->vehicleTable->setRowCount(0);

    QVector<vehicle*> vehicles = log.getVehicles();


    for (vehicle* v : vehicles)
    {
        int row = ui->vehicleTable->rowCount();

        ui->vehicleTable->insertRow(row);

        ui->vehicleTable->setItem(row,0,
            new QTableWidgetItem(v->get_id())
            );

        ui->vehicleTable->setItem(
            row,
            1,
            new QTableWidgetItem(v->get_brand())
            );

        ui->vehicleTable->setItem(
            row,
            2,
            new QTableWidgetItem(v->get_model())
            );

        ui->vehicleTable->setItem(
            row,
            3,
            new QTableWidgetItem(
                QString::number(v->get_pricePerDay())
                )
            );

        ui->vehicleTable->setItem(
            row,
            4,
            new QTableWidgetItem(v->typeName())
            );

        QString status;

        if (v->get_isRented())
        {
            status = "Rented";
        }
        else
        {
            status = "Available";
        }

        ui->vehicleTable->setItem(
            row,
            5,
            new QTableWidgetItem(status)
            );
    }
}


void MainWindow::on_searchVehiclepushButton_clicked()
{
    QString id = ui->idEdit->text();

    if (id.isEmpty()){
        QMessageBox::warning(this, "Invalid Input", "Please enter a vehicle ID.");
        return;
    }

    vehicle* v = log.search(id);

    if (v == nullptr){
        QMessageBox::warning(this, "Not Found", "vehicle ID was not found.");
        return;
    }

    QMessageBox::information(this, "Vehicle Found", v->displayInfo());
}


void MainWindow::on_rentpushButton_clicked()
{
    QString id = ui->idEdit->text();

    if (id.isEmpty()){
        QMessageBox::warning(this, "Invalid Input", "enter valid a vehicle ID.");
        return;
    }

    bool success = log.rentV(id);

    if (success){

        updatevehicleTable();

        QMessageBox::information(this, "Success", "Vehicle rented successfully.");
    }
    else{
        QMessageBox::warning(this,"Unsuccessful", "Vehicle could not be rented");
    }
}


void MainWindow::on_returnpushButton_clicked()
{
    QString id = ui->idEdit->text();

    if (id.isEmpty()){
        QMessageBox::warning(this, "Invalid Input", "enter valid a vehicle ID.");
        return;
    }

    bool success = log.returnV(id);

    if (success){

        updatevehicleTable();

        QMessageBox::information(this, "Success", "Vehicle returned successfully.");
    }
    else{
        QMessageBox::warning(this,"Unsuccessful", "Vehicle could not be returned");
    }


}


void MainWindow::on_removepushButton_clicked()
{
    QString id = ui->idEdit->text();

    if (id.isEmpty()){
        QMessageBox::warning(this, "Invalid Input", "enter valid a vehicle ID.");
        return;
    }

    vehicle* v  = log.search(id);

    if (v == nullptr){
        QMessageBox::warning(this, "Not Found", "vehicle ID was not found.");
        return;
    }

    log.remove_vehicle(id);
    updatevehicleTable();

        QMessageBox::information(this,"successful", "Vehicle remove!");
}


void MainWindow::on_vehicleTypeComboBox_currentTextChanged(const QString &arg1)
{
    if (arg1 == "CAR"){
        ui->doorsEdit->show();
        ui->seatsEdit->show();
        ui->ccEdit->hide();
    }
    else if (arg1 == "MOTORCYCLE")
{
        ui->doorsEdit->hide();
        ui->seatsEdit->hide();
        ui->ccEdit->show();
    }
}


void MainWindow::updateSummary(){

    QVector<vehicle*> vehicles = log.getVehicles();

    int total = vehicles.size();
    int available = 0;
    int rented = 0;
    int cars = 0;
    int motorcycles = 0;
    QVector<vehicle*>::iterator it;

    for (it = vehicles.begin(); it != vehicles.end(); it++){

        vehicle* v= *it;

        if (v->get_isRented()){
            rented++;
        }
        else{
            available++;
        }

        if (v->typeName() == "CAR"){
            cars++;
        }
        else if (v->typeName() == "MOTORCYCLE"){
            motorcycles++;
        }
    }

    ui->totalVehiclesLabel->setText( "Total Vehicles = " + QString::number(total));

    ui->availableVehiclesLabel->setText( "Available = " + QString::number(available));

    ui->rentedVehiclesLabel->setText( "Rented = " + QString::number(rented));

    ui->carsLabel->setText( "Cars = " + QString::number(cars));

    ui->motorcyclesLabel->setText( "Motorcycles = " + QString::number(motorcycles));
}
