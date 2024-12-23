#include<stdio.h>
struct Product {
    char id[20];
    char name[100];
    float costPrice;
    float sellingPrice;
    int quantity;
};
struct Product products[100];
int numProducts;

void inputProduct() {
    struct Product product;
    printf("Nhap ma san pham: ");
    scanf("%s", product.id);
    int found = 0;
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].id, product.id) == 0) {
            found = 1;
            printf("San pham da ton tai. Cap nhat so luong.\n");
            printf("Nhap so luong: ");
            int additionalQuantity;
            scanf("%d", &additionalQuantity);
            products[i].quantity += additionalQuantity;
            printf("So luong san pham sau khi cap nhat: %d\n", products[i].quantity);
            break;
        }
    }

    if (!found) {
        printf("Nhap ten san pham: ");
        getchar();
        fgets(product.name, sizeof(product.name), stdin);
        product.name[strcspn(product.name, "\n")] = 0;
         printf("Nhap gia nhap: ");
        scanf("%f", &product.costPrice);

        printf("Nhap gia ban: ");
        scanf("%f", &product.sellingPrice);

        printf("Nhap so luong: ");
        scanf("%d", &product.quantity);
         products[numProducts] = product;
        numProducts++;
        void displayProducts() {
    if (numProducts == 0) {
        printf("Chua co san pham trong danh sach!\n");
        return;
    }

    printf("\nDanh sach san pham:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("Ma san pham: %s\n", products[i].id);
        printf("Ten san pham: %s\n", products[i].name);
        printf("Gia nhap: %.2f\n", products[i].costPrice);
        printf("Gia ban: %.2f\n", products[i].sellingPrice);
        printf("So luong: %d\n", products[i].quantity);
        printf("----------------------------\n");
    }
}
void updateProduct() {
    char id[20];
    printf("Nhap ma san pham can cap nhat: ");
    scanf("%s", id);

    int found = 0;
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].id, id) == 0) {
            found = 1;
            printf("Cap nhat thong tin cho san pham %s:\n", products[i].name);
            printf("Nhap ten san pham: ");
            getchar();
            fgets(products[i].name, sizeof(products[i].name), stdin);
            products[i].name[strcspn(products[i].name, "\n")] = 0;
            printf("Nhap gia nhap: ");
            scanf("%f", &products[i].costPrice);

            printf("Nhap gia ban: ");
            scanf("%f", &products[i].sellingPrice);

            printf("Nhap so luong: ");
            scanf("%d", &products[i].quantity);

            printf("Thong tin san pham da duoc cap nhat!\n");
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay san pham voi ma: %s\n", id);
    }
}
void displayMenu() {
    printf("\nMENU\n");
    printf("1. Nhap so luong va thong tin san pham\n");
    printf("2. Hien thi danh sach san pham\n");
    printf("3. Nhap san pham\n");
    printf("4. Cap nhat thong tin san pham\n");
    printf("5. Sap xep san pham theo gia (tang/gi?m)\n");
    printf("6. Tim kiem san pham\n");
    printf("7. Ban san pham\n");
    printf("8. Doanh thu hien tai\n");
    printf("9. Thoat\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                inputProduct();
                break;
            case 4:
                updateProduct();
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            case 7:
                
                break;
            case 8:
                
                break;
            
                
                
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }

    } while (choice != 9);

    return 0;
}