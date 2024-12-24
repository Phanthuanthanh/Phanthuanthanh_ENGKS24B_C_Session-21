#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
    int age;
} Student;

void writeStudentsToFile(Student *students, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Loi: Khong the mo tep %s\n", filename);
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%d\n", students[i].id, students[i].name, students[i].age);
    }

    fclose(file);
}

int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    Student students[n];

    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin cho sinh vien %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        getchar();
        printf("Ten: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        size_t len = strlen(students[i].name);
        if (len > 0 && students[i].name[len - 1] == '\n') {
            students[i].name[len - 1] = '\0';
        }
        printf("Tuoi: ");
        scanf("%d", &students[i].age);
    }

    writeStudentsToFile(students, n, "students.txt");
    return 0;
}

