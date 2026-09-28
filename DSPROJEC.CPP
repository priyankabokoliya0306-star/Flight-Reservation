#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

class FlightReservation
{
private:

    struct Flight
    {
        int id;
        char name[30];
        char from[25];
        char to[25];
        char time[15];

        long price;
        int seats;
    };

    struct Reservation
    {
        int ticketNo;
        int flightId;
        char passengerName[40];
        int seats;

        long amount;
    };

    Flight flights[20];
    Reservation reservations[50];

    int reservationCount;
    int nextTicket;

public:

    FlightReservation();

    void setFlight(int index, int id, char name[],
                   char from[], char to[],
                   char time[], long price, int seats);

    void displayAllFlights();
    void searchFlight();
    void displayFlightDetails();
    void reserveFlight();
    void viewAllReservations();
    void searchReservation();
    void updateReservation();
    void cancelReservation();
    void displayAvailableSeats();
    void calculateFare();
    void displayTotalReservations();
    void saveReservations();
};


/*================================================
                 CONSTRUCTOR
================================================*/

FlightReservation::FlightReservation()
{
    reservationCount = 0;
    nextTicket = 1;

    setFlight(0, 1, "Air India AI101", "Mumbai",
              "Delhi", "06:00 AM", 4500L, 60);

    setFlight(1, 2, "IndiGo 6E201", "Delhi",
              "Mumbai", "07:00 AM", 4000L, 60);

    setFlight(2, 3, "Vistara UK301", "Mumbai",
              "Bangalore", "08:00 AM", 5000L, 60);

    setFlight(3, 4, "Air India AI401", "Delhi",
              "Chennai", "09:00 AM", 4800L, 60);

    setFlight(4, 5, "IndiGo 6E501", "Pune",
              "Delhi", "10:00 AM", 4200L, 60);

    setFlight(5, 6, "Vistara UK601", "Bangalore",
              "Delhi", "11:00 AM", 4600L, 60);

    setFlight(6, 7, "Air India AI701", "Chennai",
              "Mumbai", "12:00 PM", 4300L, 60);

    setFlight(7, 8, "IndiGo 6E801", "Kolkata",
              "Delhi", "01:00 PM", 4700L, 60);

    setFlight(8, 9, "Vistara UK901", "Delhi",
              "Goa", "02:00 PM", 5200L, 60);

    setFlight(9, 10, "Air India AI111", "Mumbai",
              "Goa", "03:00 PM", 3800L, 60);

    setFlight(10, 11, "IndiGo 6E211", "Delhi",
              "Kolkata", "04:00 PM", 4500L, 60);

    setFlight(11, 12, "Vistara UK311", "Goa",
              "Mumbai", "05:00 PM", 3600L, 60);

    setFlight(12, 13, "Air India AI411", "Bangalore",
              "Chennai", "06:00 PM", 3500L, 60);

    setFlight(13, 14, "IndiGo 6E511", "Mumbai",
              "Kolkata", "07:00 PM", 4900L, 60);

    setFlight(14, 15, "Vistara UK611", "Delhi",
              "Hyderabad", "08:00 PM", 4400L, 60);

    setFlight(15, 16, "Air India AI711", "Hyderabad",
              "Delhi", "09:00 PM", 4300L, 60);

    setFlight(16, 17, "IndiGo 6E811", "Chennai",
              "Delhi", "10:00 PM", 4600L, 60);

    setFlight(17, 18, "Vistara UK911", "Pune",
              "Bangalore", "11:00 PM", 3900L, 60);

    setFlight(18, 19, "Air India AI121", "Goa",
              "Delhi", "06:30 PM", 5000L, 60);

    setFlight(19, 20, "IndiGo 6E221", "Kolkata",
              "Mumbai", "09:30 AM", 4800L, 60);
}


/*================================================
                 SET FLIGHT
================================================*/

void FlightReservation::setFlight(int index, int id,
                                  char name[], char from[],
                                  char to[], char time[],
                                  long price, int seats)
{
    flights[index].id = id;

    strcpy(flights[index].name, name);
    strcpy(flights[index].from, from);
    strcpy(flights[index].to, to);
    strcpy(flights[index].time, time);

    flights[index].price = price;
    flights[index].seats = seats;
}


/*================================================
              OPTION 1
          DISPLAY ALL FLIGHTS
================================================*/

void FlightReservation::displayAllFlights()
{
    int i;

    clrscr();

    cout << "\n============== AVAILABLE FLIGHTS ==============\n";

    for (i = 0; i < 20; i++)
    {
        cout << "\nFlight ID : " << flights[i].id;

        cout << "\nFlight    : "
             << flights[i].name;

        cout << "\nRoute     : "
             << flights[i].from
             << " -> "
             << flights[i].to;

        cout << "\nTime      : "
             << flights[i].time;

        cout << "\nFare      : Rs."
             << flights[i].price;

        cout << "\nAvailable : "
             << flights[i].seats;

        cout << "\n-----------------------------------------------";
    }

    getch();
}


/*================================================
              OPTION 2
             SEARCH FLIGHT
================================================*/

void FlightReservation::searchFlight()
{
    int id;
    int i;
    int found = 0;

    clrscr();

    cout << "\n=============== SEARCH FLIGHT ===============\n";

    cout << "\nEnter Flight ID: ";
    cin >> id;

    for (i = 0; i < 20; i++)
    {
        if (flights[i].id == id)
        {
            cout << "\nFlight Found!";

            cout << "\nFlight : "
                 << flights[i].name;

            cout << "\nFrom   : "
                 << flights[i].from;

            cout << "\nTo     : "
                 << flights[i].to;

            cout << "\nTime   : "
                 << flights[i].time;

            cout << "\nFare   : Rs."
                 << flights[i].price;

            cout << "\nSeats  : "
                 << flights[i].seats;

            found = 1;

            break;
        }
    }

    if (found == 0)
    {
        cout << "\nFlight Not Found!";
    }

    getch();
}


/*================================================
              OPTION 3
          FLIGHT DETAILS
================================================*/

void FlightReservation::displayFlightDetails()
{
    int id;

    clrscr();

    cout << "\n============= FLIGHT DETAILS =============\n";

    cout << "\nEnter Flight ID: ";
    cin >> id;

    if (id >= 1 && id <= 20)
    {
        cout << "\nFlight ID        : "
             << flights[id - 1].id;

        cout << "\nFlight Name      : "
             << flights[id - 1].name;

        cout << "\nFrom             : "
             << flights[id - 1].from;

        cout << "\nTo               : "
             << flights[id - 1].to;

        cout << "\nDeparture Time   : "
             << flights[id - 1].time;

        cout << "\nTicket Price     : Rs."
             << flights[id - 1].price;

        cout << "\nAvailable Seats  : "
             << flights[id - 1].seats;
    }
    else
    {
        cout << "\nInvalid Flight ID!";
    }

    getch();
}


/*================================================
              OPTION 4
           RESERVE FLIGHT
================================================*/

void FlightReservation::reserveFlight()
{
    int flightId;
    int seats;

    clrscr();

    cout << "\n=========== RESERVE FLIGHT SEAT ===========\n";

    if (reservationCount >= 50)
    {
        cout << "\nReservation limit reached!";
        getch();
        return;
    }

    cin.get();

    cout << "\nPassenger Name: ";

    cin.getline(
        reservations[reservationCount].passengerName,
        40
    );

    cout << "Enter Flight ID: ";
    cin >> flightId;

    if (flightId < 1 || flightId > 20)
    {
        cout << "\nInvalid Flight ID!";
        getch();
        return;
    }

    cout << "Number of Seats: ";
    cin >> seats;

    if (seats <= 0)
    {
        cout << "\nInvalid number of seats!";
        getch();
        return;
    }

    if (seats > flights[flightId - 1].seats)
    {
        cout << "\nNot enough seats available!";
        getch();
        return;
    }

    reservations[reservationCount].ticketNo =
        nextTicket;

    reservations[reservationCount].flightId =
        flightId;

    reservations[reservationCount].seats =
        seats;


    /* IMPORTANT:
       LONG CALCULATION PREVENTS OVERFLOW */

    reservations[reservationCount].amount =
        (long)seats * flights[flightId - 1].price;


    flights[flightId - 1].seats =
        flights[flightId - 1].seats - seats;


    cout << "\n============================================";
    cout << "\n       SEAT RESERVED SUCCESSFULLY!";
    cout << "\n============================================";

    cout << "\nTicket Number : "
         << nextTicket;

    cout << "\nPassenger     : "
         << reservations[reservationCount].passengerName;

    cout << "\nFlight        : "
         << flights[flightId - 1].name;

    cout << "\nSeats         : "
         << seats;

    cout << "\nPrice/Seat    : Rs."
         << flights[flightId - 1].price;

    cout << "\nTotal Fare    : Rs."
         << reservations[reservationCount].amount;

    cout << "\n============================================";


    reservationCount++;

    nextTicket++;

    saveReservations();

    getch();
}


/*================================================
              OPTION 5
        VIEW RESERVATIONS
================================================*/

void FlightReservation::viewAllReservations()
{
    int i;

    clrscr();

    cout << "\n============= ALL RESERVATIONS =============\n";

    if (reservationCount == 0)
    {
        cout << "\nNo reservations available!";
    }
    else
    {
        for (i = 0; i < reservationCount; i++)
        {
            cout << "\nTicket No : "
                 << reservations[i].ticketNo;

            cout << "\nFlight ID : "
                 << reservations[i].flightId;

            cout << "\nPassenger : "
                 << reservations[i].passengerName;

            cout << "\nSeats     : "
                 << reservations[i].seats;

            cout << "\nAmount    : Rs."
                 << reservations[i].amount;

            cout << "\n--------------------------------------------";
        }
    }

    getch();
}


/*================================================
              OPTION 6
        SEARCH RESERVATION
================================================*/

void FlightReservation::searchReservation()
{
    int ticket;
    int i;
    int found = 0;

    clrscr();

    cout << "\n=========== SEARCH RESERVATION ============\n";

    cout << "\nEnter Ticket Number: ";
    cin >> ticket;

    for (i = 0; i < reservationCount; i++)
    {
        if (reservations[i].ticketNo == ticket)
        {
            cout << "\nReservation Found!";

            cout << "\nTicket No : "
                 << reservations[i].ticketNo;

            cout << "\nFlight ID : "
                 << reservations[i].flightId;

            cout << "\nPassenger : "
                 << reservations[i].passengerName;

            cout << "\nSeats     : "
                 << reservations[i].seats;

            cout << "\nAmount    : Rs."
                 << reservations[i].amount;

            found = 1;

            break;
        }
    }

    if (found == 0)
    {
        cout << "\nReservation Not Found!";
    }

    getch();
}


/*================================================
              OPTION 7
        UPDATE RESERVATION
================================================*/

void FlightReservation::updateReservation()
{
    int ticket;
    int newSeats;
    int i;
    int j;
    int found = 0;
    int availableSeats;

    clrscr();

    cout << "\n=========== UPDATE RESERVATION ===========\n";

    cout << "\nEnter Ticket Number: ";
    cin >> ticket;

    for (i = 0; i < reservationCount; i++)
    {
        if (reservations[i].ticketNo == ticket)
        {
            found = 1;

            cout << "\nCurrent Seats : "
                 << reservations[i].seats;

            cout << "\nEnter New Number of Seats: ";
            cin >> newSeats;

            if (newSeats <= 0)
            {
                cout << "\nInvalid Number of Seats!";
                getch();
                return;
            }

            for (j = 0; j < 20; j++)
            {
                if (flights[j].id ==
                    reservations[i].flightId)
                {
                    /*
                       Add old seats back first.
                    */

                    availableSeats =
                        flights[j].seats +
                        reservations[i].seats;


                    if (newSeats <= availableSeats)
                    {
                        flights[j].seats =
                            availableSeats - newSeats;

                        reservations[i].seats =
                            newSeats;


                        /* CORRECT UPDATED FARE */

                        reservations[i].amount =
                            (long)newSeats *
                            flights[j].price;


                        cout << "\nReservation Updated Successfully!";

                        cout << "\nNew Seats : "
                             << reservations[i].seats;

                        cout << "\nPrice/Seat : Rs."
                             << flights[j].price;

                        cout << "\nNew Total Fare : Rs."
                             << reservations[i].amount;

                        saveReservations();
                    }
                    else
                    {
                        cout << "\nNot enough seats available!";
                    }

                    break;
                }
            }

            break;
        }
    }

    if (found == 0)
    {
        cout << "\nReservation Not Found!";
    }

    getch();
}


/*================================================
              OPTION 8
        CANCEL RESERVATION
================================================*/

void FlightReservation::cancelReservation()
{
    int ticket;
    int i;
    int j;
    int found = 0;

    clrscr();

    cout << "\n=========== CANCEL RESERVATION ============\n";

    cout << "\nEnter Ticket Number: ";
    cin >> ticket;

    for (i = 0; i < reservationCount; i++)
    {
        if (reservations[i].ticketNo == ticket)
        {
            found = 1;


            for (j = 0; j < 20; j++)
            {
                if (flights[j].id ==
                    reservations[i].flightId)
                {
                    flights[j].seats =
                        flights[j].seats +
                        reservations[i].seats;

                    break;
                }
            }


            for (j = i;
                 j < reservationCount - 1;
                 j++)
            {
                reservations[j].ticketNo =
                    reservations[j + 1].ticketNo;

                reservations[j].flightId =
                    reservations[j + 1].flightId;

                strcpy(
                    reservations[j].passengerName,
                    reservations[j + 1].passengerName
                );

                reservations[j].seats =
                    reservations[j + 1].seats;

                reservations[j].amount =
                    reservations[j + 1].amount;
            }


            reservationCount--;

            saveReservations();

            cout << "\nReservation Cancelled Successfully!";

            break;
        }
    }

    if (found == 0)
    {
        cout << "\nReservation Not Found!";
    }

    getch();
}


/*================================================
              OPTION 9
        AVAILABLE SEATS
================================================*/

void FlightReservation::displayAvailableSeats()
{
    int i;

    clrscr();

    cout << "\n============ AVAILABLE SEATS =============\n";

    for (i = 0; i < 20; i++)
    {
        cout << "\n"
             << flights[i].id
             << ". "
             << flights[i].name
             << " --> "
             << flights[i].seats
             << " seats";
    }

    getch();
}


/*================================================
              OPTION 10
           CALCULATE FARE
================================================*/

void FlightReservation::calculateFare()
{
    int ticket;
    int i;
    int j;
    int found = 0;

    long farePerSeat;
    long totalFare;

    clrscr();

    cout << "\n============= CALCULATE FARE =============\n";

    cout << "\nEnter Ticket Number: ";
    cin >> ticket;


    for (i = 0; i < reservationCount; i++)
    {
        if (reservations[i].ticketNo == ticket)
        {
            found = 1;

            farePerSeat = 0;


            for (j = 0; j < 20; j++)
            {
                if (flights[j].id ==
                    reservations[i].flightId)
                {
                    farePerSeat =
                        flights[j].price;

                    break;
                }
            }


            /* LONG CALCULATION */

            totalFare =
                (long)reservations[i].seats *
                farePerSeat;


            reservations[i].amount =
                totalFare;


            cout << "\nPassenger : "
                 << reservations[i].passengerName;

            cout << "\nFlight ID : "
                 << reservations[i].flightId;

            cout << "\nSeats     : "
                 << reservations[i].seats;

            cout << "\nFare/Seat : Rs."
                 << farePerSeat;

            cout << "\nCalculation: "
                 << reservations[i].seats
                 << " x Rs."
                 << farePerSeat;

            cout << "\nTotal Fare: Rs."
                 << totalFare;


            saveReservations();

            break;
        }
    }


    if (found == 0)
    {
        cout << "\nReservation Not Found!";
    }

    getch();
}


/*================================================
              OPTION 11
        TOTAL RESERVATIONS
================================================*/

void FlightReservation::displayTotalReservations()
{
    clrscr();

    cout << "\n===========================================\n";
    cout << "          RESERVATION SUMMARY\n";
    cout << "===========================================\n";

    cout << "\nTotal Reservations : "
         << reservationCount;

    cout << "\n===========================================";

    getch();
}


/*================================================
             SAVE RESERVATIONS
================================================*/

void FlightReservation::saveReservations()
{
    FILE *file;

    int i;

    file = fopen("flights.txt", "w");


    if (file == NULL)
    {
        cout << "\nFile cannot be opened!";

        return;
    }


    for (i = 0;
         i < reservationCount;
         i++)
    {
        fprintf(file,
                "Ticket No: %d\n",
                reservations[i].ticketNo);

        fprintf(file,
                "Flight ID: %d\n",
                reservations[i].flightId);

        fprintf(file,
                "Passenger: %s\n",
                reservations[i].passengerName);

        fprintf(file,
                "Seats: %d\n",
                reservations[i].seats);


        /* %ld IS USED FOR LONG */

        fprintf(file,
                "Amount: Rs.%ld\n",
                reservations[i].amount);

        fprintf(file,
                "-----------------------------\n");
    }


    fclose(file);
}


/*================================================
                 MAIN FUNCTION
================================================*/

void main()
{
    clrscr();

    FlightReservation obj;

    int choice;


    do
    {
        cout << "\n\n==========================================";
        cout << "\n       FLIGHT SEAT RESERVATION SYSTEM";
        cout << "\n==========================================";

        cout << "\n1.  Display All Flights";
        cout << "\n2.  Search Flight";
        cout << "\n3.  Display Flight Details";
        cout << "\n4.  Reserve Flight Seat";
cout << "\n5.  View All Reservations";
        cout << "\n6.  Search Reservation";
        cout << "\n7.  Update Reservation";
        cout << "\n8.  Cancel Reservation";
        cout << "\n9.  Display Available Seats";
        cout << "\n10. Calculate Fare";
        cout << "\n11. Display Total Reservations";
        cout << "\n12. Exit";


        cout << "\n==========================================";

        cout << "\nEnter Your Choice: ";

        cin >> choice;


        switch (choice)
        {
            case 1:
                obj.displayAllFlights();
                break;

            case 2:
                obj.searchFlight();
                break;

            case 3:
                obj.displayFlightDetails();
                break;

            case 4:
                obj.reserveFlight();
                break;

            case 5:
                obj.viewAllReservations();
                break;

            case 6:
                obj.searchReservation();
                break;

            case 7:
                obj.updateReservation();
                break;

            case 8:
                obj.cancelReservation();
                break;

            case 9:
                obj.displayAvailableSeats();
                break;

            case 10:
                obj.calculateFare();
                break;

            case 11:
                obj.displayTotalReservations();
                break;

            case 12:
                cout << "\nThank You!";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while (choice != 12);


    getch();
}