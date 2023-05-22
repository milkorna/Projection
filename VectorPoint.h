#pragma once
#include <math.h>
#include <iostream>

using namespace std;

/**
 * Класс вектор используется как для представления точек в виде векторов, так и для векторов в пространстве в обычном смысле
 * Дружественные функции используются для лучшего понимания используемой формулы для нахождения точки-проекции
 */
class Vector {
private:
    double  x_, y_, z_;
public:
    Vector();

    Vector(double x, double y, double z);

    Vector(const Vector& other);

    Vector& operator= (const Vector& other);

    bool operator== (const Vector& other);

    //Скалярное произведение векторов a, b
    double operator*(const Vector& a);

    double GetX() const;

    double GetY() const;

    double GetZ() const;

    //Вывод координат вектора/вектора-точки
    void Print() const;

    //Расстояние между данной точкой и точкой b
    double Distance(const Vector& b) const;

    //Проверка принадлежности точки сегменту с началом startSeg и концом endSeg
    bool IsInSegment(const Vector& startSeg, const Vector& endSeg) const;
};

//Сложение векторов a, b
Vector operator+ (const Vector& a, const Vector& b);

//Вычитание векторов a, b
Vector operator-(const Vector& a, const Vector& b);

//Умножение вектора а на скаляр l
Vector operator*(const Vector& a, const double l);
