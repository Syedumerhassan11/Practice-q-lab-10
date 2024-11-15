#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a Book
typedef struct Book {
    char title[100];
    char author[100];
    char isbn[20];
    int publicationYear;
    int isAvailable; 
    struct Book* next;
} Book;

Book* createBook(const char* title, const char* author, const char* isbn, int publicationYear) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    if (newBook == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    strcpy(newBook->isbn, isbn);
    newBook->publicationYear = publicationYear;
    newBook->isAvailable = 1;
    newBook->next = NULL;

    return newBook;
}
void addBook(Book** library, const char* title, const char* author, const char* isbn, int publicationYear) {
    Book* newBook = createBook(title, author, isbn, publicationYear);
    if (newBook == NULL) {
        return;
    }
    newBook->next = *library;
    *library = newBook;
    printf("Book added successfully: %s\n", title);
}
void searchBook(Book* library, const char* query) {
    Book* current = library;
    int found = 0;

    while (current != NULL) {
        if (strstr(current->title, query) != NULL || strstr(current->author, query) != NULL) {
            found = 1;
            printf("Book found: %s by %s (ISBN: %s, Year: %d, %s)\n", 
                   current->title, current->author, current->isbn, current->publicationYear,
                   current->isAvailable ? "Available" : "Checked Out");
        }
        current = current->next;
    }

    if (!found) {
        printf("No books found matching the query: %s\n", query);
    }
}
void updateAvailability(Book* library, const char* isbn, int isAvailable) {
    Book* current = library;
    while (current != NULL) {
        if (strcmp(current->isbn, isbn) == 0) {
            current->isAvailable = isAvailable;  // Update availability
            printf("Availability status updated for book: %s\n", current->title);
            return;
        }
        current = current->next;
    }

    printf("No book found with ISBN: %s\n", isbn);
}
void freeLibrary(Book* library) {
    Book* current = library;
    Book* nextBook;
    while (current != NULL) {
        nextBook = current->next;
        free(current);
        current = nextBook;
    }
}

int main() {
    Book* library = NULL;
    addBook(&library, "Charlie and the chocolate factory", "Rohl DAhl", "9780743273565", 1925);
    addBook(&library, "Sherlock Homles", "Charles Dickens", "9780061120084", 1960);
    addBook(&library, "1984", "Matilda", "9780451524935", 1949);
    searchBook(library, "Harper Lee");
    searchBook(library, "1984"); 
    updateAvailability(library, "9780743273565", 0); 
    updateAvailability(library, "9780061120084", 1); 
    searchBook(library, "The Great Gatsby");
    searchBook(library, "To Kill a Mockingbird");
    freeLibrary(library);

    return 0;
}


