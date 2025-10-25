#pragma once
#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    bool operator==(const Point& other) const {
        return std::abs(x - other.x) < 1e-9 && std::abs(y - other.y) < 1e-9;
    }
};
class Figure {
protected:
    std::vector<Point> vertices;
public:
    virtual ~Figure() = default;
    virtual Point center() const = 0;

    virtual double area() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    virtual bool operator==(const Figure& other) const = 0;
    operator double() const {
        return area();
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Figure& fig) {
        fig.print(os);
        return os;
    }
    
    friend std::istream& operator>>(std::istream& is, Figure& fig) {
        fig.read(is);
        return is;
    }
};
