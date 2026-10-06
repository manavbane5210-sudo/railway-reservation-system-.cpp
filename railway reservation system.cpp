#include <iostream>
#include <string>
using namespace std;

class Railway
{
    int ticketNo, age;
    string name, train, date, cls, source, destination;
    float fare, discount, finalFare;
    string payment;
    bool booked = false;

public:

    void book(int no)
    {
        ticketNo = no;

        cin.ignore();
        cout << "\nPassenger Name: ";
        getline(cin, name);

        cout << "Age: ";
        cin >> age;
        cin.ignore();

        cout << "Train Name: ";
        getline(cin, train);

        cout << "Travel Date: ";
        getline(cin, date);

        cout << "Class (1-General 2-Sleeper 3-AC): ";
        int c;
        cin >> c;

        if(c == 1) { cls = "General"; fare = 500; }
        else if(c == 2) { cls = "Sleeper"; fare = 800; }
        else { cls = "AC"; fare = 1000; }

        cin.ignore();

        cout << "Source: ";
        getline(cin, source);

        cout << "Destination: ";
        getline(cin, destination);

        discount = (age >= 60) ? fare * 0.10 : 0;
        finalFare = fare - discount;

        cout << "Payment (1-UPI 2-Card 3-Cash): ";
        int p;
        cin >> p;

        if(p == 1) payment = "UPI";
        else if(p == 2) payment = "Card";
        else payment = "Cash";

        booked = true;

        cout << "\nTicket Booked Successfully!";
        cout << "\nTicket No: " << ticketNo;
        cout << "\nFinal Fare: Rs." << finalFare;
    }

    void display()
    {
        cout << "\n\n--- TICKET DETAILS ---";
        cout << "\nTicket No: " << ticketNo;
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nTrain: " << train;
        cout << "\nDate: " << date;
        cout << "\nClass: " << cls;
        cout << "\nFrom: " << source;
        cout << "\nTo: " << destination;
        cout << "\nFare: Rs." << fare;
        cout << "\nDiscount: Rs." << discount;
        cout << "\nFinal Fare: Rs." << finalFare;
        cout << "\nPayment: " << payment;
        cout << "\nStatus: " << (booked ? "Booked" : "Cancelled");
    }

    int getNo()
    {
        return ticketNo;
    }

    void cancel()
    {
        booked = false;
        cout << "\nTicket Cancelled Successfully!";
    }
};

int main()
{
    Railway t[100];
    int count = 0, choice, no;

    do
    {
        cout << "\n\n===== RAILWAY RESERVATION =====";
        cout << "\n1. Book Ticket";
        cout << "\n2. Display Tickets";
        cout << "\n3. Search Ticket";
        cout << "\n4. Cancel Ticket";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        if(choice == 1)
        {
            t[count].book(1001 + count);
            count++;
        }
        else if(choice == 2)
        {
            for(int i = 0; i < count; i++)
                t[i].display();
        }
        else if(choice == 3 || choice == 4)
        {
            cout << "\nEnter Ticket No: ";
            cin >> no;

            bool found = false;

            for(int i = 0; i < count; i++)
            {
                if(t[i].getNo() == no)
                {
                    if(choice == 3)
                        t[i].display();
                    else
                        t[i].cancel();

                    found = true;
                    break;
                }
            }

            if(!found)
                cout << "\nTicket Not Found!";
        }
        else if(choice == 5)
            cout << "\nThank You!";

        else
            cout << "\nInvalid Choice!";

    } while(choice != 5);

    return 0;
}
