/*
10 elemaný olan,word olarak tanýmlý bir dizi içinde kac tane tek,kaç tane çift sayi oldugunu bulan programý EXE tipinde yaziniz

bu örnekte DIZI isimli 10 elemanlý bir diziden yararlanýcagýz.DÝZÝ elemanlarinin tek veya cift oldugunu anlamak için birkaç
yontem kullanmak mumkundur.
bunlardan bir tanesi sayiyi saða dogru bir kaydýrarak cf bayragýnýn durumunu kontrol ederek tek veya cift ayrýmýný yapmaktadýr.
sýmdý problemýn bu teknýkle cozulmesi durumunda uretilen kodu inceleyelim

program:ornek 9-3 ASM
10 elemanlý bir dizideki tek ve cift sayilarin adedini bulan program
bu programda SHIFT metodu kullanýlýr

*/
PAGE 60,80
TITLE TEK ÇÝFT /SHIFT KULLANARAK
SSEG SEGMENT PARA STACK 'STACK'
DW 12 DUP(?)
SSEG ENDS

DSEG SEGMENT PARA 'DATA'
//DEGÝSKEN TANIMLARI
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
//DSEG ÝSMÝYLE TANIMLI KESÝM ALANINA ERÝSEBÝLMEK ÝÇÝN GEREKLÝ TANIMLAR
MOV AX,DSEG
MOV DS,AX
//KONTROL ÝSLEMÝNÝN GERCEKLESTÝRÝLDÝGÝ KOD BLOGU
	MOV CX,ELEMAN		;//CEVRÝM DEGÝSKENÝNE ELEMAN SAYÝSÝ KONUR	
	MOV SI,0			;//DIZI SIFIRINCI ÝNDÝSLÝ ELEMANDAN BAÞLAR
CEVRÝM:MOV AX,DÝZÝ[SI]	;//ELEMANLAR SIRASI ÝLE AX YAZMACINA AKTARILIR
	SHR AX,1			;//SAGA DOGRU OTELEME ÝLE EN AZ ANLAMLI BÝT CF'YE AKTARILIR
	ADC TEK_S,0			;//CF,1 ÝSE TEKTÝR VE TEK SAYÝ ADEDÝNE EKLENÝR
	ADD SI,2			;//DIZI WORD TANIMLI OLDUGU ICIN BÝR SONRAKÝ DÝZÝ ELEMANI 2 BYTE ÝLERÝDE OLUCAKTIR

	LOOP CEVRIM			;//ÝSLEMÝ DÝZÝNÝN SON ELEMANÝNA GELÝNCEYE KADAR TEKRARLAMAYI SAÐLAYAN CEVRÝM KOMUTU
	MOV AX,ELEMAN		;//SONUC OLARAK TEK SAYÝ OLAN ELEMAN SAYÝSÝNÝ BÝLÝYORUZ
	SUB AX,TEK_S		;//BUNU ELEMAN SAYÝSÝNDAN CIKARTALIM BOYLECE KALANLARIN CÝFT OLDUGUNU BULDUK
	MOV CIFT_S,AX		;//BULUNAN DEGERÝ CÝFT SAYÝ ADEDÝ OLARAK ATANIR
	
	RET
	TC ENDP
	CSEG ENDS
	END TC				;//PROGRAMÝN BASLANGÝC NOKTASÝ
