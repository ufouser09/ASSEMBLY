/*
32 bit uzunlugunda pozitif iki tam sayi toplayan programi EXE tipinde yazalim

PROGRAM:�rnek 9-2 ASM
32 bit olarak tan�mlanm�� olan ASAYISI ve BSAYISI isimli degiskenleri toplayarak elde edilen 
sonucu toplam isimli 64 bitlik degiskene yerlestiren EXE tipinde program

*/
PAGE 60,80
TITLE 32 BITLIK POZITIF IKI SAYININ TOPLANMASI

STACKSG SEGMENT PARA STACK 'STACK'
DW 10 DUP(?)
STACKSG ENDS

DATASG SEGMENT PARA 'DATA'
ASAYISI DD 12345678H
BSAYISI DD 9ABCDEF0H
TOPLAM DQ 0H
DATASG ENDS
CODESG SEGMENT PARA 'CODE'
ASSUME CS:CODESG,DS:DATASG,SS:STACKSG
ANA PROC FAR
//DONUS ���N GEREKL� OLAN DEGERLER YIGINDA SAKLANIYOR
PUSH DS
SUB AX,AX
PUSH AX
//DATASG �SM�YLE TANIML� KES�M ALAN�NA ER�SMEK ���N GEREKL� TANIMLAR
MOV AX,DATASG
MOV DS,AX
//TOPLAMA ��LEM�N�N GER�EKLE�T�R�LD�G� KOD BLOGU
LEA SI,ASAYISI	;//SAY�LARLA B�R SEFERDE 64 B�T TOPLAMA YAPILMADIGI ���N 
LEA DI,BSAYISI	;//16 B�T'L�K PARCALAR HAL�NDE OKUNACAKTIR
LEA BX,TOPLAM	;//BU NEDENLE SAY�LARLA SI/DI/BX YAZMACLARI YARDIMIYLA ER�S�LECEKT�R

MOV AX,[SI]		;//AX YAZMAC�NA ASAY�S�N�N DUSUK ANLAMLI WORD'U
MOV DX,[DI]		;//DX YAZMACINA BSAY�S�N�N DUSUK ANLAMLI WORDU
ADD AX,DX
MOV [BX],AX		;//ELDE ED�LEN TOPLAM'IN DUSUK ANLAMLI WORDUNE
MOV AX,[SI+2]	;//AX YAZMACINA ASAY�S�N�N YUKSEK ANLAMLI WORDU
MOV DX,[DI+2]	;//DX YAZMACINA BSAYISININ YUKSEK ANLAMLI WORDU
ADC AX,DX		;//ELDEY� DE ��LEME DAH�L ED�YORUZ VE SONUCU 
MOV [BX+2],AX	;//TOPLAM DEG�SKEN�NE YAZ�YORUZ
ADC WORD PTR [BX+4],0
				;//�K� SAY�N�N 32 B�T TOPLAM�NDA ELDE OLUSMUS �SE BU DEGER�
				;//TOPLAM DEG�SKEN�N�N YUKSEK ANLAML� DWORD ALANINA AKTARAB�LMEK ���N
				;//ELDEL� TOPLAMA ��LEM� YAPIYORUZ

RET 
ANA ENDP
CODESG ENDS
END ANA 	;//PROGRAM�N BASLANG�C NOKTASI
