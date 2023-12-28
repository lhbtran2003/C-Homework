
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_VALUE 100

typedef struct {
    int id;
    char startDate[50];
    char endDate[50];
    char content[100];
    bool status;
}Todo;

void updateTodo();
void printTodo();
void addTodo();
void deleteTodo();
void sortTodoList();
void searchByStatus();
void searchTodo();

int main(void) {
    int choice;
    do {
        printf("************************MENU**************************\n");
        printf("1. In toan bo danh sach Todo\n");
        printf("2. Them moi Todo\n");
        printf("3. Cap nhat Todo\n");
        printf("4. Xoa Todo\n");
        printf("5. Sap xep Todo\n");
        printf("6. Tim kiem Todo\n");
        printf("7. Tim kiem Todo theo Status\n");
        printf("8. Thoat\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printTodo();
                break;
            case 2:
                addTodo();
                break;
            case 3:
                updateTodo();
                break;
            case 4:
                deleteTodo();
                break;
            case 5:
                sortTodoList();
                break;
            case 6:
                searchTodo();
                break;
            case 7:
                searchByStatus();
                break;
            case 8:
                printf("End.\n");
                break;
            default:
                printf("!!!Vui long chon lai.\n");
                break;
        }
    } while (choice != 8);

}


Todo todoList[MAX_VALUE] = {
        {1, "20/03/2023", "21/03/2023", "Sinh nhat", false},
        {2, "13/05/2023", "18/05/2023", "Happy birthday", true}
};
int size = 2;

void printTodo() {
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Start date: %s, End date: %s, Content: %s, Status: %s\n",
               todoList[i].id, todoList[i].startDate, todoList[i].endDate, todoList[i].content,
               todoList[i].status ? "Done" : "Haven't done");
    }
}

void addTodo() {
    if (size < MAX_VALUE) {
        Todo newTodo;
        printf("Nhap thong tin cho cong viec moi:\n");
        printf("ID: ");
        scanf("%d", &newTodo.id);
        printf("Start date: ");
        scanf("%s", newTodo.startDate);
        printf("End date: ");
        scanf("%s", newTodo.endDate);
        printf("Content: ");
        scanf(" %[^\n]s", newTodo.content);
        printf("Status (1 to Done, 0 to Haven't done):");
        scanf("%d", &newTodo.status);

        todoList[size++] = newTodo;
        printf("Cong viec da duoc them moi.\n\n");
    } else {
        printf("Danh sach cong viec da day. Khong the them moi.\n\n");
    }
}

void updateTodo() {
    char content[100];
    printf("Nhap noi dung cua cong viec muon cap nhat: ");
    scanf(" %[^\n]s", content);

    for (int i = 0; i < size; i++) {
        if (strcmp(todoList[i].content, content) == 0) {
            printf("Nhap thong tin cap nhat cho cong viec:\n");
            printf("New start date: ");
            scanf("%s", todoList[i].startDate);
            printf("New end date: ");
            scanf("%s", todoList[i].endDate);
            printf("New content: ");
            scanf(" %[^\n]s", todoList[i].content);
            printf("New status (1 to Done, 0 to Haven't done): ");
            scanf("%d", &todoList[i].status);
            printf("Cong viec da duoc cap nhat.\n\n");
            return;
        }
    }

    printf("Khong tim thay cong viec.\n\n");
}

void deleteTodo() {
    char content[100];
    printf("Nhap noi dung cua muc cong viec muon xoa: ");
    scanf(" %[^\n]s", content);

    for (int i = 0; i < size; i++) {
        if (strcmp(todoList[i].content, content) == 0) {
            for (int j = i; j < size - 1; j++) {
                todoList[j] = todoList[j + 1];
            }
            size--;
            printf("Cong viec da duoc xoa.\n\n");
            return;
        }
    }

    printf("Khong tim thay cong viec trong Todolist.\n\n");
}

void sortTodoList() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(todoList[i].content, todoList[j].content) > 0) {
                Todo temp = todoList[i];
                todoList[i] = todoList[j];
                todoList[j] = temp;
            }
        }
    }
    printf("Danh sach cong viec sau khi sap xep la:\n");
    printTodo();
}

void searchTodo() {
    char content[100];
    printf("Nhap noi dung cua cong viec muon tim: ");
    scanf(" %[^\n]s", content);

    for (int i = 0; i < size; i++) {
        if (strcmp(todoList[i].content, content) == 0) {
            printf("Thong tin cua cong viec can tim:\n");
            printf("ID: %d, Start date: %s, End date: %s, Content: %s, Status: %s\n\n",
                   todoList[i].id, todoList[i].startDate, todoList[i].endDate, todoList[i].content,
                   todoList[i].status ? "Done" : "Haven't done");
            return;
        }
    }

    printf("Khong tim thay cong viec.\n\n");
}

void searchByStatus() {
    int status;
    printf("Nhap trang thai cua cong viec muon tim (1 to Done, 0 to Haven't done): ");
    scanf("%d", &status);

    printf("Danh sach cong viec co trang thai %s:\n", status ? "Done" : "Haven't done");
    for (int i = 0; i < size; i++) {
        if (todoList[i].status == status) {
            printf("ID: %d, Start date: %s, End date: %s, Content: %s, Status: %s\n",
                   todoList[i].id, todoList[i].startDate, todoList[i].endDate, todoList[i].content,
                   todoList[i].status ? "Done" : "Haven't done");
        }
    }
}
