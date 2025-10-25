#include <iostream>
#include <vector>

#include <memory>
#include "rhombus.h"
#include "pentagon.h"
#include "hexagon.h"

class FigureArray {
private:
    std::vector<std::shared_ptr<Figure>> figures;
public:
    void addFigure(std::shared_ptr<Figure> fig) {
        figures.push_back(fig);
    }
    void removeFigure(int index) {
        if (index >= 0 && static_cast<size_t>(index) < figures.size()) {
            figures.erase(figures.begin() + index);
        }
    }
    void printAll() const {
        for (size_t i = 0; i < figures.size(); ++i) {
            std::cout << "Figure " << i << ": " << *figures[i] << std::endl;
            Point center = figures[i]->center();
            std::cout << "Center: (" << center.x << ", " << center.y << ")" << std::endl;
            std::cout << "Area: " << figures[i]->area() << std::endl;
            std::cout << "---" << std::endl;
        }
    }
    
    double totalArea() const {
        double total = 0;
        for (const auto& fig : figures) {
            total += fig->area();
        }
        return total;
    }
    
    size_t size() const {
        return figures.size();
    }
};

void printMenu() {
    std::cout << "\nFigure Management System" << std::endl;
  
    std::cout << "1. Add Rhombus" << std::endl;
    std::cout << "2. Add Pentagon" << std::endl;
    std::cout << "3. Add Hexagon" << std::endl;
    std::cout << "4. Remove Figure" << std::endl;
    std::cout << "5. Print All Figures" << std::endl;
    std::cout << "6. Calculate Total Area" << std::endl;
    std::cout << "7. Exit" << std::endl;

  
    std::cout << "Choose an option: ";
}

int main() {
    FigureArray figureArray;
    int choice;
    do {
        printMenu();
        std::cin >> choice;
        switch (choice) {
            case 1: {
                double d1, d2;
                std::cout << "Enter diagonals of rhombus (d1 d2): ";
                std::cin >> d1 >> d2;
                figureArray.addFigure(std::make_shared<Rhombus>(d1, d2));
                std::cout << "Rhombus added successfully!" << std::endl;
                break;
            }
            case 2: {
                double side;
                std::cout << "Enter side length of pentagon: ";
                std::cin >> side;
                figureArray.addFigure(std::make_shared<Pentagon>(side));
                std::cout << "Pentagon added successfully!" << std::endl;
                break;
            }
            case 3: {
                double side;
                std::cout << "Enter side length of hexagon: ";
                std::cin >> side;
                figureArray.addFigure(std::make_shared<Hexagon>(side));
                std::cout << "Hexagon added successfully!" << std::endl;
                break;
            }
            case 4: {
                int index;
                std::cout << "Enter index of figure to remove: ";
                std::cin >> index;
                figureArray.removeFigure(index);
                std::cout << "Figure removed successfully!" << std::endl;
                break;
            }
            case 5: {
                std::cout << "\n=== All Figures ===" << std::endl;
                figureArray.printAll();
                break;
            }
            case 6: {
                double total = figureArray.totalArea();
                std::cout << "Total area of all figures: " << total << std::endl;
                break;
            }
            case 7: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid option! Please try again." << std::endl;
                break;
            }
        }
    } while (choice != 7);
    
    return 0;
}
