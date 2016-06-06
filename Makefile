CC = C:\VerixVAps\VRXSDK\bin\vrxcc
HR = C:\VerixVAps\VRXSDK\bin\vrxhdr
CFLAGS += -vv -b
LFLAGS += -b
EFLAGS += -e
LIBFLAGS +=

all : getUsbDeviceBits.out 

getUsbDeviceBits.out : getUsbDeviceBits.c
	$(CC) $(CFLAGS) $(EFLAGS) getUsbDeviceBits.err getUsbDeviceBits.c -o getUsbDeviceBits.out

clean :
	del *.o *.out *.p7s *.err

