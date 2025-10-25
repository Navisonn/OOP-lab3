#pragma once
#include "figure.h"

class Rhombus : public Figure {
private:
    double diagonal1, diagonal2; 
public:
    Rhombus() = default;


    Rhombus(double d1, double d2);

    Rhombus(const Rhombus& other) = default;
    Point center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    bool operator==(const Figure& other) const override;
    Rhombus& operator=(const Rhombus& other);
    Rhombus& operator=(Rhombus&& other) noexcept;
};
