#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base class Car
class Car {
private:
    string model;
    float price;
    int year;

public:
    // Constructor 1: Default constructor
    Car() : model(""), price(0.0), year(0) {}

    // Constructor 2: Parameterized constructor
    Car(string m, float p, int y) : model(m), price(p), year(y) {}

    // Function 1: Displays car details
    void displayCar() const {
        cout << "Model: " << model << ", Price: $" << price << ", Year: " << year << endl;
    }

    // Function 2: Returns car price
    float getPrice() const { return price; }

    // Function 3: Returns car model
    string getModel() const { return model; }
};

// Derived class LuxuryCar (Inheritance from Car)
class LuxuryCar : public Car {
private:
    string luxuryFeature;

public:
    // Constructor: Parameterized constructor with luxury feature
    LuxuryCar(string m, float p, int y, string feature)
        : Car(m, p, y), luxuryFeature(feature) {}

    // Function: Displays luxury car details, including inherited attributes
    void displayLuxuryCar() {
        displayCar();
        cout << "Luxury Feature: " << luxuryFeature << endl;
    }
};

// Manager class (Composition with Showroom)
class Manager {
private:
    string name;

public:
    // Constructor: Initializes manager with a name
    Manager(string n) : name(n) {}

    // Function: Displays manager's name
    void displayManager() const {
        cout << "Manager: " << name << endl;
    }
};

// Customer class
class Customer {
private:
    string name;
    string purchasedModel;

public:
    // Constructor 1: Default constructor
    Customer() : name(""), purchasedModel("") {}

    // Constructor 2: Parameterized constructor
    Customer(string n, string model) : name(n), purchasedModel(model) {}

    // Function: Displays customer details
    void displayCustomer() const {
        cout << "Customer Name: " << name << ", Purchased Model: " << purchasedModel << endl;
    }
};

// Showroom class
class Showroom {
private:
    vector<Car> cars;           // Vector to manage cars (Composition)
    vector<Customer> customers; // Vector to manage customers
    float totalSales;           // Total sales amount
    Manager manager;            // Manager object (Composition)

public:
    // Constructor: Initializes showroom with a manager
    Showroom(string managerName) : totalSales(0.0), manager(managerName) {}

    // Function 1: Adds a car to the showroom
    void addCar(const Car& car) {
        cars.push_back(car);
        cout << "Car added: " << car.getModel() << endl;
    }

    // Function 2: Displays available cars
    void viewCars() const {
        if (cars.empty()) {
            cout << "No cars available!" << endl;
            return;
        }
        cout << "Available Cars: " << endl;
        for (const auto& car : cars) {
            car.displayCar();
        }
    }

    // Function 3: Sells a car and adds a customer
    void sellCar(const string& model, const string& customerName) {
        for (size_t i = 0; i < cars.size(); ++i) {
            if (cars[i].getModel() == model) {
                totalSales += cars[i].getPrice();
                customers.push_back(Customer(customerName, model));
                cout << "Car sold: " << model << " for $" << cars[i].getPrice() << endl;

                // Remove the sold car
                cars.erase(cars.begin() + i);
                return;
            }
        }
        cout << "Car not found!" << endl;
    }

    // Function 4: Displays total sales
    void viewTotalSales() const {
        cout << "Total Sales: $" << totalSales << endl;
    }

    // Function 5: Displays all customers
    void viewCustomers() const {
        if (customers.empty()) {
            cout << "No customers found!" << endl;
            return;
        }
        cout << "Customers: " << endl;
        for (const auto& customer : customers) {
            customer.displayCustomer();
        }
    }

    // Function 6: Displays showroom information (Friend function)
    void showroomInfo() const {
        cout << "Showroom Information: " << endl;
        manager.displayManager();
        cout << "Total Sales: $" << totalSales << endl;
    }
};

// Main function (Menu-driven program)
int main() {
    Showroom showroom("junaid"); // Initialize showroom with manager "Alice"
    int choice;

    do {
        // Display menu options
        cout << "\nCar Showroom Management System" << endl;
        cout << "1. Add Car" << endl;
        cout << "2. View Cars" << endl;
        cout << "3. Sell Car" << endl;
        cout << "4. View Total Sales" << endl;
        cout << "5. View Customers" << endl;
        cout << "6. Showroom Info" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the buffer for string inputs

        switch (choice) {
            case 1: {
                string model;
                float price;
                int year;
                cout << "Enter car model: ";
                cin.ignore(); // Clear buffer
                getline(cin, model);
                cout << "Enter car price: ";
                cin >> price;
                cout << "Enter car year: ";
                cin >> year;
                cin.ignore(); // Clear buffer
                showroom.addCar(Car(model, price, year)); // Add new car
                break;
            }
            case 2:
                showroom.viewCars(); // View available cars
                break;
            case 3: {
                string model, customerName;
                cout << "Enter car model to sell: ";
                cin.ignore();
                getline(cin, model);
                cout << "Enter customer name: ";
                getline(cin, customerName);
                showroom.sellCar(model, customerName); // Sell a car
                break;
            }
            case 4:
                showroom.viewTotalSales(); // View total sales
                break;
            case 5:
                showroom.viewCustomers(); // View customers
                break;
            case 6:
                showroom.showroomInfo(); // Display showroom info
                break;
            case 7:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);
}
