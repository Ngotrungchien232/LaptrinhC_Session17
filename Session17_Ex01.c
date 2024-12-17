#include <stdio.h>
#include <stdlib.h> //chua cac ham cap phat bo nho va giai phong


void nhapchuoi(char **arr, int *n) {
    printf("Nhap so phan tu cua chuoi: ");
    scanf("%d", n);

    // cap phat bo nho cho chuoi
    *arr = (char *)malloc(*n * sizeof(char));

    // nhap cac phan tu cho chuoi
    printf("Nhap cac phan tu cho chuoi: \n");
    int i;
    for (i = 0; i < *n; i++) {
        printf("Ph?n t? th? %d: ", i + 1);
        scanf(" %c", &(*arr)[i]); 
    }
}

// ham hien thi chuoi
void hienthichuoi(char *arr, int n) {
    printf("Cac phan tu co trong chuoi la: \n");
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

// Ham dem so luong chu cai trong chuoi
void demchucai(char *arr, int n) {
    int dem = 0;
    int i;
    for (i = 0; i < n; i++) {
        if ((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z')) {
            dem++;
        }
    }
    printf("So luong chu cai co trong chuoi la: %d\n", dem);
}

// Ham dem so luong chu so trong chuoi
void demchuso(char *arr, int n) {
    int dem = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] >= '0' && arr[i] <= '9') {
            dem++;
        }
    }
    printf("So luong chu so trong chuoi la: %d\n", dem);
}

// Ham dem ki tu dac biet trong chuoi
void demkitu(char *arr, int n) {
    int dem = 0;
    int i;
    for (i = 0; i < n; i++) {
        if ((arr[i] < '0' || arr[i] > '9') && (arr[i] < 'A' || arr[i] > 'Z') && (arr[i] < 'a' || arr[i] > 'z')) {
            dem++;
        }
    }
    printf("So ki tu dac biet trong chuoi la: %d\n", dem);
}

int main() {
    char *arr = NULL;
    int n = 0;
    int luachon;

    // In menu cho nguoi dung nhap
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Ðem so luong chu cai trong chuoi va in ra\n");
        printf("4. Ðem so luong ki tu trong chuoi in ra\n");
        printf("5. Ðem so luong ki tu dac biet in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luachon);

        switch (luachon) {
            case 1:
                nhapchuoi(&arr, &n);
                break;
            case 2:
                if (arr != NULL) {
                    hienthichuoi(arr, n);
                } else {
                    printf("Ban chua nhap chuoi!\n");
                }
                break;
            case 3:
                if (arr != NULL) {
                    demchucai(arr, n);
                } else {
                    printf("Ban chua nhap chuoi!\n");
                }
                break;
            case 4:
                if (arr != NULL) {
                    demchuso(arr, n);
                } else {
                    printf("Ban chua nhap chuoi!\n");
                }
                break;
            case 5:
                if (arr != NULL) {
                    demkitu(arr, n);
                } else {
                    printf("Ban chua nhap chuoi!\n");
                }
                break;
            case 6:
                free(arr); //giai phong bo nho
                printf("Chuong trinh ket thuc!\n");
                return 0;
            default:
                printf("Lua chon khong hop le vui long nhap lai\n");
        }
    }
	//ket thuc chuong trinh
    return 0;
}

