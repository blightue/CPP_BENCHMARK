//
// Created by SUISUISHOU on 2023/2/2.
//

#include "point3.h"

Point3::Point3() {
    x_ = 0;
    y_ = 0;
    z_ = 0;
}

Point3::Point3(float x, float y, float z) {
    this->x_ = x;
    this->y_ = y;
    this->z_ = z;
}

Point3 Point3::operator-(Point3 const &other) const {
    return {x_ - other.x_, y_ - other.y_, z_ - other.z_};
}

float Point3::sqr_distance() const {
    return x_ * x_ + y_ * y_ + z_ * z_;
}

float Point3::sqr_distance(const Point3 &other) const {
    float x = x_ - other.x_;
    float y = y_ - other.y_;
    float z = z_ - other.z_;

    return x * x + y * y + z * z;
}


