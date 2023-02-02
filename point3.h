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
    static float Distance2(Point3 a, Point3 b);
    static std::vector<int> FindClosedIndices(const std::vector<Point3> &points1, const std::vector<Point3> &points2);
    static int FindClosedIndex(const Point3 &target, const std::vector<Point3> &points);

private:
    float x_;
    float y_;
    float z_;
};


#endif //CLI_CPP_POINT3_H
