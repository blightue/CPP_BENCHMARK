//
// Created by SUISUISHOU on 2023/2/2.
//

#ifndef CLI_CPP_POINT3_H
#define CLI_CPP_POINT3_H

#include <vector>
#include <memory>
#include <limits>
#include <oneapi/tbb.h>

using namespace std;
using namespace tbb;

class Point3 {
public:
    Point3();
    Point3(float x, float y, float z);
    static float sqr_distance(Point3 a, Point3 b);
    static std::vector<int> find_closed_indices(const std::vector<Point3> &points1, const std::vector<Point3> &points2);
    static unique_ptr<vector<Point3>> generate_points(size_t count);
    static bool check_closed_indices(const std::vector<int> &indices, const std::vector<Point3> &points1, const std::vector<Point3> &points2);

private:
    float x_;
    float y_;
    float z_;

    static int find_closed_index(const Point3 &target, const std::vector<Point3> &points);
    static bool check_closed_index(int index, const Point3 &point, const vector<Point3> &points);
};


#endif //CLI_CPP_POINT3_H
