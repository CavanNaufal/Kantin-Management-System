#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "headerFunction.h"



void close(){
	system("CLS");
	printf("\n\n\t-----------------------------------------------------------\n"
				"		\tRestaurant Management System 						\n"
				"		     THANK YOU FOR USING OUR PROGRAM! ^_^ 				" 									
				"\n\t-----------------------------------------------------------");
	int i;
	system("color 0A");
	printf("\n\n\n\n\n\n\n\n\t\t\t\tLoading......\n      ");
	for(i = 0; i < 65; i++){
		printf("%c", 219);
		Sleep(30);
	}
	system("CLS");
	exit(0);
}

void loadingScreen(){
	system("cls");
	printf("\n\n\t-----------------------------------------------------------\n"
				"		\tRestaurant Management System 						\n"
				"		\tKANTIN UNIVERSITAS INDONESIA 						"			
				"\n\t-----------------------------------------------------------");
	int i;
	system("color 0A");
	printf("\n\n\n\n\n\n\n\n\t\t\t\tLoading......\n      ");
	for(i = 0; i < 65; i++){
		printf("%c", 219);
		Sleep(30);
	}
	system("cls");
	printf("\n\n\n\n\n\n\n\n\t\t\t\tLoading Complete\n\n\n\n\n");
	system("color 07");
	system("pause");
}

Data inputData(){
	system("color 07");
	Data *ptrCust , Cust;
	int num;

	ptrCust = &Cust;

	Cust.ordernum = OrderID;

	printf("----------------------------|INPUT DATA|----------------------------\n");
	printf("%-15s%-1s", "Nama", ": ");
	scanf("%*c%[^\n]50s", &ptrCust->custname);
	while(1){
		printf("%-15s%-1s","Table Number", ": ");
		scanf("%s", &ptrCust->tablenum);
		num = atoi(Cust.tablenum);
		if(num > 0){
			break;
		}else{
			error();
		}
	}
	return Cust;
}

void printFoodMenu(RestMenu menus[][10]){
	int i, j;
	
	for (i = 0; i < 4; i++){
		if(i == 0)
			printf("\t\t\t-------------Dallas--------------\n");
		else if(i == 1)
			printf("\n\n\t\t\t-------------Kantek--------------");
		else if(i == 2)
			printf("\n\n\t\t\t-------------Kansas--------------");
		else if (i == 3)
			printf("\n\n\t\t\t-------------Kanjiw--------------");
		
		for(j = 0; j < 5; j++){
			printf ("\n%1d. %-18sTime : %4d,\tPrice : %7.1f,\tStock : %2d", j + 1, menus[i][j].foodname, menus[i][j].time, menus[i][j].price, menus[i][j].Available);
		}	
	}
}

void UserMenu(){
	system("cls");
	
	RestMenu makanan[][10] = {
		{{"Ayam Geprek", 15, 12000, tempStock[0][0]},
		{"Ayam Goreng", 10, 10000, tempStock[0][1]},
		{"Ikan Bakar", 20, 18000, tempStock[0][2]},
		{"Sate Ayam", 15, 15000, tempStock[0][3]},
		{"Nasi Putih", 5, 15000, tempStock[0][4]}},
		
		{{"Soto Ayam", 10, 15000, tempStock[1][0]},
		{"Soto Daging", 15, 18000, tempStock[1][1]},
		{"Tongseng", 20, 20000, tempStock[1][2]},
		{"Mie Ayam", 10, 15000, tempStock[1][3]},
		{"Telur Goreng", 5, 5000, tempStock[1][4]}},
		
		{{"Jus Melon", 130, 5000, tempStock[2][0]},
		{"Jus Alpukat", 380, 8000, tempStock[2][1]},
		{"Jus Mangga", 380, 8000, tempStock[2][2]},
		{"Es Jeruk", 247, 15000, tempStock[2][3]},
		{"Es Teh Manis", 165, 12000, tempStock[2][4]}},
		
		{{"Roti Bakar", 5, 5000, tempStock[3][0]},
		{"Martabak Manis", 10, 16000, tempStock[3][1]},
		{"Waffle", 15, 15000, tempStock[3][2]},
		{"Croffle", 15, 20000, tempStock[3][3]},
		{"Ice Cream", 15, 10000, tempStock[3][4]}}	
	};
	
	char choose[3]; 
	printf("\n\n -----------------------------------------------------------\n"
				"			User Menu			"
				"\n -----------------------------------------------------------\n"
				"\n 1. |	Customer\n 2. |	Seller Login\n 3. |	Exit\n\nMasukkan pilihan (1 - 3) : ");
	printf("\nChoose : ");
	scanf("%s", &choose);
	do{
		if(strcmp(choose, "1") == 0){
			system ("cls");
			Data diri = inputData();
			system ("cls");
			customerMenu(makanan, &diri);
		}
		else if(strcmp(choose, "2") == 0){
			login(makanan);
		}
		else if(strcmp(choose, "3") == 0){
			close();
		}
		else{
			printf("Invalid Input");
			error();
			printf("\nChoose : ");
			scanf("%s", &choose);
		}
	}while(strcmp(choose, "1") != 0 || strcmp(choose, "2") != 0 || strcmp(choose, "3") != 0);

}

void customerMenu(RestMenu makanan[][10], Data * diri){
	system("cls");
	char choice, descision[3];
	printf("\n\n -----------------------------------------------------------\n"
		"			Customer Menu			"
		"\n -----------------------------------------------------------\n"
		"\n 1. |	Lihat Menu Warung Makanan\n 2. |	Lakukan Pemesanan\n 3. |	Review order\n 4. |	Back\n\nMasukkan pilihan (1 - 4) : ");
	fflush(stdin);
	scanf("%c", &choice);
	
	switch (choice){
		case '1': 
			system ("cls");
			printFoodMenu(makanan);
			printf("\n\nApakah Anda Ingin : ");
			printf("\n1. Lakukan pemesanan\n2. Back\nPilihan: ");
			scanf("%s", &descision);

			while (strcmp(descision, "1") != 0 && strcmp(descision, "2") != 0){ 
				error();
				printf("\nPilihan: ");
				scanf("%s", &descision);	
			}

			Sleep(1000);
			system ("cls");	
		
			if(strcmp(descision, "1") == 0){	
				search_by_place(makanan, diri);
			}else if(strcmp(descision, "2") == 0){	
				customerMenu(makanan, diri);
			}								
		case '2':
			search_by_place(makanan, diri);
		case '3':
			reviewOrder(makanan, diri);
		case '4':
			UserMenu();
		default:
			error();
			customerMenu(makanan, diri);
	}
}

void login(RestMenu makanan[][10]){ 
	char username[20], userpwd[10], pilih[3];
	int i, salah; 
	system("CLS");
	printf(	"\n  +-----------------------------------+\n"
			"  |         >> SELLER LOGIN <<        |\n"
			"  +-----------------------------------+\n");
	printf("\n  Username : "); 
	scanf("%s", username); 
	printf("  Password : "); 
	for(i = 0; i < 3; i++){ 
    	userpwd[i] = getch(); //mengambil inputan user
    	printf("*"); //menampilkan * ketika input password masuk
	} 

	userpwd[i]='\0';
  	if(strcmp(username, "admin") == 0){ //membandingkan username dan password
		if(strcmp(userpwd, "123") == 0){
			printf("\n\n  Login Berhasil. Selamat datang admin!");
			Sleep(1000);
			editAvail(makanan);

		}else{
			printf("\n\n  Password yang dimasukkan salah.");
			do{
				printf ("\n  Apakah anda ingin kembali ke menu utama (yes/no)? ");
				scanf ("%s", &pilih);
				if( strcmp( pilih, "yes") == 0 ){
					system("CLS");
					UserMenu();
				}else if (strcmp( pilih, "no") == 0){
					system("CLS");
					login(makanan);
				}else { //error handling
					printf("\n  Input yang ada masukkan tidak ada");
					salah = 1;
				}
			}while(salah == 1);
		}
	}else { //jika username tidak sesuai
		printf("\n\n  User tidak ditemukan.");
		do{
			printf ("\n  Apakah anda ingin kembali ke menu utama (yes/no)?");
			scanf ("%s", &pilih);
			if( strcmp( pilih, "yes") == 0 ){
				system("CLS");
				UserMenu();
			}else if (strcmp( pilih, "no") == 0){
				system("CLS");
				login(makanan);
			}else {
				printf("\n  Input yang ada masukkan tidak ada");
				salah = 1;
			}
		}while(salah == 1);
    }
}

void editAvail(RestMenu makanan[][10]){
	system("CLS");
	int choice;
	printf("\n\n -----------------------------------------------------------\n"
		"			User Admin			"
		"\n -----------------------------------------------------------\n");
	printf("\n 1. |	Dallas\n 2. |	Kantek\n 3. |	Kansas\n 4. |	Kanjiw\n 5. |	Main Menu\n\nMasukkan pilihan (1 - 5) : ");
	printf("Select the warung : ");
    scanf("%d", &choice);
    if (choice > 5 || choice < 1) {
        printf("\nPlease Enter the valid choice\n\n");
        editAvail(makanan);
    }
    else if (choice == 5){
        system("cls");
        UserMenu();
    }
	
    else
        editFood(choice, makanan);
}

void editFood(int choice, RestMenu menus[][10]){
	system("CLS");
	int j, food_choice, pilih;
	int i = choice - 1; //0

	printf("\n\n -----------------------------------------------------------\n"
		"			Edit Menu Stock			"
		"\n -----------------------------------------------------------\n");
	for (j = 0; j < 5; j++){
		printf ("\n%1d. %-18s", j + 1, menus[i][j].foodname);
	}

	printf("\n6. Back");
    printf("\nPlease Enter Your Choice\t: ");
    scanf("%d", &food_choice);
	system("cls");
	
	if (food_choice > 0 && food_choice < 6){
		printf("\n-------------------------- Edit Stock of %s--------------------------\n");
		printf("Food Name : %s\t", menus[i][food_choice - 1].foodname);
		printf("\nStock : %d\t", tempStock[i][food_choice - 1]);
		printf("\nEdit Stock : ");
		scanf("%d", &tempStock[i][food_choice - 1]);

		system("cls");
		printf("\n-------------------------- Edit Stock of %s--------------------------\n");
		printf("Food Name : %s\t", menus[i][food_choice - 1].foodname);
		printf("\nStock : %d\t", tempStock[i][food_choice - 1]);
		printf("\n1. Back\n2. Main Menu\n");
		printf("Pilihan : ");
		scanf("%d", &pilih);
		do{
			if (pilih == 1){
				system("cls");
				editFood(choice, menus);
			}
			else if (pilih == 2){
				system("cls");
				UserMenu();
		}
		}while(pilih != 1 || pilih != 2);
	}
	else if (food_choice == 6) {
        editAvail(menus);
    }
    else {
        printf("Please Enter the valid Choice\n\n");
		error();
		editFood(choice, menus);
    }
}

void search_by_place(RestMenu menus[][10], Data * diri)
{
    int choice;
    system("cls");
    printf(     "\n\n -----------------------------------------------------------\n"
				"			Warung Makan			"
				"\n -----------------------------------------------------------\n"
				"\n 1. |	Dallas\n 2. |	Kantek\n 3. |	Kansas\n 4. |	Kanjiwn\n 5. |	Review Order\n 6. |	Back\n\nMasukkan pilihan (1 - 6) : ");
    printf("Select the warung : ");
    scanf("%d", &choice);
    if (choice > 6 || choice < 1) {
        printf("\nPlease Enter the valid choice\n\n");
		error();
        search_by_place(menus, diri);
    }
	else if (choice == 5) {
		system("cls");
		reviewOrder(menus, diri);
	}
    else if (choice == 6){
        system("cls");
        customerMenu(menus, diri);
    }
    else
        place(choice, menus, diri);
}

// Function to implement the hotel
void place(int place_choice, RestMenu menus[][10], Data * diri)
{	
    int food_choice, n, j;
    while (1) {
        system("cls");

        printf("\n\nList of foods available");
        
        int i = place_choice - 1;
        for (j = 0; j < 5; j++){
			printf ("\n%1d. %-18sTime : %4d,\tPrice : %7.1f,\tStock : %2d", j + 1, menus[i][j].foodname, menus[i][j].time, menus[i][j].price, menus[i][j].Available);
		}
		
		printf("\n6. Cart\n7. Back");
        printf("\nPlease Enter Your Choice\t: ");
        scanf("%d", &food_choice);
        
        if (food_choice != 6 && food_choice != 7 && food_choice > 0 && food_choice < 6){
			do{
				if (menus[i][food_choice - 1].Available == 0){
					printf("Sorry, %s is not available\n", menus[i][food_choice - 1].foodname);
					system("pause");
					break;
				}
				printf("Please Enter the Count of %s : ", menus[i][food_choice - 1].foodname);
				scanf("%d", &menus[i][food_choice - 1].n);
				
				if (menus[i][food_choice - 1].n > menus[i][food_choice - 1].Available){
					printf("Sorry, the stock is not enough\n");
				}
			}while (menus[i][food_choice - 1].n > menus[i][food_choice - 1].Available);

			if(menus[i][food_choice - 1].Available > 0){
				tempStock[i][food_choice - 1] = tempStock[i][food_choice - 1] - menus[i][j].n;
				menus[i][food_choice - 1].Available = tempStock[i][food_choice - 1];
				check[i][food_choice - 1] = 1;
			}
		}
		else if (food_choice == 6) {
			cart(menus, diri, check);
		}
		else if (food_choice == 7) {
			search_by_place(menus, diri);
		}
		else {
			printf("Please Enter the valid Choice\n\n");
			error();
			place(place_choice, menus, diri);
		}
	}
}

void cart(RestMenu menus[][10], Data * diri, int check [][5])
{
    system("cls");
    int i, j, time = 0, confirm, sum = 0;
	float total = 0.0, money, change, avgTime;
	char ch[4];
	for(i = 0; i < 4; i++){
		for(j = 0; j < 5; j++){
			if(check [i][j] == 1){
				
				total = total + (menus[i][j].n * menus[i][j].price);
				sum = sum + menus[i][j].n;
				time = time + (menus[i][j].time * menus[i][j].n);
			}
		}
	}

	if (time > 0){
		avgTime = time / sum;
	}

    printf("\n--------------Cart----------------");
    printf("\nYour Total Order Amount is %s%.0f\n", "Rp. ", total);
    printf("\n\nDo You wish to order (yes/no): ");
    scanf("%s", &ch);
    if (strcmp( ch, "yes") == 0) {
		do{
			printf("Input money : Rp. ");
			scanf("%f", &money);
			if (money < total){
				printf("Sorry, your money is not enough\n");
			}
		}while (money < total);

		change = money - total;
		system("cls");
		struk(sum, diri, menus, money, change, avgTime, total, check);

        system("pause");
        UserMenu(menus, diri);
    }
    else if (strcmp( ch, "no") == 0) {
        printf("Do You want to Main Menu (1) or Go back (0) : ");
        scanf("%d", &confirm);
        if (confirm == 1) {
            printf("\n\nOops! Your order is cancelled!! Exiting..");
			for(i = 0; i < 4; i++){
				for(j = 0; j < 5; j++){
				check[i][j] = 0;
				}
			}
			tempStock[i][j] = tempStock[i][j] + menus[i][j].n;
            UserMenu();
        }
        else {
            printf("\n\nThank You\n\n");
            search_by_place(menus, diri);
        }
    }
    else {
        printf("\n\nPlease Enter the correct choice\n\n");
		error();
        cart(menus, diri, check);
    }
}

void struk(int jmlhPesanan, Data * diri, RestMenu makanan[][10],float bayar, float kembali, float time, float total, int check[][5]){
	int i, j, k = 1;
	OrderID = OrderID + 1;
	printf("\n--------------- KANTIN UNIVERSITAS INDONESIA ---------------\n\n");
	printf("Order ID\t\t\t\t: %d\n", diri->ordernum);
	printf("Nama Customer\t\t\t\t: %s\n", diri -> custname);
	printf("Nomor Meja\t\t\t\t: %s\n", diri -> tablenum);
	printf("Total Pesanan\t\t\t\t: %d\n", jmlhPesanan);
	printf("Waktu Menunggu\t\t\t\t: %.1f Menit\n", time);
	printf("---------------------------------------------------------------------------------\n");
	printf("%-14s%-20s%-15s%-20s\n", "No. Pesanan", "Nama Produk", "Harga Produk", "Jumlah Pesanan");
	for(i = 0; i < 4; i++){
		for(j = 0; j < 5; j++){
			if(check[i][j] == 1){
			printf("%-14d%-20s", k, makanan[i][j].foodname);
			printf("Rp. %-15.0f", makanan[i][j].price);	
			printf("%-22d\n", makanan[i][j].n);
			k++;
			}
		}
	}		
	printf("---------------------------------------------------------------------------------\n");
	printf("%9s%65s%6.3f\n","Total", "Rp. ", total);
	printf("%9s%65s%6.3f\n","Tunai", "Rp. ", bayar);
	printf("%9s%65s%6.3f\n","Kembali", "Rp. ", kembali);
	printf("---------------------------------------------------------------------------------\n");
	printf("\n\nYour Order is Confirmed");
	printf("\n\nThank You for your order!! Your Food is on the way. Welcome again!!\n\n");

	for(i = 0; i < 4; i++){
		for(j = 0; j < 5; j++){
			check[i][j] = 0;
		}
	}
	
}


void reviewOrder(RestMenu makanan[][10] , Data * diri){
	int i, j, k = 1, n = 0, time = 0, choose, x;
	float avgTime = 0.0;
	system("cls");
	printf("------------------------------------ ORDER --------------------------------------\n");
	printf("---------------------------------------------------------------------------------\n");
	printf("%-14s%-20s%-15s%-20s\n", "No. Pesanan", "Nama Produk", "Harga Produk", "Jumlah Pesanan");
	for(i = 0; i < 4; i++){
		for(j = 0; j < 5; j++){
			if(check[i][j] == 1){
			x = makanan[i][j].time * makanan[i][j].n;
			n = n + makanan[i][j].n;
			time = time + x;
			printf("%-14d%-20s", k, makanan[i][j].foodname);
			printf("Rp. %-15.0f", makanan[i][j].price);	
			printf("%-22d\n", makanan[i][j].n);
			k++;
			}
		}
	}
	if (time > 0){
		avgTime = time / n;
	}
	

	printf("---------------------------------------------------------------------------------\n");
	printf("Nama Customer\t\t\t\t: %s\n", diri -> custname);
	printf("Nomor Meja\t\t\t\t: %s\n", diri -> tablenum);
	printf("Total Pesanan\t\t\t\t: %d\n", n);
	printf("Waktu Menunggu\t\t\t\t: %.1f Menit\n", avgTime);
	printf("---------------------------------------------------------------------------------\n");	

	printf("1. Cart\n2. Warung Makan\n3. Back\n");
	printf("Choose : ");
	scanf("%d", &choose);
	if(choose == 1){
		cart(makanan, diri, check);
	}
	else if (choose == 2){
		search_by_place(makanan, diri);
	}
	else if(choose == 3){
		customerMenu(makanan, diri);
	}
	else{
		printf("Please enter the correct choice\n");
		reviewOrder(makanan, diri);
	}
}

void error(){
	system("color 74");
	printf("\n\aError!\n");
	Sleep(500);
	system("color 07");
}

void helpdesk(){
	int i;
	char arr [35][300] =
	{	"  >> Menu Utama <<",
		"  1. Pilihlah menu yang diinginkan sesuai nomor ",
		"    - Menu 1 adalah halaman kumpulan berita ",
		"    - Menu 2 adalah halaman login untuk admin ",
		"    - Menu 3 adalah halaman panduan program",
		"    - Menu 4 program akan keluar ",
		" ",
		"  >> Menu 1 <<",
		"  1. Pilihlah menu yang diinginkan sesuai nomor ",
		"  2. Program akan menampilkan kumpulan berita ",
		"  3. Terdapat fungsi untuk berpindah halaman, mencari berita, dan mengurutkan berita ",
		"  4. Pilihlah fungsi yang diinginkan sesuai nomor ",
		"	  - Pilihan 1 untuk berpindah halaman selanjutnya ",
		"	  - Pilihan 2 untuk berpindah halaman sebelumnya ",
		"	  - Pilihan 3 untuk mencari berita berdasarkan judul, topik, tanggal, dan penulis. Lalu dapat menuju link yang dituju ",
		"	  - Pilihan 4 untuk mengurutkan (Angka-Kapital-Huruf Kecil) berita berdasarkan judul, topik, tanggal, dan penulis ",
		"	  - Pilihan 5 untuk kembali pada menu utama ",
		" ",
		"  >> Menu 2 <<",
		"  Username : admin ; Password : 123 ; Restore Key : 12345 ",
		"  1. Program akan meminta untuk memasukkan username dan password ",
		"  2. Jika sesuai maka akan berpindah pada halaman editorial ",
		"  3. Terdapat 5 pilihan fungsi. Pilihlah fungsi yang diinginkan sesuai nomor ",
		"	  - Pilihan 1 berfungsi untuk menambah berita ",
		"	  - Pilihan 2 berfungsi untuk mengedit berita ",
		"	  - Pilihan 3 berfungsi untuk menghapus berita ",
		"	  - Pilihan 4 berfungsi untuk mengembalikan berita yang ada ke default ",
		"	  - Pilihan 5 untuk kembali pada menu utama ",
		" ",
		"  >> Menu 3 <<",
		"  Program akan menampilkan panduan program E-News Management",
		" ",
		"  >> Menu 4 <<",
		"  Program akan keluar. ",
	};
	printf(	" \n  +----------------------------------+\n"
				"  |        >> MENU HELPDESK <<       |\n"
				"  +----------------------------------+\n\n");

	for ( i = 0; i < 35; i++){ //output
		printf("%s\n", arr[i]);
	}
	system("pause");
}