//
// Created by SUISUISHOU on 2023/2/2.
//

#ifndef CLI_CPP_POINT3_H
#define CLI_CPP_POINT3_H

#include <vector>

class Point3 {
public:
    Point3();
    Point3(float x, float y, float z);

    Point3 operator-(Point3 const &other) const;
    float sqr_distance() const;
    float sqr_distance(Point3 const &other) const;


private:
    float x_;
    float y_;
    float z_;
};


#endif //CLI_CPP_POINT3_H
