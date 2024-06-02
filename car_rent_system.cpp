// Online C++ compiler to run C++ program online
#include <iostream>
//#include <conio.h>
#include <cstdlib>
using namespace std;

struct Cars {
    string company[9] = {"Maruti Suzuki", "Volkswagen", "BMW", "Audi", "KIA", "Tesla", "Mercedes", "Mahindra", "TATA"};
    string model[9] = {"800", "2020", "Q7", "R8", "Saltos", "S-Series", "Benz", "Thar", "Nano"};
    string color[9] = {"Yellow", "Black", "Red", "Brown", "Blue", "Silver", "Black", "Grey", "Red"};
    string max_speed[9] = {"80 Km/h", "200 Km/h", "300 Km/h", "250 Km/h", "320 Km/h", "400 Km/h", "200 Km/h", "250 Km/h", "280 Km/h"};
    int price[9] = {10000, 20000, 50000, 40000, 50000, 50000, 20000, 20000, 20000};
    int date[9] = {2020, 2012, 2019, 2018, 2017, 2016, 2015, 2021, 2010};
} car;

struct Lease_info {
    string Name[100];
    string Natio_ID[100];
    int payment_acc[100];
} lease;

void Menu() {
    int num = 1;
    for (int i = 0; i < 9; ++i) {
        cout << "\t\t\t";
        cout << "Enter " << num << "\t- To Select " << car.company[i] << endl;
        num++;
    }
}

void Details(int Choice) {
    system("CLS");
    cout << "\n\n\n\t\t\t-----------------------------\n";
    cout << "\t\t\tYou Have Selected - " << car.company[Choice - 1] << endl;
    cout << "\t\t\t-----------------------------\n\n\n";
    cout << "\t\t\tModel : " << car.model[Choice - 1] << endl;
    cout << "\t\t\tColor : " << car.color[Choice - 1] << endl;
    cout << "\t\t\tMaximum Speed : " << car.max_speed[Choice - 1] << endl;
    cout << "\t\t\tPrice : " << car.price[Choice - 1] << endl;
}

void checklease(int k) {
    if (lease.payment_acc[k] >= car.price[k])
        cout << "\n\n\n\t\t\tProcess has been done successfully!! " << endl;
    else
        cout << "\n\n\n\t\t\tNot Available " << endl;
}

void user_input(int theChoice) {
    system("CLS");
    int j = theChoice - 1;
    cout << "\t\t\t----------------------------------------\n";
    cout << "\t\t\tPlease Provide Your Personal Details  : \n";
    cout << "\t\t\t----------------------------------------\n\n";
    cout << "\n\tNOTE: PROVIDE FIRST NAME ONLY, DO NOT ENTER SPACE WHILE PROVIDING NAME,\n\tPAYMENT WON'T PROCEED IF THE GIVEN AMOUNT IS LESS THAN THE RATE OF CAR\n\n\n\n";
    cout << "\t\t\tEnter Your Name : ";
    cin >> lease.Name[j];
    cout << "\t\t\tEnter Your National ID : ";
    cin >> lease.Natio_ID[j];
    cout << "\t\t\tPayment Amount: ";
    cin >> lease.payment_acc[j];

    checklease(j);
}

int login() {
  string password;
  cout << "\n\n\n\n\n\n\n\t\t\t\t\t Sunshine Car Rental System Login";
  cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
  // Read the entire password
  cin >> password;

  if (password.empty()) {
      cout << "\n\n\n\n\t\t\t\t\tInvalid Input! Please Enter Password.\n";
      return login(); // Retry login
  }

  if (password == "pass") {
    cout << "\n\n\n\n\t\t\t\t\t Access Granted! Welcome To Our System \n\n";
    system("PAUSE");
    system("CLS");
    return 1;
  } else {
    cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
    system("PAUSE");
    system("CLS");
    return login(); // Retry login
  }
}


int main() {
    login();

    string decide = "yes";
    cout << "\t\t\t----------------------------------------------\n";
    cout << "\t\t\t\tSIMPLE CAR RENTAL SYSTEM \n";
    cout << "\t\t\tWelcome to Our Company, Choose from the menu : " << endl;
    cout << "\t\t\t----------------------------------------------\n";
    while (decide != "exit") {
        Menu();
        cout << "\n\n\n\t\t\tYour Choice: ";
        int theChoice;
        cin >> theChoice;
        Details(theChoice);
        cout << "\n\n\n\t\t\tAre You Sure, you want to rent this Car? (yes/no/exit): ";
        cin >> decide;
        if (decide == "yes") {
            user_input(theChoice);
            cout << "\n\n\t\t\tDo you want to continue? (yes/no) ";
            cin >> decide;
            if (decide == "no") break;
            system("CLS");
        } else if (decide == "no") {
            system("CLS");
            continue;
        } else if (decide == "exit") {
            system("CLS");
            break;
        }
    }

    //getch();
    return 0;
}