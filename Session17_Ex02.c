#include <stdio.h>
#include <stdlib.h> // chua cac ham cap phat va giai phong bo nho 

//tao ham nhap mang
void nhapMang(int **arr, int *n) {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", n);

    // cap phat bo nho cho mang 
    *arr = (int *)malloc(*n * sizeof(int));

    printf("Nhap cac phan tu:\n");
    int i;
    for (i = 0; i < *n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &(*arr)[i]); // nhap tung phan tu cho mang 
    }
}

// ham hien thi mang 
void hienThiMang(int *arr, int n) {
    printf("Cac phan tu trong mang la:\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ham tinh tong cac phan tu trong mang 
int tinhTong(int *arr, int n) {
    int tong = 0;
    int i;
    for (i = 0; i < n; i++) {
        tong += arr[i]; //cong tung phan tu trong mang
    }
    return tong;
}

//ham tim phan tu lon nhat trong mang
int timMax(int *arr, int n) {
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i]; //cap nhap max neu phan tu lon hon
        }
    }
    return max;
}

int main() {
    int *arr = NULL;
    int n = 0;
    int luaChon;

    do {
        //hien thi menu cho nguoi dung nhap
        printf("\n--- THUC DON ---\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
            	// ham goi mang
                nhapMang(&arr, &n); 
                break;

            case 2:
                if (arr != NULL) {
                    hienThiMang(arr, n); // goi ham hien thi mang 
                } else {
                    printf("Mang chua duoc nhap.\n");
                }
                break;

            case 3:
                if (arr != NULL) {
                    printf("Do dai mang: %d\n", n); // in do dai mang 
                } else {
                    printf("Mang chua duoc nhap.\n");
                }
                break;

            case 4:
                if (arr != NULL) {
                    printf("Tong cac phan tu trong mang: %d\n", tinhTong(arr, n)); //goi ham tinh tong 
                } else {
                    printf("Mang chua duoc nhap.\n");
                }
                break;

            case 5:
                if (arr != NULL) {
                    printf("Phan tu lon nhat trong mang: %d\n", timMax(arr, n)); //gia tri max
                } else {
                    printf("Mang chua duoc nhap.\n");
                }
                break;

            case 6:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le, vui long chon lai.\n");
        }

    } while (luaChon != 6);

    if (arr != NULL) {
        free(arr); //giai phong bo nho va ket thuc
    }
    return 0;
}

