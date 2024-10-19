#include <iostream>
#include <vector>
#include <memory>
#include "Figure.h"
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"

int main() {
    std::vector<std::unique_ptr<Figure>> figures;

    std::cout << "Enter number of figures: ";
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cout << "Enter figure type (1 - Triangle, 2 - Square, 3 - Rectangle): ";
        int type;
        std::cin >> type;

        std::unique_ptr<Figure> fig;

        if (type == 1) {
            fig = std::make_unique<Triangle>();
        } else if (type == 2) {
            fig = std::make_unique<Square>();
        } else if (type == 3) {
            fig = std::make_unique<Rectangle>();
        } else {
            std::cerr << "Invalid figure type" << std::endl;
            continue;
        }

        std::cin >> *fig;
        figures.push_back(std::move(fig));
    }

    for (const auto& fig : figures) {
        std::cout << *fig << std::endl;
        auto center = fig->center();
        std::cout << "Center: (" << center.first << ", " << center.second << ")" << std::endl;
        std::cout << "Area: " << static_cast<double>(*fig) << std::endl;
    }

    double totalArea = 0.0;
    for (const auto& fig : figures) {
        totalArea += static_cast<double>(*fig);
    }
    std::cout << "Total area: " << totalArea << std::endl;

    std::cout << "Enter index of figure to delete: ";
    int index;
    std::cin >> index;
    if (index >= 0 && static_cast<size_t>(index) < figures.size()) {
        figures.erase(figures.begin() + index);
    } else {
        std::cerr << "Invalid index" << std::endl;
    }

    return 0;
}