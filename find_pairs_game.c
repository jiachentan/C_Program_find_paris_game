#pragma warning(disable:4996)
#include<stdio.h>/* include standard library stdio.h for use of scanf(), printf(), fscanf() and fprintf() */ 
#include<string.h>/* include standard library string.h for use of strcmp(), strcpy() and getchar() */
#include<stdlib.h>/* inlcude standard library stdlib.h for use of exit() */
#include<time.h>/* include standard library time.h for use of clock() */
#include<conio.h>/* include standard library conio.h for use of getch() */
#include<windows.h>/* inlclude standard library windows.h for use of Sleep() */

typedef struct _user {   /* define a structure whose structure type is _user containing the users' data, and typedef it as User */
	char account[200];
	char password[200];
} User;

typedef struct _history{  /* define a structure whose structure type is _history containing the users' history data, and typedef it as History */
	char account[200];
	char level[200];
	int attempts;
	double times;
}History;

typedef struct _record{  /* define a structure of type of _record containing the users's best game recoed, and typedef it as Record */
	char account[200];
	char level[200];
	int attempts;
	double times;
}Record;

typedef struct user_node{    /* define a structure whose structure type is user_node containing the users' data and a structure pointer, and typedef it as User_Node */
	User users;
	struct user_node *pNext;
}User_Node;

typedef struct history_node{ /* define a structure whose structure type is history_node containing the users'history data and a structure pointer, and typedef it as History_Node */
	History histories;
	struct history_node *pNext;
}History_Node;

typedef struct record_node{ /* define a structure of type of record_node containing the user's best game record and a structure pointer, and typedef it as Record_Node */
	Record records;
	struct record_node *pNext;
}Record_Node;


void Free_Linkedlist_User(User_Node *p);   /* define a function named Free_Linkedlist_User to free the linklist of type of User_Node */

void Free_Linkedlist_History(History_Node *p);   /* define a function named Free_Linkedlist_History to free the linklist of type of History_Node */

void Free_Linkedlist_Record(Record_Node *p);   /* define a function named Free_Linkedlist_Record to free the linklist of type of Record_Node */

void Save_Users(User *head);    /* define a function named Save_Users to save the users' data into the file "User.txt" */

User_Node *Read_File_User();              /* define a function named Read_File_User to read the users' data from the file "User.txt" */

History_Node *Read_File_History();  /*  define a function named Read_File_History to read the users' game history from the file "History.txt" */

Record_Node *Read_File_Record();  /*  define a function named Read_File_Recoed to read the users' best game history from the file "Record.txt" */

void Menu1();                   /* define a function named Menu1 to print the welcome screen */

int Whether_Same_Account(char _account[200]);/* define a function named Whether_Same_Account to check whether the inputting account has already existed when logging in */

void Register();               /* define a function named Register to complete the register part */

const char *Login();           /* define a function named Login to complete the login part */

void Main_Interface();          /* define a function namned Main_Interface to choose register or login or exit */

void Menu2();                   /* define a function named Menu2 */

void Menu3();                   /* define a function named Menu3 */

void Menu4();                   /* define a function named Menu4 */

void ShowBoard_Low(char Chess[][4]);/* define a function named ShowBoard_Low to show the latest chess board of 4x4 in real time */

void ShowBoard_Middle(char Chess[][6]);/* define a function named ShowBoard_Middle to show the latest chess board of 6x6 in real time */

void ShowBoard_High(char Chess[][8]);/* define a function named ShowBoard_High to show the latest chess board of 8x8 in real time */

int array_row_low(int n); /* define a function named array_row_low to calculate the input is in which row of low level */

int array_col_low(int n); /* define a function named array_col_low to calculate the input is in which column of low level */

int array_row_Middle(int n); /* define a function named array_row_Middle to calculate the input is in which row of middle level */

int array_col_Middle(int n); /* define a function named array_col_Middle to calculate the input is in which column of middle level */

int array_row_High(int n); /* define a function named array_row_High to calculate the input is in which row of high level */

int array_col_High(int n); /* define a function named array_col_High to calculate the input is in which column of high level */

int Judge_Low(int n, char ChessBoard[][4]);      /* define a function named Judge_Low to check whether the two chesses are the same of low level */

int Judge_Middle(int n, char ChessBoard[][6]);      /* define a function named Judge_Middle to check whether the two chesses are the same of middle level*/

int Judge_High(int n, char ChessBoard[][8]);      /* define a function named Judge_High to check whether the two chesses are the same of high level*/

void Record_Game_Data(History *p); /* define a function named Record_Game_Data to write the user's game data into the file "History.txt" */

void Sentence();  /* define a function named Sentence */

int Check_Chess_Low(char board[][4], int m, int n); /* define a function named Check_Chess_Low to check whether the random element occurs in pairs or not in the game of low level */

int Check_Chess_Middle(char board[][6], int m, int n); /* define a function named Check_Chess_Middle to check whether the random element occurs in pairs or not in the game of middle level */

int Check_Chess_High(char board[][8], int m, int n);/* define a function named Check_Chess_High to check whether the random element occurs in pairs or not in the game of high level */

void Write_Into_Record(Record_Node *p); /* define a function named Write_Into_Record to renew the latest data into the file "Record.txt" */

int Whether_Break_Record(char account[200], char level[200], int attempts, double times);  /* define a function named Whether_Break_Record to check whether the user breaks his own best record before */

void Save_First_Record(char account[200], char level[200], int attempts, double times); /* define a function named Save_First_Record to save the user's game record for first time */

void Low_Level(char account_temp[200]); /* define a function named Low_Level to start the game of low level */

void Middle_Level(char account_temp[200]);  /* define a function named Middle_Level to start the game of middle level */

void High_Level(char account_temp[200]);  /* define a function named High_Level to start the game of high level */

void Print_Game_Interface(); /* define a function named Print_Game_Interface to print the game interface */

void Start_Game(char account_temp[200]);     /* define a function named Start_Game to start the game */

void Review_History(char account_temp[200]); /* define a function named Review_History to review the game history */

void Delete_History(char account_temp[200]); /* define a function named Delete_Histore to delete the game history */

void GameMenu(); /* define a function named GameMenu to print the game screen */

void Game(char account_temp[200]);    /* define a function named Game to give some choices to the users */

void Free_Linkedlist_User(User_Node *p){  /* free the linked list of type of User_Node */
	User_Node *temp;  /* declare a pointer variable of type of User_Node */
	temp = p;
	while (p){     /* free the linked list one by one */
		p = p->pNext;
		free(temp);
		temp = p;
	}
}

void Free_Linkedlist_History(History_Node *p){  /* free the linked list of type of History_Node */
	History_Node *temp;  /* declare a pointer variable of type of History_Node */
	temp = p;
	while (p){     /* free the linked list one by one */
		p = p->pNext;
		free(temp);
		temp = p;
	}
}

void Free_Linkedlist_Record(Record_Node *p){  /* free the linked list of type of Record_Node */
	Record_Node *temp;  /* declare a pointer variable of type of History_Node */
	temp = p;
	while (p){     /* free the linked list one by one */
		p = p->pNext;
		free(temp);
		temp = p;
	}
}


void Save_Users(User *temp){  /* save the users' data into the file "User.txt" */
	FILE *pFile;  /* define a file pointer */
	pFile = fopen("User.txt", "a+");  /* open the file named "data.text" with the style of "a+", if the file does not exit, creat it */
	fprintf(pFile, "%s\t%s\n", temp->account, temp->password); /* write the users' data into the file */
	fclose(pFile);  /* close the file */
}

User_Node *Read_File_User(){  /* use the linked list to read the data from the file "User.txt" */
	User_Node *pNewNode = NULL;
	User_Node *head = NULL;
	User_Node *p1 = NULL; /* declare three pointer variables of type of User_Node */
	FILE *pFile;
	if ((pFile = fopen("User.txt", "a+")) == NULL){
		printf("\t\t\t\t\tfail to open the file\n");
		printf("\t\t\t\t\t");
		system("pause");
		exit(0);
	}
	pNewNode = (User_Node *)malloc(sizeof(User_Node)); /* creat the dynamic memory by using malloc() */
	pNewNode->pNext = NULL;
	while ((fscanf(pFile, "%s\t%s\t%d\t%lf\n", pNewNode->users.account, pNewNode->users.password)) != EOF){  /* read the users' data from the file "User.txt" */
		if (head == NULL){   /* creat the linked list */
			head = p1 = pNewNode;
		}
		else {
			p1->pNext = pNewNode;
			p1 = pNewNode;
		}
		pNewNode = (User_Node *)malloc(sizeof(User_Node)); /* creat the dynamic memory by using malloc() */
		pNewNode->pNext = NULL;
	}/* use the dynamic linklist to read the data from the file one by one until reading the end of the file */
	free(pNewNode); /* free the last linked list */
	fclose(pFile);
	return head; /* return the linked list containing the whole users' data */
}

History_Node *Read_File_History(){  /* use the linked list to read the data from the file "History.txt" */
	History_Node *pNewNode = NULL;
	History_Node *head = NULL;
	History_Node *p1 = NULL;  /* declare three pointer variables of type of History_Node */
	FILE *pFile;
	if ((pFile = fopen("History.txt", "a+")) == NULL){
		printf("\t\t\t\t\tfail to open the file\n");
		printf("\t\t\t\t\t");
		system("pause");
		exit(0);
	}
	pNewNode = (History_Node *)malloc(sizeof(History_Node)); /* creat the dynamic memory by using malloc() */
	pNewNode->pNext = NULL;
	while ((fscanf(pFile, "%s\t%s\t%d\t%lf\n", pNewNode->histories.account, pNewNode->histories.level, &pNewNode->histories.attempts, &pNewNode->histories.times)) != EOF){/* read the users' game history data from the file "History.txt" */
		if (head == NULL){   /* creat the linked list */
			head = p1 = pNewNode;
		}
		else {
			p1->pNext = pNewNode;
			p1 = pNewNode;
		}
		pNewNode = (History_Node *)malloc(sizeof(History_Node)); /* creat the dynamic memory by using malloc() */
		pNewNode->pNext = NULL;
	}/* use the dynamic linked list to read the data from the file one by one until reading the end of the file */
	free(pNewNode); /* free the last linked list */
	fclose(pFile);
	return head; /* return the linked list containing the whole users' history */
}

Record_Node *Read_File_Record(){  /* use the linked list to read the data from the file "Record.txt" */
	Record_Node *pNewNode = NULL;
	Record_Node *head = NULL;
	Record_Node *p1 = NULL;  /* declare three pointer variables of type of Record_Node */
	FILE *pFile;
	if ((pFile = fopen("Record.txt", "a+")) == NULL){
		printf("\t\t\t\t\tfail to open the file\n");
		printf("\t\t\t\t\t");
		system("pause");
		exit(0);
	}
	pNewNode = (Record_Node *)malloc(sizeof(Record_Node)); /* creat the dynamic memory by using malloc() */
	pNewNode->pNext = NULL;
	while ((fscanf(pFile, "%s\t%s\t%d\t%lf\n", pNewNode->records.account, pNewNode->records.level, &pNewNode->records.attempts, &pNewNode->records.times)) != EOF){/* read the users' best game history data from the file "Record.txt" */
		if (head == NULL){   /* creat the linked list */
			head = p1 = pNewNode;
		}
		else {
			p1->pNext = pNewNode;
			p1 = pNewNode;
		}
		pNewNode = (Record_Node *)malloc(sizeof(Record_Node)); /* creat the dynamic memory by using malloc() */
		pNewNode->pNext = NULL;
	}/* use the dynamic linked list to read the data from the file one by one until reading the end of the file */
	free(pNewNode); /* free the last linked list */
	fclose(pFile);
	return head; /* return the linked list containing the whole users' best game record */
}

void Menu1(){    /* print the welcome screen */
	system("cls");
	printf("\t\t\t\t==================WELCOME==================\n");
	printf("\n");
	printf("\t\t\t\t=========1.Register========2.Log in========\n");
	printf("\n");
	printf("\t\t\t\t===================0.Exit==================\n");
	printf("\n");
}

int Whether_Same_Account(char _account[200]){  /* to check whether the input account has already existed */
	int ret = 1;
	User_Node *head, *p_temp;
	head = p_temp = Read_File_User();  /* read all the users' data from the file by using dynamic linklists */
	while (p_temp){
		if ((strcmp(p_temp->users.account, _account)) == 0){
			return ret;
		}
		p_temp = p_temp->pNext;
	}
	Free_Linkedlist_User(head);  /* call the Free_Link_Lisk function defined before to free the linked list one by one */
	ret = 0;
	return ret;
	/* if the input account has already existed, return 1, otherwise return 0 */
}

void Register(){
	system("cls");
	char _account[200];
	char _password[200];
	User temp;  /* declare a structure variable of type of User named temp */
	printf("\t\t\t\t\tPlease input your account:\n");
	printf("\n");
	while (1){   /* if the input account has already existed, let the user register another one by using the while(1) loop */
		printf("\t\t\t\t\t");
		scanf("%s", _account); /* input the account */
		printf("\n");
		if (Whether_Same_Account(_account)){  /* call the Whether_Same_Account function defined before */
			printf("\t\t\t\t\tThe account has already existed, please input another one:\n");
			printf("\n");
		}
		else {
			break; /* exit the while(1) loop */
		}
	}
	strcpy(temp.account, _account); /* copy the account to the temp.account */
	while (1){
		printf("\t\t\t\t\tPlease input your password:\n");
		printf("\n");
		printf("\t\t\t\t\t");
		scanf("\t\t\t\t\t%s", _password); /* input the password */
		printf("\n");
		printf("\t\t\t\t\tPlease input your password again:\n");
		printf("\n");
		printf("\t\t\t\t\t");
		scanf("\t\t\t\t\t%s", temp.password);  /* input the password again */
		printf("\n");
		if (strcmp(_password, temp.password) != 0){
			printf("\t\t\t\t\tYour second input is wrong, please try again!\n");
			printf("\n");
			continue;  /* if the two inputs are not the same, comtinue the while(1) loop */
		}
		else {
			printf("\t\t\t\t\tYou have regesistered your account successfully!\n");
			printf("\n");
			break;  /* exit the while(1) loop */
		}
	}
	Save_Users(&temp);  /* call the Save_Users function defined before to save the user's data */
	printf("\t\t\t\t\t");
	system("pause");
}

const char *Login(){
	static char account[200];
	system("cls");
	char password[200];
	int ret = 1;
	printf("\t\t\t\t\tPlease input your account:\n");
	printf("\n");
	User_Node *p1, *p2;  /* declare two structure variables of type of Node */
	p1 = p2 = Read_File_User();  /* read the whole users' data from the file by using dynamic linklists */
	printf("\t\t\t\t\t");
	scanf("\t\t\t\t\t%s", account);  /* input the account */
	printf("\n");
	while (p1){   /* to find whether the input account exists or not */
		if (strcmp(p1->users.account, account) == 0){
			strcpy(password, p1->users.password);
			ret = 0;  /* if exists, let ret be 0 */
			break;    /* quit the while(1) loop */
		}
		p1 = p1->pNext;
	}
	if (ret){
		printf("\t\t\t\t\tYour input account does not exist.\n");
		printf("\n");
		printf("\t\t\t\t\tPlease go back and register first.\n");
		printf("\n");
		printf("\t\t\t\t\t");
		system("pause");
		Free_Linkedlist_User(p2);  /* if the account not exists, call the Free_Link_Lisk function defined before to free the linked list one by one */
		return "0";          /* then return the character "0" */
	}
	printf("\t\t\t\t\tPlease input your password:\n");
	printf("\n");
	while (1){
		char _password[200];
		printf("\t\t\t\t\t");
		scanf("\t\t\t\t\t%s", _password); /* input the password */
		printf("\n");
		if ((strcmp(password, _password)) == 0){  /* if the password is right, quit the while(1) loop */
			printf("\t\t\t\t\tYou have logged in successfully\n");
			printf("\n");
			break;
		}
		else if ((strcmp(_password, "q") == 0)){
			return "q";  /* input the character "q" if want to quit */
		}
		else {   /* continue the while(1) loop */
			printf("\t\t\t\t\tYour password is wrong, please try again.\n");
			printf("\n");
			printf("\t\t\t\t\tIf you want to quit, just input 'q'.\n");
			printf("\n");
		}
	}
	Free_Linkedlist_User(p2); /* call the Free_Linkedlist_User function defined before to free the linked list one by one */
	printf("\t\t\t\t\t");
	system("pause");
	return account; /* return the account which has logged in successfully */
}

void Main_Interface(){
	char account_temp[200];
	while (1)
	{
		Menu1();  /* call the Menu1 function defined before to print the menu */
		printf("\t\t\t\t\t");
		char ch = getch();
		switch (ch)  /* use switch to provide the choices */
		{
		case '1':
			Register(); /* call the Register function defined before */
			break;      /* quit the switch after finishing registering */
		case '2':
			strcpy(account_temp, Login()); /* call the Login function defined before and copy the return value to account_temp */
			if ((strcmp(account_temp, "0")) == 0 || (strcmp(account_temp, "q") == 0)){
				break;
			}
			else{
				Game(account_temp);  /* go into the game part if the user logs in successfully */
				break;
			}
		case '0':
			printf("Goodbye\n");
			printf("\n");
			printf("\t\t\t\t\t");
			exit(0);
		default:
			printf("Your input is wrong, please try again\n");
			printf("\t\t\t\t\t");
			system("pause");
			system("cls");
			break;
		}
	}
}

void Menu2(){   /* print the game' interface of low level (4x4) */
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t1\t2\t3\t4\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t5\t6\t7\t8\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t9\t10\t11\t12\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t13\t14\t15\t16\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t\n");
}

void Menu3(){  /* print the game' interface of middle level (6x6) */
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t1\t2\t3\t4\t5\t6\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t7\t8\t9\t10\t11\t12\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t13\t14\t15\t16\t17\t18\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t19\t20\t21\t22\t23\t24\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t25\t26\t27\t28\t29\t30\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t31\t32\t33\t34\t35\t36\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t\n");
}

void Menu4(){  /* print the game' interface of high level (8x8) */
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t1\t2\t3\t4\t5\t6\t7\t8\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t9\t10\t11\t12\t13\t14\t15\t16\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t17\t18\t19\t20\t21\t22\t23\t24\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t25\t26\t27\t28\t29\t30\t31\t32\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t33\t34\t35\t36\t37\t38\t39\t40\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t41\t42\t43\t44\t45\t46\t47\t48\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t49\t50\t51\t52\t53\t54\t55\t56\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t57\t58\t59\t60\t61\t62\t63\t64\n");
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t\n");
}


void ShowBoard_Low(char Chess[][4]){  /* show the latest chess board of low level (4x4) */
	system("cls");
	Menu2();  /* call the Menu2 function defined before to print the game menu */
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t%c\t%c\t%c\t%c\n", Chess[0][0], Chess[0][1], Chess[0][2], Chess[0][3]);
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t%c\t%c\t%c\t%c\n", Chess[1][0], Chess[1][1], Chess[1][2], Chess[1][3]);
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t%c\t%c\t%c\t%c\n", Chess[2][0], Chess[2][1], Chess[2][2], Chess[2][3]);
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t%c\t%c\t%c\t%c\n", Chess[3][0], Chess[3][1], Chess[3][2], Chess[3][3]);
	printf("\t\t\t\t\t\n");
}

void ShowBoard_Middle(char Chess[][6]){  /* show the latest chess board of middle level (6x6) */
	system("cls");
	Menu3(); /* call the Menu3 function defined before to print the game menu */
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t%c\t%c\t%c\t%c\t%c\t%c\n", Chess[0][0], Chess[0][1], Chess[0][2], Chess[0][3], Chess[0][4], Chess[0][5]);
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t%c\t%c\t%c\t%c\t%c\t%c\n", Chess[1][0], Chess[1][1], Chess[1][2], Chess[1][3], Chess[1][4], Chess[1][5]);
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t%c\t%c\t%c\t%c\t%c\t%c\n", Chess[2][0], Chess[2][1], Chess[2][2], Chess[2][3], Chess[2][4], Chess[2][5]);
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t%c\t%c\t%c\t%c\t%c\t%c\n", Chess[3][0], Chess[3][1], Chess[3][2], Chess[3][3], Chess[3][4], Chess[3][5]);
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t%c\t%c\t%c\t%c\t%c\t%c\n", Chess[4][0], Chess[4][1], Chess[4][2], Chess[4][3], Chess[4][4], Chess[4][5]);
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t%c\t%c\t%c\t%c\t%c\t%c\n", Chess[5][0], Chess[5][1], Chess[5][2], Chess[5][3], Chess[5][4], Chess[5][5]);
	printf("\t\t\t\t\t\n");
}
void ShowBoard_High(char Chess[][8]){    /* show the latest chess board of high level (8x8) */
	system("cls");
	Menu4();  /* call the Menu4 function defined before to print the game menu */
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\n", Chess[0][0], Chess[0][1], Chess[0][2], Chess[0][3], Chess[0][4], Chess[0][5], Chess[0][6], Chess[0][7]);
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\n", Chess[1][0], Chess[1][1], Chess[1][2], Chess[1][3], Chess[1][4], Chess[1][5], Chess[1][6], Chess[1][7]);
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\n", Chess[2][0], Chess[2][1], Chess[2][2], Chess[2][3], Chess[2][4], Chess[2][5], Chess[2][6], Chess[2][7]);
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\n", Chess[3][0], Chess[3][1], Chess[3][2], Chess[3][3], Chess[3][4], Chess[3][5], Chess[3][6], Chess[3][7]);
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\n", Chess[4][0], Chess[4][1], Chess[4][2], Chess[4][3], Chess[4][4], Chess[4][5], Chess[4][6], Chess[4][7]);
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\n", Chess[5][0], Chess[5][1], Chess[5][2], Chess[5][3], Chess[5][4], Chess[5][5], Chess[5][6], Chess[5][7]);
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\n", Chess[6][0], Chess[6][1], Chess[6][2], Chess[6][3], Chess[6][4], Chess[6][5], Chess[6][6], Chess[6][7]);
	printf("\t\t\t\t\t\n");
	printf("\t\t\t\t\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\n", Chess[7][0], Chess[7][1], Chess[7][2], Chess[7][3], Chess[7][4], Chess[7][5], Chess[7][6], Chess[7][7]);
	printf("\t\t\t\t\t\n");
}

int array_row_low(int n){  /* determine which row the input is of low level */
	int row;
	if (n >= 1 && n <= 4){
		row = 0;
	}
	else if (n >= 5 && n <= 8){
		row = 1;
	}
	else if (n >= 9 && n <= 12){
		row = 2;
	}
	else if (n >= 13 && n <= 16){
		row = 3;
	}
	return row;
}

int array_col_low(int n){ /* determine which column the input is of low level */
	int col;
	if (n >= 1 && n <= 4){
		col = n - 1;
	}
	else if (n >= 5 && n <= 8){
		col = n - 5;
	}
	else if (n >= 9 && n <= 12){
		col = n - 9;
	}
	else if (n >= 13 && n <= 16){
		col = n - 13;
	}
	return col;
}

int array_row_Middle(int n){   /* determine which row the input is of middle level */
	int row;
	if (n >= 1 && n <= 6){
		row = 0;
	}
	else if (n >= 7 && n <= 12){
		row = 1;
	}
	else if (n >= 13 && n <= 18){
		row = 2;
	}
	else if (n >= 19 && n <= 24){
		row = 3;
	}
	else if (n >= 25 && n <= 30){
		row = 4;
	}
	else if (n >= 31 && n <= 36){
		row = 5;
	}
	return row;
}
int array_col_Middle(int n){   /* determine which column the input is of middle level */
	int col;
	if (n >= 1 && n <= 6){
		col = n - 1;
	}
	else if (n >= 7 && n <= 12){
		col = n - 7;
	}
	else if (n >= 13 && n <= 18){
		col = n - 13;
	}
	else if (n >= 19 && n <= 24){
		col = n - 19;
	}
	else if (n >= 25 && n <= 30){
		col = n - 25;
	}
	else if (n >= 31 && n <= 36){
		col = n - 31;
	}
	return col;
}

int array_row_High(int n){  /* determine which row the input is of high level */
	int row;
	if (n >= 1 && n <= 8){
		row = 0;
	}
	else if (n >= 9 && n <= 16){
		row = 1;
	}
	else if (n >= 17 && n <= 24){
		row = 2;
	}
	else if (n >= 25 && n <= 32){
		row = 3;
	}
	else if (n >= 33 && n <= 40){
		row = 4;
	}
	else if (n >= 41 && n <= 48){
		row = 5;
	}
	else if (n >= 49 && n <= 56){
		row = 6;
	}
	else if (n >= 57 && n <= 64){
		row = 7;
	}
	return row;
}

int array_col_High(int n){  /* determine which column the input is of high level */
	int col;
	if (n >= 1 && n <= 8){
		col = n - 1;
	}
	else if (n >= 9 && n <= 16){
		col = n - 9;
	}
	else if (n >= 17 && n <= 24){
		col = n - 17;
	}
	else if (n >= 25 && n <= 32){
		col = n - 25;
	}
	else if (n >= 33 && n <= 40){
		col = n - 33;
	}
	else if (n >= 41 && n <= 48){
		col = n - 41;
	}
	else if (n >= 49 && n <= 56){
		col = n - 49;
	}
	else if (n >= 57 && n <= 64){
		col = n - 57;
	}
	return col;
}

int Judge_Low(int n, char ChessBoard[][4]){  /* check whether the input chess is covered or not of low level */
	int row, col;
	row = array_row_low(n);  /* call the array_row_low function defined before */
	col = array_col_low(n);  /* call the array_col_low function defined before */
	if (ChessBoard[row][col] == '_'){
		return 0;
	}
	else return 1;
}

int Judge_Middle(int n, char ChessBoard[][6]){  /* check whether the input chess is covered or not of middle level */
	int row, col;
	row = array_row_Middle(n);  /* call the array_row_Middle function defined before */
	col = array_col_Middle(n);  /* call the array_col_Middle function defined before */
	if (ChessBoard[row][col] == '_'){
		return 0;
	}
	else return 1;
}

int Judge_High(int n, char ChessBoard[][8]){  /* check whether the input chess is covered or not of high level */
	int row, col;
	row = array_row_High(n);  /* call the array_row_High function defined before */
	col = array_col_High(n);  /* call the array_col_High function defined before */
	if (ChessBoard[row][col] == '_'){
		return 0;
	}
	else return 1;
}

void Record_Game_Data(History *p){   /* write the game record into the file "History.txt" */
	FILE *pFile;
	pFile = fopen("History.txt", "a+");
	fprintf(pFile, "%s\t%s\t%d\t%f\n", p->account, p->level, p->attempts, p->times);
	fclose(pFile);  /* close the file */
}

void Sentence(){  /* print the sentences */
	printf("\t\t\t\t\tYour input is wrong, please try again (print '0' to exit)\n");
	printf("\n");
	printf("\t\t\t\t\tIf you exit halfway, your game history will not be recorded!!\n");
}

int Check_Chess_Low(char board[][4], int m, int n){  /* check whether the element occurs in pairs in low level of the game */
	int i, j;
	int cnt = 0;
	for (i = 0; i <= 3; i++){
		for (j = 0; j <= 3; j++){
			if (board[i][j] == board[m][n]){  /* if the element occurs a time, cnt++ */
				cnt++;
			}
		}
	}
	if (cnt <= 2){  /* check whether the element occurs more than twice or not */
		return 1;
	}
	else return 0;
}

int Check_Chess_Middle(char board[][6], int m, int n){  /* check whether the element occurs in pairs in middle level of the game */
	int i, j;
	int cnt = 0;
	for (i = 0; i <= 5; i++){
		for (j = 0; j <= 5; j++){
			if (board[i][j] == board[m][n]){ /* if the element occurs a time, cnt++ */
				cnt++;
			}
		}
	}
	if (cnt <= 2){  /* check whether the element occurs more than twice or not */
		return 1;
	}
	else return 0;
}

int Check_Chess_High(char board[][8], int m, int n){  /* check whether the element occurs in pairs in high level of the game */
	int i, j;
	int cnt = 0;
	for (i = 0; i <= 7; i++){
		for (j = 0; j <= 7; j++){
			if (board[i][j] == board[m][n]){  /* if the element occurs a time, cnt++ */
				cnt++;
			}
		}
	}
	if (cnt <= 2){   /* check whether the element occurs more than twice or not */
		return 1;
	}
	else return 0;
}

void Write_Into_Record(Record_Node *p){  /* renew the latest users' best game record into the file "Record.txt" */
	FILE *pFile;  /* declare a file pointer named pFile */
	if ((pFile = fopen("Record.txt", "w")) == NULL){
		printf("\t\t\t\t\tfail to open the file\n");
		printf("\t\t\t\t\t");
		system("pause");
		exit(0);
	}
	fclose(pFile);
	fopen("Record.txt", "a+");
	while (p){
		fprintf(pFile, "%s\t%s\t%d\t%f\n", p->records.account, p->records.level, p->records.attempts, p->records.times);
		p = p->pNext;
	}
	fclose(pFile);
}

int Whether_Break_Record(char account[200], char level[200], int attempts, double times){  /* check whether the user has broken his best game record before */
	int ret = 0;
	Record_Node *temp1, *temp2, *temp3;  /* declare three structure variables of type of Record_Node */
	temp1 = temp2 = temp3 = Read_File_Record();  /* call the Read_File_Record function defined before to read all the data from the file "Record.txt" */
	while (temp1){
		if ((strcmp(temp1->records.account, account)) == 0 && (strcmp(temp1->records.level, level)) == 0){  /* use a while loop to find the corresponding account and game level */
			if (attempts < temp1->records.times && times < temp1->records.times){  /* check whether the user's attempts and times break his best game record */
				temp1->records.attempts = attempts;
				temp1->records.times = times;
				Write_Into_Record(temp2);  /* call the Write_Into_Record function defined before to renew the latest data into the file "Record.txt" */
				ret = 1;
				Free_Linkedlist_Record(temp3); /* call the Free_Linkedlist_Record function defined before to free the linked list of type of Recoed_Node */
				return ret;
			}
		}
		temp1 = temp1->pNext;
	}
	Free_Linkedlist_Record(temp3);  /* call the Free_Linkedlist_Record function defined before to free the linked list of type of Recoed_Node */
	return ret;
}

void Save_First_Record(char account[200], char level[200], int attempts, double times){
	int ret = 1;
	FILE *pFile;  /* declare a pointer of type of FILE */
	Record_Node *temp1, *temp2;  /* declare two structure variables of type of Record_Node */
	temp1 = temp2 = Read_File_Record(); /* call the Read_File_Record function defined before to read all the data from the file "Record.txt" */
	while (temp1){  /* check whether there has already been a record in the file "Record.txt" */
		if ((strcmp(temp1->records.account, account)) == 0 && (strcmp(temp1->records.level, level)) == 0){
			ret = 0;
		}
		temp1 = temp1->pNext;
	}
	if (ret){  /* if it is the first time that the user plays this level of game, write the game record into the file "Record.txt" */
		if ((pFile = fopen("Record.txt", "a+")) == NULL){
			printf("\t\t\t\t\tfail to open the file\n");
			printf("\t\t\t\t\t");
			system("pause");
			exit(0);
		}
		fprintf(pFile, "%s\t%s\t%d\t%f\n", account, level, attempts, times);
		fclose(pFile);
	}
	Free_Linkedlist_Record(temp2);  /* call the Free_Linkedlist_Record function defined before to free the linked list of type of Recoed_Node */
}

void Low_Level(char account_temp[200]){
	system("cls");
	int ret = 1;
	char level[200];
	strcpy(level, "Low");
	History temp;  /* declare a structure variable of type of History */
	strcpy(temp.account, account_temp);
	strcpy(temp.level, "Low");
	double times;
	clock_t start, finish;  /* declare two variables of type of clock_t */
	int attempts = 0;
	char Template_Board[4][4] = { { '!', '$', '@', '^' }, { '?', '%', '=', '+' }, { '!', '$', '@', '^' }, { '?', '%', '=', '+' } }; /* declare a template chessboard for the randomlized chessboard */
	char Random_ChessBoard[4][4] = { { '0' } };
	int m = 0;
	int n = 0;
	srand((unsigned)time(NULL));
	for (m = 0; m <= 3; m++){   /* randomlize the chessboard */
		for (n = 0; n <= 3; n++){
			while (1){
				Random_ChessBoard[m][n] = Template_Board[rand() % 4][rand() % 4];
				if (Check_Chess_Low(Random_ChessBoard, m, n)){
					break;
				}
			}
		}
	}
	char ChessBoard[4][4] = { { '_', '_', '_', '_' }, { '_', '_', '_', '_' }, { '_', '_', '_', '_' }, { '_', '_', '_', '_' } };  /* define a covered chess board for the player */
	printf("\t\t\t\t\tAre you ready?\n");
	printf("\n");
	printf("\t\t\t\t\t");
	system("pause");
	system("cls");
	int cnt = 0;
	int countdown = 5;
	while (countdown > 0){  /* a 5-seconds countdown */
		ShowBoard_Low(Random_ChessBoard);
		printf("\t\t\t\t\tPlease remember as much as you can\n");
		printf("\n");
		printf("\t\t\t\t\tTime remaining£º%ds\n", countdown);
		printf("\n");
		Sleep(1000);  /* let the function stay for one second */
		countdown--;
	}
	start = clock();  /* start counting the time */
	while (1){
		ShowBoard_Low(ChessBoard);  /* call the ShowBoard function defined before to show the latest chess board */
		printf("\t\t\t\t\tplease input a number (print '0' to exit)\n");
		printf("\n");
		printf("\t\t\t\t\tIf you exit halfway, your game history will not be recorded!!\n");
		printf("\n");
		int n;  /* declare a variable of type of int */
		while (1){
			printf("\n");
			printf("\t\t\t\t\t");
			if ((scanf("%d", &n)) != 1){
				printf("\n");
				Sentence();  /* call the Sentence function defined before to print the sentence */
				fflush(stdin); /* clear error data from input buffer */
			}
			else {
				break;
			}
		}
		printf("\n");
		if (n == 0){   /* if n=0, quit the while(1) loop */
			ret = 0;   /* if exit halfway, let ret be 0 */
			printf("\t\t\t\t\tGoodbye:)\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		}
		while (1){   /* use a while(1) loop to check whether the input is in 1~16 and covered */
			if (n>16 || n<0){         /* if n is not in 0~16, continue the while(1) loop */
				Sentence();       /* call the Sentence function defined before to print the sentence */
			}
			else if (Judge_Low(n, ChessBoard)){   /* if n has already uncovered, continue the while(1) loop */
				Sentence();       /* call the Sentence function defined before to print the sentence */
			}
			else{
				break;       /* if n is is in 1~16 and covered, quit the while(1) loop */
			}
			while (1){    /* continue to input the number */
				printf("\n");
				printf("\t\t\t\t\t");
				if ((scanf("%d", &n)) != 1){
					printf("\n");
					Sentence();  /* call the Sentence function defined before to print the sentence */
					fflush(stdin); /* clear error data from input buffer */
				}
				else {
					break;
				}
			}
			printf("\n");
			if (n == 0){  /* if n=0, quit the while(1) loop */
				break;
			}
		}
		if (n == 0){  /* if n=0, quit the game immediately */
			ret = 0;
			printf("\t\t\t\t\tGoodbye:)\n");
			printf("\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		}
		ChessBoard[array_row_low(n)][array_col_low(n)] = Random_ChessBoard[array_row_low(n)][array_col_low(n)];/* convert the selected one of two-dimensional arrays into uncovered */
		ShowBoard_Low(ChessBoard);  /* call the ShowBoard_Low function defined before to show the latest chess board */
		printf("\t\t\t\t\tplease input another number (print '0' to exit)\n");
		printf("\n");
		printf("\t\t\t\t\tIf you exit halfway, your game history will not be recorded!!\n");
		printf("\n");
		int m;  /* declare a variable of type of int */
		while (1){
			printf("\n");
			printf("\t\t\t\t\t");
			if ((scanf("%d", &m)) != 1){  /* if the input is not a number, continue to input again */
				printf("\n");
				Sentence();  /* if the input is not a number, show the sentence to let the user try again */
				fflush(stdin); /* clear error data from input buffer */
			}
			else break;
		}
		printf("\n");
		if (m == 0){    /* if m=0, quit the while(1) loop */
			ret = 0;    /* if exit halfway, let ret be 0 */
			printf("\t\t\t\t\tGoodbye:)\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		}
		while (1){   /* use a while(1) loop to check whether the input is in 1~16 and covered */
			if (m>16 || m<0){   /* if m is not in 0~16, continue the while(1) loop */
				Sentence();
			}
			else if (Judge_Low(m, ChessBoard)){  /* if m has already uncovered, continue the while(1) loop */
				Sentence();  /* call the Sentence function defined before to print the sentence */
			}
			else{
				break;    /* if m is is in 1~16 and covered, quit the while(1) loop */
			}
			while (1){   /* continue to input the number */
				printf("\n");
				printf("\t\t\t\t\t");
				if ((scanf("%d", &m)) != 1){
					printf("\n");
					Sentence();  /* call the Sentence function defined before to print the sentence */
					fflush(stdin); /* clear error data from input buffer */
				}
				else {
					break;
				}
			}
			if (m == 0){
				break;
			}
		}
		if (m == 0){  /* if m=0, quit the game immediately */
			ret = 0;  /* if exit halfway, let ret be 0 */
			printf("\t\t\t\t\tGoodbye:)\n");
			printf("\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		}
		ChessBoard[array_row_low(m)][array_col_low(m)] = Random_ChessBoard[array_row_low(m)][array_col_low(m)]; /* convert the selected one of two-dimensional arrays into uncovered */
		ShowBoard_Low(ChessBoard);  /* call the ShowBoard_Low function defined before to show the latest chess board */
		if (Random_ChessBoard[array_row_low(m)][array_col_low(m)] == Random_ChessBoard[array_row_low(n)][array_col_low(n)]){  /* check whether two chesses of the corresponding inpnuts are the same */
			printf("\t\t\t\t\tGood job! :)\n");
			printf("\n");
			int countdown = 1;
			while (countdown > 0){   /* do a 1 second countdown */
				Sleep(1000);  /* let the function stay for one second */
				countdown--;
			}
			cnt++;  /* cnt++ if a successful match is completed */
		}
		else {
			printf("\t\t\t\t\tYou are wrong, please try again\n");
			int countdown = 2;
			while (countdown > 0){   /* do a 2-seconds countdown */
				ShowBoard_Low(ChessBoard);
				printf("\t\t\t\t\tYou are wrong,please try again\n");
				printf("\n");
				printf("\t\t\t\t\tTime remaining£º%dseconds\n", countdown);
				Sleep(1000);  /* let the function stay for one second */
				countdown--;
			}
			ChessBoard[array_row_low(n)][array_col_low(n)] = '_';  /* if the match is unsuccessful, recover the chess board */
			ChessBoard[array_row_low(m)][array_col_low(m)] = '_';  /* if the match is unsuccessful, recover the chess board */
		}
		attempts++;  /* after a match is done, attempts++ */
		if (cnt == 8){    /* if the whole chesses are matched successfully, show it to the user and quit the game */
			printf("\t\t\t\t\tYou win the game,congratulations! :)\n");
			printf("\n");
			int countdown = 2;
			while (countdown > 0){ /* do a 2-seconds countdown */
				Sleep(1000);  /* let the function stay for one second */
				countdown--;
			}
			break;
		}
	}
	finish = clock();  /* finish counting the time */
	times = (double)(finish - start) / CLOCKS_PER_SEC;  /* calculate the time */
	temp.attempts = attempts;
	temp.times = times;
	if (ret){
		Save_First_Record(account_temp, level, attempts, times);  /* if the user plays the game for the first time, call the Save_First_Record function to save the game history into the file "Record.txt" */
		Record_Game_Data(&temp);/* call the Record_Game_Data function defined before to write the game data into the file "History.txt" */
		if (Whether_Break_Record(account_temp, level, attempts, times)){ /* call the Whether_Break_Record function defined before to check whether the use breaks his best game record */
			printf("\t\t\t\t\tWOW! You have broken your record!");
			system("pause");
		}
	}
}

void Middle_Level(char account_temp[200]){
	system("cls");
	int ret = 1;
	char level[200];
	strcpy(level, "Middle");
	History temp;  /* declare a structure variable of type of History */
	strcpy(temp.account, account_temp);
	strcpy(temp.level, "Middle");
	double times;
	clock_t start, finish;  /* declare two variables of type of clock_t */
	int attempts = 0;
	char Template_Board[6][6] = { { '!', '$', '@', '^', '[', ']' }, { '?', '%', '=', '+', '(', ')' }, { '#', '<', '>', '{', '}', '*' }, { '!', '$', '@', '^', '[', ']' }, { '?', '%', '=', '+', '(', ')' }, { '#', '<', '>', '{', '}', '*' } }; /* declare a template chessboard for the randomlized chessboard of middle level*/
	char Random_ChessBoard[6][6] = { { '0' } };
	int m = 0;
	int n = 0;
	srand((unsigned)time(NULL));
	for (m = 0; m <= 5; m++){   /* randomlize the chessboard */
		for (n = 0; n <= 5; n++){
			while (1){
				Random_ChessBoard[m][n] = Template_Board[rand() % 6][rand() % 6];
				if (Check_Chess_Middle(Random_ChessBoard, m, n)){
					break;
				}
			}
		}
	}
	char ChessBoard[6][6] = { { '_', '_', '_', '_', '_', '_' }, { '_', '_', '_', '_', '_', '_' }, { '_', '_', '_', '_', '_', '_' }, { '_', '_', '_', '_', '_', '_' }, { '_', '_', '_', '_', '_', '_' }, { '_', '_', '_', '_', '_', '_' } };  /* define a covered chess board for the player of middle level */
	printf("\t\t\t\t\tAre you ready?\n");
	printf("\n");
	printf("\t\t\t\t\t");
	system("pause");
	system("cls");
	int cnt = 0;
	int countdown = 15;
	while (countdown > 0){  /* a 15-seconds countdown */
		ShowBoard_Middle(Random_ChessBoard);
		printf("\t\t\t\t\tPlease remember as much as you can\n");
		printf("\n");
		printf("\t\t\t\t\tTime remaining£º%ds\n", countdown);
		printf("\n");
		Sleep(1000);  /* let the function stay for one second */
		countdown--;
	}
	start = clock();  /* start counting the time */
	while (1){
		ShowBoard_Middle(ChessBoard);  /* call the ShowBoard_Middle function defined before to show the latest chess board */
		printf("\t\t\t\t\tplease input a number (print '0' to exit)\n");
		printf("\n");
		printf("\t\t\t\t\tIf you exit halfway, your game history will not be recorded!!\n");
		printf("\n");
		int n;  /* declare a variable of type of int */
		while (1){
			printf("\n");
			printf("\t\t\t\t\t");
			if ((scanf("%d%*c", &n)) != 1){  /* if the input is not a number, continue to input again */;
			printf("\n");
			Sentence();    /* if the input is not a number, show the sentence to let the user try again */
			fflush(stdin); /* clear error data from input buffer */
			}
			else break;
		}
		printf("\n");
		if (n == 0){   /* if n=0, quit the while(1) loop */
			ret = 0;   /* if exit halfway, let ret be 0 */
			printf("\t\t\t\t\tGoodbye:)\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		}
		while (1){   /* use a while(1) loop to check whether the input is in 1~36 and covered */
			if (n>36 || n<0){         /* if n is not in 0~36, continue the while(1) loop */
				Sentence();       /* call the Sentence function defined before to print the sentence */
			}
			else if (Judge_Middle(n, ChessBoard)){   /* if n has already uncovered, continue the while(1) loop */
				Sentence();       /* call the Sentence function defined before to print the sentence */
			}
			else{
				break;       /* if n is is in 1~16 and covered, quit the while(1) loop */
			}
			while (1){    /* continue to input the number */
				printf("\n");
				printf("\t\t\t\t\t");
				if ((scanf("%d%*c", &n)) != 1){
					printf("\n");
					Sentence(); /* call the Sentence function defined before to print the sentence */
					fflush(stdin); /* clear error data from input buffer */
				}
				else break;
			}
			printf("\n");
			if (n == 0){  /* if n=0, quit the while(1) loop */
				break;
			}
		}
		if (n == 0){  /* if n=0, quit the game immediately */
			ret = 0;
			printf("\t\t\t\t\tGoodbye:)\n");
			printf("\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		}
		ChessBoard[array_row_Middle(n)][array_col_Middle(n)] = Random_ChessBoard[array_row_Middle(n)][array_col_Middle(n)];/* convert the selected one of two-dimensional arrays into uncovered */
		ShowBoard_Middle(ChessBoard);  /* call the ShowBoard_Middle function defined before to show the latest chess board */
		printf("\t\t\t\t\tplease input another number (print '0' to exit)\n");
		printf("\n");
		printf("\t\t\t\t\tIf you exit halfway, your game history will not be recorded!!\n");
		printf("\n");
		int m;  /* declare a variable of type of int */
		while (1){
			printf("\n");
			printf("\t\t\t\t\t");
			if ((scanf("%d", &m)) != 1){  /* if the input is not a number, continue to input again */
				printf("\n");
				Sentence();  /* if the input is not a number, show the sentence to let the user try again */
				fflush(stdin); /* clear error data from input buffer */
			}
			else break;
		}
		printf("\n");
		if (m == 0){    /* if m=0, quit the while(1) loop */
			ret = 0;    /* if exit halfway, let ret be 0 */
			printf("\t\t\t\t\tGoodbye:)\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		}
		while (1){   /* use a while(1) loop to check whether the input is in 1~16 and covered */
			if (m>36 || m<0){   /* if m is not in 0~36, continue the while(1) loop */
				Sentence();
			}
			else if (Judge_Middle(m, ChessBoard)){  /* if m has already uncovered, continue the while(1) loop */
				Sentence();  /* call the Sentence function defined before to print the sentence */
			}
			else{
				break;    /* if m is is in 1~36 and covered, quit the while(1) loop */
			}
			while (1){   /* continue to input the number */
				printf("\n");
				printf("\t\t\t\t\t");
				if ((scanf("%d", &m)) != 1){
					printf("\n");
					Sentence();  /* call the Sentence function defined before to print the sentence */
					fflush(stdin); /* clear error data from input buffer */
				}
				else break;
			}
			if (m == 0){
				break;
			}
		}
		if (m == 0){  /* if m=0, quit the game immediately */
			ret = 0;  /* if exit halfway, let ret be 0 */
			printf("\t\t\t\t\tGoodbye:)\n");
			printf("\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		}
		ChessBoard[array_row_Middle(m)][array_col_Middle(m)] = Random_ChessBoard[array_row_Middle(m)][array_col_Middle(m)]; /* convert the selected one of two-dimensional arrays into uncovered */
		ShowBoard_Middle(ChessBoard);  /* call the ShowBoard_Middle function defined before to show the latest chess board */
		if (Random_ChessBoard[array_row_Middle(m)][array_col_Middle(m)] == Random_ChessBoard[array_row_Middle(n)][array_col_Middle(n)]){  /* check whether two chesses of the corresponding inpnuts are the same */
			printf("\t\t\t\t\tGood job! :)\n");
			printf("\n");
			int countdown = 1;
			while (countdown > 0){   /* do a 1 second countdown */
				Sleep(1000);  /* let the function stay for one second */
				countdown--;
			}
			cnt++;  /* cnt++ if a successful match is completed */
		}
		else {
			printf("\t\t\t\t\tYou are wrong, please try again\n");
			int countdown = 2;
			while (countdown > 0){   /* do a 2-seconds countdown */
				ShowBoard_Middle(ChessBoard);  /* call the ShowBoard_High function defined before to show the latest chess board */
				printf("\t\t\t\t\tYou are wrong,please try again\n");
				printf("\n");
				printf("\t\t\t\t\tTime remaining£º%dseconds\n", countdown);
				Sleep(1000);  /* let the function stay for one second */
				countdown--;
			}
			ChessBoard[array_row_Middle(n)][array_col_Middle(n)] = '_';  /* if the match is unsuccessful, recover the chess board */
			ChessBoard[array_row_Middle(m)][array_col_Middle(m)] = '_';  /* if the match is unsuccessful, recover the chess board */
		}
		attempts++;  /* after a match is done, attempts++ */
		if (cnt == 18){    /* if the whole chesses are matched successfully, show it to the user and quit the game */
			printf("\t\t\t\t\tYou win the game,congratulations! :)\n");
			printf("\n");
			int countdown = 2;
			while (countdown > 0){ /* do a 2-seconds countdown */
				Sleep(1000);  /* let the function stay for one second */
				countdown--;
			}
			break;
		}
	}
	finish = clock();  /* finish counting the time */
	times = (double)(finish - start) / CLOCKS_PER_SEC;  /* calculate the time */
	temp.attempts = attempts;
	temp.times = times;
	if (ret){
		Save_First_Record(account_temp, level, attempts, times);  /* if the user plays the game for the first time, call the Save_First_Record function to save the game history into the file "Record.txt" */
		Record_Game_Data(&temp);/* call the Record_Game_Data function defined before to write the game data into the file "History.txt" */
		if (Whether_Break_Record(account_temp, level, attempts, times)){ /* call the Whether_Break_Record function defined before to check whether the use breaks his best game record */
			printf("\t\t\t\t\tWOW! You have broken your record!");
			system("pause");
		}
	}
}

void High_Level(char account_temp[200]){
	system("cls");
	int ret = 1;
	char level[200];
	strcpy(level, "High");
	History temp;  /* declare a structure variable of type of History */
	strcpy(temp.account, account_temp);
	strcpy(temp.level, "High");
	double times;
	clock_t start, finish;  /* declare two variables of type of clock_t */
	int attempts = 0;
	char Template_Board[8][8] = { { '!', '$', '@', '^', '[', ']', 'Q', 'T' }, { '?', '%', '=', '+', '(', ')', 'W', 'S' }, { '#', '<', '>', '{', '}', '*', 'U', 'P' }, { 'H', 'R', 'V', 'B', 'C', 'Z', 'D', 'E' }, { '!', '$', '@', '^', '[', ']', 'Q', 'T' }, { '?', '%', '=', '+', '(', ')', 'W', 'S' }, { '#', '<', '>', '{', '}', '*', 'U', 'P' }, { 'H', 'R', 'V', 'B', 'C', 'Z', 'D', 'E' } }; /* declare a template chessboard for the randomlized chessboard of high level*/
	char Random_ChessBoard[8][8] = { { '0' } };
	int m = 0;
	int n = 0;
	srand((unsigned)time(NULL));
	for (m = 0; m <= 7; m++){   /* randomlize the chessboard */
		for (n = 0; n <= 7; n++){
			while (1){
				Random_ChessBoard[m][n] = Template_Board[rand() % 8][rand() % 8];
				if (Check_Chess_High(Random_ChessBoard, m, n)){
					break;
				}
			}
		}
	}
	char ChessBoard[8][8] = { { '_', '_', '_', '_', '_', '_', '_', '_' }, { '_', '_', '_', '_', '_', '_', '_', '_' }, { '_', '_', '_', '_', '_', '_', '_', '_' }, { '_', '_', '_', '_', '_', '_', '_', '_' }, { '_', '_', '_', '_', '_', '_', '_', '_' }, { '_', '_', '_', '_', '_', '_', '_', '_' }, { '_', '_', '_', '_', '_', '_', '_', '_' }, { '_', '_', '_', '_', '_', '_', '_', '_' } };  /* define a covered chess board for the player of high level */
	printf("\t\t\t\t\tAre you ready?\n");
	printf("\n");
	printf("\t\t\t\t\t");
	system("pause");
	system("cls");
	int cnt = 0;
	int countdown = 30;
	while (countdown > 0){  /* a 5-seconds countdown */
		ShowBoard_High(Random_ChessBoard);
		printf("\t\t\t\t\tPlease remember as much as you can\n");
		printf("\n");
		printf("\t\t\t\t\tTime remaining£º%ds\n", countdown);
		printf("\n");
		Sleep(1000);  /* let the function stay for one second */
		countdown--;
	}
	start = clock();  /* start counting the time */
	while (1){
		ShowBoard_High(ChessBoard);  /* call the ShowBoard_High function defined before to show the latest chess board */
		printf("\t\t\t\t\tplease input a number (print '0' to exit)\n");
		printf("\n");
		printf("\t\t\t\t\tIf you exit halfway, your game history will not be recorded!!\n");
		printf("\n");
		int n;  /* declare a variable of type of int */
		while (1){
			printf("\n");
			printf("\t\t\t\t\t");
			if ((scanf("%d%*c", &n)) != 1){  /* if the input is not a number, continue to input again */;
			printf("\n");
			Sentence();    /* if the input is not a number, show the sentence to let the user try again */
			fflush(stdin); /* clear error data from input buffer */
			}
			else break;
		}
		printf("\n");
		if (n == 0){   /* if n=0, quit the while(1) loop */
			ret = 0;   /* if exit halfway, let ret be 0 */
			printf("\t\t\t\t\tGoodbye:)\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		}
		while (1){   /* use a while(1) loop to check whether the input is in 1~64 and covered */
			if (n>64 || n<0){         /* if n is not in 1~64, continue the while(1) loop */
				Sentence();       /* call the Sentence function defined before to print the sentence */
			}
			else if (Judge_High(n, ChessBoard)){   /* if n has already uncovered, continue the while(1) loop */
				Sentence();       /* call the Sentence function defined before to print the sentence */
			}
			else{
				break;       /* if n is is in 1~64 and covered, quit the while(1) loop */
			}
			while (1){    /* continue to input the number */
				printf("\n");
				printf("\t\t\t\t\t");
				if ((scanf("%d%*c", &n)) != 1){
					printf("\n");
					Sentence(); /* call the Sentence function defined before to print the sentence */
					fflush(stdin); /* clear error data from input buffer */
				}
				else break;
			}
			printf("\n");
			if (n == 0){  /* if n=0, quit the while(1) loop */
				break;
			}
		}
		if (n == 0){  /* if n=0, quit the game immediately */
			ret = 0;
			printf("\t\t\t\t\tGoodbye:)\n");
			printf("\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		}
		ChessBoard[array_row_High(n)][array_col_High(n)] = Random_ChessBoard[array_row_High(n)][array_col_High(n)];/* convert the selected one of two-dimensional arrays into uncovered */
		ShowBoard_High(ChessBoard);  /* call the ShowBoard_High function defined before to show the latest chess board */
		printf("\t\t\t\t\tplease input another number (print '0' to exit)\n");
		printf("\n");
		printf("\t\t\t\t\tIf you exit halfway, your game history will not be recorded!!\n");
		printf("\n");
		int m;  /* declare a variable of type of int */
		while (1){
			printf("\n");
			printf("\t\t\t\t\t");
			if ((scanf("%d", &m)) != 1){  /* if the input is not a number, continue to input again */
				printf("\n");
				Sentence();  /* if the input is not a number, show the sentence to let the user try again */
				fflush(stdin); /* clear error data from input buffer */
			}
			else break;
		}
		printf("\n");
		if (m == 0){    /* if m=0, quit the while(1) loop */
			ret = 0;    /* if exit halfway, let ret be 0 */
			printf("\t\t\t\t\tGoodbye:)\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		}
		while (1){   /* use a while(1) loop to check whether the input is in 1~64 and covered */
			if (m>64 || m<0){   /* if m is not in 1~64, continue the while(1) loop */
				Sentence();
			}
			else if (Judge_High(m, ChessBoard)){  /* if m has already uncovered, continue the while(1) loop */
				Sentence();  /* call the Sentence function defined before to print the sentence */
			}
			else{
				break;    /* if m is is in 1~64 and covered, quit the while(1) loop */
			}
			while (1){   /* continue to input the number */
				printf("\n");
				printf("\t\t\t\t\t");
				if ((scanf("%d", &m)) != 1){
					printf("\n");
					Sentence();  /* call the Sentence function defined before to print the sentence */
					fflush(stdin); /* clear error data from input buffer */
				}
				else break;
			}
			if (m == 0){
				break;
			}
		}
		if (m == 0){  /* if m=0, quit the game immediately */
			ret = 0;  /* if exit halfway, let ret be 0 */
			printf("\t\t\t\t\tGoodbye:)\n");
			printf("\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		}
		ChessBoard[array_row_High(m)][array_col_High(m)] = Random_ChessBoard[array_row_High(m)][array_col_High(m)]; /* convert the selected one of two-dimensional arrays into uncovered of high level */
		ShowBoard_High(ChessBoard);  /* call the ShowBoard_High function defined before to show the latest chess board */
		if (Random_ChessBoard[array_row_High(m)][array_col_High(m)] == Random_ChessBoard[array_row_High(n)][array_col_High(n)]){  /* check whether two chesses of the corresponding inpnuts are the same */
			printf("\t\t\t\t\tGood job! :)\n");
			printf("\n");
			int countdown = 1;
			while (countdown > 0){   /* do a 1 second countdown */
				Sleep(1000);  /* let the function stay for one second */
				countdown--;
			}
			cnt++;  /* cnt++ if a successful match is completed */
		}
		else {
			printf("\t\t\t\t\tYou are wrong, please try again\n");
			int countdown = 2;
			while (countdown > 0){   /* do a 2-seconds countdown */
				ShowBoard_High(ChessBoard); /* call the ShowBoard_High function defined before to show the latest chess board */
				printf("\t\t\t\t\tYou are wrong,please try again\n");
				printf("\n");
				printf("\t\t\t\t\tTime remaining£º%dseconds\n", countdown);
				Sleep(1000);  /* let the function stay for one second */
				countdown--;
			}
			ChessBoard[array_row_High(n)][array_col_High(n)] = '_';  /* if the match is unsuccessful, recover the chess board */
			ChessBoard[array_row_High(m)][array_col_High(m)] = '_';  /* if the match is unsuccessful, recover the chess board */
		}
		attempts++;  /* after a match is done, attempts++ */
		if (cnt == 32){    /* if the whole chesses are matched successfully, show it to the user and quit the game */
			printf("\t\t\t\t\tYou win the game,congratulations! :)\n");
			printf("\n");
			int countdown = 2;
			while (countdown > 0){ /* do a 2-seconds countdown */
				Sleep(1000);  /* let the function stay for one second */
				countdown--;
			}
			break;
		}
	}
	finish = clock();  /* finish counting the time */
	times = (double)(finish - start) / CLOCKS_PER_SEC;  /* calculate the time */
	temp.attempts = attempts;
	temp.times = times;
	if (ret){
		Save_First_Record(account_temp, level, attempts, times);  /* if the user plays the game for the first time, call the Save_First_Record function to save the game history into the file "Record.txt" */
		Record_Game_Data(&temp);/* call the Record_Game_Data function defined before to write the game data into the file "History.txt" */
		if (Whether_Break_Record(account_temp, level, attempts, times)){ /* call the Whether_Break_Record function defined before to check whether the use breaks his best game record */
			printf("\t\t\t\t\tWOW! You have broken your record!");
			system("pause");
		}
	}
}

void Print_Game_Interface(){  /* print the interface */
	system("cls");
	printf("\t\t\t\t\tPlease choose the game level\n");
	printf("\n");
	printf("\t\t\t\t\t1.Low (4x4)\n");
	printf("\n");
	printf("\t\t\t\t\t2.Middle (6x6)\n");
	printf("\n");
	printf("\t\t\t\t\t3.High (8x8)\n");
	printf("\n");
	printf("\t\t\t\t\tPress any keyboard except '1', '2', '3' to exit\n");
	printf("\n");
}

void Start_Game(char account_temp[200]){     /* start the game */
	Print_Game_Interface();      /* call the Print_Game_Interface function to print the interface */
	char ch = getch();
	switch (ch){        /* do the switch case to provide the choices */
	case'1':
		Low_Level(account_temp);  /* call the Low_Level function defined before to start the game of low level */
		break;
	case'2':
		Middle_Level(account_temp);   /* call the Middle_Level function defined before to start the game of middle level */
		break;
	case'3':
		High_Level(account_temp);  /* call the High_Level function defined before to start the game of high level */
		break;
	default:
		printf("\t\t\t\t\tGoodbye\n");
		printf("\n");
		printf("\t\t\t\t\t");
		system("pause");
		break;
	}

}

void Review_History(char account_temp[200]){    /* define a function named Review_History to review the game history */
	int ret = 1;
	History_Node *head, *p_temp;    /* declare two structure variables of type of History_Node */
	head = p_temp = Read_File_History();  /* call the Read_File_History function to read the whole users' data from the file by using dynamic linked lists */
	while (p_temp){  /* use a while loop to traverse the dynamic linked lists */
		if ((strcmp(p_temp->histories.account, account_temp)) == 0){   /* find the corresponding account */
			printf("Level:%s\tAttempts:%d\tTimes:%fseconds\n", p_temp->histories.level, p_temp->histories.attempts, p_temp->histories.times); /* print the corresponding game level, attemps and times */
			printf("\t\t\t\t\t");
			ret = 0;
		}
		p_temp = p_temp->pNext;
	}
	if (ret){
		printf("You have no game history\n");
	}
	printf("\t\t\t\t\t");
	system("pause");
	Free_Linkedlist_History(head);  /* call the Free_Linkedlist_History function defined before to free the dynamic linkedlists one by one */
}

void Delete_History(char account_temp[200]){
	History_Node *head, *p_temp1, *p_temp2;   /* declare three structure variables of type of History_Node */
	FILE *pFile;   /* define a file pointer */
	head = p_temp1 = p_temp2 = Read_File_History();  /* call the Read_File_History function to read the whole users' data from the file by using dynamic linklists */
	while (p_temp1){  /* use a while loop to traverse the dynamic linklists */
		if ((strcmp(p_temp1->histories.account, account_temp)) == 0){  /* find the corresponding account */
			strcpy(p_temp1->histories.account, "\0"); /* let the accoount name be "\0" */
		}
		p_temp1 = p_temp1->pNext;
	}
	pFile = fopen("History.txt", "w"); /* open the file in the style of "w" to empty the file */
	fclose(pFile);   /* close the file */
	pFile = fopen("History.txt", "a+");
	while (p_temp2){     /* rewrite the latest users' history data into the file in the style of "a+" */
		fprintf(pFile, "%s\t%s\t%d\t%f\n", p_temp2->histories.account, p_temp2->histories.level, p_temp2->histories.attempts, p_temp2->histories.times);
		p_temp2 = p_temp2->pNext;
	}
	fclose(pFile); /* close the file */
	Free_Linkedlist_History(head);  /* call the Free_Linkedlist_History function defined before to free the dynamic linklists one by one */
	printf("Delete successfullly\n");
	printf("\t\t\t\t\t");
	system("pause");
}

void GameMenu(){  /* print the game menu */
	system("cls");
	printf("\t\t\t\t\t1.Start a new game\n");
	printf("\n");
	printf("\t\t\t\t\t2.Review your game history\n");
	printf("\n");
	printf("\t\t\t\t\t3.Delete your game history\n");
	printf("\n");
	printf("\t\t\t\t\t4.Log out\n");
	printf("\n");
}

void Game(char account_temp[200]){
	system("cls");
	int ret = 0;
	while (1){
		GameMenu();  /* call the GameMenu function to print the game menu */
		printf("\t\t\t\t\t");
		char ch = getch();  /* use getch() to input choice */
		switch (ch)
		{
		case '1':
			Start_Game(account_temp); /* call the Start_Game function defined before to start the game with corresponding account */
			break;
		case '2':
			Review_History(account_temp);  /* call the Review_History function defined before to review the game history with corresponding account */
			break;
		case '3':
			Delete_History(account_temp);  /* call the Delete_History function defined before to delete the history */
			break;
		case'4':
			ret = 1;  /* if the user want to quit, let ret be 1 */
			printf("Goodbye:)\n");
			printf("\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		default:
			printf("You input is wrong, please input agian\n");
			printf("\t\t\t\t\t");
			system("pause");
			break;
		}
		if (ret){  /* if ret=1, go back to the previous level */
			break;
		}
	}
}
int main(){
	Main_Interface();   /* call the Main_Interface funtion defined before to start the whole program */
	return 0;
}