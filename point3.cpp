//
// Created by SUISUISHOU on 2023/2/2.
//

#include "point3.h"
#include <limits>
#include <algorithm>
#include "numeric"
#include "execution"

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

float Point3::Distance2(Point3 a, Point3 b) {
    float offset_x = a.x_ - b.x_;
    float offset_y = a.y_ - b.y_;
    float offset_z = a.z_ - b.z_;

    return offset_x * offset_x + offset_y * offset_y + offset_z * offset_z;
}

std::vector<int> Point3::FindClosedIndices(const std::vector<Point3> &points1, const std::vector<Point3> &points2) {
    std::vector<int> indices(points1.size());
    std::iota(indices.begin(), indices.end(), 0);

    std::for_each(std::execution::par_unseq, indices.begin(), indices.end(), [&](int target){

    });

    return indices;
}

int Point3::FindClosedIndex(const Point3 &target, const std::vector<Point3> &points) {
    float min_distance2 = std::numeric_limits<float>::max();
    int min_index = 0;

    for (int i = 0; i < points.size(); ++i) {
        float distance2 = Point3::Distance2(target, points[i]);

        if (distance2 < min_distance2){
            min_distance2 = distance2;
            min_index = i;
        }
    }

    return min_index;
}
