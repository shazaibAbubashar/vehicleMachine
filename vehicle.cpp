#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include "vehicle.h"
using namespace std;
int main()
{
    Inventory inventory;
    Vehicle *ptr;
    int choice = 0;
    while (1)
    {
        cout << "\n-----------------Welcome In the Parking Software--------------" << endl;
        cout << "\t1. Add Car\n";
        cout << "\t2. Add Truck\n";
        cout << "\t3. Add Motorcycle\n";
        cout << "\t4. Remove vehicle\n";
        cout << "\t5. Display vehicles\n";
        cout << "\t6. Search Vehicle by make\n";
        cout << "\t7. Search Vehicle by model\n";
        cout << "\t8. Search Vehicle by year\n";
        cout << "\t9. Search Vehicle by price\n";
        cout << "\t10. Sort by make\n";
        cout << "\t11. Sort by model\n";
        cout << "\t12. Sort by Year\n";
        cout << "\t13. Sort by Price\n";
        cout << "\t-1. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        if (choice == 1)
        {
            string make, model;
            int year;
            double price;
            int nd;
            cout << "\n-------------------------Inputing Details of Car-------------------" << endl;
            cout << "\tEnter the make of the Car : ";
            fflush(stdin);
            getline(cin, make);
            cout << "\tEnter the model of the Car : ";
            fflush(stdin);
            getline(cin, model);
            cout << "\tEnter the year of the Car : ";
            cin >> year;
            cout << "\tEnter the price of the Car : ";
            cin >> price;
            cout << "\tEnter no of doors : ";
            cin >> nd;
            inventory.addVehicle(new Car(make, model, year, price, nd));
        }
        else if (choice == 2)
        {
            string make, model;
            int year;
            double price;
            string bs;
            cout << "\n--------------------Inputing Details of the Truck-----------------------" << endl;
            cout << "\tEnter the make of the Truck : ";
            fflush(stdin);
            getline(cin, make);
            cout << "\tEnter the model of the Truck : ";
            fflush(stdin);
            getline(cin, model);
            cout << "\tEnter the year of the Truck : ";
            cin >> year;
            cout << "\tEnter the price of the Truck : ";
            cin >> price;
            cout << "\tEnter bed sizes of the Truck : ";
            fflush(stdin);
            getline(cin, bs);
            inventory.addVehicle(new Truck(make, model, year, price, bs));
        }
        else if (choice == 3)
        {
            string make, model;
            int year;
            double price;
            double enginesize;
            cout << "\n----------------Inputing Details MotorCycle------------------" << endl;
            cout << "\tEnter the make of the MotorCycle : ";
            fflush(stdin);
            getline(cin, make);
            cout << "\tEnter the model of the MotorCycle : ";
            fflush(stdin);
            getline(cin, model);
            cout << "\tEnter the year of the MotorCycle : ";
            cin >> year;
            cout << "\tEnter the price of the MotorCycle : ";
            cin >> price;
            cout << "\tEnter engine size of the MotorCycle : ";
            cin >> enginesize;
            inventory.addVehicle(new Motorcycle(make, model, year, price, enginesize));
        }
        else if (choice == 4)
        {
            int num;
            cout << "Enter the number of the vehicle : ";
            cin >> num;
            inventory.removeVehicle(num);
        }
        else if (choice == 5)
        {
            inventory.displayInventory();
        }
        else if (choice == 6)
        {
            string make;
            cout << "Enter the make of the vehicle : ";
            fflush(stdin);
            getline(cin, make);
            inventory.searchByMake(make);
        }
        else if (choice == 7)
        {
            string model;
            cout << "Enter the model to search : ";
            fflush(stdin);
            getline(cin, model);
            inventory.searchByModel(model);
        }
        else if (choice == 8)
        {
            int year;
            cout << "Enter the year to search : ";
            cin >> year;
            inventory.searchByYear(year);
        }
        else if (choice == 9)
        {
            double price;
            cout << "Enter the price to search : ";
            fflush(stdin);
            cin >> price;
            inventory.searchByPrice(price);
        }
        else if (choice == 10)
        {
            inventory.sortByMake();
        }
        else if (choice == 11)
        {
            inventory.sortByModel();
        }
        else if (choice == 12)
        {
            inventory.sortByYear();
        }
        else if (choice == 13)
        {
            inventory.sortByPrice();
        }
        else if (choice == -1)
        {
            cout << "*********************************************" << endl;
            cout << "**ThankYou Guys For using my Parking software**\n";
            cout << "**********************************************" << endl;
            break;
        }
    }
    return 0;
}