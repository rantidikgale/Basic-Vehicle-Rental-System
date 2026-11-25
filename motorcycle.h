#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "vehicle.h"

class motorcycle : public vehicle {
private:
    int engineCapacityCC;
public:
    motorcycle(
        QString id,
        QString brand,
        QString model,
        double pricePerDay,
        bool isRented,
        int cc);


    int get_cc();

    void set_cc(int cc);


    QString typeName() const override;
    QString displayInfo() const override;


};

#endif // MOTORCYCLE_H
