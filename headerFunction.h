#ifndef HEADERFUNCTION_H_
#define HEADERFUNCTION_H_

//Manu Makanan
typedef struct{
    char foodname[50];
    int time;   
    float price;
    int Available;
	int n;
}RestMenu;

//Pelanggan
typedef struct{
    char custname[50];
    char tablenum[10];
    int ordernum;  
}Data;

//variabel global
int tempStock[4][5] = {{1,2,2,3,4},{2,1,3,4,9},{2,4,5,1,3},{3,1,2,5,6}};
int check[4][5] = {0};
int OrderID = 1;

//function prototype
void loadingScreen();
void helpdesk();
void editFood(int choice, RestMenu makanan[][10]);
void editAvail(RestMenu makanan[][10]);
Data inputData();
void printFoodMenu(RestMenu menus[][10]);
void login(RestMenu makanan[][10]);
void search_by_place(RestMenu menus[][10], Data * diri);
void place(int place_choice, RestMenu menus[][10], Data  * diri);
void cart(RestMenu menus[][10], Data * diri, int check [][5]);
void error();
void UserMenu();
void customerMenu(RestMenu makanan[][10], Data * diri);
void struk(int jmlhPesanan, Data * diri, RestMenu makanan[][10], float bayar, float kembali, float time, float total, int check[][5]);
void reviewOrder(RestMenu makanan[][10] , Data * diri);
void close();

#endif