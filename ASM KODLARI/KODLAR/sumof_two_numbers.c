/*
�RNEK 9-1
16 bit uzunlugunda pozitif iki tam sayi toplayan programi EXE tipinde yazalim.
tahmin edilebilece�i gibi pozitif 16 bitlik iki sayinin toplami 16 bit ile ifade edilebilenden 
daha buyuk bir deger olabilir.bu durumda sonucun bir ust birim cinsinden 
yani 32 bit olmasi gerekecektir.
buna g�re programimizda toplanacak sayilari ASAY�S� ve BSAY�S� sonucu ise TOPLAM isimli degiskenlerde tutmak i�in gerekli veri tan�mlamalar�n� yapal�m.
toplama i�leminin ax yazmac� kullan�larak yap�lmas� daha etkin bir program yazmam�z� sagl�yacakt�r
TOPLAM isimli degiskenin 32 bit olacagi ve 8086 mikroislemcisi ile bir seferde en fazla 16 bit islem yap�labildigi dikkate al�nd�g�nda yazmac dolayl� ,baz goreli veya dogrudan indisli adresleme tekniklerinden birinin kullan�lmas� uygun olucakt�r

PROGRAM :ornek 9-1 ASM
16 bit tan�ml� ASAYISI ve BSAYISI isimli degiskenleri toplayarak elde edilen sonucu 
TOPLAM isimli 32 bit'lik degiskene yerlestiren EXE program

*/
PAGE 60,80
TITLE 16 BITLIK POZITIF IKI SAYININ TOPLANMASI

STACKSG SEGMENT PARA STACK 'STACK'
DW 10 DUP(?)
STACKSG ENDS

DATASG SEGMENT PARA 'DATA'
ASAYISI DW 1234H	;//G�R�S/CIKIS DEGERLER�N�N VER� ALANI UZER�NDE �LK DEGER ATAMASI YAPILMAKTADIR
BSAYISI DW 0ABCDH
TOPLAM DD 0H		;//TOPLAM DEG�SKEN�N�N �LK DEGER� SIFIR YAPILIR
DATASG ENDS

CODESG SEGMENT PARA 'CODE'
ASSUME CS:CODESG,DS:DATASG,SS:STACKSG
ANA PROC FAR
//DONUS ICIN GEREKL� OLAN DEGERLER YIGINDA SAKLANIYOR
PUSH DS
SUB AX,AX
PUSH AX
//DATASG �SM�YLE TANIMLI KES�M ALAN�NA ER�SEB�LMEK ���N GEREKL� TANIMLAR
MOV AX,DATASG
MOV DS,AX
//TOPLAMA �SLEM�N�N GERCEKLEST�R�LD�G� KOD BLOGU
LEA SI,TOPLAM	;//SI TOPLAM DEG�SKEN�N�N BASLAD�G� ADRES� BEL�RLER
MOV AX,ASAYISI	;//AX YAZMAC� ASAY�S�'N�N DEGER�N� TUTAR
MOV BX,BSAYISI	;//BX YAZMAC� BSAY�S�'N�N DEGER�N� TUTAR
ADD AX,BX		;//TOPLAM�N SONUCUN AX YAZMACINDA BULUNUR
MOV [SI],AX		;//SONUC TOPLAM'�N EN AZ ANLAML� WORDUNDE OLUSAN ELDEY� YUKSEK ANLAMLI WORDE YAZ	

ADC WORD PTR [SI+2],0
RET
ANA ENDP
CODESG ENDS
END ANA					;//PROGRAMIN BASLANGIC NOKTASI



