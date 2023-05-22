#include "VectorPoint.h"

Vector::Vector() : x_(0), y_(0), z_(0) {}

Vector::Vector(double x, double y, double z) : x_(x), y_(y), z_(z) {}

Vector::Vector(const Vector& other) : x_(other.x_), y_(other.y_), z_(other.z_) {}

double Vector::GetX() const {
    return this->x_;
}

double Vector::GetY() const {
    return this->y_;
}

double Vector::GetZ() const {
    return this->z_;
}

Vector& Vector::operator= (const Vector& other)
{
    x_ = other.x_;
    y_ = other.y_;
    z_ = other.z_;
    return *this;
}

bool Vector::operator== (const Vector& other)
{
    return fabs(x_ - other.x_) < numeric_limits<double>::epsilon() &&
        fabs(y_ - other.y_) < numeric_limits<double>::epsilon() &&
        fabs(z_ - other.z_) < numeric_limits<double>::epsilon();
}

double Vector::operator*(const Vector& a) {
    return this->x_ * a.x_ + this->y_ * a.y_ + this->z_ * a.z_;
}

void Vector::Print() const {
    cout << "point " << this->x_ << " " << this->y_ << " " << this->z_;
}

double Vector::Distance(const Vector& b) const {
    return sqrt(pow(b.x_ - this->x_, 2) + pow(b.y_ - this->y_, 2) + pow(b.z_ - this->z_, 2));
}

bool Vector::IsInSegment(const Vector& startSeg, const Vector& endSeg) const {
    //Epsilon умножается на 3 из-за накапливания погрешности
    return fabs(this->Distance(startSeg) + this->Distance(endSeg) - endSeg.Distance(startSeg)) < numeric_limits<double>::epsilon() * 3;
}

Vector operator+(const Vector& a, const Vector& b) {
    return { a.GetX() + b.GetX(), a.GetY() + b.GetY(), a.GetZ() + b.GetZ() };
}

Vector operator-(const Vector& a, const Vector& b) {
    return { a.GetX() - b.GetX(), a.GetY() - b.GetY(), a.GetZ() - b.GetZ() };
}

Vector operator*(const Vector& a, const double l) {
    return { a.GetX() * l, a.GetY() * l, a.GetZ() * l };
}
