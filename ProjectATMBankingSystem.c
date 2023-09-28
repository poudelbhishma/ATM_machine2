                    /*
*******MINI PROJECT ATM BANKING SYSTEM******
NAME : BHISHMA POUDEL.
ROLL NO: 192006.
PROGRAM : BACHLOER OF COMPUTER APPLICATION(BCA)
YEAR : 2019(II).
FACULTY : SCINCE AND TECHNONOGY.


****ABOUT PROGRAM****
START DATE : 20/6/2021.
END DATE :   23/3/2021.


*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	int dd,mm,yy,ph_no,ac_no;      //dd:-day  mm:-month  yy:- year.
   	char name[50];


	FILE *fp;

   	int current_pin,new_pin,re_pin,pin,choice,choice1,k,transfer_amount,other_account;
   	char tran;
   	long int amount=25000,withdraw,deposit;
   	int citizenship_no;

   	stop:

	printf("ENTER YOUR SECRET PIN NUMBER : ");
	scanf("%d", &pin);
  	printf("\n");
	if (pin != 9980) 		//check wheather  a pin number is match or not.
    {
		printf("\t\tSORRY!!! \n\tPLEASE ENTER VALID PASSWORD\n");
        goto stop; //at the end of the program.
    }
    else
    {
        goto next;
    }


    next:    //goto statement  (else part).
   	do
	{
		printf("********WELCOME TO ATM SERVICE**************\n\n\n");
		printf("1. CREATE A NEW ACCOUNT\t\t");
		printf("2. CHECK BALENCE\n\n");
		printf("3. WITHDRAW CASH\t\t");
		printf("4. DEPOSITE CASH\n\n");
		printf("5. PIN CHANGE\t\t\t");
    	printf("6. TRANSFER AMOUNT\n\n");
    	printf("7. MORE DETAILS\t\t\t");
		printf("8. QUIT\n\n");
		printf("***********************************************\n\n");
		printf("\tENTER YOUR CHOICE: ");
		scanf("%d", &choice);
		switch (choice)
        {
        	case 1:
         			fp=fopen("banking.txt","w+");
					if(fp==NULL)
					{
						printf("FILE NOT TO BE OPENED");
						getch();
						exit(0);
					}
            		printf("CUSTOMER DETAIL\n");
					printf("ENTER FULL NAME (please use block letter): ");
					scanf(" %[^\n]s",name);
					printf("\nDATE OF BIRTH (day/month/year) : ");
					scanf("%d%d%d",&dd,&mm,&yy);
					printf("\nENTER YOUR PHONE NUMBER : ");
					scanf("%d",&ph_no);
               		printf("\nENTER YOUR CITIZENSHIP NUMBER : ");
               		scanf("%d",&citizenship_no);
					printf("\nCHOOSE YOUR ACCOUNT NUMBER :  ");
					scanf("%d",&ac_no);

					fprintf(fp,"NAME : %s\nBIRTH YEAR : %d/%d/%d\nPHONE NUMBER : %d\nCITIZENSHIP NUMBER : %d\nACCOUNT NUMBER : %d",name,dd,mm,yy,ph_no,citizenship_no,ac_no);
					printf("\n\tSUCCESSFULLY\n");
					printf("\tYOUR ACCOUNT WAS CREADTED :- \n");
					fscanf(fp,"%s%dd/%mm/%yy%d%d%d",&name,&dd,&mm,&yy,&ph_no,&ac_no);
					printf("NAME : %s\nDATE OF BIRTH : %d/%d/%d\nPHONE NUMBER : %d\nCITIZENSHIP NUMBER : %d\nACCONUT NUMBER : %d",name,dd,mm,yy,ph_no,citizenship_no,ac_no);
					fclose(fp);
    				break;

			case 2:
					printf("\n YOUR BALANCE IN Rs : %ld ", amount);
					break;

         	case 3:
					printf("\n ENTER THE AMOUNT TO WITHDRAW: ");
					scanf("%ld", &withdraw);
					if (withdraw % 500 != 0)
               		{
						printf("\n PLEASE ENTER THE AMOUNT IN MULTIPLES OF 500");
					}
					else if (withdraw >(amount - 500))
					{
						printf("\n INSUFFICENT BALANCE \nPLEASE CHECK YOUR BALANCE AND TRY AGAIN. \n\tTHANK YOU ");
					}
					else
					{
         			amount = amount - withdraw;
						printf("\n\n PLEASE COLLECT CASH");
						printf("\n YOUR CURRENT BALANCE ln :%ld", amount);
					}
					break;

         	case 4:
					printf("\n ENTER THE AMOUNT TO DEPOSIT");
					scanf("%lu", &deposit);
               		amount = amount + deposit;
					printf("YOUR BALANCE IS %ld", amount);
					break;

         	case 5:
               	top:
			   		printf("ENTER YOUR CURRENT PIN ");
               		scanf("%d",&current_pin);
               		if (pin==current_pin)
               		{
               			printf("ENTER  NEW PIN ");
               			scanf("%d",&new_pin);
                  		printf("RE-ENTER  NEW PIN ");
               			scanf("%d",&re_pin);
                  		if(new_pin==re_pin)
                  		{
                  			printf("\nSUCCESSFULLY CHANGED PIN");
                  		}
                  		else
                  		{
                     		printf("PLEASE ENTER CORRECT PIN.\n");
                     		goto top;
                  		}



               			goto down;
            		}

               	else
               	{
               		printf("PLEASE ENTER CORRECT PIN.\n");
               		goto top;
               	}



        	case 6:
         			printf("ENTER  RECERVER'S ACCOUNT NUMBER : ");
                	scanf("%d", &other_account);
                	printf("ENTER AMMOUNT : ");
                	scanf("%d",&transfer_amount);
                	amount=amount-transfer_amount;
                	printf("\n%d AMOUNT HAS BEEN TRANSFERED TO %d ACCOUNT RESPECTIVELY :)",transfer_amount,other_account);
                	printf("\nYOUR REMAINING BALANCE IN %d",amount);
                	break;
         	case 7:
         			printf("1. PERSONAL INFORMATION\t\t");
            		printf("2. CARD DETAILS\n\n");
               		printf("\tENTER YOUR CHOICE  ");
               		scanf("%d",&choice1 );

         			switch (choice1)	//ANOTHER SWITCH.
            		{
            			case 1:
								printf("\nPERSONAL INFORMATION\n");
               					printf("\nNAME : BHISHMA POUDEL");
               					printf("\nADDRESS : LALITPUR ");
                        		printf("\nGENDER : MALE");
                           		printf("\nDATE OF BIRTH : 1999/12/3");
                           		printf("\nPHONE NUMBER : 9617636056");
                           		printf("\nGMAIL I'D : poudel002@gmail.com");
                        		printf("\nACCOUNT NUMUBER : 456801238651");
                        		printf("\n");
								break;

               			case 2:
                  				printf("\nCARD DETAILS\n");
               					printf("\nACCOUNT NUMBER : 456801238651");
               					printf("\nCARD NUMBER : 456 987 362 123");
               					printf("\nCARD TYPE : VISA");
               					printf("\nVALID UNTIL : 2030/05/12");
                        		printf("\nBANK TEL NO. : 123891\nGMAINL i'd : ourbank654@gmail.com.np\nADDRESS : KUMARIPATI-12,lalitpur\n");
								break;


       		case 8:
       				
              		exit(0);
                	break;


			default:
      	  			printf("\n INVALID CHOICE");	//switch 1




      				}//CHOICE 1 SWITCH CLOSE.



    }// CHOICE SWITCH CLOSE.

            //pin change. goto label
          	down:
         		printf("\n");


			printf("\n\n DO YOU WANT TO ANOTHER TRANSCATION : \n");
         	printf("\nIF YOU WANT PLEASE ENTER  'Y' OTHERWISE ENTER 'N' : ");
         	fflush(stdin);
			scanf("%c", &tran);

			if (tran == 'n'|| tran == 'N')
      		k =1;
   	} while (!k);


   getch();
}


//file pointer.
//do while.
//goto statement .
//switch and nested switch case.
//fflush.