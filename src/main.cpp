#include <iostream>
#include <string>
#include "../include/Figure.h"
#include "../include/Rhombus.h"
#include "../include/Pentagon.h"
#include "../include/Hexagon.h"
#include "../include/Array.h"

int main() {
    Array arr;
    std::string type;
    while (std::cin >> type) {
        Figure* f = nullptr;
        if (type == "rhombus") {
            f = new Rhombus();
        } else if (type == "pentagon") {
            f = new Pentagon();
        } else if (type == "hexagon") {
            f = new Hexagon();
        } else {
            std::cerr << "Unknown type: " << type << std::endl;
            continue;
        }
        std::cin >> *f;
        if (std::cin.fail()) {
            delete f;
            break;
        }
        arr.add(f);
    }
    std::cin.clear();
    for (size_t i = 0; i < arr.size(); ++i) {
        const Figure* f = arr[i];
        std::cout << "Figure " << i << " vertices: " << *f << std::endl;
        std::cout << "Center: " << f->geometricCenter() << std::endl;
        std::cout << "Area: " << static_cast<double>(*f) << std::endl;
    }
    double total = 0.0;
    for (size_t i = 0; i < arr.size(); ++i) {
        total += static_cast<double>(*arr[i]);
    }
    std::cout << "Total area: " << total << std::endl;
    size_t index;
    if (std::cin >> index) {
        arr.remove(index);
        std::cout << "After deletion:" << std::endl;
        for (size_t i = 0; i < arr.size(); ++i) {
            const Figure* f = arr[i];
            std::cout << "Figure " << i << " vertices: " << *f << std::endl;
            std::cout << "Center: " << f->geometricCenter() << std::endl;
            std::cout << "Area: " << static_cast<double>(*f) << std::endl;
        }
        total = 0.0;
        for (size_t i = 0; i < arr.size(); ++i) {
            total += static_cast<double>(*arr[i]);
        }
        std::cout << "New total area: " << total << std::endl;
    }
    return 0;
}
