#include <svc.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define UDB_USBHUB	(1 <<23)
#define RESERVED05	(1 << 5)
#define RESERVED15	(1 <<15)
#define RESERVED16	(1 <<16)
#define RESERVED17	(1 <<17)
#define RESERVED18	(1 <<18)
#define RESERVED24	(1 <<24)
#define RESERVED25	(1 <<25)
#define RESERVED26	(1 <<26)
#define RESERVED27	(1 <<27)
#define RESERVED28	(1 <<28)
#define RESERVED31	(1 <<31)

#define KEY_ONE	(49)
#define KEY_TWO	(50)

#define MSG_MAX	(256)

typedef struct
{
	int open;
    int read;
    int write;
    int close;
}st_device_sts;

void test_GetUsbDeviceBits(void);

st_device_sts console;
 
open_block_t ob;
 
char msg[MSG_MAX];
char key[1];


int main(void)
{
	
 	ob.rate = Rt_115200;
 	ob.format = Fmt_A8N1;
 	ob.protocol = P_char_mode;
 	ob.parameter = 0;
 
 	console.open=open(DEV_CONSOLE,0);
	
 	set_owner_all(console.open);
	
 	memset(msg,0,sizeof(msg));
    memset(key,0,sizeof(key));
	
	while(1)
	{
		clrscr();
		sprintf(msg, "1. get_usb_device_bits() Test\n");	
  		console.write=write(console.open, msg, strlen(msg));
		sprintf(msg, "2. End Test\n");	
  		console.write=write(console.open, msg, strlen(msg));

		wait_evt(EVT_KBD);

		console.read=read(console.open, key, sizeof(key));
		
		switch(key[0] & 0x7f)
		{
			case KEY_ONE:
				test_GetUsbDeviceBits();
		        sprintf(msg, "\nPlease wait for 10 secs.\n");	
  		        console.write=write(console.open, msg, strlen(msg));				
				SVC_WAIT(10000);
			break;
			
			case KEY_TWO:
				clrscr();
		       	sprintf(msg, "Test End\n");	
  				console.write=write(console.open, msg, strlen(msg));				
			return 0;
			
			default:
			break;
		}
	}		
			
	console.close=close(console.open);
}

void test_GetUsbDeviceBits(void)
{

 	if(get_usb_device_bits() & UDB_FLASH)
 	{
		sprintf(msg, "FLASH  1 << 0\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}
 
 	if(get_usb_device_bits() & UDB_ETHER)
 	{
		sprintf(msg, "ETHER  1 << 1\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}

 	if(get_usb_device_bits() & UDB_WIFI)
 	{
		sprintf(msg, "WIFI   1 << 2\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}

 	if(get_usb_device_bits() & UDB_COM3)
 	{
		sprintf(msg, "COM3   1 << 3\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}

 	if(get_usb_device_bits() & UDB_COM6)
 	{
		sprintf(msg, "COM6   1 << 4\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}

 	if(get_usb_device_bits() & UDB_COM4)
 	{
		sprintf(msg, "UDB_COM4 1 << 6\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}
	
 	if(get_usb_device_bits() & UDB_KYBD)
 	{
		sprintf(msg, "KBYD   1 << 7\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}

 	if(get_usb_device_bits() & UDB_VX810)
 	{
		sprintf(msg, "UDB_VX810 1 << 8\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}		
	
 	if(get_usb_device_bits() & UDB_PP1000SE)
 	{
		sprintf(msg, "EPP    1 << 9\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}		
	
 	if(get_usb_device_bits() & UDB_BIO)
 	{
		sprintf(msg, "BIO    1 << 10\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}	

 	if(get_usb_device_bits() & UDB_BAR)
 	{
		sprintf(msg, "BAR    1 << 11\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}	
	
 	if(get_usb_device_bits() & UDB_COM2)
 	{
		sprintf(msg, "COM2   1 << 12\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}	

 	if(get_usb_device_bits() & UDB_COM9)
 	{
		sprintf(msg, "COM9   1 << 13\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}	

 	if(get_usb_device_bits() & UDB_COM10)
 	{
		sprintf(msg, "COM10  1 << 14\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}		

 	if(get_usb_device_bits() & UDB_VX820)
 	{
		sprintf(msg, "UDB_VX820 1 << 19\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}	

 	if(get_usb_device_bits() & UDB_VX805)
 	{
		sprintf(msg, "UDB_VX805 1 << 20\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}	

 	if(get_usb_device_bits() & UDB_APL)
 	{
		sprintf(msg, "UDB_APL 1 << 21\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}	

 	if(get_usb_device_bits() & UDB_XCDMA)
 	{
		sprintf(msg, "UDB_XCDMA 1 << 21\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}		
	
 	if(get_usb_device_bits() & UDB_XCDMA_A)
 	{
		sprintf(msg, "UDB_XCDMA_A 1 << 22\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}			
	
 	if(get_usb_device_bits() & UDB_USBHUB)
 	{
		sprintf(msg, "USBHUB 1 << 23\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}	

 	if(get_usb_device_bits() & UDB_IBHUB)
 	{
		sprintf(msg, "IBHUB  1 << 29\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}

 	if(get_usb_device_bits() & UDB_SINGLE)
 	{
		sprintf(msg, "UDB_SINGLE 1 << 30\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}	

 	if(get_usb_device_bits() & RESERVED05)
 	{
		sprintf(msg, "UDB_? 1 << 5\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}		
	
 	if(get_usb_device_bits() & RESERVED15)
 	{
		sprintf(msg, "UDB_? 1 << 15\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}	

 	if(get_usb_device_bits() & RESERVED16)
 	{
		sprintf(msg, "UDB_? 1 << 16\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}	

 	if(get_usb_device_bits() & RESERVED17)
 	{
		sprintf(msg, "UDB_? 1 << 17\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}		
	
 	if(get_usb_device_bits() & RESERVED18)
 	{
		sprintf(msg, "UDB_? 1 << 18\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}	

 	if(get_usb_device_bits() & RESERVED24)
 	{
		sprintf(msg, "UDB_? 1 << 24\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}	

 	if(get_usb_device_bits() & RESERVED25)
 	{
		sprintf(msg, "UDB_? 1 << 25\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}	

 	if(get_usb_device_bits() & RESERVED26)
 	{
		sprintf(msg, "UDB_? 1 << 26\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}	

 	if(get_usb_device_bits() & RESERVED27)
 	{
		sprintf(msg, "UDB_? 1 << 27\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}		
	
 	if(get_usb_device_bits() & RESERVED28)
 	{
		sprintf(msg, "UDB_? 1 << 28\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}	

 	if(get_usb_device_bits() & RESERVED31)
 	{
		sprintf(msg, "UDB_? 1 << 31\n");	
  		console.write=write(console.open, msg, strlen(msg));
 	}		
	
}