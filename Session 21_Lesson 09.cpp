#include <stdio.h>
#include <string.h>

typedef struct {
    char id[20];
    char title[100];
    char author[50];
    float price;
    char category[30];
} Book;

Book books[100];
int book_count = 0;

void inputBooks();
void saveBooksToFile();
void loadBooksFromFile();
void displayBooks();
void menu();

int main() {
    menu();
    return 0;
}
    
void inputBooks() {
    printf("Nhap so luong sach: ");
    scanf("%d", &book_count);
    getchar(); 

    if (book_count > 100) {
        printf("Chi duoc nhap toi da 100 quyen sach.\n");
        book_count = 100;
    }

    for (int i = 0; i < book_count; i++) {
        printf("\nSach thu %d:\n", i + 1);
        printf("Nhap ma sach: ");
        fgets(books[i].id, 20, stdin);
        books[i].id[strcspn(books[i].id, "\n")] = 0; 

        printf("Nhap ten sach: ");
        fgets(books[i].title, 100, stdin);
        books[i].title[strcspn(books[i].title, "\n")] = 0;

        printf("Nhap tac gia: ");
        fgets(books[i].author, 50, stdin);
        books[i].author[strcspn(books[i].author, "\n")] = 0;

        printf("Nhap gia tien: ");
        scanf("%f", &books[i].price);
        getchar(); 

        printf("Nhap the loai: ");
        fgets(books[i].category, 30, stdin);
        books[i].category[strcspn(books[i].category, "\n")] = 0;
    }
}

void saveBooksToFile() {
    FILE *file = fopen("books.dat", "wb");
    if (file == NULL) {
        perror("Loi mo file");
        return;
    }
    fwrite(&book_count, sizeof(int), 1, file);
    fwrite(books, sizeof(Book), book_count, file);
    fclose(file);
    printf("Da luu thong tin sach thanh cong!\n");
}

void loadBooksFromFile() {
    FILE *file = fopen("books.dat", "rb");
    if (file == NULL) {
        perror("Loi mo file");
        return;
    }
    fread(&book_count, sizeof(int), 1, file);
    fread(books, sizeof(Book), book_count, file);
    fclose(file);
    printf("Da doc thong tin sach thanh cong!\n");
}

void displayBooks() {
    if (book_count == 0) {
        printf("Khong co sach de hien thi.\n");
        return;
    }

    for (int i = 0; i < book_count; i++) {
        printf("\nSach thu %d:\n", i + 1);
        printf("Ma sach: %s\n", books[i].id);
        printf("Ten sach: %s\n", books[i].title);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia tien: %.2f\n", books[i].price);
        printf("The loai: %s\n", books[i].category);
    }
}

void menu() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap thong tin sach\n");
        printf("2. Luu thong tin sach vao file\n");
        printf("3. Doc thong tin sach tu file\n");
        printf("4. Hien thi thong tin sach\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                inputBooks();
                break;
            case 2:
                saveBooksToFile();
                break;
            case 3:
                loadBooksFromFile();
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                printf("Ket thuc chuong trinh. Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 5);
}

