#pragma once
#include <math.h>
#include <iostream>

using namespace std;

/**
 * ����� ������ ������������ ��� ��� ������������� ����� � ���� ��������, ��� � ��� �������� � ������������ � ������� ������
 * ������������� ������� ������������ ��� ������� ��������� ������������ ������� ��� ���������� �����-��������
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

    //��������� ������������ �������� a, b
    double operator*(const Vector& a);

    double GetX() const;

    double GetY() const;

    double GetZ() const;

    //����� ��������� �������/�������-�����
    void Print() const;

    //���������� ����� ������ ������ � ������ b
    double Distance(const Vector& b) const;

    //�������� �������������� ����� �������� � ������� startSeg � ������ endSeg
    bool IsInSegment(const Vector& startSeg, const Vector& endSeg) const;
};

//�������� �������� a, b
Vector operator+ (const Vector& a, const Vector& b);

//��������� �������� a, b
Vector operator-(const Vector& a, const Vector& b);

//��������� ������� � �� ������ l
Vector operator*(const Vector& a, const double l);