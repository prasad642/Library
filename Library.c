#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

typedef struct{
    char a_name[50];
    int birthYear;
}Author;

typedef struct{
    int ID;
    char title[50];
    Author a1;
    float price;
}Book;

void displayBook(Book *b);

int main(){
    int n,target,id_ = -1,loaded_n;
    int booksize = sizeof(Book);
    bool isFound = false;
    bool file = false; // file is present means file is created
    bool isAllocated = false;
    FILE *library_in,*library_out;
    library_in = fopen("library.bin","wb");
    if(library_in == NULL){
        printf("File not created...try again");
    }else{
        file = true;
    }
    printf("Enter number of books:");
    scanf("%d",&n);
    getchar();
    //Book books[n];
    Book *ptr = malloc(n*booksize);
    if(ptr == NULL){
        printf("Allocation failed..!");
    }else{
        isAllocated = true;
        for(int i=0;i<n;i++){
            printf("Enter details of book %d:\n",i+1);
            printf("Enter Book Title:");
            fgets(ptr[i].title,50,stdin);
            ptr[i].title[strcspn(ptr[i].title,"\n")] = 0;
            printf("Enter Author Name:");
            fgets(ptr[i].a1.a_name,50,stdin);
            ptr[i].a1.a_name[strcspn(ptr[i].a1.a_name,"\n")] = 0;
            printf("Enter Birth Year Of Author:");
            scanf("%d",&ptr[i].a1.birthYear);
            getchar();
            printf("Assigned Book ID: %d\n",(i+1));
            ptr[i].ID = (i+1);
            printf("Enter cost:");
            scanf("%f",&ptr[i].price);
            getchar();

        }
    }

    if(file){
        fwrite(&n,sizeof(n),1,library_in);
        fwrite(ptr,booksize,n,library_in);
    }else{
        printf("Something wrong with the saving data in file..try again");
    }

    fclose(library_in);
    free(ptr);

    library_out = fopen("library.bin","rb");
    fread(&loaded_n,sizeof(loaded_n),1,library_out);
    ptr = (Book *)malloc(loaded_n*sizeof(Book));
    fread(ptr,booksize,loaded_n,library_out);

    if(isAllocated){
        printf("Enter Book ID you're looking for:");
        scanf("%d",&target);
        for(int i=0;i<loaded_n;i++){
            if(target == ptr[i].ID){
                isFound = true;
                id_ = i;
                break;
            }
        }
        if(isFound){
            displayBook((ptr+id_));
        }else{
            printf("\nSorry, Book with ID: %d not found",target);
        }
    }else{
        printf("Something went wrong....! Try again after some time");
    }
    return 0;
}

void displayBook(Book *b){
    printf("book name:%s\n",b->title);
    printf("written by %s born in %d\n",b->a1.a_name,b->a1.birthYear);
    printf("ID:%d\n",b->ID);
    printf("Cost:%.2f\n",b->price);
}