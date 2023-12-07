// Hotel Booking Project
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
const string FILE_NAME = "server.txt";
vector<int> booked(10, 0);
int guest_number;

class Hotel_booking
{
public:
    int id, i;
    int day1, month1, year1, day2, month2, year2;
    // int guest_number;
    int available = 10;
    int book = 0;

    void setbooking()
    {
        cout << "HOTEL INFORMATION AND RULES :" << endl;
        cout << "Available rooms : " << available << endl;
        cout << "Rent amount :" << endl
             << "For AC room rent is 2000/per member" << endl
             << "For Non-AC room rent is 1500/per member" << endl;
        cout << "NOTE : Only one is allotted to only one person." << endl;
        for (int i = 0; i < booked.size(); i++)
        {
            if (booked[i] != 0)
                cout << "Booked room :" << booked[i] << endl;
        }
        // vector<int>::iterator i;

        do
        {
            cout << "Enter the rooms id between 1 to 10 :" << endl;
            cin >> id;

            for (i = 0; i <= booked.size(); i++)
            {
                if (booked[i] == id)
                    book = -1;
            }
            if (book == -1 || id >= 11)
            {
                cout << "Room " << id << " is booked. " << endl;
            }
        } while (book == -1 || id >= 11);
        booked.push_back(id);
        available = available - 1;

        do
        {
            cout << "Enter the from date (dd/mm/year : 27/10/2023):" << endl;
            cin >> day1 >> month1 >> year1;
            if (!((1 <= day1 && day1 <= 31) && (1 <= month1 && month1 <= 12) && (2023 <= year1 && year1 <= 3000)))
            {
                cout << "Invalid date !" << endl;
            }
        } while (!((1 <= day1 && day1 <= 31) && (1 <= month1 && month1 <= 12) && (2023 <= year1 && year1 <= 3000)));

        do
        {
            cout << "Enter the to date (dd/mm/year : 27/10/2023):" << endl;
            cin >> day2 >> month2 >> year2;
            if (!((1 <= day2 && day2 <= 31) && (1 <= month2 && month2 <= 12) && (2023 <= year2 && year2 <= 3000)))
            {
                cout << "Invalid date !" << endl;
            }
        } while (!((1 <= day2 && day2 <= 31) && (1 <= month2 && month2 <= 12) && (2023 <= year2 && year2 <= 3000)));

        do
        {
            cout << "Enter the guest number :" << endl;
            cin >> guest_number;
            if (guest_number <= 0)
            {
                cout << "Invalid guest number!" << endl;
            }
        } while (guest_number <= 0);
    }

    void printbooking()
    {
        cout << "BOOKING DETAILS :" << endl;
        cout << "Date :" << day1 << "/" << month1 << "/" << year1 << " to " << day2 << "/" << month2 << "/" << year2 << endl;
        cout << "Number of guest  :" << guest_number << endl;
        fstream out(FILE_NAME, ios::out | ios::app);
        if (out.is_open())
        {
            out << "====================================================================================================================" << endl;
            out << "BOOKING DETAILS :" << endl;
            cout << "Date :" << day1 << "/" << month1 << "/" << year1 << " to " << day2 << "/" << month2 << "/" << year2 << endl;
            out << "Number of guest  :" << guest_number << endl;
        }
        out.close();
    }
};

class Room : public Hotel_booking
{
public:
    int room_type;

    void setroom()
    {
        do
        {
            cout << "Enter the room type :" << endl;
            cout << "1 :AC" << endl
                 << "2:Non AC" << endl;
            cin >> room_type;
            if (room_type < 1 || room_type > 2)
            {
                cout << "Invalid room type!" << endl;
            }
        } while (room_type < 1 || room_type > 2);
    }

    void printroom()
    {
        cout << "ROOM DETAILS :" << endl;
        cout << "Room type :" << room_type << endl;
        fstream out(FILE_NAME, ios::out | ios::app);
        if (out.is_open())
        {
            out << "ROOM DETAILS :" << endl;
            out << "Room type :" << room_type << endl;
        }
        out.close();
    }
};

class Guest : public Hotel_booking
{
public:
    string first_name, last_name;
    string phone_number;
    int age;

    void setguest()
    {

        cout << "Enter the guest first name and last name  :" << endl;
        cin >> first_name >> last_name;
        do
        {
            cout << "Enter the phone number :" << endl;
            cin >> phone_number;
            if (phone_number.length() != 10)
            {
                cout << "Invalid phone number!" << endl;
            }
        } while (phone_number.length() != 10);
        do
        {
            cout << "Enter the age :" << endl;
            cin >> age;
            if (age <= 0 || age > 100)
            {
                cout << "Invalid age!" << endl;
            }
        } while (age <= 0 || age > 100);
    }

    void printguest()
    {
        cout << "GUEST DETAILS :" << endl;
        cout << "Name of guest :" << first_name << " " << last_name << endl;
        cout << "Phone number :" << phone_number << endl;
        cout << "Age :" << age << endl;

        fstream out(FILE_NAME, ios::out | ios::app);
        if (out.is_open())
        {
            out << "GUEST DETAILS :" << endl;
            out << "Name of guest :" << first_name << " " << last_name << endl;
            out << "Phone number :" << phone_number << endl;
            out << "Age :" << age << endl;
        }
        out.close();
    }
};

class Payment : public Room
{
public:
    int amount;
    string card_number;

    void setpayment(Room &r)
    {
        amount = 0;
        if (r.room_type == 1)
            amount = guest_number * 2000;
        else
            amount = guest_number * 1500;
        do
        {
            cout << "Enter the card number :" << endl;
            cin >> card_number;
            if (card_number.length() != 12)
            {
                cout << "Invalid card number!" << endl;
            }
        } while (card_number.length() != 12);
    }

    void printpayment()
    {
        cout << "PAYMENT DETAILS :" << endl;
        cout << "Amount :" << amount << endl;
        cout << "Card number :" << card_number << endl;
        fstream out(FILE_NAME, ios::out | ios::app);
        if (out.is_open())
        {
            out << "PAYMENT DETAILS :" << endl;
            out << "Amount :" << amount << endl;
            out << "Card number :" << card_number << endl;
            out << "====================================================================================================================" << endl;
            out << ".............................THANK YOU !!............................." << endl;
        }
        out.close();
    }
};

int main()
{
    int choice;
    Hotel_booking hotel;
    Room room;
    Guest guest;
    Payment payment;
    do
    {
        cout << endl
             << "HOTEL MANAGEMENT :" << endl;
        fstream out(FILE_NAME, ios::out | ios::app);
        if (out.is_open())
        {
            out << endl
                << "HOTEL MANAGEMENT :" << endl;
        }
        out.close();
        cout << "====================================================================================================================" << endl;
        hotel.setbooking();
        room.setroom();
        guest.setguest();
        payment.setpayment(room);

        cout << "----------------------------------------------------------------------------------------------------------------" << endl;
        hotel.printbooking();
        cout << "----------------------------------------------------------------------------------------------------------------" << endl;
        room.printroom();
        cout << "----------------------------------------------------------------------------------------------------------------" << endl;
        guest.printguest();
        cout << "----------------------------------------------------------------------------------------------------------------" << endl;
        payment.printpayment();
        cout << "====================================================================================================================" << endl;
        do
        {
            cout << "Do you want to :" << endl
                 << "1.Continue with new record" << endl
                 << "2. Read records" << endl
                 << "3.Exit" << endl;
            cin >> choice;
            if (choice < 1 || choice > 3)
                cout << "Invalid choice is selected." << endl;
        } while (choice < 1 || choice > 3);
        if (choice == 2)
        {
            string line;
            fstream file(FILE_NAME);
            {
                while (getline(file, line))
                {
                    cout << line;
                    cout << endl;
                }
            }
            choice = 3;
        }
    } while (choice !=3);

    cout << ".............................THANK YOU !!............................." << endl;
    return 0;
}
