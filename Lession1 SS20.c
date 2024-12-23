#include<stdio.h>
struct book{
	int id;
	char name[50];
	char author[50];
	float price;
	char category[50];
};
struct book Books[100];
int num = 0;
void inputBook(){
	struct book Sach;
	printf("Nhap ma sach: ");
	scanf("%d", &Sach.id);
	printf("Nhap ten sach: ");
	fgets(Sach.name, sizeof(Sach.name),stdin);
	getchar();
	printf("Nhap ten tac gia: ");
	fgets(Sach.author,sizeof(Sach.author),stdin);
	getchar();
    printf("Nhap gia sach: ");
    scanf("%f", Sach.price);
    printf("Nhap the loai: ");
    fgets(Sach.category, sizeof(Sach.category), stdin);
    getchar();
    
    Books[num]=Sach;
    num++;
  
}
void displayBook(){
	if(num==0){
		printf("Danh sach chua co sach");
		return;
	}else{
		printf("         Danh sach sach \n");
		for(int i = 0; i<num; i++){
			printf("Ma sach: %d\n", Books[i].id);
			printf("Ten sach: %s\n", Books[i].name);
			printf("Ten tac gia: %s\n", Books[i].author);
			printf("Gia sach: %d\n", Books[i].price);
			printf("The loai: %s\n", Books[i].category);
			
		}
		
	}
}
void addBook(){
	int a;
	printf("Nhap vi tri muon them sach: ");
	scanf("%d", &a);
	if(a<0 || a>num){
		printf("Vi tri khong hop le");
		
	}
	
	struct book Sach;
	printf("Nhap ma sach: ");
	scanf("%d", &Sach.id);
	printf("Nhap ten sach: ");
	fgets(Sach.name, sizeof(Sach.name),stdin);
	getchar();
	printf("Nhap ten tac gia: ");
	fgets(Sach.author,sizeof(Sach.author),stdin);
	getchar();
    printf("Nhap gia sach: ");
    scanf("%f", Sach.price);
    printf("Nhap the loai: ");
    fgets(Sach.category, sizeof(Sach.category), stdin);
    getchar();
    for(int i = num; i>a; i--){
    	Books[i]=Books[i-1];
	}
	Books[num]=Sach;
	num++;
}
void DeleteBook(){
	int id;
	printf("Nhap ma sach muon xoa: ");
	scanf("%d", &id);
	int found = 0;
	for(int i = 0; i<num; i++){
		if(strcmp(Books[i].id,id)==0){
			found=1;
			for(int j = 0;j<num;j++){
				Books[i]=Books[i+1];
				
			}
			num--;
			break;
		}
	}
	if(!found){
		printf("Khong tim thay sach");
	}
}
void updated(){
	int id;
	printf("Nhap ma sach muon cap nhat: ");
	scanf("%d", &id);
	int found =  0;
	for(int i = 0; i<num; i++){
		if(strcmp(Books[i].id,id)==0){
			found = 1;
			
			printf("Nhap ma sach cap nhat: ");
	scanf("%d", &Books[i].id);
	printf("Nhap ten sach cap nhat: ");
	fgets(Books[i].name, sizeof(Books[i].name),stdin);
	getchar();
	printf("Nhap ten tac gia cap nhat: ");
	fgets(Books[i].author,sizeof(Books[i].author),stdin);
	getchar();
    printf("Nhap gia sach cap nhat: ");
    scanf("%f", Books[i].price);
    printf("Nhap the loai cap nhat: ");
    fgets(Books[i].category, sizeof(Books[i].category), stdin);
    getchar();
    break;
		}
	}
	
	if(!found){
		printf("Khong tim thay sach");
	}
	
}
void displayMenu() {
    printf("\nMENU\n");
    printf("1. Nhap so luong va thong tin sach\n");
    printf("2. Hien thi thong tin sach\n");
    printf("3. Them sach vao vi tri\n");
    printf("4. Xoa sach theo ma sach\n");
    printf("5. Cap nhat thong tin sach theo ma sach\n");
    printf("6. Sap xep sach theo gia (tang/gi?m)\n");
    printf("7. Tim kiem sach theo ten sach\n");
    printf("8. Thoat\n");
}
int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputBook();
                break;
            case 2:
                displayBook();
                break;
            case 3:
                addBook();
                break;
            case 4:
                DeleteBook();
                break;
            case 5:
                updated();
                break;
            case 6:
                
                break;
            case 7:
                
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }

    } while (choice != 8);

    return 0;
}



