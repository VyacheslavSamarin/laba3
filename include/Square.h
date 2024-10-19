#ifndef SQUARE_H
#define SQUARE_H

#include "Figure.h"

class Square : public Figure {
private:
    double x, y, side;

public:
    Square();
    Square(double x, double y, double side);

    std::pair<double, double> center() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    double area() const override;

    Square* clone() const override;
    Square* move() override;

    bool operator==(const Figure& other) const override;
};

#endif