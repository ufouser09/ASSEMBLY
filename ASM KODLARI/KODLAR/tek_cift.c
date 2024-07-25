/*
10 eleman� olan,word olarak tan�ml� bir dizi i�inde kac tane tek,ka� tane �ift sayi oldugunu bulan program� EXE tipinde yaziniz

bu �rnekte DIZI isimli 10 elemanl� bir diziden yararlan�cag�z.D�Z� elemanlarinin tek veya cift oldugunu anlamak i�in birka�
yontem kullanmak mumkundur.
bunlardan bir tanesi sayiyi sa�a dogru bir kayd�rarak cf bayrag�n�n durumunu kontrol ederek tek veya cift ayr�m�n� yapmaktad�r.
s�md� problem�n bu tekn�kle cozulmesi durumunda uretilen kodu inceleyelim

program:ornek 9-3 ASM
10 elemanl� bir dizideki tek ve cift sayilarin adedini bulan program
bu programda SHIFT metodu kullan�l�r

*/
PAGE 60,80
TITLE TEK ��FT /SHIFT KULLANARAK
SSEG SEGMENT PARA STACK 'STACK'
DW 12 DUP(?)
SSEG ENDS

DSEG SEGMENT PARA 'DATA'
//DEG�SKEN TANIMLARI
DIZI DW 10,21,43,71,199,67,88,234,0,467
ELEMAN DW 10
TEK_S DW 0
CIFT_S DW 0
DSEG ENDS

CSEG SEGMENT PARA 'CODE'
TC PROC FAR
ASSUME CS:CSEG,SS:SSEG,DS:DSEG
//DONUS ICIN GEREKLI OLAN DEGERLER YIGINDA SAKLANIYOR
PUSH DS
XOR AX,AX
PUSH AX
//DSEG �SM�YLE TANIMLI KES�M ALANINA ER�SEB�LMEK ���N GEREKL� TANIMLAR
MOV AX,DSEG
MOV DS,AX
//KONTROL �SLEM�N�N GERCEKLEST�R�LD�G� KOD BLOGU
	MOV CX,ELEMAN		;//CEVR�M DEG�SKEN�NE ELEMAN SAY�S� KONUR	
	MOV SI,0			;//DIZI SIFIRINCI �ND�SL� ELEMANDAN BA�LAR
CEVR�M:MOV AX,D�Z�[SI]	;//ELEMANLAR SIRASI �LE AX YAZMACINA AKTARILIR
	SHR AX,1			;//SAGA DOGRU OTELEME �LE EN AZ ANLAMLI B�T CF'YE AKTARILIR
	ADC TEK_S,0			;//CF,1 �SE TEKT�R VE TEK SAY� ADED�NE EKLEN�R
	ADD SI,2			;//DIZI WORD TANIMLI OLDUGU ICIN B�R SONRAK� D�Z� ELEMANI 2 BYTE �LER�DE OLUCAKTIR

	LOOP CEVRIM			;//�SLEM� D�Z�N�N SON ELEMAN�NA GEL�NCEYE KADAR TEKRARLAMAYI SA�LAYAN CEVR�M KOMUTU
	MOV AX,ELEMAN		;//SONUC OLARAK TEK SAY� OLAN ELEMAN SAY�S�N� B�L�YORUZ
	SUB AX,TEK_S		;//BUNU ELEMAN SAY�S�NDAN CIKARTALIM BOYLECE KALANLARIN C�FT OLDUGUNU BULDUK
	MOV CIFT_S,AX		;//BULUNAN DEGER� C�FT SAY� ADED� OLARAK ATANIR
	
	RET
	TC ENDP
	CSEG ENDS
	END TC				;//PROGRAM�N BASLANG�C NOKTAS�
