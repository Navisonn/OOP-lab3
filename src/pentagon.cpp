#include "pentagon.h"
#include <cmath>
#define M_PI 3.14159265

Pentagon::Pentagon(double s) : side(s) {
    vertices.clear();
    for (int i = 0; i < 5; ++i) {
        double angle = 2.0 * M_PI * i / 5.0 - M_PI/2.0; 
        double radius = side / (2.0 * sin(M_PI / 5.0));
        vertices.emplace_back(radius * cos(angle), radius * sin(angle));
    }
}
Point Pentagon::center() const {
    return Point(0, 0);
}
double Pentagon::area() const {
    return (5.0 * side * side) / (4.0 * tan(M_PI / 5.0));
}


void Pentagon::print(std::ostream& os) const {
    os << "Pentagon vertices: ";
    for (size_t i = 0; i < vertices.size(); ++i) {
        os << "(" << vertices[i].x << ", " << vertices[i].y << ")";
        if (i != vertices.size() - 1) os << " ";
    }
}

void Pentagon::read(std::istream& is) {
    is >> side;
    *this = Pentagon(side);
}

bool Pentagon::operator==(const Figure& other) const {
    const Pentagon* rhs = dynamic_cast<const Pentagon*>(&other);
    if (!rhs) return false;
    return std::abs(side - rhs->side) < 1e-9;
}

Pentagon& Pentagon::operator=(const Pentagon& other) {
    if (this != &other) {
        side = other.side;
        vertices = other.vertices;
    }
    return *this;
}

Pentagon& Pentagon::operator=(Pentagon&& other) noexcept {
    if (this != &other) {
        side = std::move(other.side);
        vertices = std::move(other.vertices);
    }
    return *this;
}
