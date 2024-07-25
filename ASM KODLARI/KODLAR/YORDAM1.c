/*
örnek 10-1
sekil 10-1'de verilen ve bir sayinin kuvvetini almayý saðlayan USTAL isimli yordamý EXE tipinde bir program içinde kullanalým.
USTAL isimli yordam giris verilerini BX ve CX yazmaclarý uzerinden almakta islem sonucunda hesaplanan degeri ise AX yazmacý üzerinde tutmaktadýr.
ust almak için carpma iþleminden yararlanýlacaktýr.

programýmýzdaki SAYI,UST ve SONUC isimli degiskenler word olarak tanýmlanmýstýr.

burada SAYI ve UST degerleri buyuk secilecek olursa elde edilecek deger SONUC isimli degiskene sýgmayacak kadar buyuk olucaktýr.
buna göre programýmýzý test ederken giris degerlerini özenle secmek gerekecektir.


*/
//PROGRAM : ÖRNEK 10-1 ASM
//KESÝM ÝÇÝNDEKÝ YORDAMI ÇAÐIRAN EXE TÝPÝNDE PROGRAM

PAGE 60,80
TITLE SAYÝNÝN KUVVETÝNÝ HESAPLAR

STACKSG SEGMENT PARA STACK 'STACK'
		DW 10 DUP(?)
STACKSG ENDS
DATASG SEGMENT PARA 'DATA'

//KULLANICAGIMIZ DEGÝSKENLER
SAYI DW 2
UST DW 10
SONUC DW 0
DATASG ENDS
CODESG SEGMENT PARA 'CODE'
ASSUME CS:CODESG,DS:DATASG,SS:STACKSG
ANA PROC FAR

//DONUS ÝÇÝN GEREKLÝ OLAN DEGERLER YIGINDA SAKLANIYOR

PUSH DS
SUB AX,AX
PUSH AX

//DATASG ÝSMÝYLE TANIMLI KESÝM ALANINA ERÝÞEBÝLMEK ÝÇÝN GEREKLÝ TANIMLAR

MOV AX,DATASG
MOV DS,AX

//ÝÞLEMÝNÝN GERÇEKLEÞTÝRÝLDÝÐÝ KOD BLOGU

MOV CX,UST	;//UST VE SAYI PARAMETRELERÝ YAZMACLARDA		
MOV BX,SAYI
CALL USTAL	;//YORDAM ÇAÐIRMA
MOV SONUC,AX;//ÝSLEMÝNÝN SONUCU AX YAZMACI ÜZERÝNDEN AKTARILIYOR
RET			;//DON
ANA ENDP

//UST ALMA ÝSLEMÝNÝ GERCEKLESTÝREN YORDAM 

USTAL 	PROC NEAR
		MOV AX,1
	L1:	MUL BX	;//CARPMA ÝÞLEMÝ AX ÜZERÝNDEN YAPILIYOR.
		LOOP L1
		RET		;//CAGRILDIGIN NOKTAYA DON
USTAL	ENDP
CODESG ENDS
		END ANA	;//PROGRAMIN BASLANGIC NOKTASI
		
		
**		
