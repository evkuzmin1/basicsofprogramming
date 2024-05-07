#include <iostream>
#include <cmath> 

#define _USE_MATH_DEFINES
#include <cmath>
const double PI = 3.14159265358979323846;

class Point {
public:
    virtual void draw() const = 0;
    virtual void erase() const = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void rotate(double angle, double cx, double cy) = 0;
    virtual ~Point() {}
};


class Line : public Point {
private:
    double x1, y1, x2, y2;
public:
    Line(double x1, double y1, double x2, double y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
    void draw() const override {
        std::cout << "Drawing Line from (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")\n";
    }
    void erase() const override {
        std::cout << "Erasing Line from (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")\n";
    }
    void move(double dx, double dy) override {
        x1 += dx; y1 += dy;
        x2 += dx; y2 += dy;
    }
    void rotate(double angle, double cx, double cy) override {
        double radians = angle * PI / 180;
        double nx1 = cos(radians) * (x1 - cx) - sin(radians) * (y1 - cy) + cx;
        double ny1 = sin(radians) * (x1 - cx) + cos(radians) * (y1 - cy) + cy;
        double nx2 = cos(radians) * (x2 - cx) - sin(radians) * (y2 - cy) + cx;
        double ny2 = sin(radians) * (x2 - cx) + cos(radians) * (y2 - cy) + cy;
        x1 = nx1;
        y1 = ny1;
        x2 = nx2;
        y2 = ny2;
    }
};


class Rectangle : public Point {
protected:
    double x, y, width, height;
public:
    Rectangle(double x, double y, double width, double height) : x(x), y(y), width(width), height(height) {}
    void draw() const override {
        std::cout << "Drawing Rectangle at (" << x << ", " << y << ") with width " << width << " and height " << height << "\n";
    }
    void erase() const override {
        std::cout << "Erasing Rectangle at (" << x << ", " << y << ") with width " << width << " and height " << height << "\n";
    }
    void move(double dx, double dy) override {
        x += dx;
        y += dy;
    }
    void rotate(double angle, double cx, double cy) override {
        double radians = angle * PI / 180;
        double nx = cos(radians) * (x - cx) - sin(radians) * (y - cy) + cx;
        double ny = sin(radians) * (x - cx) + cos(radians) * (y - cy) + cy;
        x = nx;
        y = ny;
        std::cout << "Rotating Rectangle's new center at (" << x << ", " << y << ") \n";
    }
};


class Parallelogram : public Rectangle {
public:
    Parallelogram(double x, double y, double width, double height) : Rectangle(x, y, width, height) {}
    void draw() const override {
        std::cout << "Drawing Parallelogram at (" << x << ", " << y << ") with width " << width << " and height " << height << "\n";
    }
    void erase() const override {
        std::cout << "Erasing Parallelogram at (" << x << ", " << y << ") with width " << width << " and height " << height << "\n";
    }
    void move(double dx, double dy) override {
        x += dx;
        y += dy;
    }
    void rotate(double angle, double cx, double cy) override {
        Rectangle::rotate(angle, cx, cy);
        std::cout << "Rotating Parallelogram's new center at (" << x << ", " << y << ") \n";
    }
};


class Rhombus : public Parallelogram {
public:
    Rhombus(double x, double y, double d1, double d2) : Parallelogram(x, y, d1, d2) {}
    void draw() const override {
        std::cout << "Drawing Rhombus at (" << x << ", " << y << ") with diagonal 1 " << width << " and diagonal 2 " << height << "\n";
    }
    void erase() const override {
        std::cout << "Erasing Rhombus at (" << x << ", " << y << ") with diagonal 1 " << width << " and diagonal 2 " << height << "\n";
    }
    void move(double dx, double dy) override {
        Parallelogram::move(dx, dy);
    }
    void rotate(double angle, double cx, double cy) override {
        Parallelogram::rotate(angle, cx, cy);
        std::cout << "Rotating Rhombus'es new center at (" << x << ", " << y << ") \n";
    }
};


class Square : virtual public Parallelogram {
public:
    Square(double x, double y, double side) : Parallelogram(x, y, side, side) {}
    void draw() const override {
        std::cout << "Drawing Square at (" << x << ", " << y << ") with side " << width << "\n";
    }
    void erase() const override {
        std::cout << "Erasing Square at (" << x << ", " << y << ") with side " << width << "\n";
    }
    void move(double dx, double dy) override {
        Parallelogram::move(dx, dy);
    }
    void rotate(double angle, double cx, double cy) override {
        Parallelogram::rotate(angle, cx, cy);
        std::cout << "Rotating Square's new center at (" << x << ", " << y << ") \n";
    }
};

int main() {
    Line line(0, 0, 10, 10);
    Rectangle rect(10, 10, 20, 10);
    Square square(20, 20, 30);

    line.draw();
    rect.draw();
    square.draw();

    line.erase();
    rect.erase();
    square.erase();

    line.move(1, 1);
    rect.move(1, 1);
    square.move(1, 1);

    line.rotate(45, 5, 5);
    rect.rotate(45, 15, 15);
    square.rotate(45, 35, 35);

    return 0;
}