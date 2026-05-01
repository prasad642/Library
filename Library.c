#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct{
    char a_name[20];
    int birthYear;
}Author;

typedef struct{
    int ID;
    char title[30];
    Author a;
    float price;
}Book;

void displayBook(Book *);

int main(){
    bool isHere = false;
    int n,i,target=0,loaded_n;
    printf("Enter Number of books:");
    scanf("%d",&n);
    getchar();

    FILE *library_in,*library_out;
    library_in = fopen("Library.bin","wb");
    if(library_in == NULL){
        printf("File creation failed");
        return 1;
    }
    


    Book *ptr = (Book *)malloc(n * sizeof(Book));
    if(ptr == NULL){
        printf("Allocation Failed...try again");
        return 1;
    }else{
        //Asking details for books
        for(i=0;i<n;i++){
            printf("Enter Book Title:");
            fgets(ptr[i].title,30,stdin);
            ptr[i].title[strcspn(ptr[i].title,"\n")] = 0;
            printf("Enter Author Name:");
            fgets(ptr[i].a.a_name,20,stdin);
            ptr[i].a.a_name[strcspn(ptr[i].a.a_name,"\n")] = 0;
            printf("Enter birth year of the author:");
            scanf("%d",&ptr[i].a.birthYear);
            getchar();
            printf("Asssigned ID: %d\n",i+1);
            ptr[i].ID = i+1;
            printf("Enter cost:");
            scanf("%f",&ptr[i].price);
            getchar();
        }

        //loading details into files
        fwrite(&n,sizeof(n),1,library_in);
        fwrite(ptr,sizeof(Book),n,library_in);

        fclose(library_in);
        free(ptr);


        library_out = fopen("Library.bin","rb");
        if(library_out == NULL){
            printf("Loading file Failed...try again");
            return 1;
        }

        fread(&loaded_n,sizeof(loaded_n),1,library_out);
        
        ptr = (Book *)malloc(loaded_n * sizeof(Book));
        if(ptr == NULL){
            printf("Memory allocation Failed...try again");
        }else{
            fread(ptr,sizeof(Book),loaded_n,library_out);
            printf("enter book ID:");
            scanf("%d",&target);
            for(i=0;i<loaded_n;i++){
                if(target == ptr[i].ID){
                    isHere = true;
                    break;
                }
            }

            if(isHere){
                displayBook(&ptr[i]);
            }else{
                printf("Book with ID: %d not found in library",target);
            }
        }

        fclose(library_out);
        free(ptr);
        ptr = NULL;
    }

    return 0;
}

void displayBook(Book *b){
    printf("Book Found in the Library..\n");
    printf("Book Title: %s\n",b->title);
    printf("Written by %s, born in %d\n",b->a.a_name,b->a.birthYear);
    printf("Given ID:%d\n",b->ID);
    printf("Cost : $%.2f",b->price);
}