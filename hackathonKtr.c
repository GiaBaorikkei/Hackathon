#include<stdio.h>
#include<string.h>

struct sinhVien {
    int id;
    char name[100];
    char birthday[100];
    char address[100];
    int status;
};

void displaysinhVien(struct sinhVien arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("ID: %d\tHo va ten: %s\tNgay sinh: %s\tDia chi: %s\tTrang Thai: %d\n", arr[i].id, arr[i].name, arr[i].birthday, arr[i].address, arr[i].status);
    }
}

int searchsinhVien(struct sinhVien arr[], int size, char answer[50]) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].name, answer) == 0) {
            index = i;
            break;
        }
    }
    return index;
}

int main() {
	char answer[100];
    struct sinhVien sv1 = {1, "Thai Nguyen Gia Bao", "21/08/2005", "Minh Thanh, Yen Thanh, Nghe An", 1};
    struct sinhVien sv2 = {2, "Duong Sy Hiep", "04/09/2005", "Thanh Tri, Ha Noi", 0};
    struct sinhVien studentList[500] = {sv1, sv2};
    int currentSize = 2;
do{
    printf("1. In toan bo danh sach sinh vien co o trong mang studentList tren cung mot hang\n");
    printf("2. Thuc hien chuc nang them moi sinh vien vao vi tri cuoi cung cua studentList\n");
    printf("3. Thuc hien chuc nang cap nhat thong tin cua mot sinh vien\n");
    printf("4. Thuc hien chuc nang xoa mot sinh vien\n");
    printf("5. Thuc hien chuc nang sap xep\n");
    printf("6. Thuc hien chuc nang tim kiem va in ra ten cua sinh vien\n");
    printf("7. Thuc hien chuc nang tim kiem va in ra toan bo thong tin sinh vien theo status\n");
    printf("8. Thoat\n");
    printf("Lua chon cua ban la:");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Toan bo danh sach sinh vien co trong mang:\n");
            displaysinhVien(studentList, currentSize);
            break;

        case 2: {
            struct sinhVien newsv;

            printf("Nhap vao ID cua sinh vien: \n");
            scanf("%d", &newsv.id);
            fflush(stdin);

            printf("Nhap vao ho va ten cua sinh vien: \n");
            scanf("%s", newsv.name);
            fflush(stdin);

            printf("Nhap vao ngay sinh cua sinh vien: \n");
            scanf("%s", newsv.birthday);
            fflush(stdin);

            printf("Nhap vao dia chi cua sinh vien: \n");
            scanf("%s", newsv.address);
            fflush(stdin);

            printf("Nhap vao trang thai cua sinh vien: \n");
            scanf("%d", &newsv.status);
            fflush(stdin);

            studentList[currentSize] = newsv;
            currentSize++;

            displaysinhVien(studentList, currentSize);

            break;
        }

        case 3: {
            char answer[100];
            printf("Nhap vao sinh vien ban muon chinh sua: \n");
            fflush(stdin);
            scanf("%[^\n]s", answer);
            fflush(stdin);

            int updateIndex = searchsinhVien(studentList, currentSize, answer);

            if (updateIndex != -1) {
                struct sinhVien newsv;

                printf("Nhap vao ID cua sinh vien: \n");
                scanf("%d", &newsv.id);
                fflush(stdin);

                printf("Nhap vao ho va ten cua sinh vien: \n");
                scanf("%s", newsv.name);
                fflush(stdin);

                printf("Nhap vao ngay sinh cua sinh vien: \n");
                scanf("%s", newsv.birthday);
                fflush(stdin);

                printf("Nhap vao dia chi cua sinh vien: \n");
                scanf("%s", newsv.address);
                fflush(stdin);

                printf("Nhap vao trang thai cua sinh vien: \n");
                scanf("%d", &newsv.status);
                fflush(stdin);

                studentList[updateIndex] = newsv;

                displaysinhVien(studentList, currentSize);
            }
            break;
        }

        case 4: 
            printf("Nhap vao sinh vien ban muon xoa: \n");
            fflush(stdin);
            scanf("%[^\n]s", answer);
            fflush(stdin);

            int deleteIndex = searchsinhVien(studentList, currentSize, answer);

            if (deleteIndex != -1) {
                for (int i = deleteIndex; i < currentSize; i++) {
                    studentList[i] = studentList[i + 1];
                }
                currentSize--;

                displaysinhVien(studentList, currentSize);
            }
            break;
        }
    return 0;
} while (1==1);
}
