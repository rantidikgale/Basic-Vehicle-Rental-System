#include "car.h"

car::car(QString id,
        QString brand,
        QString model,
        double pricePerDay,
        bool isRented,
        int doors,
        int seats)

    :vehicle(id,brand,model,pricePerDay,isRented){
    num_doors=doors;
    num_seats=seats;
}

int car::get_doors(){
    return num_doors;
}
int car::get_seats(){
    return num_seats;
}

void car::set_seats(int seats){
    num_seats= seats;
}
void car::set_doors(int doors){
    num_doors=doors;
}

QString car::typeName() const{
    return "car";
}

QString car::displayInfo() const{
    return vehicle::displayInfo() + "\n"+
           "DOORS: "+ QString::number(num_doors) + "\n"+
           "SEATS: "+ QString::number(num_seats);
}
