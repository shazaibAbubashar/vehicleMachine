#include<bits/stdc++.h>
using namespace std;
class Vehicle
{
public:
    string make;
    string model;
    int year;
    double price;

public:
    Vehicle(){};
    Vehicle(string _make, string _model, int _year, double _price)
        : make(_make), model(_model), year(_year), price(_price) {}

    virtual void displayInfo()
    {
        cout << "----------------------Vehicle Detials-----------------" << endl;
        cout << "\tMake : " << make << endl;
        cout << "\tModel : " << model << endl;
        cout << "\tYear : " << year << endl;
        cout << "\tPrice : " << price << " $" << endl;
    }
};
class Truck : public Vehicle
{
private:
    string bedSize;

public:
    Truck(string _make, string _model, int _year, double _price, string _bedSize)
        : Vehicle(_make, _model, _year, _price), bedSize(_bedSize) {}
    void displayInfo() override
    {
        cout << "Truck - ";
        Vehicle::displayInfo();
        cout << "\tBed Size: " << bedSize << endl;
        cout << "-------------------------------------------------------" << endl;
    }
};
class Motorcycle : public Vehicle
{
private:
    double engineSize;

public:
    Motorcycle(string _make, string _model, int _year, double _price, double _engineSize)
        : Vehicle(_make, _model, _year, _price), engineSize(_engineSize) {}
    void displayInfo() override
    {
        cout << "Motorcycle - ";
        Vehicle::displayInfo();
        cout << "\tEngine Size: " << engineSize << "cc" << endl;
        cout << "-------------------------------------------------------" << endl;
    }
};
class Car : public Vehicle
{
private:
    int numDoors;

public:
    Car(){};
    Car(string _make, string _model, int _year, double _price, int _numDoors)
        : Vehicle(_make, _model, _year, _price), numDoors(_numDoors) {}
    void displayInfo() override
    {
        cout << "Car - ";
        Vehicle::displayInfo();
        cout << "\tNumber of Doors: " << numDoors << endl;
        cout << "-------------------------------------------------------" << endl;
    }
};
class Inventory
{
private:
    vector<Vehicle *> vehicles;

public:
    Inventory(){};
    void addVehicle(Vehicle *vehicle)
    {
        vehicles.push_back(vehicle);
    }
    void removeVehicle(int index)
    {
        if (index < vehicles.size())
        {
            vehicles.erase(vehicles.begin() + index);
            cout << "---------------------------------" << endl;
            cout << "Succesfully Removed a vehicle\n";
            cout << "---------------------------------" << endl;
        }
    }
    void displayInventory()
    {
        if (vehicles.empty())
        {
            cout << "-------------------------" << endl;
            cout << "Vehicle is empty\n";
            cout << "-------------------------" << endl;
        }
        for (Vehicle *vehicle : vehicles)
        {
            vehicle->displayInfo();
        }
    }
    void searchByMake(string make)
    {
        cout << "Search Results for Make: " << make << endl;
        for (Vehicle *vehicle : vehicles)
        {
            if (vehicle->make == make)
            {
                vehicle->displayInfo();
            }
        }
    }
    void searchByModel(string model)
    {
        cout << "Search Results for Model: " << model << endl;
        for (Vehicle *vehicle : vehicles)
        {
            if (vehicle->model == model)
            {
                vehicle->displayInfo();
            }
        }
    }
    void searchByYear(int year)
    {
        cout << "Search Results for Year: " << year << endl;
        for (Vehicle *vehicle : vehicles)
        {
            if (vehicle->year == year)
            {
                vehicle->displayInfo();
            }
        }
    }
    void searchByPrice(double price)
    {
        cout << "Search Results for Price: $" << price << endl;
        for (Vehicle *vehicle : vehicles)
        {
            if (vehicle->price == price)
            {
                vehicle->displayInfo();
            }
        }
    }
    void sortByMake()
    {
        sort(vehicles.begin(), vehicles.end(), [](Vehicle *a, Vehicle *b)
             { return a->make < b->make; });
    }
    void sortByModel()
    {
        sort(vehicles.begin(),
             vehicles.end(), [](Vehicle *a, Vehicle *b)
             { return a->model < b->model; });
    }
    void sortByYear()
    {
        sort(vehicles.begin(),
             vehicles.end(), [](Vehicle *a, Vehicle *b)
             { return a->year < b->year; });
    }
    void sortByPrice()
    {
        sort(vehicles.begin(),
             vehicles.end(), [](Vehicle *a, Vehicle *b)
             { return a->price < b->price; });
    }
};
