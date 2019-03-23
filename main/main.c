#include "tm4c123gh6pm.h"
#include "head.h"
#include "stdint.h"
//  Declarations Section
unsigned long SWI;//Increment switch
unsigned long SWD;//Decrement switch
unsigned long SWE;//Enable switch On/Off
unsigned long SWR;//Reset switch
int SWD_previous_state=1;
int counter=0;

//Main Function
void SystemInit(void){

port_init(portf);
	port_init(porta);
	port_init(portb);
	DioSetPinDir(portf,1,output);
	DioSetPinDir(portf,2,output);
	DioSetPinDir(portf,3,output);
	
		DioSetPinDir(porta,4,input);
		DioSetPinDir(porta,5,input);
		DioSetPinDir(porta,6,input);

	

}

int main (void) 
{
	
	//Switches & Ports Initialization
  SW_Init();
	
		while(1)
	{ 	
			SWI=DioGetPinValue(0 , 0);// port A pin 0 is input SWI
	        SWD=DioGetPinValue(0 , 1);// port A pin 1 is input SWD
			SWR=DioGetPinValue(0 , 2);// port A pin 2 is input SWR
			SWE=DioGetPinValue(0 , 3);// port A pin 3 is input SWE  
	
		  //while (!SWE) //while circuit is enabled(negative logic)
		  //{
			
			
			        while (SWI ==0) // increment switch is pressed
							{
								
                Delay1ms(200); //delay 0.2 sec
							  counter = increment(counter);
								seg3(1,5,1,2,3,counter);//port b(1).. port f(5) pins 1,2,3
								
							}
							
							
							
							
							
							
							
							
							if  (SWD ==0 && SWD_previous_state==0) // Decrement switch is pressed
							{
								counter = decrement(counter);
								seg3(1,5,1,2,3,counter);//port b(1).. port f(5) pins 1,2,3
								SWD_previous_state = 1;
							}
							
							
							
							
							if(SWD == 0x01)
							{SWD_previous_state=0;}
				    
					
					
					
							while (SWR ==0) // Reset switch is pressed
							{

              if(SWR==1) //SWR is not pressed
							{								
		            clear();
							}
					
							}		
			//}
  }		

}
