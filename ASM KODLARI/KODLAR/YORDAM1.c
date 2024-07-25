/*
�rnek 10-1
sekil 10-1'de verilen ve bir sayinin kuvvetini almay� sa�layan USTAL isimli yordam� EXE tipinde bir program i�inde kullanal�m.
USTAL isimli yordam giris verilerini BX ve CX yazmaclar� uzerinden almakta islem sonucunda hesaplanan degeri ise AX yazmac� �zerinde tutmaktad�r.
ust almak i�in carpma i�leminden yararlan�lacakt�r.

program�m�zdaki SAYI,UST ve SONUC isimli degiskenler word olarak tan�mlanm�st�r.

burada SAYI ve UST degerleri buyuk secilecek olursa elde edilecek deger SONUC isimli degiskene s�gmayacak kadar buyuk olucakt�r.
buna g�re program�m�z� test ederken giris degerlerini �zenle secmek gerekecektir.


*/
//PROGRAM : �RNEK 10-1 ASM
//KES�M ���NDEK� YORDAMI �A�IRAN EXE T�P�NDE PROGRAM

PAGE 60,80
TITLE SAY�N�N KUVVET�N� HESAPLAR

STACKSG SEGMENT PARA STACK 'STACK'
		DW 10 DUP(?)
STACKSG ENDS
DATASG SEGMENT PARA 'DATA'

//KULLANICAGIMIZ DEG�SKENLER
SAYI DW 2
UST DW 10
SONUC DW 0
DATASG ENDS
CODESG SEGMENT PARA 'CODE'
ASSUME CS:CODESG,DS:DATASG,SS:STACKSG
ANA PROC FAR

//DONUS ���N GEREKL� OLAN DEGERLER YIGINDA SAKLANIYOR

PUSH DS
SUB AX,AX
PUSH AX

//DATASG �SM�YLE TANIMLI KES�M ALANINA ER��EB�LMEK ���N GEREKL� TANIMLAR

MOV AX,DATASG
MOV DS,AX

//��LEM�N�N GER�EKLE�T�R�LD��� KOD BLOGU

MOV CX,UST	;//UST VE SAYI PARAMETRELER� YAZMACLARDA		
MOV BX,SAYI
CALL USTAL	;//YORDAM �A�IRMA
MOV SONUC,AX;//�SLEM�N�N SONUCU AX YAZMACI �ZER�NDEN AKTARILIYOR
RET			;//DON
ANA ENDP

//UST ALMA �SLEM�N� GERCEKLEST�REN YORDAM 

USTAL 	PROC NEAR
		MOV AX,1
	L1:	MUL BX	;//CARPMA ��LEM� AX �ZER�NDEN YAPILIYOR.
		LOOP L1
		RET		;//CAGRILDIGIN NOKTAYA DON
USTAL	ENDP
CODESG ENDS
		END ANA	;//PROGRAMIN BASLANGIC NOKTASI
		
		
**		
