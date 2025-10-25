#include "rhombus.h"
#include <cmath>

Rhombus::Rhombus(double d1, double d2) : diagonal1(d1), diagonal2(d2) {
    vertices.clear();
    vertices.emplace_back(0, d2/2);       
    vertices.emplace_back(d1/2, 0);       
    vertices.emplace_back(0, -d2/2);  
    vertices.emplace_back(-d1/2, 0);       
}
Point Rhombus::center() const {
    return Point(0, 0); 
}
double Rhombus::area() const {
    return (diagonal1 * diagonal2) / 2.0;
}
void Rhombus::print(std::ostream& os) const {
    os << "Rhombus vertices: ";
    for (size_t i = 0; i < vertices.size(); ++i) {
      
        os << "(" << vertices[i].x << ", " << vertices[i].y << ")";
      
        if (i != vertices.size() - 1) os << " ";
    }
}

void Rhombus::read(std::istream& is) {
    is >> diagonal1 >> diagonal2;

  
    *this = Rhombus(diagonal1, diagonal2);
}

bool Rhombus::operator==(const Figure& other) const {
    const Rhombus* rhs = dynamic_cast<const Rhombus*>(&other);
    if (!rhs) return false;
    return std::abs(diagonal1 - rhs->diagonal1) < 1e-9 && 
           std::abs(diagonal2 - rhs->diagonal2) < 1e-9;
}
Rhombus& Rhombus::operator=(const Rhombus& other) {
    if (this != &other) {
        diagonal1 = other.diagonal1;
        diagonal2 = other.diagonal2;
        vertices = other.vertices;
    }
    return *this;
}
Rhombus& Rhombus::operator=(Rhombus&& other) noexcept {
    if (this != &other) {
        diagonal1 = std::move(other.diagonal1);
      
        diagonal2 = std::move(other.diagonal2);
      
        vertices = std::move(other.vertices);
    }
    return *this;
}
