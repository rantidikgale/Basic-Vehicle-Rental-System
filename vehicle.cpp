#include "vehicle.h"

vehicle::vehicle() {}



        QString vehicle::get_id(){
            return id;
        }
        QString vehicle::get_brand(){
            return brand;
        }
        QString vehicle::get_model(){
            return model;
        }
        double vehicle::get_pricePerDay(){
            return pricePerDay;
        }
        bool vehicle::get_isRented(){
            return isRented;
        }

        void vehicle::set_id(QString id){
            this ->id=id;
        }
        void vehicle::set_brand(QString brand){
            this ->brand=brand;
        }
        void vehicle::set_model(QString model){
            this ->model=model;
        }
        void vehicle::set_price(double pricePerDay){
            this ->pricePerDay=pricePerDay;
        }
        void vehicle::set_rent(bool isRented){
            this ->isRented  = isRented;
        }

     QString vehicle::displayInfo() const{
            return "ID "+id +"\n" +
            "brand: "+brand +"\n" +
            "price per day: "+QString::number(pricePerDay)+ "\n"+
            "rented: "+QString(isRented? "yes" : "no");
        }
