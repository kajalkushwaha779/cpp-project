#include <iostream>
using namespace std;

class Vehicle {
private:
    int vehicleID, year;
    string manufacturer, model;
public:
//static variable
    static int totalvehicles;
//default constructer
    Vehicle(){
	}
//parameterized constructer
    Vehicle(int id, int year, string manufacturer, string model) {
        this->vehicleID = id;
        this->year = year;
        this->manufacturer = manufacturer;
        this->model = model;
        totalvehicles++;
    }
//setter function
    void inputVehicleDetails() {
        cout << "\nEnter Vehicle ID : ";
        cin >> vehicleID;
        cout << "Enter Vehicle Year : ";
        cin >> year;
        cout << "Enter Vehicle Manufacturer : ";
        cin >> manufacturer;
        cout << "Enter Vehicle Model : ";
        cin >> model;
        totalvehicles++;
    }
//getter function
    void displayVehicleDetails() {
        cout << "\nVehicle ID : " << vehicleID << endl;
        cout << "Vehicle Year : " << year << endl;
        cout << "Vehicle Manufacturer : " << manufacturer << endl;
        cout << "Vehicle Model : " << model << endl;
    }

    int getID() {
        return vehicleID;
    }
 // Static Function
    static int gettotalvehicles() {
        return totalvehicles;
    }
 //destructor
    ~Vehicle() {
        totalvehicles--;
    }
};
int Vehicle::totalvehicles = 0;
// Single Inheritance
class Car : public Vehicle {
private:
    string fueltype;
public:
    void inputVehicleDetails() {
        Vehicle::inputVehicleDetails();
        cout << "Enter Fuel Type : ";
        cin >> fueltype;
    }
    void displayVehicleDetails() {
        Vehicle::displayVehicleDetails();
        cout << "Fuel Type : " << fueltype << endl;
    }
};
// Multilevel Inheritance
class ElectricCar : public Car {
private:
    int batteryCapacity;
public:
    void inputVehicleDetails() {
        Car::inputVehicleDetails();
        cout << "Enter Battery Capacity : ";
        cin >> batteryCapacity;
    }
    void displayVehicleDetails() {
        Car::displayVehicleDetails();
        cout << "Battery Capacity : " << batteryCapacity << " kWh" << endl;
    }
};
class SportsCar : public ElectricCar {
private:
    int topSpeed;
public:
    void inputVehicleDetails() {
        ElectricCar::inputVehicleDetails();
        cout << "Enter Top Speed : ";
        cin >> topSpeed;
    }
    void displayVehicleDetails() {
        ElectricCar::displayVehicleDetails();
        cout << "Top Speed : " << topSpeed << " km/h" << endl;
    }
};
// Multiple Inheritance
class Aircraft {
private:
    int flightRange;
public:
    void inputAircraftDetails() {
        cout << "Enter Flight Range : ";
        cin >> flightRange;
    }
    void displayAircraftDetails() {
        cout << "Flight Range : " << flightRange << " km" << endl;
    }
};
class FlyingCar : public Car, public Aircraft {
private:
    int maxAltitude;
public:
    void inputFlyingCarDetails() {
        inputVehicleDetails();
        inputAircraftDetails();
        cout << "Enter Max Altitude : ";
        cin >> maxAltitude;
    }
    void displayFlyingCarDetails() {
        displayVehicleDetails();
        displayAircraftDetails();
        cout << "Max Altitude : " << maxAltitude << " ft" << endl;
    }
};
// Hierarchical Inheritance
class SUV : public Car {
private:
    string driveType;
public:
    void inputVehicleDetails() {
        Car::inputVehicleDetails();
        cout << "Enter Drive Type (4WD/AWD/FWD) : ";
        cin >> driveType;
    }
    void displayVehicleDetails() {
        Car::displayVehicleDetails();
        cout << "Drive Type : " << driveType << endl;
    }
};
class Sedan : public Car {
private:
    int seatingCapacity;
public:
    void inputVehicleDetails() {
        Car::inputVehicleDetails();
        cout << "Enter Seating Capacity : ";
        cin >> seatingCapacity;
    }
    void displayVehicleDetails() {
        Car::displayVehicleDetails();
        cout << "Seating Capacity : " << seatingCapacity << endl;
    }
};
class VehicleRegistry {
private:
    Vehicle* vehiclearr[100];
    int count = 0;
public:
    void addVehicle() {
        int type;
        cout << "\n1. Sedan";
        cout << "\n2. SUV";
        cout << "\n3. SportsCar";
        cout << "\n4. ElectricCar";
        cout << "\nChoose Vehicle Type: ";
        cin >> type;
        if (type == 1)
            vehiclearr[count] = new Sedan();
        else if (type == 2)
            vehiclearr[count] = new SUV();
        else if (type == 3)
            vehiclearr[count] = new SportsCar();
        else if (type == 4)
            vehiclearr[count] = new ElectricCar();
        else {
            cout << "Invalid choice!" << endl;
            return;
        }
        vehiclearr[count]->inputVehicleDetails();
        count++;
    }
    void displayvehicle() {
        for (int i = 0; i < count; i++) {
            vehiclearr[i]->displayVehicleDetails();
            cout << "---------------------------------" << endl;
        }
    }
    void searchVehicle() {
        int searchID;
        cout << "\nEnter Vehicle ID for Search : ";
        cin >> searchID;
        for (int i = 0; i < count; i++) {
            if (vehiclearr[i]->getID() == searchID) {
                vehiclearr[i]->displayVehicleDetails();
                return;
            }
        }
        cout << "Vehicle not found!" << endl;
    }
    ~VehicleRegistry() {
        for (int i = 0; i < count; i++) {
            delete vehiclearr[i];
        }
    }
    void menu() {
        int choice;
        do {
            cout << "\n========== VEHICLE REGISTRY ==========";
            cout << "\n1. Add Vehicle";
            cout << "\n2. Display All Vehicles";
            cout << "\n3. Search Vehicle By ID";
            cout << "\n4. Total Vehicles";
            cout << "\n5. Exit";
            cout << "\nEnter Choice : ";
            cin >> choice;
            switch (choice) {
            case 1:
                addVehicle();
                break;
            case 2:
                if (count == 0)
                    cout << "\nNo Vehicles Found!" << endl;
                else
                    displayvehicle();
                break;
            case 3:
                searchVehicle();
                break;
            case 4:
                cout << "\nTotal Vehicles Added : "<< Vehicle::gettotalvehicles() << endl;
                break;
            case 5:
                cout << "\nThank You!" << endl;
                break;
            default:
                cout << "\nInvalid Choice!" << endl;
            }
        } while (choice != 5);
    }
};
int main(){
    VehicleRegistry manage;
    manage.menu();
    return 0;
}