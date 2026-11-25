#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

class car : public vehicle
{
private:
    int num_doors;
    int num_seats;
public:
    car(
        QString id,
        QString brand,
        QString model,
        double pricePerDay,
        bool isRented,
        int doors,
        int seats);

    int get_doors();
    int get_seats();

    void set_doors(int doors);
    void set_seats(int seats);

    QString typeName() const override;
    QString displayInfo() const override;
};

#endif // CAR_H
