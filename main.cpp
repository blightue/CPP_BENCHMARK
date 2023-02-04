#include <iostream>
#include <memory>
#include <vector>
#include <chrono>
#include <random>
#include "point3.h"
#include "benchmark.h"

using namespace std;
using namespace chrono;

const int kCount = 100000;



int main()
{

    for (size_t i = 0; i < 10; i++)    
    {
        auto start = system_clock::now();
        unique_ptr<vector<Point3>> points1 = generate_points(kCount);
        unique_ptr<vector<Point3>> points2 = generate_points(kCount);
        auto finished = system_clock::now();

        cout << "Gen points with length: "
             << points1->size()
             << " speed time: "
             << duration_cast<milliseconds>(finished - start).count()
             << " ms\n";

        start = system_clock::now();

        auto result = find_closed_indices(*points1, *points2);

        finished = system_clock::now();

        cout << "Find closed indices: "
             << result.size()
             << " speed time: "
             << duration_cast<milliseconds>(finished - start).count()
             << " ms\n";

        cout << "Check result: "
            << (check_indices(result, *points1, *points2) ? "Passed": "Failed")
            << "\n\n";
    }
}
