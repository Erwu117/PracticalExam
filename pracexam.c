#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

int main(void){
	pos();
	return 0;
}
void pos(){
	//Initializing array of variable for the menu list
	char itemcode[20][5]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16"};
	char itemdesc[20][50]={"Chicken Fillet","Chicken Nuggets Meal","Chicken Flute","Chicken Poppers","Quad Wings","Box of Mojos","Chicken Fingers","Box of Chicken Skin","Squad Bilao","Party Bilao","Gravy", "Original Vinegar", "Spicy Vinegar", "Sweet & Spicy Dip", "Rice","Ranchero Dip"} ;
	char itemprice[20][20]={"95","99","119","149","225","350","169","249","1200","1500","30","30","30","30","30","30"};
	int total;
	int subtotal, addonsubtotal;
	int option;
	int i,j,l,m,n;
	int len, lenaddon;
	int qty, addonqty;
	char ordercode[20];
	char addonordercode[20];
	char c,a,ad;
	char printcode[20][5];
	char printdesc[20][50];
	char printprice[20][50];
	int printqty[20];
	int printsubtotal[20];
	int k,o;
	int cash;
	int change;
	total =0;
	addonsubtotal = 0;
	subtotal = 0;

	//Action on orders part
	//Options
    printf("===============================Monster Wings===============================\n");
	printf("\t\t\t\t OPTIONS \n");
	printf("1 SHOW MENU \n");
	printf("2 TAKE ORDER \n");
	printf("3 EXIT\n");
	printf("Enter a number from 1-3 for choosing an option: ");
	scanf("%d",&option);

 
	if (option == 1)   
	{
		for (i=0;i<10;i++)
		{
			//Responsible for the display of the menu restaurant.
			printf("%s ",itemcode[i]);
			printf ("   ");
			printf("%s",itemdesc[i]);
			len = strlen(itemdesc[i]);   
			for (j=0; j<(20-len);j++ )
			printf(" "); 
			printf("%sPHP",itemprice[i]);
			len = strlen(itemprice[i]);   
			for (j=0; j<(10-len);j++)
			printf(" "); 
			printf("%s ",itemcode[i+1]);
			printf (" ");
			printf("%s",itemdesc[i+1]);
			len = strlen(itemdesc[i+1]);   
			for (j=0; j<(25-len);j++ )
			printf(" "); 
			printf("%sPHP\n",itemprice[i+1]);
			i = i+ 1;
		}        
    }
	else if (option == 2)
	{
		exit;
   }
	else if (option == 3)
   {
		return;
   }
	qty = 0;
	k = 0;
	//Take Order
do { 
		printf ("===============================Monster Wings===============================\n"); 
		printf("\t\t\t\tTAKE ORDER\n");
		printf("Order #: ") ;
		scanf ("%s",ordercode);
		printf("Quantity: ") ;
		scanf ("%d",&qty);
  
    
		for (i=0;i<10;i++)  
		if (strcmp(itemcode[i] ,ordercode) == 0 )
        {
			printf("Found in Database\n");
			subtotal =qty *atoi(itemprice[i]);     
			total = subtotal + total;
			strcpy(printcode[k],itemcode[i]);
			strcpy(printdesc[k],itemdesc[i]);
			strcpy(printprice[k],itemprice[i]);
			printsubtotal[k]= subtotal;
			printqty[k] =qty;
			printf("%s",printdesc[k]);
			printf("     %sPHP\n",printprice[k]);
			printf("%d\n",total );
			k = k +1;
			printf ("Anything Else? Y/N? ");
			scanf ("%s",&c);
//			i = 21; 
			if (c == 'N' || c == 'n') {
			   	printf("Any add-on? Y/N ");
			   	scanf("%s",&a);
			   	if (a == 'N' || a == 'n'){
			   		break;
				} 
			   	do{
			   	for (i=10;i<16;i++)	{
					//Responsible for the display of the menu restaurant.
					printf("%s ",itemcode[i]);
					printf ("   ");
					printf("%s",itemdesc[i]);
					len = strlen(itemdesc[i]);   
					for (j=0; j<(20-len);j++ )
					printf(" "); 
					printf("%sPHP",itemprice[i]);
					len = strlen(itemprice[i]);   
					for (j=0; j<(10-len);j++)
					printf(" "); 
					printf("%s ",itemcode[i+1]);
					printf ("   ");
					printf("%s",itemdesc[i+1]);
					len = strlen(itemdesc[i+1]);   
					for (j=0; j<(20-len);j++ )
					printf(" "); 
					printf("%sPHP\n",itemprice[i+1]);
					i = i+ 1;	
				}
				printf("Order #: ") ;
				scanf ("%s",ordercode);
				printf("Quantity: ") ;
				scanf ("%d",&qty);
//				k = k+1;
				for (i=10;i<16;i++){
					if (strcmp(itemcode[i] ,ordercode) == 0 ) {
						printf("Found in Database\n");
						subtotal =qty *atoi(itemprice[i]);     
						total = subtotal + total;
						strcpy(printcode[k],itemcode[i]);
						strcpy(printdesc[k],itemdesc[i]);
						strcpy(printprice[k],itemprice[i]);
						printsubtotal[k]= subtotal;
						printqty[k] =qty;
						printf("%s",printdesc[k]);
						printf("     %sPHP\n",printprice[k]);
						printf("%d\n",total );
						k = k +1;
					}
				}
			   	printf ("Anything Else? Y/N ");
				scanf ("%s",&ad);
			   	if (ad == 'N' || ad == 'n'){
					break;
				} 
			   	} while (a == 'Y' || a == 'y');

			}    
        
		}
            
//		else if (i == 20 ){
//			printf("Not Found in the database\n");
//			return;
//		}
			
    } while (c == 'Y'|| c == 'y');
   	printf ("PRESS 1-Receipt, 2-Options, 3-Exit : ");
	scanf("%d",&option);
	if (option == 1)   exit ; 
	else if (option == 2) pos();
	else if (option == 3) return ;
	exit;
    printf ("Monster Wings\n");
	//Showing the receipt for the user
	if (k >0 )
		{
			printf ("===============RECEIPT===============\n");
			i = 0;
			printf ("     Order                Qty   Price \n");
		do {
 
			printf("%s  ",printcode[i]);
			printf("%s  ",printdesc[i]);    
			len = strlen(printdesc[i]);   
			for (j=0; j<(20-len);j++ )
			printf(" "); 
			printf("%d",printqty[i]);
			printf ("    ");
			printf("%d\n",printsubtotal[i]);
			i = i + 1 ;
			} while (i < k);
			printf("TOTAL                           ");
			printf("%d\n",total) ;	  
		}
    printf("Cash: ");
    scanf("%d",&cash) ;
    change = cash - total;
    
    printf("Change: ");
    printf("%d",change);
}
