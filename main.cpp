#include <iostream>
#include <memory>
#include "point3.h"
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

const int kCount = 100000;

vector<Point3> *generate_points()
{
    auto *result = new vector<Point3>(kCount, Point3());

    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<float> dist(-1.0, 1.0);

    for (int i = 0; i < kCount; ++i)
    {
        result->at(i) = Point3(dist(mt), dist(mt), dist(mt));
    }

    return result;
}

int main()
{

    for (size_t i = 0; i < 10; i++)    
    {
        auto start = system_clock::now();
        unique_ptr<vector<Point3>> points1(generate_points());
        unique_ptr<vector<Point3>> points2(generate_points());
        auto finished = system_clock::now();

        cout << "Gen points with length: "
             << points1->size()
             << " speed time: "
             << duration_cast<milliseconds>(finished - start).count()
             << " ms\n";

        start = system_clock::now();

        auto result = Point3::FindClosedIndices(*points1, *points2);

        finished = system_clock::now();

        cout << "Find closed indices: "
             << result.size()
             << " speed time: "
             << duration_cast<milliseconds>(finished - start).count()
             << " ms\n";
    }
}
