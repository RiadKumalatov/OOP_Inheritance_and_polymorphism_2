#include <iostream>
#include <string>

class Shape {
public:
    virtual void print_info() const = 0; 
    virtual ~Shape() {}
};

class Triangle : public Shape {
protected:
    double a, b, c;
    double A, B, C;

public:
    Triangle(double a, double b, double c, double A, double B, double C) : a(a), b(b), c(c), A(A), B(B), C(C) {}

    virtual void print_info() const override {
        std::cout << "Треугольник:\nСтороны: a=" << a << " b=" << b << " c=" << c << "\nУглы: A=" << A << " B=" << B << " C=" << C << "\n";
    }
};

class Quadrangle : public Shape {
protected:
    double a, b, c, d;
    double A, B, C, D;

public:
    Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) :
        a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    virtual void print_info() const override {
        std::cout << "Четырёхугольник:\nСтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d
            << "\nУглы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c, double A, double B) : Triangle(a, b, c, A, B, 90) {}
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double A, double B) : Triangle(a, b, a, A, B, A) {}
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60) {}
};

class Rectangle : public Quadrangle {
public:
    Rectangle(double a, double b) : Quadrangle(a, b, a, b, 90, 90, 90, 90) {}
};

class Square : public Rectangle {
public:
    Square(double a) : Rectangle(a, a) {}
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(double a, double b, double A, double B) : Quadrangle(a, b, a, b, A, B, A, B) {}
};

class Rhombus : public Parallelogram {
public:
    Rhombus(double a, double A, double B) : Parallelogram(a, a, A, B) {}
};
void print_shape_info(const Shape& shape) {
    shape.print_info();
}

int main() {
    setlocale(LC_ALL, "Russian");

    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle right_triangle(10, 20, 30, 50, 60);
    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    EquilateralTriangle equilateral_triangle(30);
    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    print_shape_info(triangle);
    print_shape_info(right_triangle);
    print_shape_info(isosceles_triangle);
    print_shape_info(equilateral_triangle);
    print_shape_info(quadrangle);
    print_shape_info(rectangle);
    print_shape_info(square);
    print_shape_info(parallelogram);
    print_shape_info(rhombus);

    return 0;
}
