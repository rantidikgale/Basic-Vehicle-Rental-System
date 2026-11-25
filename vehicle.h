#ifndef VEHICLE_H
#define VEHICLE_H

#include <QString>

class vehicle
{
private:
    QString id;
    QString brand;
    QString model;
    double pricePerDay;
    bool isRented;
public:
    vehicle();

    vehicle(QString id,
            QString brand,
            QString model,
            double price,
            bool rent) :
            id(id),
            brand(brand),
            model(model),
            pricePerDay(price),
            isRented(rent){}

    virtual ~vehicle(){}


    QString get_id();
    QString get_brand();
    QString get_model();
    double get_pricePerDay();
    bool get_isRented();


    void set_id(QString id);
    void set_brand(QString brand);
    void set_model(QString model);
    void set_price(double pricePerDay);
    void set_rent(bool isRented);

    virtual QString typeName() const = 0;
    virtual QString displayInfo() const;

};

#endif // VEHICLE_H
