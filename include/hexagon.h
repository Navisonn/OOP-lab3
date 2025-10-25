#pragma once
#include "figure.h"

class Hexagon : public Figure {
private:
    double side; 
public:
    Hexagon() = default;


    Hexagon(double s);

    Hexagon(const Hexagon& other) = default; 

    Point center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    bool operator==(const Figure& other) const override;
    Hexagon& operator=(const Hexagon& other);
    Hexagon& operator=(Hexagon&& other) noexcept;
};
