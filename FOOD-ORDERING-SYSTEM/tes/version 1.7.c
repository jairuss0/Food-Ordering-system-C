#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#define MAX 100


void mainMenu(); // main menu of the system
int login(); // login process

// staff menu functions
void staffMenu(); 

// staff order main menu 
void staffOrderMenuDays();
// staff days order menu
void mon_order_menu();
void tues_order_menu();

// staff view order history main menu
void staffViewOrderHistory();
// staff days view order history menu
void mon_order_history();
void tues_order_history();


// admin - START menu
void adminMenu();

// admin - ADD menu section
void adminAddMenuItems();
void mon_add_menu(); 
void add_food_monday();
void add_beverage_monday();
void tues_add_menu(); 
void add_food_tuesday();
void add_beverage_tuesday();

// admin - VIEW menu functions
void adminViewItems();
void mon_view_menu();
void tues_view_menu();

// admin - SALES REPORT functions
void adminSalesReport();
void mon_sales_report();
void tues_sales_report();

void weekly_sales_report();
void week_1();
void week_2();
void week_3();
void week_4();


void monthly_sales_report();
void jan_report();
void feb_report();
void mar_report();
void apr_report();
void may_report();
void jun_report();
void jul_report();
void aug_report();
void sept_report();
void oct_report();
void nov_report();
void dec_report();

// admin - EDIT function
void adminUpdateMenuItems();
void mon_edit_menu();
void edit_food_monday();
void edit_beverage_monday();
void tues_edit_menu();
void edit_food_tuesday();
void edit_beverage_tuesday();

// admin - DELETE item function
void adminDeleteMenuItems();
void mon_delete_menu();
void delete_food_monday();
void delete_beverage_monday();
void tues_delete_menu();
void delete_food_tuesday();
void delete_beverage_tuesday();


void loadingScreen();
void gotoxy(int x, int y); // coordinates of the output


// MAIN FUNCTION
int main(){
	
	mainMenu();
	return 0;
}


// MAIN MENU INTERFACE //
void mainMenu(){
	
	fflush(stdin);
	system("cls"); // CLEARS OUTPUT INTERFACE
	

	int type;
	
	gotoxy(39,10);
	printf("\t===============================\n");
	gotoxy(39,12);
	printf("\t||      BELINDA'S EATERY     ||\n");
	gotoxy(39,14);
	printf("\t===============================");
	
	gotoxy(40,17);
	printf("Press ANY KEY TO CONTINUE >>>>>");
	
	getch();
	fflush(stdin);
	
	system("cls");
	
	// proceeds to log in interface
	type = login();  // assign the return value of login function to type variable
	
	// evaluates the value of type
	switch(type){
		case 1:
			system("cls");
			gotoxy(39,10);		
			loadingScreen();
			staffMenu();
			break;
		case 2:
			system("cls");
			gotoxy(39,10);
			loadingScreen();
			adminMenu();
			break;
			
	}
	
	
}



// LOG IN FUNCTION //
int login(){
	

	char staff_user[][50] = {"staff"};
	char staff_pass[][50] = {"staff123"};
	
	char admin_user[][50] = {"admin"};
	char admin_pass[][50] = {"admin123"};
	
	// size of array
	int size = sizeof(staff_user)/sizeof(staff_user[0]);
	
	// user input
	char username[50];
	char password[50];
	
	
	int checkuserStaff;
	int checkpassStaff;
	int checkuserAdmin;
	int checkpassAdmin;
	
	// for log-in attempts
	int log_attempts = 0;
	
	do{
		
		system("cls");
		
		gotoxy(39,10);	printf("\t============================\n");
		gotoxy(39,11);	printf("\t||	   LOG IN	  ||\n");
		gotoxy(39,12);	printf("\t============================");
	
		gotoxy(39,14);
		printf("\tUsername: ");
		scanf("%[^\n]s",&username);
		fflush(stdin); // clear buffer 
		
		gotoxy(39,15);
		printf("\tPassword: ");
		scanf("%[^\n]s",&password);
		fflush(stdin);
		
		
		for(int i = 0; i < size; i++){
			
			checkuserStaff = strcmp(username,staff_user[i]);
			checkpassStaff = strcmp(password,staff_pass[i]);
			
			checkuserAdmin = strcmp(username,admin_user[i]);
			checkpassAdmin = strcmp(password,admin_pass[i]);
			
			if(checkuserStaff == 0 && checkpassStaff == 0){
				return 1;
				log_attempts = 0;
				
			}
			else if(checkuserAdmin == 0 && checkpassAdmin == 0){
				return 2;
				log_attempts = 0;
				
			}else{
				log_attempts++;
				gotoxy(39,19);
				printf("\tINVALID USERNAME AND PASSWORD!\n");
				gotoxy(39,22);
				printf("\tPress ANY KEY to continue.\n");
				gotoxy(68,22);
				getch();
				break;
			}			
			
		}
		
		// log-in attempts 
		if(log_attempts == 5){
			
			system("cls");
			
			for(int i = 5; i >=1; i--){
				gotoxy(39,10);
				printf("\tTOO MANY ATTEMPTS!");
				gotoxy(39,12);
				printf("\tTry Again in: ");
				usleep(900000);
				printf(" %d",i);
				fflush(stdin);
				
			}
			
			mainMenu(); // goes back to the main menu after timer ends
			break;
		}
	
	
		
		
	}while(log_attempts != 5);
	
	
	
	
	
	
}



//STAFF INTERFACE MENU // 
void staffMenu(){
	
	system("cls");
	
	int staff_choice;
	int validation;
	
	gotoxy(8,1); 

		
	gotoxy(39,5);	
	printf("===============================");
	gotoxy(39,6);	
	printf("||	STAFF INTERFACE     ||");
	gotoxy(39,7);	
	printf("===============================");
	gotoxy(39,9);
	printf("PRESS [1] ORDER");
	gotoxy(39,10);
	printf("PRESS [2] VIEW ORDERS");
	gotoxy(39,11);
	printf("PRESS [3] LOGOUT");
	gotoxy(39,13);
	printf("==============================");
	
	
	// implement input validation here ---//
	gotoxy(39,14);
	do{
		gotoxy(39,14);
		printf("SELECT: ");
		if(scanf("%d",&staff_choice) != 1 || staff_choice <= 0 || staff_choice >=4){
			gotoxy(39,16);
			printf("INVALID INPUT!");
			fflush(stdin);
			validation = 0;
		}else{
			validation = 1;
		}	
		
	}while(!validation || staff_choice <= 0 || staff_choice >= 4);
	fflush(stdin); // buffer to avoid invinsible characters that unnecessarily scanf fetching
	
	
	// proceed to menu if the validation is correct
	switch(staff_choice){
		case 1:
			staffOrderMenuDays();
			break;
		case 2:
			staffViewOrderHistory();
			break;
		case 3:
			system("cls");
			gotoxy(39,10);
			loadingScreen();
			mainMenu();
			break;
	}
}


// STAFF - MENU OF THE DAY ORDER //
void staffOrderMenuDays(){
	
	system("cls");
	
//	int isDigit;
//	int n_items;
    int validation;
	int select_menu_day;

	gotoxy(0,1);printf("SELECT 0 to go back to menu <<<<");
	
	gotoxy(39,4);	printf("=============================");
	gotoxy(39,5);	printf("|| CHOOSE MENU OF THE DAY ||");
	gotoxy(39,6);	printf("=============================");
	
	
	gotoxy(39,9); printf("[1] Monday    	MENU\n");
	gotoxy(39,10);printf("[2] Tuesday	MENU\n");
	gotoxy(39,11);printf("[3] Wednesday 	MENU\n");
	gotoxy(39,12);printf("[4] Thursday  	MENU\n");
	gotoxy(39,13);printf("[5] Friday    	MENU\n");
	gotoxy(39,14);printf("[6] Saturday  	MENU");
	// implement input validation here ---//
	gotoxy(39,16);
	do{
		gotoxy(39,16);
		printf("SELECT: ");
		if(scanf("%d",&select_menu_day) != 1 || select_menu_day < 0 || select_menu_day >=7){
			gotoxy(39,18);
			printf("INVALID INPUT!");
			fflush(stdin);
			validation = 0;
		}else{
			validation = 1;
		}	
		
	}while(!validation || select_menu_day <  0 || select_menu_day >= 7);
	fflush(stdin); // buffer to avoid invinsible characters that unnecessarily scanf fetching
	
	switch(select_menu_day){
		case 0:
			system("cls");
			gotoxy(39,10);		
			loadingScreen();
			staffMenu();
			break;
		case 1:
			mon_order_menu();
			break;
		case 2:
			tues_order_menu();
			break;
 		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			break;
			
	}
	
}
// STAFF - *MONDAY* MENU OF THE DAY ORDER //
void mon_order_menu(){
	
	system("cls");
	
	char y_n; // yes or no to get the order or add more
	char proceed;
	int cash_payment; // customer payment
	float change; // change of customer payment
	float overall_total; // get the total of food and beverage orders
	
	int FOOD_number_order_times = 0; // the count of order if the customer proceed to order more
	int BEV_number_order_times = 0;	// the count of order if the customer proceed to order more
	
	// MONDAY FOOD MENU BUFFERS
	char food_name[MAX][MAX];
	char food_status[MAX];
	float food_price;
	float food_get_price[MAX];
	int food_id;
	
	char food_get_name[MAX][MAX]; // array to store the order of the customer
	int food_quantity_per_item[MAX]; // array to store the quantity of certain ordered item
	
	int food_choice, food_quantity; 
	float food_subtotal[MAX], food_total;
	int food_position = 0;
	int food_order_id = 1;

	
	// MONDAY BEVERAGE MENU BUFFERS
	char bev_name[MAX][MAX];
	char bev_status[MAX];
	float bev_price;
	float bev_get_price[MAX];
	int bev_id;
	
	char bev_get_name[MAX][MAX]; // array to store the order of the customer
	int bev_quantity_per_item[MAX]; // array to store the quantity of certain ordered item
	
	int bev_choice, bev_quantity; 
	float bev_subtotal[MAX], bev_total; 
	int bev_position = 0;
	int bev_order_id = 1;

	// --- ORDERING PROCESS ---- //
	do{
		
	system("cls");
		
	// BODY OF THE MENU ///
	gotoxy(39,1);
	printf("|| ========== BELINDA'S EATERY ========== ||\n");
	
	// DISPLAY MONDAY FOOD MENU 
	FILE *monday_menu_F = fopen("monday_menu_F.txt","r");
	gotoxy(12,4);
	printf(" ~~~~~ FOOD MENU ~~~~~~ ");
	gotoxy(3,5);
	printf("==============================================");
	gotoxy(3,6);
	printf("ID\tITEM NAME\t\tPRICE\tSTATUS\n");
	gotoxy(3,7);
	printf("==============================================");
	while(fscanf(monday_menu_F,"%d %[^\n]%*c %f %[^\n]%*c",&food_id,food_name[food_position],&food_price,food_status) != EOF){
		gotoxy(3,8+food_order_id);
		printf("[%d]\t%-20s\t%5.2f\t%4s\n",food_id,food_name[food_position],food_price,food_status);
	
		food_get_price[food_position] = food_price;
		food_order_id++;
		food_position++;
	
		
	}
	
	food_order_id = 1; // resets the value of the order ID y axis
	fclose(monday_menu_F);
	

	// DISPLAY MONDAY BEVERAGE MENU
	FILE *monday_menu_B = fopen("monday_menu_B.txt","r");
	gotoxy(75,4);
	printf(" ~~~~~ BEVERAGE MENU ~~~~~~ ");
	gotoxy(62,5);
	printf("===================================================");
	gotoxy(62,6);
	printf("ID\tITEM NAME\t\tPRICE\tSTATUS\n");
	gotoxy(62,7);
	printf("===================================================");
	while(fscanf(monday_menu_B,"%d %[^\n]%*c %f %[^\n]%*c",&bev_id,bev_name[bev_position],&bev_price,bev_status) != EOF){
		gotoxy(62,8+bev_order_id);
		printf("[%d]\t%-20s\t%5.2f\t%4s\n",bev_order_id,bev_name[bev_position],bev_price,bev_status);
		bev_get_price[bev_position] = bev_price;
		bev_order_id++;
		bev_position++;
	}
	
	bev_order_id = 1;	// resets the value of the order ID y axis
	fclose(monday_menu_B);
	
	printf("\n");		
	// ---  START ORDERING PROCESS ---- //
		int validation;
		char food_or_bev;
		
		gotoxy(3,20);
		printf("-Choose Category to order-");
		gotoxy(3,21);
		printf("input 'F' - Food");
		gotoxy(3,22);
		printf("input 'B' - beverage");
		gotoxy(3,23);
		scanf("%c",&food_or_bev);
		food_or_bev = toupper(food_or_bev);
		fflush(stdin);
		
		// FOOD - ORDERING PROCESS
		if(food_or_bev == 'F'){
		// select order id input- FOOD
		gotoxy(62,20);
		do{
			
			gotoxy(62,20);
			printf("Select Food ID: ");
			if(scanf("%d",&food_choice) != 1 || food_choice <= 0 || food_choice > food_id){
			
				fflush(stdin);
				gotoxy(62,21);
				printf("ORDER ID DOES NOT EXIST! Try Again");
	 			fflush(stdin);
	 			validation = 0;
			
			}// error handling for out of range order id
			else{
				
				validation = 1;
			}	
			
		}while(!validation || food_choice <= 0 || food_choice > food_id);
		fflush(stdin);
		validation = 0; // resets it
		

		// select quantity input- FOOD
		gotoxy(62,23);
		do{
			gotoxy(62,23);
			printf("Quantity: ");
			if(scanf("%d",&food_quantity) != 1){
				fflush(stdin);
				gotoxy(62,24);
				printf("Invalid Input. Try Again");
	 			fflush(stdin);
	 			validation = 0;	
			}
			else{
				validation = 1;
			}	
		}while(!validation);
		fflush(stdin);
		validation = 0;
		
		
		// PROCEED TO ADD THE FOOD ITEM - ORDERING PROCESS
		gotoxy(62,25);
		do{
			gotoxy(62,25);
		    printf("PROCEED TO ORDER THE FOLLOWING ITEM? (Y / N): ");
		    scanf("%c",&proceed);
			proceed = toupper(proceed);
			
		    if(proceed == 'Y' || proceed == 'N'){
				validation = 1;
			}
			else{
				fflush(stdin);
				gotoxy(62,26);
				printf("Select Y or N only.");
	 			validation = 0;	
			}
			
			
		}while(!validation);
		validation = 0;
		fflush(stdin);
		
		if(proceed == 'Y'){
				
			food_quantity_per_item[FOOD_number_order_times] = food_quantity;
			food_subtotal[FOOD_number_order_times] = food_get_price[food_choice-1] * food_quantity;
			food_total += food_subtotal[FOOD_number_order_times];
			strcpy(food_get_name[FOOD_number_order_times],food_name[food_choice-1]);

			FOOD_number_order_times++;
			
			
			gotoxy(44,28);
			printf("ORDER AGAIN? (Y / N): ");
			scanf("%c",&y_n);
			y_n = toupper(y_n);
			fflush(stdin);	
					
				
		}
		else if(proceed == 'N'){
			mon_order_menu();
			break;	
		}
		
		
	} // BEVERAGE - ORDERING PROCESS
	else if(food_or_bev == 'B'){
		
			// select order id input- BEVERAGE
			gotoxy(62,20);
			do{
				gotoxy(62,20);
				printf("Select Beverage ID: ");
				scanf("%d",&bev_choice);
				fflush(stdin);
				
				if(bev_choice <= 0 || bev_choice > bev_id){
					fflush(stdin);
					gotoxy(62,21);
					printf("ORDER ID DOES NOT EXIST! Try Again");		
				}
			
	 			
			}while(bev_choice <= 0 || bev_choice > bev_id);
			fflush(stdin);
			
			// quanitity input - BEVERAGE
			gotoxy(62,23);
			do{
				gotoxy(62,23);
				printf("Quantity: ");
				if(scanf("%d",&bev_quantity) != 1){
					fflush(stdin);
					gotoxy(62,24);
					printf("Invalid Input. Try Again");
	 				fflush(stdin);
	 				validation = 0;		
				}
				else{
					validation = 1;
				}
			}while(!validation);
			validation = 0;
			fflush(stdin);
			
			// PROCEED TO ADD THE BEVERAGE ITEM - ORDERING PROCESS
			gotoxy(62,25);
			printf("PROCEED TO ORDER THE FOLLOWING ITEM? (Y / N): ");
			scanf("%c",&proceed);
			proceed = toupper(proceed);
			fflush(stdin);
			
			if(proceed == 'Y'){
				bev_quantity_per_item[BEV_number_order_times] = bev_quantity;
				bev_subtotal[BEV_number_order_times] = bev_get_price[bev_choice-1] * bev_quantity;
				bev_total += bev_subtotal[BEV_number_order_times];
				strcpy(bev_get_name[BEV_number_order_times],bev_name[bev_choice-1]);
				
				BEV_number_order_times++;
				
				gotoxy(44,28);
				printf("ORDER AGAIN? (Y / N): ");
				scanf("%c",&y_n);
				y_n = toupper(y_n);
				fflush(stdin);
			}
			else{
				mon_order_menu();
				break;
			}
		
		
	}
	else{
		gotoxy(3,24);
		printf("select 'F' or 'B' only. try again");
		getch();
		fflush(stdin);
		staffMenu();
		break;
	}

		// DISPLAY THE FOLLOWING ORDERS // 
		if(y_n == 'N'){
			
			system("cls"); // clears the preceding output
			
			// FILE FOR ORDER HISTORY - STAFF 
			FILE *monday_order_history = fopen("monday_order_history.txt","a+");
			
			// FILE FOR SALES REPORT - ADMIN 
			FILE *monday_sales_report = fopen("monday_sales_report.txt","a+");
			// weekly
			FILE *weekly_sales_report = fopen("weekly_sales_report.txt","a+");
			// monthly
			FILE *monthly_sales_report = fopen("monthly_sales_report.txt","a+");

				
			overall_total = food_total + bev_total; // get the total of orders from subtotal of food and beverages
			
			gotoxy(32,1);printf("==================================================");
			gotoxy(32,2);printf("|| ------------- FOLLOWING ORDERS ------------- ||");
			gotoxy(32,3);printf("==================================================");
			
			gotoxy(10,5);
			printf("||------- FOOD ORDERED -------||");
			gotoxy(3,6);
			printf("-----------------------------------------------");
			gotoxy(3,7);
			printf("ITEM-NAME\t\tSUB-TOTAL\tQUANTITY\n");
			gotoxy(3,8);
			printf("-----------------------------------------------");
			
			int Food_count = 1;
			int Bev_count = 1;
			int F_order_code; // generates random order code
			int B_order_code;
			// for daily sales report transaction date
			time_t time_order = time(&time_order);
			// for weekly and monthly report transaction date
			// Get the current time
    		time_t current_time = time(NULL);
    		// Convert the time to a string using the desired format
    		char date_string[20];
    		strftime(date_string, 20, "%d-%m-%Y", localtime(&current_time));
    		
    		time_t current_time_month = time(NULL);
    		// Convert the time to a string using the desired format
    		char month_string[20];
    		strftime(month_string, 20, "%m-%d-%Y", localtime(&current_time_month));
			
			
			
			for(int i = 0; i < FOOD_number_order_times; i++){
				
				gotoxy(3,9+Food_count);
				printf("%-20s\t%3.2f\t%9d\n",food_get_name[i],food_subtotal[i],food_quantity_per_item[i]);
				
				srand(time(0));
				F_order_code = rand() % 100;
				
				// for order history
				fprintf(monday_order_history,"%d\n %s\n %d\n %f\n",F_order_code,food_get_name[i],food_quantity_per_item[i],food_subtotal[i]); 
				// for sales report
				fprintf(monday_sales_report,"%d\n %s\n %d\n %f\n %s\n",F_order_code,food_get_name[i],food_quantity_per_item[i],food_subtotal[i],ctime(&time_order));
	
				// for weekly sales report
				fprintf(weekly_sales_report,"%d\n %s\n %d\n %f\n %s\n",F_order_code,food_get_name[i],food_quantity_per_item[i],food_subtotal[i],date_string);
				// for monthly sales report
				fprintf(monthly_sales_report,"%d\n %s\n %d\n %f\n %s\n %s\n",F_order_code,food_get_name[i],food_quantity_per_item[i],food_subtotal[i],date_string,month_string);
				
				Food_count++;
				
			}
			
			
			
			if(BEV_number_order_times){ // DISPLAY THE ORDERES OF BEVERAGES IF THE BEV_number_order_times is true (1) / or not 0
				for(int i = 0; i < BEV_number_order_times; i++){
					
					gotoxy(67,5);
					printf("||------- BEVERAGE ORDERED -------||");
					gotoxy(62,6);
					printf("--------------------------------------------------");
					gotoxy(62,7);
					printf("ITEM-NAME\t\t\tSUB-TOTAL\tQUANTITY\n");
					gotoxy(62,8);
					printf("--------------------------------------------------");
					
					gotoxy(62,9+Bev_count);			
					printf("%-20s\t%3.2f\t%9d\n",bev_get_name[i],bev_subtotal[i],bev_quantity_per_item[i]);
					
					srand(time(0));
					B_order_code = rand() % 100;
					
					// for order history
					fprintf(monday_order_history,"%d\n %s\n %d\n %f\n",B_order_code,bev_get_name[i],bev_quantity_per_item[i],bev_subtotal[i]);
					// for sales report
					fprintf(monday_sales_report,"%d\n %s\n %d\n %f\n %s\n",B_order_code,bev_get_name[i],bev_quantity_per_item[i],bev_subtotal[i],ctime(&time_order));
					// for weekly report
					fprintf(weekly_sales_report,"%d\n %s\n %d\n %f\n %s\n",B_order_code,bev_get_name[i],bev_quantity_per_item[i],bev_subtotal[i],date_string);
					// for monthly report
					fprintf(monthly_sales_report,"%d\n %s\n %d\n %f\n %s\n %s\n",B_order_code,bev_get_name[i],bev_quantity_per_item[i],bev_subtotal[i],date_string,month_string);
					
					Bev_count++;
					
				}	
			}
			fclose(monday_order_history);
			fclose(monday_sales_report);
			fclose(weekly_sales_report);
			fclose(monthly_sales_report);
			
			gotoxy(39,20);
			printf("TOTAL: %.2f",overall_total);
		//	fprintf(monday_order_history,"%f\n",overall_total);
			
			gotoxy(39,21);
			do{
				
				gotoxy(39,21);
				printf("Customer Cash Payment: ");
				if(scanf("%d",&cash_payment) != 1 || cash_payment < overall_total){
					fflush(stdin);
					gotoxy(74,21);
					printf("Invalid Input! Try Again");
					validation = 0;
				}else{
					validation = 1;
				}
				
				if(cash_payment < overall_total){
					gotoxy(39,22);
					printf("Cash is Short!");
				}		
				
			}while(!validation || cash_payment < overall_total);
			
				change = (float) cash_payment - overall_total;
				gotoxy(39,24);
				printf("Change: %.2f",change);
				gotoxy(39,28);
				printf("Press ANY KEY to go back to menu <<<");
				getch();
				system("cls");
				fflush(stdin);
				staffMenu();
			
		}
		
		
	}while(y_n == 'Y');
	
	
	
	
	
}
void tues_order_menu(){
	system("cls");
	
	char y_n; // yes or no to get the order or add more
	char proceed;
	int cash_payment; // customer payment
	float change; // change of customer payment
	float overall_total; // get the total of food and beverage orders
	
	int FOOD_number_order_times = 0; // the count of order if the customer proceed to order more
	int BEV_number_order_times = 0;	// the count of order if the customer proceed to order more
	
	// MONDAY FOOD MENU BUFFERS
	char food_name[MAX][MAX];
	char food_status[MAX];
	float food_price;
	float food_get_price[MAX];
	int food_id;
	
	char food_get_name[MAX][MAX]; // array to store the order of the customer
	int food_quantity_per_item[MAX]; // array to store the quantity of certain ordered item
	
	int food_choice, food_quantity; 
	float food_subtotal[MAX], food_total;
	int food_position = 0;
	int food_order_id = 1;

	
	// MONDAY BEVERAGE MENU BUFFERS
	char bev_name[MAX][MAX];
	char bev_status[MAX];
	float bev_price;
	float bev_get_price[MAX];
	int bev_id;
	
	char bev_get_name[MAX][MAX]; // array to store the order of the customer
	int bev_quantity_per_item[MAX]; // array to store the quantity of certain ordered item
	
	int bev_choice, bev_quantity; 
	float bev_subtotal[MAX], bev_total; 
	int bev_position = 0;
	int bev_order_id = 1;

	// --- ORDERING PROCESS ---- //
	do{
		
	system("cls");
		
	// BODY OF THE MENU ///
	gotoxy(39,1);
	printf("|| ========== BELINDA'S EATERY ========== ||\n");
	
	// DISPLAY MONDAY FOOD MENU 
	FILE *tuesday_menu_F = fopen("tuesday_menu_F.txt","r");
	gotoxy(12,4);
	printf(" ~~~~~ FOOD MENU ~~~~~~ ");
	gotoxy(3,5);
	printf("==============================================");
	gotoxy(3,6);
	printf("ID\tITEM NAME\t\tPRICE\tSTATUS\n");
	gotoxy(3,7);
	printf("==============================================");
	while(fscanf(tuesday_menu_F,"%d %[^\n]%*c %f %[^\n]%*c",&food_id,food_name[food_position],&food_price,food_status) != EOF){
		gotoxy(3,8+food_order_id);
		printf("[%d]\t%-20s\t%5.2f\t%4s\n",food_id,food_name[food_position],food_price,food_status);
	
		food_get_price[food_position] = food_price;
		food_order_id++;
		food_position++;
	
		
	}
	
	food_order_id = 1; // resets the value of the order ID y axis
	fclose(tuesday_menu_F);
	

	// DISPLAY MONDAY BEVERAGE MENU
	FILE *tuesday_menu_B = fopen("tuesday_menu_B.txt","r");
	gotoxy(75,4);
	printf(" ~~~~~ BEVERAGE MENU ~~~~~~ ");
	gotoxy(62,5);
	printf("===================================================");
	gotoxy(62,6);
	printf("ID\tITEM NAME\t\tPRICE\tSTATUS\n");
	gotoxy(62,7);
	printf("===================================================");
	while(fscanf(tuesday_menu_B,"%d %[^\n]%*c %f %[^\n]%*c",&bev_id,bev_name[bev_position],&bev_price,bev_status) != EOF){
		gotoxy(62,8+bev_order_id);
		printf("[%d]\t%-20s\t%5.2f\t%4s\n",bev_order_id,bev_name[bev_position],bev_price,bev_status);
		bev_get_price[bev_position] = bev_price;
		bev_order_id++;
		bev_position++;
	}
	
	bev_order_id = 1;	// resets the value of the order ID y axis
	fclose(tuesday_menu_B);
	
	printf("\n");		
	// ---  START ORDERING PROCESS ---- //
		int validation;
		char food_or_bev;
		
		gotoxy(3,20);
		printf("-Choose Category to order-");
		gotoxy(3,21);
		printf("input 'F' - Food");
		gotoxy(3,22);
		printf("input 'B' - beverage");
		gotoxy(3,23);
		scanf("%c",&food_or_bev);
		food_or_bev = toupper(food_or_bev);
		fflush(stdin);
		
		// FOOD - ORDERING PROCESS
		if(food_or_bev == 'F'){
		// select order id input- FOOD
		gotoxy(62,20);
		do{
			
			gotoxy(62,20);
			printf("Select Food ID: ");
			if(scanf("%d",&food_choice) != 1 || food_choice <= 0 || food_choice > food_id){
			
				fflush(stdin);
				gotoxy(62,21);
				printf("ORDER ID DOES NOT EXIST! Try Again");
	 			fflush(stdin);
	 			validation = 0;
			
			}// error handling for out of range order id
			else{
				
				validation = 1;
			}	
			
		}while(!validation || food_choice <= 0 || food_choice > food_id);
		fflush(stdin);
		validation = 0; // resets it
		

		// select quantity input- FOOD
		gotoxy(62,23);
		do{
			gotoxy(62,23);
			printf("Quantity: ");
			if(scanf("%d",&food_quantity) != 1){
				fflush(stdin);
				gotoxy(62,24);
				printf("Invalid Input. Try Again");
	 			fflush(stdin);
	 			validation = 0;	
			}
			else{
				validation = 1;
			}	
		}while(!validation);
		fflush(stdin);
		validation = 0;
		
		
		// PROCEED TO ADD THE FOOD ITEM - ORDERING PROCESS
		gotoxy(62,25);
		do{
			gotoxy(62,25);
		    printf("PROCEED TO ORDER THE FOLLOWING ITEM? (Y / N): ");
		    scanf("%c",&proceed);
			proceed = toupper(proceed);
			
		    if(proceed == 'Y' || proceed == 'N'){
				validation = 1;
			}
			else{
				fflush(stdin);
				gotoxy(62,26);
				printf("Select Y or N only.");
	 			validation = 0;	
			}
			
			
		}while(!validation);
		validation = 0;
		fflush(stdin);
		
		if(proceed == 'Y'){
				
			food_quantity_per_item[FOOD_number_order_times] = food_quantity;
			food_subtotal[FOOD_number_order_times] = food_get_price[food_choice-1] * food_quantity;
			food_total += food_subtotal[FOOD_number_order_times];
			strcpy(food_get_name[FOOD_number_order_times],food_name[food_choice-1]);

			FOOD_number_order_times++;
			
			
			gotoxy(44,28);
			printf("ORDER AGAIN? (Y / N): ");
			scanf("%c",&y_n);
			y_n = toupper(y_n);
			fflush(stdin);	
					
				
		}
		else if(proceed == 'N'){
			tues_order_menu();
			break;	
		}
		
		
	} // BEVERAGE - ORDERING PROCESS
	else if(food_or_bev == 'B'){
		
			// select order id input- BEVERAGE
			gotoxy(62,20);
			do{
				gotoxy(62,20);
				printf("Select Beverage ID: ");
				scanf("%d",&bev_choice);
				fflush(stdin);
				
				if(bev_choice <= 0 || bev_choice > bev_id){
					fflush(stdin);
					gotoxy(62,21);
					printf("ORDER ID DOES NOT EXIST! Try Again");		
				}
			
	 			
			}while(bev_choice <= 0 || bev_choice > bev_id);
			fflush(stdin);
			
			// quanitity input - BEVERAGE
			gotoxy(62,23);
			do{
				gotoxy(62,23);
				printf("Quantity: ");
				if(scanf("%d",&bev_quantity) != 1){
					fflush(stdin);
					gotoxy(62,24);
					printf("Invalid Input. Try Again");
	 				fflush(stdin);
	 				validation = 0;		
				}
				else{
					validation = 1;
				}
			}while(!validation);
			validation = 0;
			fflush(stdin);
			
			// PROCEED TO ADD THE BEVERAGE ITEM - ORDERING PROCESS
			gotoxy(62,25);
			printf("PROCEED TO ORDER THE FOLLOWING ITEM? (Y / N): ");
			scanf("%c",&proceed);
			proceed = toupper(proceed);
			fflush(stdin);
			
			if(proceed == 'Y'){
				bev_quantity_per_item[BEV_number_order_times] = bev_quantity;
				bev_subtotal[BEV_number_order_times] = bev_get_price[bev_choice-1] * bev_quantity;
				bev_total += bev_subtotal[BEV_number_order_times];
				strcpy(bev_get_name[BEV_number_order_times],bev_name[bev_choice-1]);
				
				BEV_number_order_times++;
				
				gotoxy(44,28);
				printf("ORDER AGAIN? (Y / N): ");
				scanf("%c",&y_n);
				y_n = toupper(y_n);
				fflush(stdin);
			}
			else{
				tues_order_menu();
				break;
			}
		
		
	}
	else{
		gotoxy(3,24);
		printf("select 'F' or 'B' only. try again");
		getch();
		fflush(stdin);
		staffMenu();
		break;
	}

		// DISPLAY THE FOLLOWING ORDERS // 
		if(y_n == 'N'){
			
			system("cls"); // clears the preceding output
			
			// FILE FOR ORDER HISTORY - STAFF 
			FILE *tuesday_order_history = fopen("tuesday_order_history.txt","a+");
			
			// FILE FOR SALES REPORT - ADMIN 
			FILE *tuesday_sales_report = fopen("tuesday_sales_report.txt","a+");
			// weekly
			FILE *weekly_sales_report = fopen("weekly_sales_report.txt","a+");
			// monthly
			FILE *monthly_sales_report = fopen("monthly_sales_report.txt","a+");

				
			overall_total = food_total + bev_total; // get the total of orders from subtotal of food and beverages
			
			gotoxy(32,1);printf("==================================================");
			gotoxy(32,2);printf("|| ------------- FOLLOWING ORDERS ------------- ||");
			gotoxy(32,3);printf("==================================================");
			
			gotoxy(10,5);
			printf("||------- FOOD ORDERED -------||");
			gotoxy(3,6);
			printf("-----------------------------------------------");
			gotoxy(3,7);
			printf("ITEM-NAME\t\tSUB-TOTAL\tQUANTITY\n");
			gotoxy(3,8);
			printf("-----------------------------------------------");
			
			int Food_count = 1;
			int Bev_count = 1;
			int F_order_code; // generates random order code
			int B_order_code;
			// for daily sales report transaction date
			time_t time_order = time(&time_order);
			// for weekly and monthly report transaction date
			// Get the current time
    		time_t current_time = time(NULL);
    		// Convert the time to a string using the desired format
    		char date_string[20];
    		strftime(date_string, 20, "%d-%m-%Y", localtime(&current_time));
    		
    		time_t current_time_month = time(NULL);
    		// Convert the time to a string using the desired format
    		char month_string[20];
    		strftime(month_string, 20, "%m-%d-%Y", localtime(&current_time_month));
			
			
			
			for(int i = 0; i < FOOD_number_order_times; i++){
				
				gotoxy(3,9+Food_count);
				printf("%-20s\t%3.2f\t%9d\n",food_get_name[i],food_subtotal[i],food_quantity_per_item[i]);
				
				srand(time(0));
				F_order_code = rand() % 100;
				
				// for order history
				fprintf(tuesday_order_history,"%d\n %s\n %d\n %f\n",F_order_code,food_get_name[i],food_quantity_per_item[i],food_subtotal[i]); 
				// for sales report
				fprintf(tuesday_sales_report,"%d\n %s\n %d\n %f\n %s\n",F_order_code,food_get_name[i],food_quantity_per_item[i],food_subtotal[i],ctime(&time_order));
	
				// for weekly sales report
				fprintf(weekly_sales_report,"%d\n %s\n %d\n %f\n %s\n",F_order_code,food_get_name[i],food_quantity_per_item[i],food_subtotal[i],date_string);
				// for monthly sales report
				fprintf(monthly_sales_report,"%d\n %s\n %d\n %f\n %s\n %s\n",F_order_code,food_get_name[i],food_quantity_per_item[i],food_subtotal[i],date_string,month_string);
				
				Food_count++;
				
			}
			
			
			
			if(BEV_number_order_times){ // DISPLAY THE ORDERES OF BEVERAGES IF THE BEV_number_order_times is true (1) / or not 0
				for(int i = 0; i < BEV_number_order_times; i++){
					
					gotoxy(67,5);
					printf("||------- BEVERAGE ORDERED -------||");
					gotoxy(62,6);
					printf("--------------------------------------------------");
					gotoxy(62,7);
					printf("ITEM-NAME\t\t\tSUB-TOTAL\tQUANTITY\n");
					gotoxy(62,8);
					printf("--------------------------------------------------");
					
					gotoxy(62,9+Bev_count);			
					printf("%-20s\t%3.2f\t%9d\n",bev_get_name[i],bev_subtotal[i],bev_quantity_per_item[i]);
					
					srand(time(0));
					B_order_code = rand() % 100;
					
					// for order history
					fprintf(tuesday_order_history,"%d\n %s\n %d\n %f\n",B_order_code,bev_get_name[i],bev_quantity_per_item[i],bev_subtotal[i]);
					// for sales report
					fprintf(tuesday_sales_report,"%d\n %s\n %d\n %f\n %s\n",B_order_code,bev_get_name[i],bev_quantity_per_item[i],bev_subtotal[i],ctime(&time_order));
					// for weekly report
					fprintf(weekly_sales_report,"%d\n %s\n %d\n %f\n %s\n",B_order_code,bev_get_name[i],bev_quantity_per_item[i],bev_subtotal[i],date_string);
					// for monthly report
					fprintf(monthly_sales_report,"%d\n %s\n %d\n %f\n %s\n %s\n",B_order_code,bev_get_name[i],bev_quantity_per_item[i],bev_subtotal[i],date_string,month_string);
					
					Bev_count++;
					
				}	
			}
			fclose(tuesday_order_history);
			fclose(tuesday_sales_report);
			fclose(weekly_sales_report);
			fclose(monthly_sales_report);
			
			gotoxy(39,20);
			printf("TOTAL: %.2f",overall_total);
		//	fprintf(monday_order_history,"%f\n",overall_total);
			
			gotoxy(39,21);
			do{
				
				gotoxy(39,21);
				printf("Customer Cash Payment: ");
				if(scanf("%d",&cash_payment) != 1 || cash_payment < overall_total){
					fflush(stdin);
					gotoxy(74,21);
					printf("Invalid Input! Try Again");
					validation = 0;
				}else{
					validation = 1;
				}
				
				if(cash_payment < overall_total){
					gotoxy(39,22);
					printf("Cash is Short!");
				}		
				
			}while(!validation || cash_payment < overall_total);
			
				change = (float) cash_payment - overall_total;
				gotoxy(39,24);
				printf("Change: %.2f",change);
				gotoxy(39,28);
				printf("Press ANY KEY to go back to menu <<<");
				getch();
				system("cls");
				fflush(stdin);
				staffMenu();
			
		}
		
		
	}while(y_n == 'Y');
	
	
}


// STAFF - ORDER HISTORY OF THAT "DAY" MENU //
void staffViewOrderHistory(){
		
	system("cls");
	
//	int isDigit;
//	int n_items;
	int select_menu_day;
	int validation;
	

	gotoxy(0,1);printf("SELECT 0 to go back to menu <<<<");
	
	gotoxy(39,4);	printf("===============================");
	gotoxy(39,5);	printf("|| CHOOSE ORDER HISTORY DAY ||");
	gotoxy(39,6);	printf("===============================");
	
	
	gotoxy(39,9); printf("[1] Monday	View Orders\n");
	gotoxy(39,10);printf("[2] Tuesday	View Orders\n");
	gotoxy(39,11);printf("[3] Wednesday	View Orders\n");
	gotoxy(39,12);printf("[4] Thursday	View Orders\n");
	gotoxy(39,13);printf("[5] Friday	View Orders\n");
	gotoxy(39,14);printf("[6] Saturday	View Orders");
	
	gotoxy(39,16);
	do{
		gotoxy(39,16);
		printf("SELECT: ");
		if(scanf("%d",&select_menu_day) != 1 || select_menu_day < 0 || select_menu_day >=7){
			gotoxy(39,18);
			printf("INVALID INPUT!");
			fflush(stdin);
			validation = 0;
		}else{
			validation = 1;
		}	
		
	}while(!validation || select_menu_day <  0 || select_menu_day >= 7);
	fflush(stdin); // buffer to avoid invinsible characters that unnecessarily scanf fetching
	
	switch(select_menu_day){
		case 0:
			system("cls");
			gotoxy(39,10);		
			loadingScreen();
			staffMenu();
			break;
		case 1:
			mon_order_history();
			break;
		case 2:
			tues_order_history();
			break;
 		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			break;
			
	}
}
// STAFF -  ORDER HISTORY (MONDAY)
void mon_order_history(){
	
	system("cls");

	gotoxy(42,2);printf("============================");
	gotoxy(42,3);printf("|| *MONDAY* ORDER HISTORY ||");
	gotoxy(42,4);printf("============================");
	
	// initialize buffers
	char order_name[MAX];
	int order_quantity;
	float order_subtotal;
	int order_count = 0;
	int order_code;
	char clear_history;
	char proceed;
	
	// NAG-BUBUG PA POTEK
	FILE *monday_order_history = fopen("monday_order_history.txt","r");
	while(fscanf(monday_order_history,"%d %[^\n]%*c %d %f",&order_code,order_name,&order_quantity,&order_subtotal) != EOF){
		
		printf("\n");
		//printf("\n\t\t\tOrder #%d",order_count+1);
		printf("\n\t\t\t\t\tOrder Code:\t%-4d",order_code);
		printf("\n\t\t\t\t\tItem Ordered:\t%-20s",order_name);
		printf("\n\t\t\t\t\tQuantity:\t%-4d",order_quantity);
		printf("\n\t\t\t\t\tSub-total:\t%-6.2f",order_subtotal);
		printf("\n\t\t\t\t\t--------------------------------");
		order_count++;
		
	}
	fclose(monday_order_history);

	

	gotoxy(0,1);
	printf("CLear the following Content?");
	gotoxy(0,3);
	printf("Y - for yes / Select ANY KEY if no");
	gotoxy(0,4);
	scanf("%c",&clear_history);
	clear_history = toupper(clear_history);
	
	if(clear_history == 'Y'){
	
		remove("monday_order_history.txt");	
		fflush(stdin);
		staffMenu();
			
	}
	else{
		
		fflush(stdin);
		staffMenu();
	}


	
	
}
void tues_order_history(){
	
	system("cls");

	gotoxy(42,2);printf("============================");
	gotoxy(42,3);printf("|| *TUESDAY* ORDER HISTORY ||");
	gotoxy(42,4);printf("============================");
	
	// initialize buffers
	char order_name[MAX];
	int order_quantity;
	float order_subtotal;
	int order_count = 0;
	int order_code;
	char clear_history;
	char proceed;
	
	FILE *tuesday_order_history = fopen("tuesday_order_history.txt","r");
	while(fscanf(tuesday_order_history,"%d %[^\n]%*c %d %f",&order_code,order_name,&order_quantity,&order_subtotal) != EOF){
		
		printf("\n");
		//printf("\n\t\t\tOrder #%d",order_count+1);
		printf("\n\t\t\t\t\tOrder Code:\t%-4d",order_code);
		printf("\n\t\t\t\t\tItem Ordered:\t%-20s",order_name);
		printf("\n\t\t\t\t\tQuantity:\t%-4d",order_quantity);
		printf("\n\t\t\t\t\tSub-total:\t%-6.2f",order_subtotal);
		printf("\n\t\t\t\t\t--------------------------------");
		order_count++;
		
	}
	fclose(tuesday_order_history);

	

	gotoxy(0,1);
	printf("CLear the following Content?");
	gotoxy(0,3);
	printf("Y - for yes / Select ANY KEY if no");
	gotoxy(0,4);
	scanf("%c",&clear_history);
	clear_history = toupper(clear_history);
	
	if(clear_history == 'Y'){
	
		remove("tuesday_order_history.txt");	
		fflush(stdin);
		staffMenu();
			
	}
	else{
		
		fflush(stdin);
		staffMenu();
	}


	

}






// ADMIN INTERFACE MENU //
void adminMenu(){
	
	system("cls");
	

	int admin_choice;
	
	int validation; // determines if the input is valid
	
	
		
	gotoxy(39,4);	
	printf("===============================");
	gotoxy(39,5);	
	printf("||	ADMIN INTERFACE     ||");
	gotoxy(39,6);	
	printf("===============================");
	gotoxy(39,8);
	printf("PRESS [1] ADD MENU ITEM");
	gotoxy(39,9);
	printf("PRESS [2] VIEW MENU ITEM");
	gotoxy(39,10);
	printf("PRESS [3] PROFIT REPORTS");
	gotoxy(39,11);
	printf("PRESS [4] EDIT MENU ITEM");
	gotoxy(39,12);
	printf("PRESS [5] DELETE MENU ITEM");
	gotoxy(39,13);
	printf("PRESS [6] LOGOUT\n\n");
	gotoxy(39,15);
	printf("===============================");
	
	
	
	// implement input validation here ---//
	gotoxy(39,17);
	do{
		gotoxy(39,17);
		printf("SELECT: ");
		if(scanf("%d",&admin_choice) != 1 || admin_choice <= 0 || admin_choice >= 7){
			fflush(stdin);
			gotoxy(39,18);
			printf("INVALID INPUT!\n");
			validation = 0;
		}else{
			validation = 1;
		}	
		
	}while(!validation || admin_choice <= 0 || admin_choice >= 7);
	
	fflush(stdin); // buffer to avoid invinsible characters that unnecessarily scanf fetching
	
	// proceed to the evaluate the input value if the validation is correct
	switch(admin_choice){
		case 1:
			adminAddMenuItems();
			break;
		case 2:
			adminViewItems();
			break;
		case 3:
			adminSalesReport();
			break;
		case 4:
			adminUpdateMenuItems();
			break;
		case 5:
			adminDeleteMenuItems();
			break;
		case 6:
			system("cls");
			gotoxy(39,10);
			loadingScreen();
			mainMenu();
			break;
	}	
}


// ADMIN ADD ITEM MENU OF THE DAY INTERFACE //
void adminAddMenuItems(){
	
	system("cls");
	
	
//	int isDigit;
//	int n_items;
	int select_menu_day;
	int validation;
	
	gotoxy(0,1);printf("SELECT 0 to go back to menu <<<<");
	
	gotoxy(39,4);	printf("===========================");
	gotoxy(39,5);	printf("||	ADD ITEM        ||");
	gotoxy(39,6);	printf("===========================");
	
	
	gotoxy(39,9); printf("[1] Monday    	MENU\n");
	gotoxy(39,10);printf("[2] Tuesday	MENU\n");
	gotoxy(39,11);printf("[3] Wednesday 	MENU\n");
	gotoxy(39,12);printf("[4] Thursday  	MENU\n");
	gotoxy(39,13);printf("[5] Friday    	MENU\n");
	gotoxy(39,14);printf("[6] Saturday  	MENU");
	
	gotoxy(39,16);
	do{
		gotoxy(39,16);
		printf("SELECT: ");
		if(scanf("%d",&select_menu_day) != 1 || select_menu_day < 0 || select_menu_day >=7){
			gotoxy(39,18);
			printf("INVALID INPUT!");
			fflush(stdin);
			validation = 0;
		}else{
			validation = 1;
		}	
		
	}while(!validation || select_menu_day <  0 || select_menu_day >= 7);
	
	fflush(stdin); // buffer to avoid invinsible characters that unnecessarily scanf fetching
	
	switch(select_menu_day){
		case 0:
			system("cls");
			gotoxy(39,10);		
			loadingScreen();
			adminMenu();
			break;
		case 1:
			mon_add_menu();
			break;
		case 2:
			tues_add_menu();
			break;
 		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			break;
			
	}
	
	
}

// ADMIN - ADD ITEM TO MONDAY MENU //
void mon_add_menu(){
	
	system("cls");
	
	int select_category;
	int validation;
	
	gotoxy(0,1);printf("SELECT 0 to go back to menu <<<<");
	
	gotoxy(32,8);printf("===================================\n");
	gotoxy(32,9);printf("|| ADD ITEM TO THE MENU (MONDAY) ||\n");
	gotoxy(32,10);printf("==================================\n");
	
	gotoxy(32,12);
	printf("[1] Add Food\n");
	gotoxy(32,13);
	printf("[2] Add Beverage\n");
	gotoxy(32,16);
	do{
		gotoxy(32,16);
		printf("SELECT: ");
		if(scanf("%d",&select_category) != 1 || select_category < 0 || select_category >=3){
			gotoxy(32,18);
			printf("INVALID INPUT!");
			fflush(stdin);
			validation = 0;
		}else{
			validation = 1;
		}	
		
	}while(!validation || select_category <  0 || select_category >= 3);// IMPLEMENT INPUT VALIDATION
	fflush(stdin); // buffer to avoid invinsible characters that unnecessarily scanf fetching
	
	switch(select_category){
		
		case 0:
			system("cls");
			gotoxy(39,10);		
			loadingScreen();
			adminMenu();
			break;
		case 1:
			add_food_monday();
			break;
		case 2:
			add_beverage_monday();
			break;
	}
	
	
	
}
// ADMIN - ADD FOOD (MONDAY) //
void add_food_monday(){
	
	system("cls");
	
	char y_n;
	char proceed;
	
	
	do{
		system("cls");
		
		gotoxy(40,2);printf("|||| ADD FOOD ITEM *MONDAY* ||||\n");
		
		// initialize buffers for reading text file		
		char food_name[MAX][MAX];			
		int food_id;												
		float food_price;
		char food_status[MAX];
		
		// initialize buffer 
		char food_name_add[MAX];			
		int food_id_add = 1;					
		float food_price_add;
		char food_status_add[MAX];
		
		int validation = 0;
		int pos = 0;

		FILE *monday_menu_F = fopen("monday_menu_F.txt","r");
		while(fscanf(monday_menu_F,"%d %[^\n]%*c %f %[^\n]%*c",&food_id,food_name[pos],&food_price,food_status) != EOF){
			if(food_id_add == food_id){
				food_id_add++;
			}
			pos++;
			
		}
		fclose(monday_menu_F);
		
		// ITEM NAME validation	
		gotoxy(20,7);
		printf("Input Food Name: ");
		scanf("%[^\n]s",food_name_add);
			fflush(stdin);
			
			
		// check the string if it has digits 
		for(int i = 0; i < strlen(food_name_add); i++){
				if(food_name_add[i] > '0' && food_name_add[i] < '9'){
					gotoxy(20,5);
					printf("Invalid Name Input!");
					gotoxy(0,2);
					printf("Press ANY KEY to try again");
					getch();
					fflush(stdin);
					add_food_monday();
					
				}
			
		}
			
		for(int i = 0; i < pos; i++){	
				if(strcmp(food_name_add,food_name[i]) == 0){
					gotoxy(20,6);
					printf("Name Already Exist!");
					gotoxy(0,2);
					printf("Press ANY KEY to try again");
					getch();
					fflush(stdin);
					add_food_monday();
					
				}

		}				
		fflush(stdin);
	
			
		// ADD PRICE -
		do{
			gotoxy(20,8);
			printf("Input Food Price: ");
			if(scanf("%f",&food_price_add) != 1){
				fflush(stdin);
				gotoxy(2,8);
				printf("Invalid Data!");
				gotoxy(2,9);
				printf("Try again");
				validation = 0;
				
			}
			else{
				validation = 1;
			}
				
		}while(!validation);
		fflush(stdin);
		validation = 0;
		
		// ITEM STATUS
		strcpy(food_status_add,"Available");
		// PROCEED TO ADD PART
		gotoxy(20,10);
		printf("PROCEED TO ADD THE ITEM? Y (yes) / N (no)\n");
		gotoxy(20,11);
		printf("Choose: ");
		scanf("%c",&proceed);
		proceed = toupper(proceed);
		
		fflush(stdin);
		
		if(proceed == 'Y'){
			
			FILE *monday_menu_F = fopen("monday_menu_F.txt","a");
			
			if(monday_menu_F == NULL){
				gotoxy(70,9);printf("ERROR: FILE DOES NOT EXIST!");
			}
			else{
				gotoxy(70,9);printf("==================\n");
				gotoxy(70,10);printf("|| FOOD ADDED! ||\n");
				gotoxy(70,11);printf("==================\n");
			}
			
			fprintf(monday_menu_F,"%d\n %s\n %f\n %s\n",food_id_add,food_name_add,food_price_add,food_status_add);
			fclose(monday_menu_F);
				
		}
		else if(proceed == 'N'){
			
			fflush(stdin);
			system("cls");
			add_food_monday();
	
		}
		else{
			fflush(stdin);
			gotoxy(39,19);
			printf("INVALID INPUT!");
			gotoxy(39,20);
			printf("press ANY KEY to refresh");
			getch();
			fflush(stdin);
			system("cls");
			gotoxy(39,10);
			loadingScreen();
			add_food_monday();
			break;	
		}
		
		gotoxy(39,17);printf("ADD MORE? : Y (yes) / N (no)\n");
		gotoxy(39,18);printf("Choose: ");
		scanf("%c",&y_n);
		y_n = toupper(y_n);
		fflush(stdin);
		
		if(y_n == 'N'){
			
			fflush(stdin);
			system("cls");
			gotoxy(39,10);
			loadingScreen();
			adminMenu();
			break;
			
		}
		else if(y_n == 'Y'){
			add_food_monday();
		}
		else{
			fflush(stdin);
			gotoxy(39,19);
			printf("INVALID INPUT!");
			gotoxy(39,20);
			printf("press ANY KEY to refresh");
			getch();
			fflush(stdin);
			system("cls");
			gotoxy(39,10);
			loadingScreen();
			adminMenu();
			break;
		}
		
		
	}while(y_n == 'Y');
	
}
// ADMIN - ADD BEVERAGE (MONDAY) //
void add_beverage_monday(){
	
	system("cls");
	
	
	char y_n;
	char proceed;
	
	do{
		system("cls");
		
		gotoxy(40,4);printf("|||| ADD BEVERAGE ITEM *MONDAY* ||||\n");
		
		// buffers for reading   // bev stands for "beverage"
		char bev_name[MAX][MAX];
		int bev_id;
		float bev_price;
		char bev_status[MAX];
		
		// initialize buffer for storing
		char bev_name_add[MAX];			
		int bev_id_add = 1;					
		float bev_price_add;
		char bev_status_add[MAX];
		
		int validation = 0;
		int pos = 0;
		
		FILE *monday_menu_B = fopen("monday_menu_B.txt","r");
		while(fscanf(monday_menu_B,"%d %[^\n]%*c %f %[^\n]%*c",&bev_id,bev_name[pos],&bev_price,bev_status) != EOF){
			if(bev_id_add == bev_id){
				bev_id_add++;
			}
			pos++;
		}
		fclose(monday_menu_B);
		
		gotoxy(20,7);
		printf("Input Beverage Name: ");
		scanf("%[^\n]s",bev_name_add);
		fflush(stdin);
		
		// check the string if it has digits 
		for(int i = 0; i < strlen(bev_name_add); i++){
				if(bev_name_add[i] > '0' && bev_name_add[i] < '9'){
					gotoxy(20,5);
					printf("Invalid Name Input!");
					gotoxy(0,2);
					printf("Press ANY KEY to try again");
					getch();
					fflush(stdin);
					add_beverage_monday();
					
				}
			
		}
			
		for(int i = 0; i < pos; i++){	
				if(strcmp(bev_name_add,bev_name[i]) == 0){
					gotoxy(20,6);
					printf("Name Already Exist!");
					gotoxy(0,2);
					printf("Press ANY KEY to try again");
					getch();
					fflush(stdin);
					add_beverage_monday();
					
				}

		}				
		fflush(stdin);
		
		// ADD PRICE
		do{
			gotoxy(20,8);
			printf("Input Beverage Price: ");
			if(scanf("%f",&bev_price_add) != 1){
				fflush(stdin);
				gotoxy(2,8);
				printf("Invalid Data!");
				gotoxy(2,9);
				printf("Try again");;
				validation = 0;
				
			}
			else{
				validation = 1;
			}
				
		}while(!validation);
		fflush(stdin);
		validation = 0;
		// ITEM STATUS
		strcpy(bev_status_add,"Available");
		// PROCEED TO ADD
		gotoxy(20,10);
		printf("PROCEED TO ADD THE ITEM? Y (yes) / N (no)\n");
		gotoxy(20,11);
		printf("Choose: ");
		scanf("%c",&proceed);
		proceed = toupper(proceed);
		
		fflush(stdin);
		
		if(proceed == 'Y'){
			
			FILE *monday_menu_B = fopen("monday_menu_B.txt","a");
			
			if(monday_menu_B == NULL){
				gotoxy(70,9);printf("ERROR: FILE DOES NOT EXIST!");
			}
			else{
				gotoxy(70,9);printf("======================\n");
				gotoxy(70,10);printf("|| BEVERAGE ADDED! ||\n");
				gotoxy(70,11);printf("======================\n");
			}
			fprintf(monday_menu_B,"%d\n %s\n %f\n %s\n",bev_id_add,bev_name_add,bev_price_add,bev_status_add);
			fclose(monday_menu_B);
			
		}
		else if(proceed == 'N'){
			fflush(stdin);
			system("cls");
			add_beverage_monday();
			
		}else{
			fflush(stdin);
			gotoxy(39,19);
			printf("INVALID INPUT!");
			gotoxy(39,20);
			printf("press ANY KEY to refresh");
			getch();
			fflush(stdin);
			system("cls");
			gotoxy(39,10);
			loadingScreen();
			add_beverage_monday();
			break;		
		}
		
		gotoxy(39,17);
		printf("ADD MORE? : Y (yes) / N (no)\n");
		gotoxy(39,18);
		printf("Choose: ");
		scanf("%c",&y_n);
		y_n = toupper(y_n);
		fflush(stdin);
		
		if(y_n == 'N'){
			
			fflush(stdin);
			system("cls");
			gotoxy(39,10);
			loadingScreen();
			adminMenu();
			break;
		}
		else if(y_n == 'Y'){
			add_beverage_monday();
		}
		else{
			fflush(stdin);
			gotoxy(39,19);
			printf("INVALID INPUT!");
			gotoxy(39,20);
			printf("press ANY KEY to refresh");
			getch();
			fflush(stdin);
			system("cls");
			gotoxy(39,10);
			loadingScreen();
			adminMenu();
			break;	
		}
		
		
		
	}while(y_n == 'Y');
	
}
// ADMIN - ADD ITEM TO TUESDAY MENU //
void tues_add_menu(){
	
	system("cls");
	
	int select_category;
	int validation;
	
	gotoxy(0,1);printf("SELECT 0 to go back to menu <<<<");
	
	gotoxy(32,8);printf("===================================\n");
	gotoxy(32,9);printf("|| ADD ITEM TO THE MENU (TUESDAY) ||\n");
	gotoxy(32,10);printf("==================================\n");
	
	gotoxy(32,12);
	printf("[1] Add Food\n");
	gotoxy(32,13);
	printf("[2] Add Beverage\n");
	gotoxy(32,16);
	do{
		gotoxy(32,16);
		printf("SELECT: ");
		if(scanf("%d",&select_category) != 1 || select_category < 0 || select_category >=3){
			gotoxy(32,18);
			printf("INVALID INPUT!");
			fflush(stdin);
			validation = 0;
		}else{
			validation = 1;
		}	
		
	}while(!validation || select_category <  0 || select_category >= 3);// IMPLEMENT INPUT VALIDATION
	fflush(stdin); // buffer to avoid invinsible characters that unnecessarily scanf fetching
	
	switch(select_category){
		
		case 0:
			system("cls");
			gotoxy(39,10);		
			loadingScreen();
			adminMenu();
			break;
		case 1:
			add_food_tuesday();
			break;
		case 2:
			add_beverage_tuesday();
			break;
	}
	
	
	
}
void add_food_tuesday(){
	
	system("cls");
	
	char y_n;
	char proceed;
	
	
	do{
		system("cls");
		
		gotoxy(40,2);printf("|||| ADD FOOD ITEM *TUESDAY* ||||\n");
		
		// initialize buffers for reading text file		
		char food_name[MAX][MAX];			
		int food_id;												
		float food_price;
		char food_status[MAX];
		
		// initialize buffer 
		char food_name_add[MAX];			
		int food_id_add = 1;					
		float food_price_add;
		char food_status_add[MAX];
		
		int validation = 0;
		int pos = 0;

		FILE *tuesday_menu_F = fopen("tuesday_menu_F.txt","r");
		while(fscanf(tuesday_menu_F,"%d %[^\n]%*c %f %[^\n]%*c",&food_id,food_name[pos],&food_price,food_status) != EOF){
			if(food_id_add == food_id){
				food_id_add++;
			}
			pos++;
			
		}
		fclose(tuesday_menu_F);
		
		// ITEM NAME validation	
		gotoxy(20,7);
		printf("Input Food Name: ");
		scanf("%[^\n]s",food_name_add);
		fflush(stdin);
			
			
		// check the string if it has digits 
		for(int i = 0; i < strlen(food_name_add); i++){
				if(food_name_add[i] > '0' && food_name_add[i] < '9'){
					gotoxy(20,5);
					printf("Invalid Name Input!");
					gotoxy(0,2);
					printf("Press ANY KEY to try again");
					getch();
					fflush(stdin);
					add_food_tuesday();
					
				}
			
		}
			
		for(int i = 0; i < pos; i++){	
				if(strcmp(food_name_add,food_name[i]) == 0){
					gotoxy(20,6);
					printf("Name Already Exist!");
					gotoxy(0,2);
					printf("Press ANY KEY to try again");
					getch();
					fflush(stdin);
					add_food_tuesday();
					
				}

		}				
		fflush(stdin);
	
			
		// ADD PRICE -
		do{
			gotoxy(20,8);
			printf("Input Food Price: ");
			if(scanf("%f",&food_price_add) != 1){
				fflush(stdin);
				gotoxy(2,8);
				printf("Invalid Data!");
				gotoxy(2,9);
				printf("Try again");
				validation = 0;
				
			}
			else{
				validation = 1;
			}
				
		}while(!validation);
		fflush(stdin);
		validation = 0;
		
		// ITEM STATUS
		strcpy(food_status_add,"Available");
		// PROCEED TO ADD PART
		gotoxy(20,10);
		printf("PROCEED TO ADD THE ITEM? Y (yes) / N (no)\n");
		gotoxy(20,11);
		printf("Choose: ");
		scanf("%c",&proceed);
		proceed = toupper(proceed);
		
		fflush(stdin);
		
		if(proceed == 'Y'){
			
			FILE *tuesday_menu_F = fopen("tuesday_menu_F.txt","a");
			
			if(tuesday_menu_F == NULL){
				gotoxy(70,9);printf("ERROR: FILE DOES NOT EXIST!");
			}
			else{
				gotoxy(70,9);printf("==================\n");
				gotoxy(70,10);printf("|| FOOD ADDED! ||\n");
				gotoxy(70,11);printf("==================\n");
			}
			
			fprintf(tuesday_menu_F,"%d\n %s\n %f\n %s\n",food_id_add,food_name_add,food_price_add,food_status_add);
			fclose(tuesday_menu_F);
				
		}
		else if(proceed == 'N'){
			
			fflush(stdin);
			system("cls");
			add_food_tuesday();
	
		}
		else{
			fflush(stdin);
			gotoxy(39,19);
			printf("INVALID INPUT!");
			gotoxy(39,20);
			printf("press ANY KEY to refresh");
			getch();
			fflush(stdin);
			system("cls");
			gotoxy(39,10);
			loadingScreen();
			add_food_tuesday();
			break;	
		}
		
		gotoxy(39,17);printf("ADD MORE? : Y (yes) / N (no)\n");
		gotoxy(39,18);printf("Choose: ");
		scanf("%c",&y_n);
		y_n = toupper(y_n);
		fflush(stdin);
			
			if(y_n == 'N'){
				
				fflush(stdin);
				system("cls");
				gotoxy(39,10);
				loadingScreen();
				adminMenu();
				break;
				
			}
			else if(y_n == 'Y'){
				add_food_tuesday();
			}
			else{
				fflush(stdin);
				gotoxy(39,19);
				printf("INVALID INPUT!");
				gotoxy(39,20);
				printf("press ANY KEY to refresh");
				getch();
				fflush(stdin);
				system("cls");
				gotoxy(39,10);
				loadingScreen();
				adminMenu();
				break;
			}
			
			
		}while(y_n == 'Y');
}
void add_beverage_tuesday(){
	
	system("cls");
	
	
	char y_n;
	char proceed;
	
	do{
		system("cls");
		
		gotoxy(40,4);printf("|||| ADD BEVERAGE ITEM *TUESDAY* ||||\n");
		
		// buffers for reading   // bev stands for "beverage"
		char bev_name[MAX][MAX];
		int bev_id;
		float bev_price;
		char bev_status[MAX];
		
		// initialize buffer for storing
		char bev_name_add[MAX];			
		int bev_id_add = 1;					
		float bev_price_add;
		char bev_status_add[MAX];
		
		int validation = 0;
		int pos = 0;
		
		FILE *tuesday_menu_B = fopen("tuesday_menu_B.txt","r");
		while(fscanf(tuesday_menu_B,"%d %[^\n]%*c %f %[^\n]%*c",&bev_id,bev_name[pos],&bev_price,bev_status) != EOF){
			if(bev_id_add == bev_id){
				bev_id_add++;
			}
			pos++;
		}
		fclose(tuesday_menu_B);
		
		gotoxy(20,7);
		printf("Input Beverage Name: ");
		scanf("%[^\n]s",bev_name_add);
		fflush(stdin);
		
		// check the string if it has digits 
		for(int i = 0; i < strlen(bev_name_add); i++){
				if(bev_name_add[i] > '0' && bev_name_add[i] < '9'){
					gotoxy(20,5);
					printf("Invalid Name Input!");
					gotoxy(0,2);
					printf("Press ANY KEY to try again");
					getch();
					fflush(stdin);
					add_beverage_tuesday();
					
				}
			
		}
			
		for(int i = 0; i < pos; i++){	
				if(strcmp(bev_name_add,bev_name[i]) == 0){
					gotoxy(20,6);
					printf("Name Already Exist!");
					gotoxy(0,2);
					printf("Press ANY KEY to try again");
					getch();
					fflush(stdin);
					add_beverage_tuesday();
					
				}

		}				
		fflush(stdin);
		
		// ADD PRICE
		do{
			gotoxy(20,8);
			printf("Input Beverage Price: ");
			if(scanf("%f",&bev_price_add) != 1){
				fflush(stdin);
				gotoxy(2,8);
				printf("Invalid Data!");
				gotoxy(2,9);
				printf("Try again");;
				validation = 0;
				
			}
			else{
				validation = 1;
			}
				
		}while(!validation);
		fflush(stdin);
		validation = 0;
		// ITEM STATUS
		strcpy(bev_status_add,"Available");
		// PROCEED TO ADD
		gotoxy(20,10);
		printf("PROCEED TO ADD THE ITEM? Y (yes) / N (no)\n");
		gotoxy(20,11);
		printf("Choose: ");
		scanf("%c",&proceed);
		proceed = toupper(proceed);
		
		fflush(stdin);
		
		if(proceed == 'Y'){
			
			FILE *tuesday_menu_B = fopen("tuesday_menu_B.txt","a");
			
			if(tuesday_menu_B == NULL){
				gotoxy(70,9);printf("ERROR: FILE DOES NOT EXIST!");
			}
			else{
				gotoxy(70,9);printf("======================\n");
				gotoxy(70,10);printf("|| BEVERAGE ADDED! ||\n");
				gotoxy(70,11);printf("======================\n");
			}
			fprintf(tuesday_menu_B,"%d\n %s\n %f\n %s\n",bev_id_add,bev_name_add,bev_price_add,bev_status_add);
			fclose(tuesday_menu_B);
			
		}
		else if(proceed == 'N'){
			fflush(stdin);
			system("cls");
			add_beverage_tuesday();
			
		}else{
			fflush(stdin);
			gotoxy(39,19);
			printf("INVALID INPUT!");
			gotoxy(39,20);
			printf("press ANY KEY to refresh");
			getch();
			fflush(stdin);
			system("cls");
			gotoxy(39,10);
			loadingScreen();
			add_beverage_tuesday();
			break;		
		}
		
		gotoxy(39,17);
		printf("ADD MORE? : Y (yes) / N (no)\n");
		gotoxy(39,18);
		printf("Choose: ");
		scanf("%c",&y_n);
		y_n = toupper(y_n);
		fflush(stdin);
		
		if(y_n == 'N'){
			
			fflush(stdin);
			system("cls");
			gotoxy(39,10);
			loadingScreen();
			adminMenu();
			break;
		}
		else if(y_n == 'Y'){
			add_beverage_tuesday();
		}
		else{
			fflush(stdin);
			gotoxy(39,19);
			printf("INVALID INPUT!");
			gotoxy(39,20);
			printf("press ANY KEY to refresh");
			getch();
			fflush(stdin);
			system("cls");
			gotoxy(39,10);
			loadingScreen();
			adminMenu();
			break;	
		}
		
		
		
	}while(y_n == 'Y');		
}

// ADMIN - VIEW THE ITEMS OF MENU OF THE DAY //
void adminViewItems(){
	
	system("cls");
	
	
//	int isDigit;
//	int n_items;
	int select_menu_day;
	int validation;

	gotoxy(0,1);printf("SELECT 0 to go back to menu <<<<");
	
	gotoxy(39,4);	printf("===========================");
	gotoxy(39,5);	printf("|| VIEW MENU OF THE DAYS ||");
	gotoxy(39,6);	printf("===========================");
	
	
	gotoxy(39,9); printf("[1] View Monday		MENU\n");
	gotoxy(39,10);printf("[2] View Tuesday		MENU\n");
	gotoxy(39,11);printf("[3] View Wednesday	MENU\n");
	gotoxy(39,12);printf("[4] View Thursday	MENU\n");
	gotoxy(39,13);printf("[5] View Friday		MENU\n");
	gotoxy(39,14);printf("[6] View Saturday	MENU");
	
	gotoxy(39,16);
	do{
		gotoxy(39,16);
		printf("SELECT: ");
		if(scanf("%d",&select_menu_day) != 1 || select_menu_day < 0 || select_menu_day >=7){
			gotoxy(39,18);
			printf("INVALID INPUT!");
			fflush(stdin);
			validation = 0;
		}else{
			validation = 1;
		}	
		
	}while(!validation || select_menu_day <  0 || select_menu_day >= 7);
	fflush(stdin); // buffer to avoid invinsible characters that unnecessarily scanf fetching
	
	
	switch(select_menu_day){
		case 0:
			system("cls");
			gotoxy(39,10);		
			loadingScreen();
			adminMenu();
			break;
		case 1:
			mon_view_menu();
			break;
		case 2:
			tues_view_menu();
			break;
 		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			break;
			
	}
	
	
	
}
// ADMIN - VIEW MENU OF THE DAYS - MONDAY - //
void mon_view_menu(){
	
	system("cls");
	
	// initialization of buffers FOOD
	char food_name[MAX];
	int food_id;
	float food_price;
	char food_status[MAX];
	// initialization of buffers BEVERAGE
	char bev_name[MAX];
	int bev_id;
	float bev_price;
	char bev_status[MAX];
	
	int F_item_count = 1;
	int B_item_count = 1;
	
	
	gotoxy(49,1);printf("===================\n");
	gotoxy(49,2);printf("||  MONDAY MENU  ||\n");
	gotoxy(49,3);printf("===================\n");
	// DISPLAY THE FOOD ITEMS HERE
	gotoxy(30,4);
	printf("||====================== FOOD MENU ======================||");
	gotoxy(20,6);
	printf("=============================================================================");
	gotoxy(20,7);
	printf("NO.\t\tID\tITEM NAME\t\t\tPRICE\t\tSTATUS\n");
	gotoxy(20,8);
	printf("=============================================================================");
	FILE *monday_menu_F = fopen("monday_menu_F.txt","r");
//	gotoxy(10,9+F_item_count);
	while(fscanf(monday_menu_F,"%d %[^\n]%*c %f %[^\n]%*c",&food_id,food_name,&food_price,food_status) != EOF){ // read the text inside the file
		gotoxy(20,8+F_item_count);
		printf("[%d]\t\t%-5d\t%-20s\t\t%4.2f\t\t%8s\n",F_item_count,food_id,food_name,food_price,food_status);
		F_item_count++;
	}
	fclose(monday_menu_F);
	

	// DISPLAY THE BEVERAGE ITEMS HERE
	gotoxy(28,18);
	printf("||====================== BEVERAGE MENU ======================||");
	gotoxy(20,20);
	printf("=============================================================================");
	gotoxy(20,21);
	printf("NO.\t\tID\tITEM NAME\t\t\tPRICE\t\tSTATUS\n");
	gotoxy(20,22);
	printf("=============================================================================");
	
	FILE *monday_menu_B = fopen("monday_menu_B.txt","r");

	while(fscanf(monday_menu_B,"%d %[^\n]%*c %f %[^\n]%*c",&bev_id,bev_name,&bev_price,bev_status) != EOF){
		gotoxy(20,22+B_item_count);
		printf("[%d]\t\t%-5d\t%-20s\t\t%4.2f\t\t%8s\n",B_item_count,bev_id,bev_name,bev_price,bev_status);
		B_item_count++;
	}
	fclose(monday_menu_B);
	gotoxy(0,1); printf("Press ANY KEY to go BACK TO MENU <<<");
	getch();	
	fflush(stdin);
	adminMenu();
	
	
}
void tues_view_menu(){
	
	system("cls");
	
	// initialization of buffers FOOD
	char food_name[MAX];
	int food_id;
	float food_price;
	char food_status[MAX];
	// initialization of buffers BEVERAGE
	char bev_name[MAX];
	int bev_id;
	float bev_price;
	char bev_status[MAX];
	
	int F_item_count = 1;
	int B_item_count = 1;
	
	
	gotoxy(49,1);printf("====================\n");
	gotoxy(49,2);printf("||  TUESDAY MENU  ||\n");
	gotoxy(49,3);printf("====================\n");
	// DISPLAY THE FOOD ITEMS HERE
	gotoxy(30,4);
	printf("||====================== FOOD MENU ======================||");
	gotoxy(20,6);
	printf("=============================================================================");
	gotoxy(20,7);
	printf("NO.\t\tID\tITEM NAME\t\t\tPRICE\t\tSTATUS\n");
	gotoxy(20,8);
	printf("=============================================================================");
	FILE *tuesday_menu_F = fopen("tuesday_menu_F.txt","r");
//	gotoxy(10,9+F_item_count);
	while(fscanf(tuesday_menu_F,"%d %[^\n]%*c %f %[^\n]%*c",&food_id,food_name,&food_price,food_status) != EOF){ // read the text inside the file
		gotoxy(20,8+F_item_count);
		printf("[%d]\t\t%-5d\t%-20s\t\t%4.2f\t\t%8s\n",F_item_count,food_id,food_name,food_price,food_status);
		F_item_count++;
	}
	fclose(tuesday_menu_F);
	

	// DISPLAY THE BEVERAGE ITEMS HERE
	gotoxy(28,18);
	printf("||====================== BEVERAGE MENU ======================||");
	gotoxy(20,20);
	printf("=============================================================================");
	gotoxy(20,21);
	printf("NO.\t\tID\tITEM NAME\t\t\tPRICE\t\tSTATUS\n");
	gotoxy(20,22);
	printf("=============================================================================");
	
	FILE *tuesday_menu_B = fopen("tuesday_menu_B.txt","r");

	while(fscanf(tuesday_menu_B,"%d %[^\n]%*c %f %[^\n]%*c",&bev_id,bev_name,&bev_price,bev_status) != EOF){
		gotoxy(20,22+B_item_count);
		printf("[%d]\t\t%-5d\t%-20s\t\t%4.2f\t\t%8s\n",B_item_count,bev_id,bev_name,bev_price,bev_status);
		B_item_count++;
	}
	fclose(tuesday_menu_B);
	gotoxy(0,1); printf("Press ANY KEY to go BACK TO MENU <<<");
	getch();	
	fflush(stdin);
	adminMenu();	
}



// ADMIN - SALES REPORT MENU //
void adminSalesReport(){
	
	system("cls");
	
//	int isDigit;
//	int n_items;
	int select;
	int validation;

	gotoxy(0,1);printf("SELECT 0 to go back to menu <<<<");
	
	gotoxy(41,4);	printf("====================");
	gotoxy(41,5);	printf("|| SALES REPORT ||");
	gotoxy(41,6);	printf("====================");
	
	
	gotoxy(39,9); printf("[1] Monday	Sales\n");
	gotoxy(39,10);printf("[2] Tuesday	Sales\n");
	gotoxy(39,11);printf("[3] Wednesday	Sales\n");
	gotoxy(39,12);printf("[4] Thursday	Sales\n");
	gotoxy(39,13);printf("[5] Friday	Sales\n");
	gotoxy(39,14);printf("[6] Saturday	Sales\n");
	gotoxy(39,15);printf("[7] Weekly	Sales\n");
	gotoxy(39,16);printf("[8] Monthly	Sales");

	
	gotoxy(39,18);
	do{
		gotoxy(39,18);
		printf("SELECT: ");
		if(scanf("%d",&select) != 1 || select < 0 || select >=9){
			gotoxy(39,20);
			printf("INVALID INPUT!");
			fflush(stdin);
			validation = 0;
		}else{
			validation = 1;
		}	
		
	}while(!validation || select <  0 || select >= 9);
	fflush(stdin); // buffer to avoid invinsible characters that unnecessarily scanf fetching
	
	switch(select){
		case 0:
			system("cls");
			gotoxy(39,10);		
			loadingScreen();
			adminMenu();
			break;
		case 1:
			mon_sales_report();
			break;
		case 2:
			tues_sales_report();
			break;
 		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			break;
		case 7:
			weekly_sales_report();
			break;
		case 8:
			monthly_sales_report();
			break;
			
	}	
}

// ADMIN - SALES REPORT -MONDAY- //
void mon_sales_report(){
	
	system("cls");
	
	gotoxy(0,1);
	printf("press ANY KEY to go back to menu <<");

	gotoxy(41,2);printf("============================");
	gotoxy(41,3);printf("|| *MONDAY* SAlES REPORT ||");
	gotoxy(41,4);printf("============================");
	
	// buffers 
	char order_name[MAX];
	float order_subtotal;
	int order_quantity;
	int order_code;
	int order_count = 1;
	char order_date[MAX];
	
	float mon_sales;
	
	FILE *monday_sales_report = fopen("monday_sales_report.txt","r");
	
	gotoxy(5,6);
	printf("===================================================================================================");
	gotoxy(5,7);
	printf("ORDER COUNT\tITEM NAME\t\tQUANTITY\tSUBTOTAL\tTRANSACTION DATE\n");
	gotoxy(5,8);
	printf("===================================================================================================");
	
	while(fscanf(monday_sales_report,"%d %[^\n]%*c %d %f %[^\n]%*c",&order_code,order_name,&order_quantity,&order_subtotal,order_date) != EOF){
		
		gotoxy(5,8+order_count);
		printf("%-5d\t\t%-20s\t%5d\t%13.2f\t\t%-20s\n",order_count,order_name,order_quantity,order_subtotal,order_date);
		mon_sales += order_subtotal;
		order_count++;
	}
	fclose(monday_sales_report);
	

	gotoxy(80,1);
	printf("TODAY SALES: %.2f",mon_sales);
	getch();
	fflush(stdin);
	adminMenu();
	
	
	
}
void tues_sales_report(){
	
	
	system("cls");
	
	gotoxy(0,1);
	printf("press ANY KEY to go back to menu <<");

	gotoxy(41,2);printf("============================");
	gotoxy(41,3);printf("|| *TUESDAY* SAlES REPORT ||");
	gotoxy(41,4);printf("============================");
	
	// buffers 
	char order_name[MAX];
	float order_subtotal;
	int order_quantity;
	int order_code;
	int order_count = 1;
	char order_date[MAX];
	
	float tue_sales;
	
	FILE *tuesday_sales_report = fopen("tuesday_sales_report.txt","r");
	
	gotoxy(5,6);
	printf("===================================================================================================");
	gotoxy(5,7);
	printf("ORDER COUNT\tITEM NAME\t\tQUANTITY\tSUBTOTAL\tTRANSACTION DATE\n");
	gotoxy(5,8);
	printf("===================================================================================================");
	
	while(fscanf(tuesday_sales_report,"%d %[^\n]%*c %d %f %[^\n]%*c",&order_code,order_name,&order_quantity,&order_subtotal,order_date) != EOF){
		
		gotoxy(5,8+order_count);
		printf("%-5d\t\t%-20s\t%5d\t%13.2f\t\t%-20s\n",order_count,order_name,order_quantity,order_subtotal,order_date);
		tue_sales += order_subtotal;
		order_count++;
	}
	fclose(tuesday_sales_report);
	

	gotoxy(80,1);
	printf("TODAY SALES: %.2f",tue_sales);
	
	getch();
	fflush(stdin);
	adminMenu();
}



// ADMIN - SALES REPORT -WEEKLY-
void weekly_sales_report(){
	
	system("cls");
	fflush(stdin);	
	week_1();
	
}
void week_1(){
	
	fflush(stdin);
	// initialize buffers WEEK 1;
	char order_name_w1[MAX];
	int order_quantity_w1;
	float order_subtotal_w1;
	char order_date_w1[MAX];
	int order_code_w1;
	int order_count_w1 = 1;
	
	float week1_sales;
	float week1_total;
	
	char next_back;
	
	gotoxy(5,5);
	printf("WEEK 1: REPORT");
	gotoxy(5,6);
	printf("=============================================================================================");
	gotoxy(5,7);
	printf("ORDER COUNT\tITEM NAME\t\tQUANTITY\tSUBTOTAL\tTRANSACTION DATE\n");
	gotoxy(5,8);
	printf("=============================================================================================");
	FILE *weekly_sales_report = fopen("weekly_sales_report.txt","r");
	while(fscanf(weekly_sales_report,"%d %[^\n]%*c %d %f %[^\n]%*c",&order_code_w1,order_name_w1,&order_quantity_w1,&order_subtotal_w1,order_date_w1) != EOF){
		if(atoi(order_date_w1) <= 6){
			gotoxy(5,8+order_count_w1);
			printf("%-5d\t\t%-20s\t%5d\t%13.2f\t\t%-20s\n",order_count_w1,order_name_w1,order_quantity_w1,order_subtotal_w1,order_date_w1);
			order_count_w1++;	
			week1_sales += order_subtotal_w1;	
		}
	}
	fclose(weekly_sales_report);
	week1_total = week1_sales;
	gotoxy(5,4);
	printf("WEEK 1 SALES: %.2f",week1_total);
		
	gotoxy(0,1);
	printf("Press ANY KEY to go back to menu <<<");
	gotoxy(0,2);
	printf("Press 'N' > preview WEEK 2 REPORT: ");
	scanf("%c",&next_back);
	next_back = toupper(next_back);
	fflush(stdin);
	
	if(next_back == 'N'){
		system("cls");
		week_2();
	}
	else{
		adminMenu();
	}
	
	
}
void week_2(){
	
	fflush(stdin);
	
	char order_name_w2[MAX];
	int order_quantity_w2;
	float order_subtotal_w2;
	char order_date_w2[MAX];
	int order_code_w2;
	int order_count_w2 = 1;
	
	float week2_sales;
	float week2_total;
	char next_back;
	
	gotoxy(5,5);
	printf("WEEK 2: REPORT");
	gotoxy(5,6);
	printf("=============================================================================================");
	gotoxy(5,7);
	printf("ORDER COUNT\tITEM NAME\t\tQUANTITY\tSUBTOTAL\tTRANSACTION DATE\n");
	gotoxy(5,8);
	printf("=============================================================================================");
	FILE *weekly_sales_report = fopen("weekly_sales_report.txt","r");
	
	while(fscanf(weekly_sales_report,"%d %[^\n]%*c %d %f %[^\n]%*c",&order_code_w2,order_name_w2,&order_quantity_w2,&order_subtotal_w2,order_date_w2) != EOF){
		
		if(atoi(order_date_w2) > 6 && atoi(order_date_w2) <= 12){
			gotoxy(5,8+order_count_w2);
			printf("%-5d\t\t%-20s\t%5d\t%13.2f\t\t%-20s\n",order_count_w2,order_name_w2,order_quantity_w2,order_subtotal_w2,order_date_w2);
			week2_sales += order_subtotal_w2;
			order_count_w2++;
		}

	}
	fclose(weekly_sales_report);
	week2_total = week2_sales;
	gotoxy(5,4);
	printf("WEEK 2 SALES: %.2f",week2_total);
		
	gotoxy(0,1);
	printf("Press 'B' < go back WEEK 1");
	gotoxy(0,2);
	printf("Press 'N' > preview WEEK 3 REPORT: ");
	scanf("%c",&next_back);
	next_back = toupper(next_back);
	fflush(stdin);
	
	if(next_back == 'N'){
		system("cls");
		week_3();
	}
	else if(next_back == 'B'){
		system("cls");
		week_1();
	}
	else{
		adminMenu();
	}	
}
void week_3(){
	
	fflush(stdin);
	// initialize buffers WEEK 3;
	char order_name_w3[MAX];
	int order_quantity_w3;
	float order_subtotal_w3;
	char order_date_w3[MAX];
	int order_code_w3;
	int order_count_w3 = 1;
	
	float week3_sales;
	float week3_total;
	char next_back;
		// WEEK 3 REPORT	
	gotoxy(5,5);
	printf("WEEK 3: REPORT");
	gotoxy(5,6);
	printf("=============================================================================================");
	gotoxy(5,7);
	printf("ORDER COUNT\tITEM NAME\t\tQUANTITY\tSUBTOTAL\tTRANSACTION DATE\n");
	gotoxy(5,8);
	printf("=============================================================================================");
	FILE *weekly_sales_report = fopen("weekly_sales_report.txt","r");
	while(fscanf(weekly_sales_report,"%d %[^\n]%*c %d %f %[^\n]%*c",&order_code_w3,order_name_w3,&order_quantity_w3,&order_subtotal_w3,order_date_w3) != EOF){
		
		if(atoi(order_date_w3) > 12 && atoi(order_date_w3) <= 18){
			gotoxy(5,8+order_count_w3);
			printf("%-5d\t\t%-20s\t%5d\t%13.2f\t\t%-20s\n",order_count_w3,order_name_w3,order_quantity_w3,order_subtotal_w3,order_date_w3);
			week3_sales += order_subtotal_w3;
			order_count_w3++;
		}

	}
	fclose(weekly_sales_report);
	week3_total = week3_sales;
	gotoxy(5,4);
	printf("WEEK 3 SALES: %.2f",week3_total);
		
	gotoxy(0,1);
	printf("Press 'B' < go back WEEK 2");
	gotoxy(0,2);
	printf("Press 'N' > preview WEEK 4 REPORT: ");
	scanf("%c",&next_back);
	next_back = toupper(next_back);
	fflush(stdin);
	
	if(next_back == 'N'){
		system("cls");
		week_4();
	}
	else if(next_back == 'B'){
		system("cls");
		week_2();
	}
	else{
		adminMenu();
	}	
	
}
void week_4(){
	
	fflush(stdin);
	// initialize buffers WEEK 4;
	char order_name_w4[MAX];
	int order_quantity_w4;
	float order_subtotal_w4;
	char order_date_w4[MAX];
	int order_code_w4;
	int order_count_w4 = 1;
	
	
	float week4_sales;
	float week4_total;
	char next_back;
	
	// WEEK 4 REPORT	
	gotoxy(5,5);
	printf("WEEK 4: REPORT");
	gotoxy(5,6);
	printf("=============================================================================================");
	gotoxy(5,7);
	printf("ORDER COUNT\tITEM NAME\t\tQUANTITY\tSUBTOTAL\tTRANSACTION DATE\n");
	gotoxy(5,8);
	printf("=============================================================================================");
	FILE *weekly_sales_report = fopen("weekly_sales_report.txt","r");
	while(fscanf(weekly_sales_report,"%d %[^\n]%*c %d %f %[^\n]%*c",&order_code_w4,order_name_w4,&order_quantity_w4,&order_subtotal_w4,order_date_w4) != EOF){
		
		if(atoi(order_date_w4) > 18 && atoi(order_date_w4) <= 24){
			gotoxy(5,8+order_count_w4);
			printf("%-5d\t\t%-20s\t%5d\t%13.2f\t\t%-20s\n",order_count_w4,order_name_w4,order_quantity_w4,order_subtotal_w4,order_date_w4);
			week4_sales += order_subtotal_w4;
			order_count_w4++;
		}

	}
	fclose(weekly_sales_report);
	week4_total = week4_sales;
	gotoxy(5,4);
	printf("WEEK 4 SALES: %.2f",week4_total);	
	
	gotoxy(0,1);
	printf("Press 'B' < go back WEEK 3");
	gotoxy(0,2);
	printf("Press ANY KEY to exit ");
	scanf("%c",&next_back);
	next_back = toupper(next_back);
	fflush(stdin);
	
	if(next_back == 'B'){
		system("cls");
		week_3();
	}
	else{
		adminMenu();
	}
			
}


void monthly_sales_report(){
	
	fflush(stdin);
	system("cls");
	fflush(stdin);
	nov_report();
	
}
void nov_report(){
	
	fflush(stdin);
	// initialize buffers month 11;
	char order_name_nov[MAX];
	int order_quantity_nov;
	float order_subtotal_nov;
	char order_date_nov[MAX];
	char order_month_nov[MAX];
	int order_code_nov;
	int order_count_nov = 1;
	
	float nov_sales;
	float nov_total;
	char next_back;
		// month 11 REPORT	
	gotoxy(5,5);
	printf("MONTH 11: REPORT");
	gotoxy(5,6);
	printf("=============================================================================================");
	gotoxy(5,7);
	printf("ORDER COUNT\tITEM NAME\t\tQUANTITY\tSUBTOTAL\tTRANSACTION DATE\n");
	gotoxy(5,8);
	printf("=============================================================================================");
	FILE *monthly_sales_report = fopen("monthly_sales_report.txt","r");
	while(fscanf(monthly_sales_report,"%d %[^\n]%*c %d %f %[^\n]%*c %[^\n]%*c",&order_code_nov,order_name_nov,&order_quantity_nov,&order_subtotal_nov,order_date_nov,order_month_nov) != EOF){
		
		if(atoi(order_date_nov) <= 30 && atoi(order_month_nov) == 11){
			gotoxy(5,8+order_count_nov);
			printf("%-5d\t\t%-20s\t%5d\t%13.2f\t\t%-20s\n",order_count_nov,order_name_nov,order_quantity_nov,order_subtotal_nov,order_date_nov);
			nov_sales += order_subtotal_nov;
			order_count_nov++;
		}

	}
	fclose(monthly_sales_report);
	nov_total = nov_sales;
	gotoxy(5,4);
	printf("November Sales: %.2f",nov_total);
		
	gotoxy(0,1);
	printf("Press 'B' < go back October");
	gotoxy(0,2);
	printf("Press 'N' > preview December REPORT: ");
	scanf("%c",&next_back);
	next_back = toupper(next_back);
	fflush(stdin);
	
	if(next_back == 'N'){
		system("cls");
		dec_report();
	}
	else if(next_back == 'B'){
		system("cls");
	//	oct_report();
	}
	else{
		adminMenu();
	}	
}
void dec_report(){
	
	fflush(stdin);
	// initialize buffers MONTH 12;
	char order_name_dec[MAX];
	int order_quantity_dec;
	float order_subtotal_dec;
	char order_date_dec[MAX];
	char order_month_dec[MAX];
	int order_code_dec;
	int order_count_dec = 1;
	
	
	float dec_sales;
	float dec_total;
	char next_back;
	
	// WEEK 4 REPORT	
	gotoxy(5,5);
	printf("MONTH 12: REPORT");
	gotoxy(5,6);
	printf("=============================================================================================");
	gotoxy(5,7);
	printf("ORDER COUNT\tITEM NAME\t\tQUANTITY\tSUBTOTAL\tTRANSACTION DATE\n");
	gotoxy(5,8);
	printf("=============================================================================================");
	FILE *monthly_sales_report = fopen("monthly_sales_report.txt","r");
	while(fscanf(monthly_sales_report,"%d %[^\n]%*c %d %f %[^\n]%*c %[^\n]%*c",&order_code_dec,order_name_dec,&order_quantity_dec,&order_subtotal_dec,order_date_dec,order_month_dec) != EOF){
		
		if(atoi(order_date_dec) <= 30 && atoi(order_month_dec) == 12){
			gotoxy(5,8+order_count_dec);
			printf("%-5d\t\t%-20s\t%5d\t%13.2f\t\t%-20s\n",order_count_dec,order_name_dec,order_quantity_dec,order_subtotal_dec,order_date_dec);
			dec_sales += order_subtotal_dec;
			order_count_dec++;
		}

	}
	fclose(monthly_sales_report);
	dec_total = dec_sales;
	gotoxy(5,4);
	printf("December Sales: %.2f",dec_total);	
	
	gotoxy(0,1);
	printf("Press 'B' < go back November");
	gotoxy(0,2);
	printf("Press ANY KEY to exit ");
	scanf("%c",&next_back);
	next_back = toupper(next_back);
	fflush(stdin);
	
	if(next_back == 'B'){
		system("cls");
		nov_report();
	}
	else{
		adminMenu();
	}
	
}





// ADMIN - EDIT THE ITEMS OF MENU OF THE DAY //
void adminUpdateMenuItems(){
	
	system("cls");
	
	
//	int isDigit;
//	int n_items;
	int select_menu_day;
	int validation;

	gotoxy(0,1);printf("press 0 to go back to menu <<");
	
	gotoxy(39,4);	printf("============================");
	gotoxy(39,5);	printf("||	EDIT ITEM        ||");
	gotoxy(39,6);	printf("============================");
	
	
	gotoxy(39,9); printf("[1] Monday    	MENU\n");
	gotoxy(39,10);printf("[2] Tuesday	MENU\n");
	gotoxy(39,11);printf("[3] Wednesday 	MENU\n");
	gotoxy(39,12);printf("[4] Thursday  	MENU\n");
	gotoxy(39,13);printf("[5] Friday    	MENU\n");
	gotoxy(39,14);printf("[6] Saturday  	MENU");
	
	gotoxy(39,16);
	do{
		gotoxy(39,16);
		printf("SELECT: ");
		if(scanf("%d",&select_menu_day) != 1 || select_menu_day < 0 || select_menu_day >=7){
			gotoxy(39,18);
			printf("INVALID INPUT!");
			fflush(stdin);
			validation = 0;
		}else{
			validation = 1;
		}	
		
	}while(!validation || select_menu_day <  0 || select_menu_day >= 7);
	fflush(stdin); // buffer to avoid invinsible characters that unnecessarily scanf fetching
	
	switch(select_menu_day){
		case 0:
			system("cls");
			gotoxy(39,10);		
			loadingScreen();
			adminMenu();
			break;
		case 1:
			mon_edit_menu();
			break;
		case 2:
			tues_edit_menu();
			break;
 		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			break;
			
	}
		
}

// ADMIN - EDIT ITEM *MONDAY* //
void mon_edit_menu(){
	
	system("cls");
	
	int select_category;
	int validation;
	
	gotoxy(0,1);printf("press 0 to go back to menu <<");
	
	gotoxy(4,4);printf("========================");
	gotoxy(4,5);printf("|| EDIT ITEM *MONDAY* ||");
	gotoxy(4,6);printf("========================");
	
	gotoxy(4,7);printf("Select Category:");
	gotoxy(4,8);printf("[1] FOOD ITEMS");
	gotoxy(4,9);printf("[2] BEVERAGE ITEMS");
	
	gotoxy(4,10);
	do{
		gotoxy(4,10);
		printf("SELECT: ");
		if(scanf("%d",&select_category) != 1 || select_category < 0 || select_category >=3){
			gotoxy(4,12);
			printf("INVALID INPUT!");
			fflush(stdin);
			validation = 0;
		}else{
			validation = 1;
		}	
		
	}while(!validation || select_category <  0 || select_category >=3);
	fflush(stdin); // buffer to avoid invinsible characters that unnecessarily scanf fetching
	
	switch(select_category){
		case 0:
			system("cls");
			gotoxy(39,10);
			loadingScreen();	
			adminUpdateMenuItems();
			break;
		case 1:
			edit_food_monday();
			break;
		case 2:
			edit_beverage_monday();
			break;
		
		
	}
	
	
	
}
// ADMIN - EDIT FOOD DETAILS *MONDAY* //
void edit_food_monday(){
	
	// initialize buffers
	char food_name[MAX][MAX];
	int food_id;
	float food_price;
	char food_status[MAX];
	
	// variables for modification //
	char new_food_name[MAX];
	float new_food_price;
	char new_food_status[MAX];
	
	char select_status;
	int select_food_id;
	int select_update;
	char y_n;
	char proceed;
	int validation;
	int isFound;
	int pos = 0;
	int name_valid;
	int i = 0;
	
	gotoxy(45,3);
	printf("-SELECTED CATEGORY- : *FOOD*"); // implement input validation
	gotoxy(45,4);
	printf("Enter the FOOD ID you want to Edit: ");
	gotoxy(45,5);
	scanf("%d",&select_food_id);
	fflush(stdin);
	


	FILE *monday_menu_F = fopen("monday_menu_F.txt","r");
	FILE *monday_menu_F_temp = fopen("monday_menu_F_temp.txt","w"); // temporary text file for modification
	
	while(fscanf(monday_menu_F,"%d %[^\n]%*c %f %[^\n]%*c",&food_id,food_name[pos],&food_price,food_status) != EOF){
		
		if(food_id == select_food_id){
			
			isFound = 1;
			
			gotoxy(45,7);
			printf("------Current Item Details------");
			gotoxy(45,8);
			printf("Food ID:\t\t%-5d\n",food_id);
			gotoxy(45,9);
			printf("Item:\t\t%-20s\n",food_name[pos]);
			gotoxy(45,10);
			printf("Price:\t\t%-5.2f\n",food_price);
			gotoxy(45,11);
			printf("Status:\t\t%-20s\n",food_status);
			gotoxy(45,12);
			printf("---------------------------------\n");
			gotoxy(45,14);
			printf("-Select Details to Edit-");
			gotoxy(45,15);
			printf("[1] Food item Name");
			gotoxy(45,16);
			printf("[2] Food item Price");
			gotoxy(45,17);
			printf("[3] Food item Status");
			gotoxy(45,18);
			printf("SELECT: ");	// input validation
			scanf("%d",&select_update);
			fflush(stdin);
			// UPDATE ITEM NAME
			if(select_update == 1){
				
				gotoxy(45,20);	
				printf("Enter New Item Name: ");
				scanf("%[^\n]s",new_food_name);	
				fflush(stdin);				
												
				for(i = 0; i < pos; i++){
					
					if(strcmp(new_food_name,food_name[i]) == 0){
						gotoxy(45,21);
						printf("Name Already Exist. Try Again");
						name_valid = 1;
							
					}
					else{
						name_valid = 0;
					}
								
				}
				
				if(name_valid){
					gotoxy(45,20);	
					printf("Enter New Item Name: ");
					scanf("%[^\n]s",new_food_name);	
					fflush(stdin);
				}
				
				fprintf(monday_menu_F_temp,"%d\n %s\n %f\n %s\n",food_id,new_food_name,food_price,food_status);	
				
						
			}
			// UPDATE PRICE
			else if(select_update == 2){
					gotoxy(45,20);
					printf("Enter New Item price: ");
					scanf("%f",&new_food_price);
					fflush(stdin);
					fprintf(monday_menu_F_temp,"%d\n %s\n %f\n %s\n",food_id,food_name[pos],new_food_price,food_status);
			
			}
			// UPDATE STATUS
			else if(select_update == 3){
					gotoxy(45,20);
					printf("Select Status of the Item:"); 
					gotoxy(45,21);
					printf("input 'A' for -Available- /  input 'S' for -Sold out- : ");
					scanf("%c",&select_status);
					select_status = toupper(select_status);
					fflush(stdin);
					
					if(select_status == 'A'){
						strcpy(new_food_status,"Available");
						fprintf(monday_menu_F_temp,"%d\n %s\n %f\n %s\n",food_id,food_name[pos],food_price,new_food_status);
					}
					else if(select_status == 'S'){
						strcpy(new_food_status,"Sold out");
						fprintf(monday_menu_F_temp,"%d\n %s\n %f\n %s\n",food_id,food_name[pos],food_price,new_food_status);
					}				
			}	
				
		
		} 
		else if(food_id != select_food_id){
			fprintf(monday_menu_F_temp,"%d\n %s\n %f\n %s\n",food_id,food_name[pos],food_price,food_status);

		}
		pos++;
	
	
		
		
	}
	fclose(monday_menu_F);
	fclose(monday_menu_F_temp);
	
	
	
	if(isFound){
		gotoxy(45,24);
		printf("ITEM UPDATED!");
		remove("monday_menu_F.txt");
		rename("monday_menu_F_temp.txt","monday_menu_F.txt");
		gotoxy(45,26);
		printf("Press ANY KEY to go back to Menu <<<");	
		getch();
		fflush(stdin);
		adminMenu();	
	}else{
		gotoxy(45,24);
		if(!isFound){
			printf("ID DOES NOT EXIST!");	
		}
		remove("monday_menu_F.txt");
		rename("monday_menu_F_temp.txt","monday_menu_F.txt");
		gotoxy(45,26);
		printf("Press ANY KEY to go back to Menu <<<");	
		getch();
		fflush(stdin);
		adminMenu();			
	}

	
	
}
// ADMIN - EDIT BEVERAGE DETAILS *MONDAY* //
void edit_beverage_monday(){
	
	// initialize buffers
	char bev_name[MAX][MAX];
	int bev_id;
	float bev_price;
	char bev_status[MAX];
	
	// variables for modification //

	char new_bev_name[MAX];
	float new_bev_price;
	char new_bev_status[MAX];
	
	char select_status;
	int select_bev_id;
	int select_update;
	char y_n;
	char proceed;
	int isValid = 0;
	int isFound;
	int pos = 0;
	int name_valid;
	int i = 0;
		
	gotoxy(45,3);
	printf("-SELECTED CATEGORY- : *BEVERAGE*");
	gotoxy(45,4);
	printf("Enter the BEVERAGE ID you want to Edit: ");
	scanf("%d",&select_bev_id);
	fflush(stdin);
	
	FILE *monday_menu_B = fopen("monday_menu_B.txt","r");
	FILE *monday_menu_B_temp = fopen("monday_menu_B_temp.txt","w"); // temporary text file for modification
	

	while(fscanf(monday_menu_B,"%d %[^\n]%*c %f %[^\n]%*c",&bev_id,bev_name[pos],&bev_price,bev_status) != EOF){
		
		if(bev_id == select_bev_id){
			
			isFound = 1;
			
			gotoxy(45,7);
			printf("------Current Item Details------");
			gotoxy(45,8);
			printf("Food ID:\t\t%-5d\n",bev_id);
			gotoxy(45,9);
			printf("Item:\t\t%-20s\n",bev_name[pos]);
			gotoxy(45,10);
			printf("Price:\t\t%-5.2f\n",bev_price);
			gotoxy(45,11);
			printf("Status:\t\t%-20s\n",bev_status);
			gotoxy(45,12);
			printf("-----------------------------------\n");
			gotoxy(45,13);
			printf("-Select Details to Edit-");
			gotoxy(45,14);
			printf("[1] Beverage item Name");
			gotoxy(45,15);
			printf("[2] Beverage item Price");
			gotoxy(45,16);
			printf("[3] Beverage item Status");
			gotoxy(45,18);
			printf("SELECT: ");	// input validation
			scanf("%d",&select_update);
			fflush(stdin);
			//  BEV ITEM NAME
			if(select_update == 1){
				
					gotoxy(45,19);
					printf("Enter New Item Name: ");
					scanf("%[^\n]s",new_bev_name);
					fflush(stdin);
					
				for(i = 0; i < pos; i++){
					
					if(strcmp(new_bev_name,bev_name[i]) == 0){
						gotoxy(45,21);
						printf("Name Already Exist. Try Again");
						name_valid = 1;
							
					}
					else{
						name_valid = 0;
					}
								
				}
				
				if(name_valid){
					gotoxy(45,20);	
					printf("Enter New Item Name: ");
					scanf("%[^\n]s",new_bev_name);	
					fflush(stdin);
				}
				
					fprintf(monday_menu_B_temp,"%d\n %s\n %f\n %s\n",bev_id,new_bev_name,bev_price,bev_status);			
			}
			
			
			
			// BEV ITEM PRICE
			else if(select_update == 2){
					gotoxy(45,19);
					printf("Enter New Item price: ");
					scanf("%f",&new_bev_price);
					fflush(stdin);
					fprintf(monday_menu_B_temp,"%d\n %s\n %f\n %s\n",bev_id,bev_name[pos],new_bev_price,bev_status);				
			}
			
			// BEV ITEM STATUS
			else if(select_update == 3){
					gotoxy(45,20);
					printf("Select Status of the Item:"); 
					gotoxy(45,21);
					printf("input 'A' for -Available- /  input 'S' for -Sold out- : ");
					scanf("%c",&select_status);
					select_status = toupper(select_status);
					fflush(stdin);
					// AVAILABLE
					if(select_status == 'A'){
						strcpy(new_bev_status,"Available");
						fprintf(monday_menu_B_temp,"%d\n %s\n %f\n %s\n",bev_id,bev_name[pos],bev_price,new_bev_status);	
					}
					// SOLD OUT 
					else if (select_status == 'S'){
						strcpy(new_bev_status,"Sold out");
						fprintf(monday_menu_B_temp,"%d\n %s\n %f\n %s\n",bev_id,bev_name[pos],bev_price,new_bev_status);	
					}	
								
			}	
				

		
		} 
		else if(bev_id != select_bev_id){
			fprintf(monday_menu_B_temp,"%d\n %s\n %f\n %s\n",bev_id,bev_name[pos],bev_price,bev_status);
		}
		pos++;
	
		
	}
	fclose(monday_menu_B);
	fclose(monday_menu_B_temp);
	
	if(isFound){
		
		gotoxy(45,24);
		printf("ITEM UPDATED!");
		remove("monday_menu_B.txt");
		rename("monday_menu_B_temp.txt","monday_menu_B.txt");
		gotoxy(45,26);
		printf("Press ANY KEY to go back to Menu <<<");	
		getch();
		fflush(stdin);
		adminMenu();
	}
	else{
		
		gotoxy(45,24);
		printf("ID DOES NOT EXIST");
		remove("monday_menu_B.txt");
		rename("monday_menu_B_temp.txt","monday_menu_B.txt");
		gotoxy(45,26);
		printf("Press ANY KEY to go back to Menu <<<");	
		getch();
		fflush(stdin);
		adminMenu();
	}
}

// ADMIN - EDIT ITEM *TUESDAY* //
void tues_edit_menu(){
	system("cls");
	
	int select_category;
	int validation;
	
	gotoxy(0,1);printf("press 0 to go back to menu <<");
	
	gotoxy(4,4);printf("========================");
	gotoxy(4,5);printf("|| EDIT ITEM *TUESDAY* ||");
	gotoxy(4,6);printf("========================");
	
	gotoxy(4,7);printf("Select Category:");
	gotoxy(4,8);printf("[1] FOOD ITEMS");
	gotoxy(4,9);printf("[2] BEVERAGE ITEMS");
	
	gotoxy(4,10);
	do{
		gotoxy(4,10);
		printf("SELECT: ");
		if(scanf("%d",&select_category) != 1 || select_category < 0 || select_category >=3){
			gotoxy(4,12);
			printf("INVALID INPUT!");
			fflush(stdin);
			validation = 0;
		}else{
			validation = 1;
		}	
		
	}while(!validation || select_category <  0 || select_category >=3);
	fflush(stdin); // buffer to avoid invinsible characters that unnecessarily scanf fetching
	
	switch(select_category){
		case 0:
			system("cls");
			gotoxy(39,10);
			loadingScreen();	
			adminUpdateMenuItems();
			break;
		case 1:
			edit_food_tuesday();
			break;
		case 2:
			edit_beverage_tuesday();
			break;
		
		
	}
	
	

}
void edit_food_tuesday(){

// initialize buffers
	char food_name[MAX][MAX];
	int food_id;
	float food_price;
	char food_status[MAX];
	
	// variables for modification //
	char new_food_name[MAX];
	float new_food_price;
	char new_food_status[MAX];
	
	char select_status;
	int select_food_id;
	int select_update;
	char y_n;
	char proceed;
	int validation;
	int isFound;
	int pos = 0;
	int name_valid;
	int i = 0;
	
	gotoxy(45,3);
	printf("-SELECTED CATEGORY- : *FOOD*"); // implement input validation
	gotoxy(45,4);
	printf("Enter the FOOD ID you want to Edit: ");
	gotoxy(45,5);
	scanf("%d",&select_food_id);
	fflush(stdin);
	


	FILE *tuesday_menu_F = fopen("tuesday_menu_F.txt","r");
	FILE *tuesday_menu_F_temp = fopen("tuesday_menu_F_temp.txt","w"); // temporary text file for modification
	
	while(fscanf(tuesday_menu_F,"%d %[^\n]%*c %f %[^\n]%*c",&food_id,food_name[pos],&food_price,food_status) != EOF){
		
		if(food_id == select_food_id){
			
			isFound = 1;
			
			gotoxy(45,7);
			printf("------Current Item Details------");
			gotoxy(45,8);
			printf("Food ID:\t\t%-5d\n",food_id);
			gotoxy(45,9);
			printf("Item:\t\t%-20s\n",food_name[pos]);
			gotoxy(45,10);
			printf("Price:\t\t%-5.2f\n",food_price);
			gotoxy(45,11);
			printf("Status:\t\t%-20s\n",food_status);
			gotoxy(45,12);
			printf("---------------------------------\n");
			gotoxy(45,14);
			printf("-Select Details to Edit-");
			gotoxy(45,15);
			printf("[1] Food item Name");
			gotoxy(45,16);
			printf("[2] Food item Price");
			gotoxy(45,17);
			printf("[3] Food item Status");
			gotoxy(45,18);
			printf("SELECT: ");	// input validation
			scanf("%d",&select_update);
			fflush(stdin);
			// UPDATE ITEM NAME
			if(select_update == 1){
				
				gotoxy(45,20);	
				printf("Enter New Item Name: ");
				scanf("%[^\n]s",new_food_name);	
				fflush(stdin);				
												
				for(i = 0; i < pos; i++){
					
					if(strcmp(new_food_name,food_name[i]) == 0){
						gotoxy(45,21);
						printf("Name Already Exist. Try Again");
						name_valid = 1;
							
					}
					else{
						name_valid = 0;
					}
								
				}
				
				if(name_valid){
					gotoxy(45,20);	
					printf("Enter New Item Name: ");
					scanf("%[^\n]s",new_food_name);	
					fflush(stdin);
				}
				
				fprintf(tuesday_menu_F_temp,"%d\n %s\n %f\n %s\n",food_id,new_food_name,food_price,food_status);	
				
						
			}
			// UPDATE PRICE
			else if(select_update == 2){
					gotoxy(45,20);
					printf("Enter New Item price: ");
					scanf("%f",&new_food_price);
					fflush(stdin);
					fprintf(tuesday_menu_F_temp,"%d\n %s\n %f\n %s\n",food_id,food_name[pos],new_food_price,food_status);
			
			}
			// UPDATE STATUS
			else if(select_update == 3){
					gotoxy(45,20);
					printf("Select Status of the Item: input 'A' for -Available- /  input 'S' for -Sold out- : ");
					scanf("%c",&select_status);
					select_status = toupper(select_status);
					fflush(stdin);
					
					if(select_status == 'A'){
						strcpy(new_food_status,"Available");
						fprintf(tuesday_menu_F_temp,"%d\n %s\n %f\n %s\n",food_id,food_name[pos],food_price,new_food_status);
					}
					else if(select_status == 'S'){
						strcpy(new_food_status,"Sold out");
						fprintf(tuesday_menu_F_temp,"%d\n %s\n %f\n %s\n",food_id,food_name[pos],food_price,new_food_status);
					}				
			}	
				
		
		} 
		else if(food_id != select_food_id){
			fprintf(tuesday_menu_F_temp,"%d\n %s\n %f\n %s\n",food_id,food_name[pos],food_price,food_status);

		}
		pos++;
	
	
		
		
	}
	fclose(tuesday_menu_F);
	fclose(tuesday_menu_F_temp);
	
	
	
	if(isFound){
		gotoxy(45,23);
		printf("ITEM UPDATED!");
		remove("tuesday_menu_F.txt");
		rename("tuesday_menu_F_temp.txt","tuesday_menu_F.txt");
		gotoxy(45,25);
		printf("Press ANY KEY to go back to Menu <<<");	
		getch();
		fflush(stdin);
		adminMenu();	
	}else{
		gotoxy(45,23);
		if(!isFound){
			printf("ID DOES NOT EXIST!");	
		}
		remove("tuesday_menu_F.txt");
		rename("tuesday_menu_F_temp.txt","tuesday_menu_F.txt");
		gotoxy(45,25);
		printf("Press ANY KEY to go back to Menu <<<");	
		getch();
		fflush(stdin);
		adminMenu();			
	}

	
}
void edit_beverage_tuesday(){
	
	// initialize buffers
	char bev_name[MAX][MAX];
	int bev_id;
	float bev_price;
	char bev_status[MAX];
	
	// variables for modification //

	char new_bev_name[MAX];
	float new_bev_price;
	char new_bev_status[MAX];
	
	char select_status;
	int select_bev_id;
	int select_update;
	char y_n;
	char proceed;
	int isValid = 0;
	int isFound;
	int pos = 0;
	int name_valid;
	int i = 0;
		
	gotoxy(45,3);
	printf("-SELECTED CATEGORY- : *BEVERAGE*");
	gotoxy(45,4);
	printf("Enter the BEVERAGE ID you want to Edit: ");
	scanf("%d",&select_bev_id);
	fflush(stdin);
	
	FILE *tuesday_menu_B = fopen("tuesday_menu_B.txt","r");
	FILE *tuesday_menu_B_temp = fopen("tuesday_menu_B_temp.txt","w"); // temporary text file for modification
	

	while(fscanf(tuesday_menu_B,"%d %[^\n]%*c %f %[^\n]%*c",&bev_id,bev_name[pos],&bev_price,bev_status) != EOF){
		
		if(bev_id == select_bev_id){
			
			isFound = 1;
			
			gotoxy(45,7);
			printf("------Current Item Details------");
			gotoxy(45,8);
			printf("Food ID:\t\t%-5d\n",bev_id);
			gotoxy(45,9);
			printf("Item:\t\t%-20s\n",bev_name[pos]);
			gotoxy(45,10);
			printf("Price:\t\t%-5.2f\n",bev_price);
			gotoxy(45,11);
			printf("Status:\t\t%-20s\n",bev_status);
			gotoxy(45,12);
			printf("-----------------------------------\n");
			gotoxy(45,13);
			printf("-Select Details to Edit-");
			gotoxy(45,14);
			printf("[1] Beverage item Name");
			gotoxy(45,15);
			printf("[2] Beverage item Price");
			gotoxy(45,16);
			printf("[3] Beverage item Status");
			gotoxy(45,18);
			printf("SELECT: ");	// input validation
			scanf("%d",&select_update);
			fflush(stdin);
			//  BEV ITEM NAME
			if(select_update == 1){
				
					gotoxy(45,19);
					printf("Enter New Item Name: ");
					scanf("%[^\n]s",new_bev_name);
					fflush(stdin);
					
				for(i = 0; i < pos; i++){
					
					if(strcmp(new_bev_name,bev_name[i]) == 0){
						gotoxy(45,21);
						printf("Name Already Exist. Try Again");
						name_valid = 1;
							
					}
					else{
						name_valid = 0;
					}
								
				}
				
				if(name_valid){
					gotoxy(45,20);	
					printf("Enter New Item Name: ");
					scanf("%[^\n]s",new_bev_name);	
					fflush(stdin);
				}
				
				fprintf(tuesday_menu_B_temp,"%d\n %s\n %f\n %s\n",bev_id,new_bev_name,bev_price,bev_status);			
			}
			
			
			
			// BEV ITEM PRICE
			else if(select_update == 2){
					gotoxy(45,19);
					printf("Enter New Item price: ");
					scanf("%f",&new_bev_price);
					fflush(stdin);
					fprintf(tuesday_menu_B_temp,"%d\n %s\n %f\n %s\n",bev_id,bev_name[pos],new_bev_price,bev_status);				
			}
			
			// BEV ITEM STATUS
			else if(select_update == 3){
					gotoxy(45,19);
					printf("Select Status of the Item: input 'A' for -Available- /  input 'S' for -Sold out- : ");
					scanf("%c",&select_status);
					select_status = toupper(select_status);
					fflush(stdin);
					// AVAILABLE
					if(select_status == 'A'){
						strcpy(new_bev_status,"Available");
						fprintf(tuesday_menu_B_temp,"%d\n %s\n %f\n %s\n",bev_id,bev_name[pos],bev_price,new_bev_status);	
					}
					// SOLD OUT 
					else if (select_status == 'S'){
						strcpy(new_bev_status,"Sold out");
						fprintf(tuesday_menu_B_temp,"%d\n %s\n %f\n %s\n",bev_id,bev_name[pos],bev_price,new_bev_status);	
					}	
								
			}	
				

		
		} 
		else if(bev_id != select_bev_id){
			fprintf(tuesday_menu_B_temp,"%d\n %s\n %f\n %s\n",bev_id,bev_name[pos],bev_price,bev_status);
		}
		pos++;
	
		
	}
	fclose(tuesday_menu_B);
	fclose(tuesday_menu_B_temp);
	
	if(isFound){
		
		gotoxy(45,23);
		printf("ITEM UPDATED!");
		remove("tuesday_menu_B.txt");
		rename("tuesday_menu_B_temp.txt","tuesday_menu_B.txt");
		gotoxy(45,25);
		printf("Press ANY KEY to go back to Menu <<<");	
		getch();
		fflush(stdin);
		adminMenu();
	}
	else{
		
		gotoxy(45,23);
		printf("ID DOES NOT EXIST");
		remove("tuesday_menu_B.txt");
		rename("tuesday_menu_B_temp.txt","monday_menu_B.txt");
		gotoxy(45,25);
		printf("Press ANY KEY to go back to Menu <<<");	
		getch();
		fflush(stdin);
		adminMenu();
	}	
}



// ADMIN - DELETE THE ITEMS OF MENU OF THE DAY //
void adminDeleteMenuItems(){
	
	system("cls");
	
	
//	int isDigit;
//	int n_items;
	int select_menu_day;
	int validation;

	gotoxy(0,1);printf("press 0 to go back to menu <<");
	
	gotoxy(39,4);	printf("==============================");
	gotoxy(39,5);	printf("||	DELETE ITEM        ||");
	gotoxy(39,6);	printf("==============================");
	
	
	gotoxy(39,9); printf("[1] Monday    	MENU\n");
	gotoxy(39,10);printf("[2] Tuesday	MENU\n");
	gotoxy(39,11);printf("[3] Wednesday 	MENU\n");
	gotoxy(39,12);printf("[4] Thursday  	MENU\n");
	gotoxy(39,13);printf("[5] Friday    	MENU\n");
	gotoxy(39,14);printf("[6] Saturday  	MENU");
	
	gotoxy(39,16);
	do{
		gotoxy(39,16);
		printf("SELECT: ");
		if(scanf("%d",&select_menu_day) != 1 || select_menu_day < 0 || select_menu_day >=7){
			gotoxy(39,18);
			printf("INVALID INPUT!");
			fflush(stdin);
			validation = 0;
		}else{
			validation = 1;
		}	
		
	}while(!validation || select_menu_day <  0 || select_menu_day >= 7);
	fflush(stdin); // buffer to avoid invinsible characters that unnecessarily scanf fetching
	
	switch(select_menu_day){
		case 0:
			system("cls");
			gotoxy(39,10);		
			loadingScreen();
			adminMenu();
			break;
		case 1:
			mon_delete_menu();
			break;
		case 2:
			tues_delete_menu();
			break;
 		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			break;
			
	}	
}

// ADMIN - DELETE THE ITEMS *MONDAY* //
void mon_delete_menu(){
	
	system("cls");
	
	int select_category;
	int validation;
	
	gotoxy(0,1);printf("press 0 to go back to menu <<");
	
	gotoxy(4,4);printf("==========================");
	gotoxy(4,5);printf("|| DELETE ITEM *MONDAY* ||");
	gotoxy(4,6);printf("==========================");
	
	gotoxy(4,7);printf("Select Category:");
	gotoxy(4,8);printf("[1] FOOD ITEMS");
	gotoxy(4,9);printf("[2] BEVERAGE ITEMS");
	
	gotoxy(4,10);
	do{
		gotoxy(4,10);
		printf("SELECT: ");
		if(scanf("%d",&select_category) != 1 || select_category < 0 || select_category >=3){
			gotoxy(4,12);
			printf("INVALID INPUT!");
			fflush(stdin);
			validation = 0;
		}else{
			validation = 1;
		}	
		
	}while(!validation || select_category <  0 || select_category >=3);
	fflush(stdin); // buffer to avoid invinsible characters that unnecessarily scanf fetching
	
	switch(select_category){
		case 0:
			system("cls");
			gotoxy(39,10);
			loadingScreen();	
			adminDeleteMenuItems();
			break;
		case 1:
			delete_food_monday();
			break;
		case 2:
			delete_beverage_monday();
			break;
		
		
	}	
}
// ADMIN - DELETE FOOD ITEM *MONDAY* //
void delete_food_monday(){
	
	// initialize buffers
	char food_name[MAX];
	int food_id;
	float food_price;
	char food_status[MAX];
	
	char y_n;
	char proceed;
	int isValid = 0;
	int select_food_id;
	int isFound;
	
	gotoxy(45,3);
	printf("-SELECTED CATEGORY- : *FOOD*");
	gotoxy(45,4);
	printf("Enter the FOOD ID you want to Delete: ");
	gotoxy(45,5);
	scanf("%d",&select_food_id);
	fflush(stdin);

	FILE *monday_menu_F = fopen("monday_menu_F.txt","r");
	FILE *monday_menu_F_temp = fopen("monday_menu_F_temp.txt","w"); // temporary text file for modification
	
	while(fscanf(monday_menu_F,"%d %[^\n]%*c %f %[^\n]%*c",&food_id,food_name,&food_price,food_status) != EOF){
		
		if(food_id != select_food_id){
			fprintf(monday_menu_F_temp,"%d\n %s\n %f\n %s\n",food_id,food_name,food_price,food_status);
		}
		
		if(food_id == select_food_id){
			
			isFound = 1;
			
			gotoxy(45,7);
			printf("------Current Item Details------");
			gotoxy(45,8);
			printf("Food ID:\t\t%-5d\n",food_id);
			gotoxy(45,9);
			printf("Item:\t\t%-20s\n",food_name);
			gotoxy(45,10);
			printf("Price:\t\t%-5.2f\n",food_price);
			gotoxy(45,11);
			printf("Status:\t\t%-20s\n",food_status);
			gotoxy(45,12);
			printf("---------------------------------\n");
			gotoxy(45,14);
					
		} 
		
		
	}
	fclose(monday_menu_F);
	fclose(monday_menu_F_temp);

	if(isFound){
		gotoxy(45,20);
		printf("ITEM DELETED SUCCESSFULLY!");
		remove("monday_menu_F.txt");
		rename("monday_menu_F_temp.txt","monday_menu_F.txt");
		gotoxy(45,21);
		printf("Press ANY KEY to go back to Menu <<<");
		getch();
		fflush(stdin);
		adminMenu();
		
	}else{
		gotoxy(45,20);
		if(!isFound){
		   printf("ID DOES NOT EXIST");
		   
		}
		remove("monday_menu_F.txt");
		rename("monday_menu_F_temp.txt","monday_menu_F.txt");
		gotoxy(45,21);
		printf("Press ANY KEY to go back to Menu <<<");
		getch();
		fflush(stdin);
		adminMenu();
	}

		
}	
// ADMIN - DELETE BEVERAGE ITEM *MONDAY* //
void delete_beverage_monday(){
	
	// initialize buffers
	char bev_name[MAX];
	int bev_id;
	float bev_price;
	char bev_status[MAX];
	
	
	char y_n;

	int isValid = 0;
	int select_bev_id;
	int isFound;
	
	gotoxy(45,3);
	printf("-SELECTED CATEGORY- : *BEVERAGE*");
	gotoxy(45,4);
	printf("Enter the BEVERAGE ID you want to Delete: ");
	gotoxy(45,5);
	scanf("%d",&select_bev_id);
	fflush(stdin);

	FILE *monday_menu_B = fopen("monday_menu_B.txt","r");
	FILE *monday_menu_B_temp = fopen("monday_menu_B_temp.txt","w"); // temporary text file for modification
	
	while(fscanf(monday_menu_B,"%d %[^\n]%*c %f %[^\n]%*c",&bev_id,bev_name,&bev_price,bev_status) != EOF){
		
		if(bev_id != select_bev_id){
			fprintf(monday_menu_B_temp,"%d\n %s\n %f\n %s\n",bev_id,bev_name,bev_price,bev_status);
		}
		
		if(bev_id == select_bev_id){
			
			isFound = 1;
			
			gotoxy(45,7);
			printf("------Current Item Details------");
			gotoxy(45,8);
			printf("Food ID:\t\t%-5d\n",bev_id);
			gotoxy(45,9);
			printf("Item:\t\t%-20s\n",bev_name);
			gotoxy(45,10);
			printf("Price:\t\t%-5.2f\n",bev_price);
			gotoxy(45,11);
			printf("Status:\t\t%-20s\n",bev_status);
			gotoxy(45,12);
			printf("---------------------------------\n");
		
			
			
					
		} 
		
		
	}
	fclose(monday_menu_B);
	fclose(monday_menu_B_temp);

	if(isFound){
		gotoxy(45,20);
		printf("ITEM DELETED SUCCESSFULLY!");
		remove("monday_menu_B.txt");
		rename("monday_menu_B_temp.txt","monday_menu_B.txt");
		gotoxy(45,21);
		printf("Press ANY KEY to go back to Menu <<<");
		getch();
		fflush(stdin);
		adminMenu();
		
	}else{
		gotoxy(45,20);
		if(!isFound){
		   printf("ID DOES NOT EXIST");
		}
		remove("monday_menu_B.txt");
		rename("monday_menu_B_temp.txt","monday_menu_B.txt");
		gotoxy(45,21);
		printf("Press ANY KEY to go back to Menu <<<");
		getch();
		fflush(stdin);
		adminMenu();
	}


}

// ADMIN - DELETE THE ITEMS *TUESDAY* //
void tues_delete_menu(){
	
	system("cls");
	
	int select_category;
	int validation;
	
	gotoxy(0,1);printf("press 0 to go back to menu <<");
	
	gotoxy(4,4);printf("==========================");
	gotoxy(4,5);printf("|| DELETE ITEM *TUESDAY* ||");
	gotoxy(4,6);printf("==========================");
	
	gotoxy(4,7);printf("Select Category:");
	gotoxy(4,8);printf("[1] FOOD ITEMS");
	gotoxy(4,9);printf("[2] BEVERAGE ITEMS");
	
	gotoxy(4,10);
	do{
		gotoxy(4,10);
		printf("SELECT: ");
		if(scanf("%d",&select_category) != 1 || select_category < 0 || select_category >=3){
			gotoxy(4,12);
			printf("INVALID INPUT!");
			fflush(stdin);
			validation = 0;
		}else{
			validation = 1;
		}	
		
	}while(!validation || select_category <  0 || select_category >=3);
	fflush(stdin); // buffer to avoid invinsible characters that unnecessarily scanf fetching
	
	switch(select_category){
		case 0:
			system("cls");
			gotoxy(39,10);
			loadingScreen();	
			adminDeleteMenuItems();
			break;
		case 1:
			delete_food_tuesday();
			break;
		case 2:
			delete_beverage_tuesday();
			break;
		
		
	}	
}
void delete_food_tuesday(){
	
	char food_name[MAX];
	int food_id;
	float food_price;
	char food_status[MAX];
	
	char y_n;
	char proceed;
	int isValid = 0;
	int select_food_id;
	int isFound;
	
	gotoxy(45,3);
	printf("-SELECTED CATEGORY- : *FOOD*");
	gotoxy(45,4);
	printf("Enter the FOOD ID you want to Delete: ");
	gotoxy(45,5);
	scanf("%d",&select_food_id);
	fflush(stdin);

	FILE *tuesday_menu_F = fopen("tuesday_menu_F.txt","r");
	FILE *tuesday_menu_F_temp = fopen("tuesday_menu_F_temp.txt","w"); // temporary text file for modification
	
	while(fscanf(tuesday_menu_F,"%d %[^\n]%*c %f %[^\n]%*c",&food_id,food_name,&food_price,food_status) != EOF){
		
		if(food_id != select_food_id){
			fprintf(tuesday_menu_F_temp,"%d\n %s\n %f\n %s\n",food_id,food_name,food_price,food_status);
		}
		
		if(food_id == select_food_id){
			
			isFound = 1;
			
			gotoxy(45,7);
			printf("------Current Item Details------");
			gotoxy(45,8);
			printf("Food ID:\t\t%-5d\n",food_id);
			gotoxy(45,9);
			printf("Item:\t\t%-20s\n",food_name);
			gotoxy(45,10);
			printf("Price:\t\t%-5.2f\n",food_price);
			gotoxy(45,11);
			printf("Status:\t\t%-20s\n",food_status);
			gotoxy(45,12);
			printf("---------------------------------\n");
			gotoxy(45,14);
					
		} 
		
		
	}
	fclose(tuesday_menu_F);
	fclose(tuesday_menu_F_temp);

	if(isFound){
		gotoxy(45,20);
		printf("ITEM DELETED SUCCESSFULLY!");
		remove("tuesday_menu_F.txt");
		rename("tuesday_menu_F_temp.txt","tuesday_menu_F.txt");
		gotoxy(45,21);
		printf("Press ANY KEY to go back to Menu <<<");
		getch();
		fflush(stdin);
		adminMenu();
		
	}else{
		gotoxy(45,20);
		if(!isFound){
		   printf("ID DOES NOT EXIST");
		   
		}
		remove("tuesday_menu_F.txt");
		rename("tuesday_menu_F_temp.txt","monday_menu_F.txt");
		gotoxy(45,21);
		printf("Press ANY KEY to go back to Menu <<<");
		getch();
		fflush(stdin);
		adminMenu();
	}
	
}
void delete_beverage_tuesday(){
	char bev_name[MAX];
	int bev_id;
	float bev_price;
	char bev_status[MAX];
	
	
	char y_n;
	int isValid = 0;
	int select_bev_id;
	int isFound;
	
	gotoxy(45,3);
	printf("-SELECTED CATEGORY- : *BEVERAGE*");
	gotoxy(45,4);
	printf("Enter the BEVERAGE ID you want to Delete: ");
	gotoxy(45,5);
	scanf("%d",&select_bev_id);
	fflush(stdin);

	FILE *tuesday_menu_B = fopen("tuesday_menu_B.txt","r");
	FILE *tuesday_menu_B_temp = fopen("tuesday_menu_B_temp.txt","w"); // temporary text file for modification
	
	while(fscanf(tuesday_menu_B,"%d %[^\n]%*c %f %[^\n]%*c",&bev_id,bev_name,&bev_price,bev_status) != EOF){
		
		if(bev_id != select_bev_id){
			fprintf(tuesday_menu_B_temp,"%d\n %s\n %f\n %s\n",bev_id,bev_name,bev_price,bev_status);
		}
		
		if(bev_id == select_bev_id){
			
			isFound = 1;
			
			gotoxy(45,7);
			printf("------Current Item Details------");
			gotoxy(45,8);
			printf("Food ID:\t\t%-5d\n",bev_id);
			gotoxy(45,9);
			printf("Item:\t\t%-20s\n",bev_name);
			gotoxy(45,10);
			printf("Price:\t\t%-5.2f\n",bev_price);
			gotoxy(45,11);
			printf("Status:\t\t%-20s\n",bev_status);
			gotoxy(45,12);
			printf("---------------------------------\n");
		
			
			
					
		} 
		
		
	}
	fclose(tuesday_menu_B);
	fclose(tuesday_menu_B_temp);

	if(isFound){
		gotoxy(45,20);
		printf("ITEM DELETED SUCCESSFULLY!");
		remove("tuesday_menu_B.txt");
		rename("tuesday_menu_B_temp.txt","tuesday_menu_B.txt");
		gotoxy(45,21);
		printf("Press ANY KEY to go back to Menu <<<");
		getch();
		fflush(stdin);
		adminMenu();
		
	}else{
		gotoxy(45,20);
		if(!isFound){
		   printf("ID DOES NOT EXIST");
		}
		remove("tuesday_menu_B.txt");
		rename("tuesday_menu_B_temp.txt","tuesday_menu_B.txt");
		gotoxy(45,21);
		printf("Press ANY KEY to go back to Menu <<<");
		getch();
		fflush(stdin);
		adminMenu();
	}
	
}
















void loadingScreen(){
	
	printf("\tLOADING");
    for(int i = 0; i < 3; i++){
    	usleep(300000);
    	printf("."); 
	}
	system("cls");
}

void gotoxy(int x, int y){
		
	COORD c;
	c.X = x;
	c.Y = y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);

}
