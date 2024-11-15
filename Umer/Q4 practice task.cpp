#include <stdio.h>
#include <string.h>

#define MAX_FLIGHTS 100

typedef struct {
    char flightNumber[10];
    char departureCity[50];
    char arrivalCity[50];
    char departureTime[20]; 
    char arrivalTime[20];
    int availableSeats;
} Flight;

// Array to hold all flights
Flight flights[MAX_FLIGHTS];
int flightCount = 0;

// Function to add a new flight
void addFlight(const char* flightNumber, const char* departureCity, const char* arrivalCity,
               const char* departureTime, const char* arrivalTime, int availableSeats) {
    if (flightCount < MAX_FLIGHTS) {
        strcpy(flights[flightCount].flightNumber, flightNumber);
        strcpy(flights[flightCount].departureCity, departureCity);
        strcpy(flights[flightCount].arrivalCity, arrivalCity);
        strcpy(flights[flightCount].departureTime, departureTime);
        strcpy(flights[flightCount].arrivalTime, arrivalTime);
        flights[flightCount].availableSeats = availableSeats;

        flightCount++;
        printf("Flight %s added successfully.\n", flightNumber);
    } else {
        printf("Error: Cannot add more flights, storage is full.\n");
    }
}

void bookSeat(const char* flightNumber) {
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].flightNumber, flightNumber) == 0) {
            if (flights[i].availableSeats > 0) {
                flights[i].availableSeats--;
                printf("Seat booked successfully on flight %s. Remaining seats: %d\n", flightNumber, flights[i].availableSeats);
            } else {
                printf("Error: No available seats on flight %s.\n", flightNumber);
            }
            return;
        }
    }
    printf("Error: Flight %s not found.\n", flightNumber);
}
void displayFlights(const char* departureCity, const char* arrivalCity) {
    printf("Available flights from %s to %s:\n", departureCity, arrivalCity);
    int found = 0;
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].departureCity, departureCity) == 0 && 
            strcmp(flights[i].arrivalCity, arrivalCity) == 0 && 
            flights[i].availableSeats > 0) {
            found = 1;
            printf("Flight %s: Departure: %s, Arrival: %s, Available Seats: %d\n",
                   flights[i].flightNumber, flights[i].departureTime, flights[i].arrivalTime, flights[i].availableSeats);
        }
    }
    if (!found) {
        printf("No available flights from %s to %s.\n", departureCity, arrivalCity);
    }
}
void updateFlightDetails(const char* flightNumber, const char* newDepartureTime, 
                         const char* newArrivalTime, int newAvailableSeats) {
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].flightNumber, flightNumber) == 0) {

            if (newDepartureTime != NULL) {
                strcpy(flights[i].departureTime, newDepartureTime);
            }
            if (newArrivalTime != NULL) {
                strcpy(flights[i].arrivalTime, newArrivalTime);
            }
            flights[i].availableSeats = newAvailableSeats;
            printf("Flight %s updated: Departure Time: %s, Arrival Time: %s, Available Seats: %d\n", 
                   flightNumber, flights[i].departureTime, flights[i].arrivalTime, flights[i].availableSeats);
            return;
        }
    }
    printf("Error: Flight %s not found for update.\n", flightNumber);
}

int main() {
    addFlight("AA123", "New York", "Los Angeles", "2024-12-01 07:00", "2024-12-01 10:00", 50);
    addFlight("BB456", "Los Angeles", "San Francisco", "2024-12-01 08:30", "2024-12-01 09:30", 30);
    addFlight("CC789", "New York", "San Francisco", "2024-12-02 06:00", "2024-12-02 09:00", 25);
    displayFlights("New York", "San Francisco");
    bookSeat("AA123");
    displayFlights("New York", "Los Angeles");
    updateFlightDetails("BB456", "2024-12-01 09:00", "2024-12-01 10:00", 35);

    return 0;
}

