#include <QTextStream>
#include "vehiclelog.h"


vehicleLog::vehicleLog() {}

vehicleLog::~vehicleLog() {
    for(vehicle* const &v :vh){
        delete v;
    }
}

void vehicleLog::add_vehicle(vehicle *v){
    vh.append(v);
}

QVector<vehicle*> vehicleLog::getVehicles(){
    return vh;
}

bool vehicleLog::id_check(QString id)
{
    for(vehicle* const &v : vh)
    {
        if(v->get_id() == id)
        {
            return true;
        }
    }

    return false;
}

vehicle* vehicleLog::search(QString id){
    for(vehicle* const &v : vh){
        if(v->get_id()==id){
            return v;
        }
    }
    return nullptr;
}

void vehicleLog::display_all(){
    QTextStream qout(stdout);

    for(vehicle* const &v :vh){
        qout<<v->displayInfo()<<"\n";
    }
}

void vehicleLog::display_available()
{
    QTextStream qout(stdout);

    for(vehicle* const &v :vh ){

        if(!v->get_isRented())
        {
            qout<<v->displayInfo()<<"\n";
        }
    }
}
bool vehicleLog::rentV(QString id){

    vehicle* v=search(id);

    if(v==nullptr)
        return false;

    if(v->get_isRented())
        return false;

    v->set_rent(true);

    return true;
}
bool vehicleLog::returnV(QString id){
    vehicle* v=search(id);

    if(v==nullptr)
        return false;

    if(!v->get_isRented())
        return false;

    v->set_rent(false);

    return true;
}
void vehicleLog::load()
{
    QFile file("vehicles.txt");

    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
        return;

    QTextStream in(&file);

    while(!in.atEnd())
    {
        QString line=in.readLine();

        QStringList data=line.split("|");

        if(data[0]=="Car")
        {
            vehicle* v=new car(
                data[1],
                data[2],
                data[3],
                data[4].toDouble(),
                data[5].toInt(),
                data[6].toInt(), //doors
                data[7].toInt());// seats

            vh.append(v);
        }

        else if(data[0]=="motorcycle")
        {
            vehicle* v=new motorcycle(
                data[1],
                data[2],
                data[3],
                data[4].toDouble(),
                data[5].toInt(),
                data[6].toInt());//engine

            vh.append(v);
        }

    }

    file.close();
}

void vehicleLog::save()
{
    QFile file("vehicles.txt");

    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
        return;

    QTextStream out(&file);

    for(vehicle* const &v:vh)
    {
        out<<v->typeName()<<"|"
        <<v->get_id()<<"|"
        <<v->get_brand()<<"|"
        <<v->get_model()<<"|"
        <<v->get_pricePerDay()<<"|"
        <<v->get_isRented()
        <<"\n";
    }

    file.close();
}

void vehicleLog::remove_vehicle(QString id)
{
    for (int i = 0; i < vh.size(); i++)
    {
        if (vh[i]->get_id() == id)
        {
            delete vh[i];
            vh.removeAt(i);
            return;
        }
    }
}
