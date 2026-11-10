define a class shape whose attributes are radius length and width calculate the perimeter of the rectangle and circle use constructor and destructor in c++ code

#include
#include
using namespace std;

class Shape {
private:
double radius, length, width;

public:
// Constructor for circle
Shape(double r):radius(r),length(0),width(0) {

    cout << "circle created with radius:" << radius <<endl;
}

// Calculate perimeter of circle
float circlePerimeter() {
    return 2 * 3.14 * radius;
}

// Constructor for rectangle
Shape (double l,double w): length (l),width(w),radius(0) {
    cout<<"rectangle created with length:"
        <<length<<"and width:"<<width<<endl;
    
}

// Destructor
~Shape() {
    cout << "shape object destroyed" << endl;
}
//calculate circle perimeter
double calculatecircleperimeter() const{
if(radius>0){
return 2acos(-1) radius;
}else{
cout<< "invalid radius for circle"<<endl;
return 0;
}
}
//calculate rectangle perimeter
double calculaterectangleperimeter()const{
if(length >0&& width>0) {
return 2*(length+width);
}else{
cout<<"invalid length or width for rectangle"<<endl;
return 0;
}
}
};

int main() {
Shape circle (5);

cout << "Perimeter of circle = "
     << circle.calculatecircleperimeter() << endl;
Shape rectangle(4,6);
cout << "Perimeter of rectangle = "
<< rectangle.calculaterectangleperimeter() << endl;

return 0;
}

OUTPUT

circle created with radius:5
Perimeter of circle = 31.4159
rectangle created with length:4and width:6
Perimeter of rectangle = 20
shape object destroyed
shape object destroyed