@echo off

pause

ddl %1 -r*:*/ -rconfig.sys -z getUsbDeviceBits.out getUsbDeviceBits.p7s *GO=getUsbDeviceBits.out -fgetUsbDeviceBits.dld

cls
