/*
karek�k hesab�-sqroot(harici yordam)

verilen pozitif bir tam say�n�n karek�k�n� hesaplamak i�in say�dan s�ras� ile 1,3,5,... gibi tek sayilar ��kart�larak sonuc s�f�rdan kucuk c�kana kadar i�leme devam ediliyor.
ger�ekle�tirilen i�lem sayisi verilen say�n�n karek�k degerini(tam sayi olarak)verir.
karek�k alma i�lemini ger�ekle�tiren harici yordam�n assembly program�n� yazal�m.

*/

//BU PROGRAM YIGIN �ZER�NDEN 1 WORD OLARAK ALDIGI PARAMETREN�N KAREK�K DEGER�N� AX YAZMACI �ZER�NDEN D�ND�R�R
//YIGINDAK� PARAMETREY� KALDIRIR.

PUBL�C SQROOT
MYCODE SEGMENT PARA CODE
ASSUME CS:MYCODE
SQROOT PROC FAR
PUSH DX
PUSH BX
PUSH BP
MOV BP,SP
MOV DX,1
XOR AX,AX
MOV BX,[BP+10]
SUB BX,DX
L1:JL SON
INC AX
ADD DX,2
SUB BX,DX
JMP L1
SON:POP BP
POP BX
POP DX
RET 2
SQROOTENDP
MYCODE ENDS
END
