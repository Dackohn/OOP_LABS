#include <iostream>
#include <string>
using namespace std;

class Display {
private:
    int width;
    int height;
    float ppi;
    string model;

public:

    Display(int w, int h, float p, string m) : width(w), height(h), ppi(p), model(m) {}

    void compareSize(Display other) {
        int area1 = width * height;
        int area2 = other.width * other.height;
        cout << "Comparing size between " << model << " and " << other.model << ":\n";
        if (area1 > area2)
            cout << model << " is larger than " << other.model << ".\n";
        else if (area1 < area2)
            cout << other.model << " is larger than " << model << ".\n";
        else
            cout << model << " and " << other.model << " are of the same size.\n";
    }

    void compareSharpness(Display other) {
        cout << "Comparing sharpness between " << model << " and " << other.model << ":\n";
        if (ppi > other.ppi)
            cout << model << " is sharper than " << other.model << ".\n";
        else if (ppi < other.ppi)
            cout << other.model << " is sharper than " << model << ".\n";
        else
            cout << model << " and " << other.model << " have the same sharpness.\n";
    }

    void compareWithMonitor(Display other) {
        cout << "Comparing both size and sharpness between " << model << " and " << other.model << ":\n";
        compareSize(other);
        compareSharpness(other);
    }
};

int main() {
    Display display1(1920, 1080, 401.5, "Monitor A");
    Display display2(2560, 1440, 326.0, "Monitor B");
    Display display3(3840, 2160, 530.0, "Monitor C");

    display1.compareWithMonitor(display2);
    cout << endl;
    display2.compareWithMonitor(display3);
    cout << endl;
    display1.compareWithMonitor(display3);

    return 0;
}
