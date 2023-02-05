//
// Created by SUISUISHOU on 2023/2/2.
//

#include "point3.h"

Point3::Point3()
{
    x_ = 0;
    y_ = 0;
    z_ = 0;
}

Point3::Point3(float x, float y, float z)
{
    this->x_ = x;
    this->y_ = y;
    this->z_ = z;
}

float Point3::sqr_distance(Point3 a, Point3 b)
{
    float offset_x = a.x_ - b.x_;
    float offset_y = a.y_ - b.y_;
    float offset_z = a.z_ - b.z_;

    return offset_x * offset_x + offset_y * offset_y + offset_z * offset_z;
}

std::vector<int> Point3::find_closed_indices(const std::vector<Point3> &points1, const std::vector<Point3> &points2)
{
    std::vector<int> indices(points1.size(), 0);

    parallel_for(size_t(0), indices.size(), [&](const size_t i)
                 {
        Point3 target = points1[i];
        indices[i] = find_closed_index(target, points2); });

    return indices;
}

unique_ptr<vector<Point3>> Point3::generate_points(size_t count)
{
    return unique_ptr<vector<Point3>>();
}

int Point3::find_closed_index(const Point3 &target, const std::vector<Point3> &points)
{
    float min_distance2 = std::numeric_limits<float>::max();
    int min_index = 0;

    for (int i = 0; i < points.size(); ++i)
    {
        float distance2 = Point3::sqr_distance(target, points[i]);

        return min_index;
    }
}

unique_ptr<vector<Point3>> Point3::generate_points(size_t count)
{
    unique_ptr<vector<Point3>> result = make_unique<vector<Point3>>(count, Point3());

    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<float> dist(-1.0, 1.0);

    for (int i = 0; i < count; ++i)
    {
        result->at(i) = Point3(dist(mt), dist(mt), dist(mt));
    }

    return result;
}

bool Point3::check_closed_indices(const std::vector<int> &indices, const std::vector<Point3> &points1, const std::vector<Point3> &points2)
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<size_t> dist(0, points1.size());

    for (int i = 0; i < 10; ++i)
    {
        size_t index = dist(mt);
        Point3 point = points1[index];

        if (!check_closed_index(indices[index], point, points2))
        {
            return false;
        }
    }

    return true;
}

bool Point3::check_closed_index(int index, const Point3 &point, const vector<Point3> &points)
{
    float min_distance = Point3::sqr_distance(point, points[index]);

    for (Point3 p : points)
    {
        float distance = Point3::sqr_distance(point, p);

        if (distance < min_distance)
        {
            return false;
        }
    }

    return true;
}