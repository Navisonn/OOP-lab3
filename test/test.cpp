#include <iostream>
#include <cassert>
#include <cmath>
#include <memory>
#include <vector>
#include "rhombus.h"
#include "pentagon.h"
#include "hexagon.h"

void testRhombus() {
    std::cout << "Testing Rhombus..." << std::endl;
    Rhombus r(4.0, 6.0);
    assert(std::abs(r.area() - 12.0) < 1e-9);
    std::cout << "Area test passed" << std::endl;
    Point center = r.center();
    assert(std::abs(center.x - 0.0) < 1e-9 && std::abs(center.y - 0.0) < 1e-9);
    std::cout << "Center test passed" << std::endl;
    Rhombus r2(1.0, 1.0);
    r2 = r; 
    assert(r == r2);
    std::cout << "Assignment test passed" << std::endl;
    double area = static_cast<double>(r);
    assert(std::abs(area - 12.0) < 1e-9);
    std::cout << "Double conversion test passed" << std::endl;
    std::cout << "All Rhombus tests passed!\n" << std::endl;
}

void testPentagon() {
    std::cout << "Testing Pentagon..." << std::endl;
    Pentagon p(2.0);
    double expected_area = (5.0 * 2.0 * 2.0) / (4.0 * tan(M_PI / 5.0));
    assert(std::abs(p.area() - expected_area) < 1e-9);
    std::cout << "Area test passed" << std::endl;
    Point center = p.center();
    assert(std::abs(center.x - 0.0) < 1e-9 && std::abs(center.y - 0.0) < 1e-9);
    std::cout << "Center test passed" << std::endl;
    Pentagon p2(2.0);
    assert(p == p2);
    std::cout << "Comparison test passed" << std::endl;
    std::cout << "All Pentagon tests passed!\n" << std::endl;
}

void testHexagon() {
    std::cout << "Testing Hexagon..." << std::endl;
    Hexagon h(3.0);
    double expected_area = (3.0 * sqrt(3.0) * 3.0 * 3.0) / 2.0;
    assert(std::abs(h.area() - expected_area) < 1e-9);
    std::cout << "Area test passed" << std::endl;
    Point center = h.center();
    assert(std::abs(center.x - 0.0) < 1e-9 && std::abs(center.y - 0.0) < 1e-9);
    std::cout << "Center test passed" << std::endl;
    std::cout << "Hexagon output: " << h << std::endl;
    std::cout << "Stream output test passed" << std::endl;
    std::cout << "All Hexagon tests passed!\n" << std::endl;
}

void testFigureArray() {
    std::cout << "Testing Figure Array..." << std::endl;
    std::vector<std::shared_ptr<Figure>> figures;
    figures.push_back(std::make_shared<Rhombus>(4.0, 6.0));
    figures.push_back(std::make_shared<Pentagon>(2.0));
    figures.push_back(std::make_shared<Hexagon>(3.0));
    double total_area = 0;
    for (const auto& fig : figures) {
        total_area += fig->area();
    }
    
    double expected_total = 12.0 + (5.0 * 2.0 * 2.0) / (4.0 * tan(M_PI / 5.0)) + (3.0 * sqrt(3.0) * 3.0 * 3.0) / 2.0;
    assert(std::abs(total_area - expected_total) < 1e-9);
    std::cout << "Total area calculation test passed" << std::endl;
    for (const auto& fig : figures) {
        Point center = fig->center();
        double area = fig->area();
        assert(area > 0);
        std::cout << "Figure center: (" << center.x << ", " << center.y << "), area: " << area << std::endl;
    }
    std::cout << "Polymorphism test passed" << std::endl;
    std::cout << "All Figure Array tests passed!\n" << std::endl;
}

int main() {
    std::cout << "Starting unit tests...\n" << std::endl;
    try {
        testRhombus();
        testPentagon();
        testHexagon();
        testFigureArray();
        std::cout << "All tests passed successfully!" << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }
}
