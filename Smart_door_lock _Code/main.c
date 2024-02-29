	/**********************************************documentation section start********************************************************/
/*
file    : main.c
Author  : Rana Khallaf
Brief   : smart_locka_door_project

*/
/**********************************************documentation section end********************************************************/


/***********************************************include section start***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "UART_interface.h"
#include "CLCD_interface.h"
#include "util/delay.h"

/***********************************************include section end*************************************************************/



/***********************************************defination section start********************************************************/
static 	u8 flag=1;
/***********************************************defination section end**********************************************************/




/***********************************************declaration section start********************************************************/
void the_system(void);
void password_func(u8 right_pass[5]);


/***********************************************declaration section end**********************************************************/






/***********************************************main program section start********************************************************/

	

	
	

	void main()
	{
		u8 user_name[10];

		/*set the ports direction according to the project purpose*/
        DIO_voidSetPortDirection(DIO_PORTA,PORT_DIR_OUTPUT);

		DIO_voidSetPinDirection(DIO_PORTC,DIO_PIN0,PIN_DIR_OUTPUT);
		DIO_voidSetPinDirection(DIO_PORTC,DIO_PIN1,PIN_DIR_OUTPUT);

		DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN0,PIN_DIR_INPUT);
		DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN1,PIN_DIR_OUTPUT);

        /* initialization section */

		USART_voidInit();
		CLCD_voidInit();


          /* the frequent part of the code */
	while(1)
	{
		user_name[10];


     CLCD_voidClearScreen();

     CLCD_voidSetPosition(1,5);
	 CLCD_voidSendString("WELCOM");
	 CLCD_voidSetPosition(2,2);
	 CLCD_voidSendString("Enter The User Name");
	 for(u8 i=8;i<14;i++)
					 {
						 _delay_ms(400);

					 }

    CLCD_voidClearScreen();
    CLCD_voidSendString("Scanning");

    for(u8 i=10;i<15;i++)
   			 {
   				 CLCD_voidSetPosition(1,i);
   				 CLCD_voidSendData('.');
   				 _delay_ms(500);

   			 }




	USART_voidSendString("\r\n Enter The User Name \r\n");
	USART_voidRecieveString(user_name);

    CLCD_voidClearScreen();



	if(Compare_string(user_name,"AHMED"))
	{
		CLCD_voidSetPosition(1,3);

		CLCD_voidSendString("HI AHMED");


	     password_func("1111");

	}

	else if(Compare_string(user_name,"RANA"))
		{
		CLCD_voidSetPosition(1,3);

		CLCD_voidSendString("HI RANA");

		 password_func("2222");

		}
	else if(Compare_string(user_name,"RAMY"))
		{
		CLCD_voidSetPosition(1,3);

		CLCD_voidSendString("HI RAMY");


		 password_func("3333");

		}
	else if(Compare_string(user_name,"OMAR"))
		{
		CLCD_voidSetPosition(1,3);

		CLCD_voidSendString("HI OMAR");

		 password_func("4444");

		}
	else if(Compare_string(user_name,"REEM"))
		{
		CLCD_voidSetPosition(1,3);

		CLCD_voidSendString("HI REEM");


		 password_func("5555");

		}
	else if(Compare_string(user_name,"NOUR"))
		{
		CLCD_voidSetPosition(1,3);

		CLCD_voidSendString("HI NOUR");

		 password_func("6666");

		}
	else if(Compare_string(user_name,"KARIM"))
		{
		CLCD_voidSetPosition(1,3);

		CLCD_voidSendString("HI KARIM");

		 password_func("7777");

		}

	else if(Compare_string(user_name,"ZIAD"))
		{
		CLCD_voidSetPosition(1,3);

		CLCD_voidSendString("HI ZIAD");


		 password_func("8888");

		}
	else if(Compare_string(user_name,"MAHER"))
		{
		CLCD_voidSetPosition(1,3);

		CLCD_voidSendString("HI MAHER");

		 password_func("9999");

		}
	else if(Compare_string(user_name,"FARIDA"))
		{
		CLCD_voidSetPosition(1,3);

		CLCD_voidSendString("HI FARIDA");

		 password_func("1234");

		}
	else
	{



	}



	}

	}




/***********************************************main program section end********************************************************/















/***********************************************sub program section start********************************************************/

	void the_system(void)
	{
		u8 the_choice;

		USART_voidSendString("\r\n welcome home \r\n");

		USART_voidSendString("\r\n here is your options \r\n");
		USART_voidSendString("\r\n A=>>for opening the door \r\n");
		USART_voidSendString("\r\n B=>>for closing the door \r\n");
		USART_voidSendString("\r\n C=>>for turning on the light \r\n");
		USART_voidSendString("\r\n D=>>for turning off the light \r\n");
		USART_voidSendString("\r\n E=>>for logging out \r\n");


		the_choice=USART_voidRecieveByte();


		switch (the_choice)
		{
		case'A':
			CLCD_voidClearScreen();
			CLCD_voidSendString("Opening");

		    for(u8 i=8;i<14;i++)
		   			 {
		   				 CLCD_voidSetPosition(1,i);
		   				 CLCD_voidSendData('.');
		   				 _delay_ms(400);

		   			 }
			DIO_voidSetPinValue(DIO_PORTC,DIO_PIN1,PIN_VAL_HIGH);
			DIO_voidSetPinValue(DIO_PORTC,DIO_PIN0,PIN_VAL_LOW);

			 _delay_ms(90000);
			DIO_voidSetPinValue(DIO_PORTC,DIO_PIN1,PIN_VAL_LOW);
			DIO_voidSetPinValue(DIO_PORTC,DIO_PIN0,PIN_VAL_LOW);

		break;

		case'B':
					CLCD_voidClearScreen();
					CLCD_voidSendString("Closing");

				     for(u8 i=8;i<14;i++)
		   			 {
		   				 CLCD_voidSetPosition(1,i);
		   				 CLCD_voidSendData('.');
		   				 _delay_ms(400);

		   			 }
					DIO_voidSetPinValue(DIO_PORTC,DIO_PIN0,PIN_VAL_HIGH);
					DIO_voidSetPinValue(DIO_PORTC,DIO_PIN1,PIN_VAL_LOW);
					_delay_ms(90000);
					DIO_voidSetPinValue(DIO_PORTC,DIO_PIN1,PIN_VAL_LOW);
					DIO_voidSetPinValue(DIO_PORTC,DIO_PIN0,PIN_VAL_LOW);

				break;

		case'C':

			CLCD_voidClearScreen();
			CLCD_voidSendString("    LIGHT ON");
		    for(u8 i=8;i<14;i++)
				 {
					 _delay_ms(300);

				 }
				DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,PIN_VAL_HIGH);
				DIO_voidSetPinValue(DIO_PORTA,DIO_PIN3,PIN_VAL_HIGH);
				DIO_voidSetPinValue(DIO_PORTA,DIO_PIN4,PIN_VAL_HIGH);


			break;
		case'D':
			CLCD_voidClearScreen();
			CLCD_voidSendString("    LIGHT OFF");
			for(u8 i=8;i<14;i++)
							 {
								 _delay_ms(300);

							 }
				DIO_voidSetPinValue(DIO_PORTA,DIO_PIN2,PIN_VAL_LOW);
				DIO_voidSetPinValue(DIO_PORTA,DIO_PIN3,PIN_VAL_LOW);
				DIO_voidSetPinValue(DIO_PORTA,DIO_PIN4,PIN_VAL_LOW);



			break;
		case'E':
			CLCD_voidClearScreen();
			CLCD_voidSendString("LOGGING OUT");
			_delay_ms(2000000);
			CLCD_voidClearScreen();

				flag=0;

				break;

		}



		}











	void password_func(u8 right_pass[5])
	{

	  u8 password[5];
	  u8 count=0;

	  CLCD_voidSetPosition(2,0);
	  CLCD_voidSendString("You Have 3trials");

		while(count<3)
		{
			USART_voidSendString("\r\n Enter Your Passward \r\n");
			USART_voidRecieveString(password);

			if(Compare_string(password,right_pass))
				{
				flag=1;
				while(flag==1)
				{
					CLCD_voidClearScreen();
					CLCD_voidSendString("welcome home");
					for(u8 i=8;i<14;i++)
									 {
										 _delay_ms(300);

									 }
					CLCD_voidClearScreen();
					CLCD_voidSetPosition(1,3);
					CLCD_voidSendString("Choose Your ");
					CLCD_voidSetPosition(2,5);
					CLCD_voidSendString(" Option");
					_delay_ms(10);
				the_system();

				}
			   count=4;

			}
			else
			{
				count++;

			}

		}

		if(count==3)
		{
			CLCD_voidClearScreen();
          CLCD_voidSendString("WARNING ALARM !!");
          while(1)
          {
			DIO_voidSetPinValue(DIO_PORTA,DIO_PIN0,PIN_VAL_HIGH);
			DIO_voidSetPinValue(DIO_PORTA,DIO_PIN1,PIN_VAL_HIGH);
			_delay_ms(4000);
			DIO_voidSetPinValue(DIO_PORTA,DIO_PIN0,PIN_VAL_LOW);
			DIO_voidSetPinValue(DIO_PORTA,DIO_PIN1,PIN_VAL_LOW);

          }
		}


		}


		
		
/***********************************************sub program section end********************************************************/
