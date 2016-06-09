CC = C:\VerixVAps\VRXSDK\bin\vrxcc
HR = C:\VerixVAps\VRXSDK\bin\vrxhdr
CFLAGS += -vv -b
LFLAGS += -b
EFLAGS += -e
LIBFLAGS +=

all : getUsbDeviceBits.out #getUsbDeviceBits.p7s

#getUsbDeviceBits.p7s : getUsbDeviceBits.out 
#	"C:\Program Files\VERIFONE\FST\FileSignature.exe" -C "C:\TestSuite10\Common\SponsorCert.crt" -F "%cd%\getUsbDeviceBits.out" -CM 
#	rename getUsbDeviceBits.out.p7s getUsbDeviceBits.p7s 

getUsbDeviceBits.out : getUsbDeviceBits.c
	$(CC) $(CFLAGS) $(EFLAGS) getUsbDeviceBits.err getUsbDeviceBits.c -o getUsbDeviceBits.out

clean :
	del *.o *.out *.p7s *.err

