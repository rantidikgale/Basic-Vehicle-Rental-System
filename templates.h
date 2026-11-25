#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <QVector>

template <typename T>
bool containsItem(const QVector<T>& list, const T& value){

    for (auto it = list.begin(); it != list.end(); it++){

        if (*it == value){

            return true;
        }
    }

    return false;
}

#endif // TEMPLATES_H
