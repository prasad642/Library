#include<stdio.h>
#include<string.h>

int main(){
    FILE *file;
    char name[20];
    file = fopen("library.bin","wb");
    if(file == NULL){
        printf("File creation failed, Try again");
    }else{
        printf("File created successfully..");
    }
    printf("Enter name:");
    fgets(name,20,stdin);
    name[strcspn(name,"\n")] = 0;
    fprintf(file,name);
    fclose(file);
    return 0;
}