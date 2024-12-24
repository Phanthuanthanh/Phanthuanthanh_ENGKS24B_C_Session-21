#include <stdio.h>
int main(){
    FILE *fptr;
    char chuDautien;
    fptr=fopen("bt01.txt","r");
    if(fptr==NULL){
        printf("Khong the mo file\n");
        return 1;
    }
    chuDautien=fgetc(fptr);
    printf("Ky tu dau tien trong file la: %c\n", chuDautien);
    fclose(fptr);
    
    return 0;
}
