#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

// Define a class named "Coordinate" to represent points in a 2D plane.
class Coordinate {

public:
    // Declare public member variables for the x and y coordinates.
    double x;
    double y;
    
    // Constructor for the Coordinate class, initializing the x and y coordinates.
    Coordinate(int x, int y) : x(x), y(y) {}

    // Getter function for the x coordinate. Returns the value of x.
    int getX() const {
        return x;
    }

    // Getter function for the y coordinate. Returns the value of y.
    int getY() const {
        return y;
    }

    // Function to calculate the distance between this point and another given point 'p'.
    double distance(const Coordinate& p) const {
        double deltaX = x - p.getX();
        double deltaY = y - p.getY();
        return sqrt(deltaX * deltaX + deltaY * deltaY);
    }

    // Function to translate this point by given values dx and dy.
    void translate(double dx, double dy) {
        x += dx;
        y += dy;
    }

    // Function to scale this point by a given factor.
    // If 'sign' is true, the point is scaled up; otherwise, it is scaled down.
    void scale(double factor, bool sign) {
        if (sign) {
            x *= factor;
            y *= factor;
        } else {
            x /= factor;
            y /= factor;
        }
    }

    // Function to display the coordinates of this point as a formatted string.
    string display() const {
        return "X = " + to_string(x) + ", Y = " + to_string(y);
    }
};

// Define an abstract class named "Shape" to represent geometric shapes.
class Shape {

public:

    // Declare protected member variable 'position' to store the position of the shape.
    Coordinate position;
    // Declare protected member variable 'sides' to store the number of sides in the shape.
    int sides;
    // Constructor for the Shape class, initializing the number of sides and position of the shape.
    Shape(int noOfSides, const Coordinate& coord) : position(coord), sides(noOfSides) {}

    // Getter function for the position of the shape. Returns the position as a Coordinate object.
    Coordinate getCoordinates() const {
        return position;
    }

    // Getter function for the number of sides in the shape. Returns the value of 'sides'.
    int getSides() const {
        return sides;
    }

    // Setter function for the position of the shape. Updates the position with a new Coordinate object.
    void setCoordinates(const Coordinate& newcoord) {
        position = newcoord;
    }

    // Virtual function to translate the shape by given values dx and dy.
    virtual void translate(int dx, int dy) {
        position.translate(dx, dy);
    }

    // Virtual function to scale the shape by a given factor.
    // If 'sign' is true, the shape is scaled up; otherwise, it is scaled down.
    virtual void scale(int factor, bool sign) {
        position.scale(factor, sign);
    }

    // Pure virtual function to calculate the area of the shape. Must be implemented by derived classes.
    virtual double getArea() const = 0;

    // Pure virtual function to calculate the perimeter of the shape. Must be implemented by derived classes.
    virtual double getPerimeter() const = 0;

    // Pure virtual function to display the shape's information as a formatted string. Must be implemented by derived classes.
    virtual string display() const = 0;
};

// Define a class named "Rectangle" derived from the "Shape" class to represent a rectangle.
class Rectangle : public Shape {

public:
    // Declare public member variables 'width' and 'length' to store the dimensions of the rectangle.
    double width;
    double length;
    
    // Constructor for the Rectangle class, initializing the position, width, and length of the rectangle.
    Rectangle(const Coordinate& coord, double width, double length)
        : Shape(4, coord), width(width), length(length) {}

    // Override the getArea() function to calculate the area of the rectangle.
    double getArea() const override {
        return width * length;
    }

    // Override the getPerimeter() function to calculate the perimeter of the rectangle.
    double getPerimeter() const override {
        return 2 * width + 2 * length;
    }

    // Override the translate() function to translate the position of the rectangle by given values dx and dy.
    virtual void translate(int dx, int dy) {
        position.translate(dx, dy);
    }

    // Override the scale() function to scale the dimensions of the rectangle by a given factor.
    // If 'sign' is true, the dimensions are scaled up; otherwise, they are scaled down.
    void scale(int factor, bool sign) override {
        // position.scale(factor, sign);
        if (sign) {
            width *= factor;
            length *= factor;
        } else {
            width /= factor;
            length /= factor;
        }
    }

    // Override the display() function to display the rectangle's information as a formatted string.
    string display() const override {
        return "Rectangle: Coordinates (" + position.display() + "), Width = " + to_string(width) + ", Length = " + to_string(length) +
               ", Area = " + to_string(getArea()) + ", Perimeter = " + to_string(getPerimeter());
    }
};

// Define a class named "Square" derived from the "Shape" class to represent a square.
class Square : public Shape {

public:
    // Declare a public member variable 'side' to store the length of the square's side.
    double side;
    
    // Constructor for the Square class, initializing the position and side length of the square.
    Square(const Coordinate& coord, double side) : Shape(4, coord), side(side) {}

    // Override the getArea() function to calculate the area of the square.
    double getArea() const override {
        return side * side;
    }

    // Override the getPerimeter() function to calculate the perimeter of the square.
    double getPerimeter() const override {
        return 4 * side;
    }

    // Override the translate() function to translate the position of the square by given values dx and dy.
    void translate(int dx, int dy) override {
        position.translate(dx, dy);
    }

    // Override the display() function to display the square's information as a formatted string.
    string display() const override {
        return "Square: Coordinates (" + position.display() + "), Side = " + to_string(side) +
            ", Area = " + to_string(getArea()) + ", Perimeter = " + to_string(getPerimeter());
    }
};

// Define a class named "Circle" derived from the "Shape" class to represent a circle.
class Circle : public Shape {

public:
    // Declare a public member variable 'radius' to store the circle's radius.
    double radius;
    
    // Constructor for the Circle class, initializing the position and radius of the circle.
    Circle(const Coordinate& coord, double radius) : Shape(0, coord), radius(radius) {}

    // Override the getArea() function to calculate the area of the circle.
    double getArea() const override {
        return 3.1415 * radius * radius;
    }

    // Override the getPerimeter() function to calculate the perimeter of the circle.
    double getPerimeter() const override {
        return 2 * 3.1415 * radius;
    }

    // Override the translate() function to translate the position of the circle by given values dx and dy.
    void translate(int dx, int dy) override {
        position.translate(dx, dy);
    }

    // Override the scale() function to scale the circle's radius by a given factor and sign.
    void scale(int factor, bool sign) override {
        if (sign) {
            radius *= factor;
        } else {
            radius /= factor;
        }
    }

    // Override the display() function to display the circle's information as a formatted string.
    string display() const override {
        return "Circle: Coordinates (" + position.display() + "), Radius = " + to_string(radius) +
               ", Area = " + to_string(getArea()) + ", Perimeter = " + to_string(getPerimeter());
    }

};

// Define a class named "Triangle" derived from the "Shape" class to represent a triangle.
class Triangle : public Shape {

public:
    // Declare public member variables to store the triangle's vertices.
    Coordinate v1, v2, v3;

    // Helper function to calculate the distance (side length) between two given coordinates.
    double sideLength(const Coordinate& a, const Coordinate& b) const {
        return a.distance(b);
    }

    // Constructor for the Triangle class, initializing the vertices and setting the number of sides to 3.
    Triangle(const Coordinate& vertex1, const Coordinate& vertex2, const Coordinate& vertex3)
        : Shape(3, vertex1), v1(vertex1), v2(vertex2), v3(vertex3) {}

    // Override the getArea() function to calculate the area of the triangle.
    double getArea() const override {
        double a = sideLength(v1, v2);
        double b = sideLength(v2, v3);
        double c = sideLength(v3, v1);
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    // Override the getPerimeter() function to calculate the perimeter of the triangle.
    double getPerimeter() const override {
        return sideLength(v1, v2) + sideLength(v2, v3) + sideLength(v3, v1);
    }

    // Override the translate() function to translate the position of each vertex by given values dx and dy.
    void translate(int dx, int dy) override {
        v1.translate(dx, dy);
        v2.translate(dx, dy);
        v3.translate(dx, dy);
    }

    // Override the scale() function to scale the triangle's vertices by a given factor and sign.
    void scale(int factor, bool sign) override {
        if (sign) {
            v1.scale(factor, sign);
            v2.scale(factor, sign);
            v3.scale(factor, sign);
        } else {
            v1.scale(factor, sign);
            v2.scale(factor, sign);
            v3.scale(factor, sign);
        }
    }

    // Override the display() function to display the triangle's information as a formatted string.
    string display() const override {
        return "Triangle: Vertices (" + v1.display() + "), (" + v2.display() + "), (" + v3.display() + ")" +
               ", Area = " + to_string(getArea()) + ", Perimeter = " + to_string(getPerimeter());
    }
};

// Define a class named "ShapeList" to manage a collection of Shape objects.
class ShapeList {

public:
    // Declare a public member variable to store pointers to Shape objects in a vector.    
    vector<Shape*> listOfShapes;

    // Add a shape to the listOfShapes vector and print a confirmation message.
    void addShape(Shape* shape) {
        listOfShapes.push_back(shape);
        cout << "Shape added successfully.\n";
    }
    // Return the number of shapes in the listOfShapes vector.
    int size() const {
        return listOfShapes.size();
    }
    
    // Translate all shapes in the listOfShapes vector by the given values dx and dy.
    void translateShapes(int dx, int dy) {
        for (Shape* shape : listOfShapes) {
            shape->translate(dx, dy);
        }
    }
    
    // Get a pointer to the Shape object at the specified position in the listOfShapes vector, or 0 if out of bounds.
    Shape* getShape(int pos) {
        if (pos >= 0 && pos < listOfShapes.size()) {
            return listOfShapes[pos];
        }
        return 0;
    }

    // Remove the Shape object at the specified position from the listOfShapes vector and return a pointer to it, or 0 if out of bounds.
    Shape* removeShape(int pos) {
        if (pos >= 0 && pos < listOfShapes.size()) {
            Shape* removedShape = listOfShapes[pos];
            listOfShapes.erase(listOfShapes.begin() + pos);
            return removedShape;
        }
        return 0;
    }

    // Return the area of the Shape object at the specified position in the listOfShapes vector, or -1 if out of bounds.
    double area(int pos) {
        if (pos >= 0 && pos < listOfShapes.size()) {
            return listOfShapes[pos]->getArea();
        }
        return -1;
    }

    // Scale all shapes in the listOfShapes vector by the given factor and sign.
    void scale(int factor, bool sign) {
        for (Shape* shape : listOfShapes) {
            shape->scale(factor, sign);
        }
    }

    // Return the perimeter of the Shape object at the specified position in the listOfShapes vector, or -1 if out of bounds.
    double perimeter(int pos) {
        if (pos >= 0 && pos < listOfShapes.size()) {
            return listOfShapes[pos]->getPerimeter();
        }
        return -1;
    }

    // Return a formatted string displaying the information of all shapes in the listOfShapes vector.
    string display() {
        string result = "";
        for (int i = 0; i < listOfShapes.size(); ++i) {
            result += "Shape " + to_string(i + 1) + ": " + listOfShapes[i]->display() + "\n";
        }
        return result;
    }
};

// Define a class named "ShapeManagement" to manage Shape objects using a ShapeList and provide a user interface for performing operations.
class ShapeManagement {

public:
    // Declare a ShapeList member variable to store and manage Shape objects.
    ShapeList shapeList;

    // Display the main menu options for the ShapeManagement system.
    void displayMenu() {
        cout << "\nShape Management Menu:\n";
        cout << "1. Add Shape\n";
        cout << "2. Remove Shape by Position\n";
        cout << "3. Get Information About a Shape by Position\n";
        cout << "4. Display Area and Perimeter Of a Shape by Position\n";
        cout << "5. Display information of all the shapes\n";
        cout << "6. Translate all the shapes\n";
        cout << "7. Scale All Shapes\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
    }

    // Create a Shape object based on user input and add it to the ShapeList.    
    void addShape() {
        int choice;
        cout << "Select Shape to Add:\n";
        cout << "1. Rectangle\n";
        cout << "2. Square\n";
        cout << "3. Circle\n";
        cout << "4. Triangle\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int x, y, width, length, side, radius;
        Coordinate coord1(x, y);
        Coordinate coord2(x, y);
        Coordinate coord3(x, y);

        Shape *shape = 0;

        switch (choice) {
        case 1:
            cout << "Enter the coordinates (x, y), width, and length of the rectangle: ";
            cin >> x >> y >> width >> length;
            shape = new Rectangle(Coordinate(x, y), width, length);
            break;
        case 2:
            cout << "Enter the coordinates (x, y) and side of the square: ";
            cin >> x >> y >> side;
            shape = new Square(Coordinate(x, y), side);
            break;
        case 3:
            cout << "Enter the coordinates (x, y) and radius of the circle: ";
            cin >> x >> y >> radius;
            shape = new Circle(Coordinate(x, y), radius);
            break;
        case 4:
            cout << "Enter the coordinates (x, y) of the three vertices of the triangle: ";
            cin >> x >> y;
            coord1 = Coordinate(x, y);
            cin >> x >> y;
            coord2 = Coordinate(x, y);
            cin >> x >> y;
            coord3 = Coordinate(x, y);
            shape = new Triangle(coord1, coord2, coord3);
            break;
        default:
            cout << "Invalid choice. No shape added.\n";
            return;
        }

        shapeList.addShape(shape);
    }

    // Remove a Shape object from the ShapeList based on user input.
    void removeShape() {
        int pos;
        cout << "Enter the position of the shape to remove: ";
        cin >> pos;

        Shape *removedShape = shapeList.removeShape(pos - 1);
        if (removedShape != 0) {
            cout << "Removed shape: " << removedShape->display() << endl;
            delete removedShape;
        } else {
            cout << "Invalid position.\n";
        }
    }

    // Display information about a Shape object from the ShapeList based on user input.
    void getShapeInfo() {
        int pos;
        cout << "Enter the position of the shape: ";
        cin >> pos;

        Shape *shape = shapeList.getShape(pos - 1);
        if (shape != 0) {
            cout << "Shape " << pos << ": " << shape->display() << endl;
        } else {
            cout << "Invalid position.\n";
        }
    }
    
    // Display the area and perimeter of a Shape object from the ShapeList based on user input.
    void displayAreaAndPerimeter() {
        int pos;
        cout << "Enter the position of the shape: ";
        cin >> pos;

        Shape *shape = shapeList.getShape(pos - 1);
        if (shape != 0) {
            cout << "Shape " << pos << ":" << endl;
            cout << "Area: " << shape->getArea() << endl;
            cout << "Perimeter: " << shape->getPerimeter() << endl;
        } else {
            cout << "Invalid position.\n";
        }
    }

    // Translate all the shapes in the ShapeList based on user input.
    void translateShapes() {
        double dx, dy;
        cout << "Enter the translation values (dx, dy): ";
        cin >> dx >> dy;

        shapeList.translateShapes(dx, dy);
        cout << "Shapes translated successfully.\n";
    }

    // Scale all the shapes in the ShapeList based on user input.
    void scaleShapes() {
        int factor;
        bool sign;
        cout << "Enter the scaling factor and sign (1 for scaling up, 0 for scaling down): ";
        cin >> factor >> sign;

        shapeList.scale(factor, sign);
        cout << "Shapes scaled successfully.\n";
    }

    // Run the ShapeManagement system, displaying the menu and processing user input.
    void run() {
        int choice;
        do {
            displayMenu();
            cin >> choice;

            switch (choice) {
            case 1:
                addShape();
                break;
            case 2:
                removeShape();
                break;
            case 3:
                getShapeInfo();
                break;
            case 4:
                displayAreaAndPerimeter();
                break;
            case 5:
                cout << shapeList.display() << endl;
                break;
            case 6:
                translateShapes();
                break;
            case 7:
                scaleShapes();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        } while (choice != 8);
    }
};

// Define the main function as the entry point of the program.
int main() {
    // Create an instance of the ShapeManagement class.
    ShapeManagement shapeManagement;
    
    // Call the run() method of the ShapeManagement object to start the program's interactive menu and handle user input.
    shapeManagement.run();
    
    // Return 0 to indicate successful execution of the program.
    return 0;
}