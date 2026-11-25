#include "motorcycle.h"

motorcycle::motorcycle(
                        QString id,
                        QString brand,
                        QString model,
                        double price,
                        bool rent,
                        int cc)

:vehicle(id,brand,model,price,rent){
    engineCapacityCC = cc;
}

int motorcycle::get_cc(){
    return engineCapacityCC;
}

void motorcycle::set_cc(int cc){
    engineCapacityCC= cc;
}

QString motorcycle::typeName() const{
    return "motorcycle";
}

QString motorcycle::displayInfo()const{
    return vehicle::displayInfo()+"\n"+
           "engine cc: "+ QString::number(engineCapacityCC);
}
