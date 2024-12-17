#include <stdio.h>
#include <string.h> //thu vien de lam viec voi chuoi
#include <ctype.h>  // thu vien cung cap ham de co the xu ly ki tu
#include <stdlib.h> // thu vien de co the cap nhap bo nho

// Ham nhap chuoi
void nhapChuoi(char **str) {
    //giai phong bo nho neu co
    if (*str != NULL) {
        free(*str);
    }

    // cap phat bo nho cho chuoi
    *str = (char*)malloc(100 * sizeof(char));
    printf("Nh?p chu?i: ");
    getchar();  
    fgets(*str, 100, stdin);
    (*str)[strcspn(*str, "\n")] = 0; 
}

// Ham in chuoi dao nguoc
void inDaoNguoc(char *str) {
    int len = strlen(str);
    printf("Chuôi dao nguoc: ");
    int i;
    for (i = len - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    printf("\n");
}

// Ham dem so luong tu trong chuong chuoi
int demSoLuongTu(char *str) {
    int count = 0;
    char *token = strtok(str, " "); 
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// Ham so sanh do dai chuoi
void soSanhChieuDaiChuoi(char *str1) {
    char *str2;
    nhapChuoi(&str2);
    if (strlen(str2) < strlen(str1)) {
        printf("Chuoi thu hai ngan hon chuoi ban dau\n");
    } else if (strlen(str2) > strlen(str1)) {
        printf("Chuoi thu hia dai hon chuoi ban dau\n");
    } else {
        printf("Hai chuoi co do dai bang nhau\n");
    }
    free(str2);
}

// Ham in hoa tat ca chu cai trong chuoi
void inHoaTatCa(char *str) {
    printf("Chuoi in hoa: ");
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        putchar(toupper(str[i]));
    }
    printf("\n");
}

// Ham them chuoi vao chuoi ban dau
void themChuoiVao(char **str) {
    char *str2;
    nhapChuoi(&str2);
    *str = (char*)realloc(*str, (strlen(*str) + strlen(str2) + 1) * sizeof(char));
    strcat(*str, str2);
    free(str2);
    printf("Chuoi sau khi them: %s\n", *str);
}

int main() {
    char *chuoi = NULL;
    int luachon;

    while (1) {
        printf("\n--- THUC DON ---\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac so sanh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca cac chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac them chuoi da nhap vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luachon);

        switch (luachon) {
            case 1:
                nhapChuoi(&chuoi);
                break;
            case 2:
                if (chuoi != NULL) {
                    inDaoNguoc(chuoi);
                } else {
                    printf("Ban chua nhap chuoi nao\n");
                }
                break;
            case 3:
                if (chuoi != NULL) {
                    char temp[100];
                    strcpy(temp, chuoi);  
                    int soLuongTu = demSoLuongTu(temp);
                    printf("So luong tu trong chuoi %d\n", soLuongTu);
                } else {
                    printf("Ban chua nhap chuoi nao\n");
                }
                break;
            case 4:
                if (chuoi != NULL) {
                    soSanhChieuDaiChuoi(chuoi);
                } else {
                    printf("Ban chua nhap chuoi nao.\n");
                }
                break;
            case 5:
                if (chuoi != NULL) {
                    inHoaTatCa(chuoi);
                } else {
                    printf("Ban chua nhap chuoi nao\n");
                }
                break;
            case 6:
                if (chuoi != NULL) {
                    themChuoiVao(&chuoi);
                } else {
                    printf("ban chua nhap chuoi nao\n");
                break;
            case 7:
                free(chuoi);
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon cua ban khong hop le, moi ban nhap lai\n");
        }
    }
	//ket thuc chuong trinh 
    return 0;
}
}

