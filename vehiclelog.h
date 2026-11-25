#ifndef VEHICLELOG_H
#define VEHICLELOG_H
#include <QVector>
#include <QFile>
#include <QFile>
#include "vehicle.h"
#include "car.h"
#include "motorcycle.h"

class vehicleLog
{
private:
    QVector<vehicle*>vh;
public:
    vehicleLog();
    ~vehicleLog();

    void add_vehicle(vehicle* v);
    QVector<vehicle*> getVehicles();

    vehicle* search(QString id);

    void display_all();
    void display_available();

    bool rentV(QString id);
    bool returnV(QString id);
    bool id_check(QString id);

    void remove_vehicle(QString id);

    void load();
    void save();
};

#endif // VEHICLELOG_H
