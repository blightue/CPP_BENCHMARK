#include <iostream>
#include <memory>
#include "point3.h"
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include "numeric"
#include "execution"
using namespace std;
using namespace chrono;

const int kCount = 100000;

vector<Point3>* generate_points(){
    auto * result = new vector<Point3> (kCount, Point3());

    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<float> dist(-1.0, 1.0);

    for (int i = 0; i < kCount; ++i) {
        result->at(i) = Point3(dist(mt), dist(mt), dist(mt));
    }

    return result;
}

int main() {

//    while (true) {
//        auto start = system_clock::now();
//        unique_ptr<vector<Point3>> points(generate_points());
//        auto finished = system_clock::now();
//
//        cout<<"Gen points with length: "<< points->size() << " speed time: "<<duration_cast<milliseconds>(finished - start) <<endl;
//    }

    std::vector<int> indices(100);
    std::iota(indices.begin(), indices.end(), 0);

    std::for_each(std::execution::par_unseq, indices.begin(), indices.end(), [](int i){cout<<"Get: " + to_string(i) + "\n";});

}
