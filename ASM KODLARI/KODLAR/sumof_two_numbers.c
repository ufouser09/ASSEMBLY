/*
ÖRNEK 9-1
16 bit uzunlugunda pozitif iki tam sayi toplayan programi EXE tipinde yazalim.
tahmin edilebileceði gibi pozitif 16 bitlik iki sayinin toplami 16 bit ile ifade edilebilenden 
daha buyuk bir deger olabilir.bu durumda sonucun bir ust birim cinsinden 
yani 32 bit olmasi gerekecektir.
buna göre programimizda toplanacak sayilari ASAYÝSÝ ve BSAYÝSÝ sonucu ise TOPLAM isimli degiskenlerde tutmak için gerekli veri tanýmlamalarýný yapalým.
toplama iþleminin ax yazmacý kullanýlarak yapýlmasý daha etkin bir program yazmamýzý saglýyacaktýr
TOPLAM isimli degiskenin 32 bit olacagi ve 8086 mikroislemcisi ile bir seferde en fazla 16 bit islem yapýlabildigi dikkate alýndýgýnda yazmac dolaylý ,baz goreli veya dogrudan indisli adresleme tekniklerinden birinin kullanýlmasý uygun olucaktýr

PROGRAM :ornek 9-1 ASM
16 bit tanýmlý ASAYISI ve BSAYISI isimli degiskenleri toplayarak elde edilen sonucu 
TOPLAM isimli 32 bit'lik degiskene yerlestiren EXE program

*/
PAGE 60,80
TITLE 16 BITLIK POZITIF IKI SAYININ TOPLANMASI

STACKSG SEGMENT PARA STACK 'STACK'
DW 10 DUP(?)
STACKSG ENDS

DATASG SEGMENT PARA 'DATA'
ASAYISI DW 1234H	;//GÝRÝS/CIKIS DEGERLERÝNÝN VERÝ ALANI UZERÝNDE ÝLK DEGER ATAMASI YAPILMAKTADIR
BSAYISI DW 0ABCDH
TOPLAM DD 0H		;//TOPLAM DEGÝSKENÝNÝN ÝLK DEGERÝ SIFIR YAPILIR
DATASG ENDS

CODESG SEGMENT PARA 'CODE'
ASSUME CS:CODESG,DS:DATASG,SS:STACKSG
ANA PROC FAR
//DONUS ICIN GEREKLÝ OLAN DEGERLER YIGINDA SAKLANIYOR
PUSH DS
SUB AX,AX
PUSH AX
//DATASG ÝSMÝYLE TANIMLI KESÝM ALANÝNA ERÝSEBÝLMEK ÝÇÝN GEREKLÝ TANIMLAR
MOV AX,DATASG
MOV DS,AX
//TOPLAMA ÝSLEMÝNÝN GERCEKLESTÝRÝLDÝGÝ KOD BLOGU
LEA SI,TOPLAM	;//SI TOPLAM DEGÝSKENÝNÝN BASLADÝGÝ ADRESÝ BELÝRLER
MOV AX,ASAYISI	;//AX YAZMACÝ ASAYÝSÝ'NÝN DEGERÝNÝ TUTAR
MOV BX,BSAYISI	;//BX YAZMACÝ BSAYÝSÝ'NÝN DEGERÝNÝ TUTAR
ADD AX,BX		;//TOPLAMÝN SONUCUN AX YAZMACINDA BULUNUR
MOV [SI],AX		;//SONUC TOPLAM'ÝN EN AZ ANLAMLÝ WORDUNDE OLUSAN ELDEYÝ YUKSEK ANLAMLI WORDE YAZ	

ADC WORD PTR [SI+2],0
RET
ANA ENDP
CODESG ENDS
END ANA					;//PROGRAMIN BASLANGIC NOKTASI



