#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char a_name[50];
    int birthYear;
} Author;

typedef struct{
    int ID;
    char title[50];
    Author a1;
    float price;
} Book;

void displayBook(Book *b);

int main(){
    int n, target, id_ = -1, loaded_n;
    bool isFound = false;

    FILE *library_in, *library_out;

    // Open file for writing
    library_in = fopen("library.bin", "wb");
    if(library_in == NULL){
        printf("File not created...try again\n");
        return 1;
    }

    printf("Enter number of books: ");
    scanf("%d", &n);
    getchar();

    Book *ptr = (Book *)malloc(n * sizeof(Book));
    if(ptr == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input data
    for(int i = 0; i < n; i++){
        printf("\nEnter details of book %d:\n", i + 1);

        printf("Enter Book Title: ");
        fgets(ptr[i].title, 50, stdin);
        ptr[i].title[strcspn(ptr[i].title, "\n")] = 0;

        printf("Enter Author Name: ");
        fgets(ptr[i].a1.a_name, 50, stdin);
        ptr[i].a1.a_name[strcspn(ptr[i].a1.a_name, "\n")] = 0;

        printf("Enter Birth Year Of Author: ");
        scanf("%d", &ptr[i].a1.birthYear);
        getchar();

        ptr[i].ID = i + 1;
        printf("Assigned Book ID: %d\n", ptr[i].ID);

        printf("Enter cost: ");
        scanf("%f", &ptr[i].price);
        getchar();
    }

    // Write to file
    fwrite(&n, sizeof(n), 1, library_in);
    fwrite(ptr, sizeof(Book), n, library_in);

    fclose(library_in);
    free(ptr);

    // Read from file
    library_out = fopen("library.bin", "rb");
    if(library_out == NULL){
        printf("Error opening file for reading\n");
        return 1;
    }

    fread(&loaded_n, sizeof(loaded_n), 1, library_out);

    ptr = (Book *)malloc(loaded_n * sizeof(Book));
    if(ptr == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    fread(ptr, sizeof(Book), loaded_n, library_out);
    fclose(library_out);

    // Search
    printf("\nEnter Book ID you're looking for: ");
    scanf("%d", &target);

    for(int i = 0; i < loaded_n; i++){
        if(target == ptr[i].ID){
            isFound = true;
            id_ = i;
            break;
        }
    }

    if(isFound){
        displayBook(&ptr[id_]);
    } else {
        printf("\nSorry, Book with ID: %d not found\n", target);
    }

    free(ptr);
    return 0;
}

void displayBook(Book *b){
    printf("\nBook Name: %s\n", b->title);
    printf("Written by %s (Born %d)\n", b->a1.a_name, b->a1.birthYear);
    printf("ID: %d\n", b->ID);
    printf("Cost: %.2f\n", b->price);
}