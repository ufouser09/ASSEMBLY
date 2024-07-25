/*
10 elemanl� elemanlar� word tan�ml� bir dizi verilmektedir.bu dizinin elemanlarinin on alt�l� 
sayi sistemindeki g�sterimlerindeki hanelerini(hex-digit)ters-y�z eden program� EXE tipinde yazal�m

bizden istenen 0ABCDH olarak verilen bir sayinin islem sonucunda 0DCBAH seklini almas�d�r.
bunu yapabilmek i�in dondurme komutlar�ndan yararlan�lmas� uygun olacakt�r.
ancak sayiyi 16 defa saga veya sola dondurecek olursak ayn� degeri elde ederiz.

benzer bi�imde sayiyi sa�a dogru 4 defa dondursek 0DABCH,8 defa dondurursek 0CDABH degerlerini elde ederiz.
bunlardan hi�biri bizi istedigimiz sonuca ulast�rmaz.

oysa once sayinin yuksek anlaml� byte'� ile dusuk anlaml� byte'�n�n yerini degistererek 0CDABH
degerini elde edebiliriz.
ard�ndan bu degerin hem yuksek anlaml�,hem de dusuk anlaml� byte'lar�n� sa�a veya sola dogru 4 defa dondurursek
0DCBAH degerini elde etmemiz mumkun olur.
fakat kodlama s�ras�nda assembly diline has bir durumu da goz onune almak gereklidir.
tekrarlanan islemlerde CX yazmac� tekrar sayisini tutmak uzere kullan�l�r.
bizim problemimizde tarif edilen dondurme i�lemleri 10 eleman i�in ayr� ayr� tekrarlanacakt�r.
ayr�ca dondurme i�lemini de 4 defa yapacag�m�z dusunulecek olursa CX yazmac� iki farkli degeri tutacak sekilde kullan�lmal�d�r.

Program :ornek 9-4 ASM
16 bitlik bir sayinin on alt�l�k tabandaki ifadesindeki hanelerinin terstten yaz�lmas�n� saglayan exe tipinde program

*/
PAGE 60,80
TITLE HEX D�G�TLER� TERSY�Z ETME
SSEG SEGMENT PARA STACK 'STACK'
DW 12 DUP(0)
SSEG ENDS

DSEG SEGMENT PARA 'DATA'
ELEMAN DW 10
DIZI DW 1234H,2345H,3456H,4567H,5678H,6789H,789AH,89ABH,9ABCH,0ABCDH
DSEG ENDS

CSEG SEGMENT PARA 'CODE'
ENDIAN PROC FAR
ASSUME CS:CSEG,SS:SSEG,DS:DSEG
//DONUS ���N GEREKL� OLAN DEGERLER YIGINDA SAKLANIYOR
PUSH DS
SUB AX,AX
PUSH AX

//DSEG �SM�YLE TANIMLI KES�M ALAN�NA ER�SEB�LMEK ���N GEREKL� TANIMLAR
MOV AX,DSEG
MOV DS,AX
//KONTROL �SLEM�N�N GERCEKLEST�R�LD�G� KOD BLOGU

MOV CX,10		;//ELEMAN SAY�S� CX'E YERLEST�R�LD�
LEA SI,DIZI		;//ELEMANLARA ER�SMEK ���N SI �ND�S OLACAK
CEVRIM:MOV AX,[SI]	;//SAY� UZER�NDEK� �SLEM� HIZLI YAPAB�LMEK ���N AX YAZMACI UZER�NDEN YAPIYORUZ

XCHG AL,AH		;//DUSUK VE YUKSEK ANLAMLI BYTELARI DEG�ST�R
PUSH CX			;//TEKRAR SAY�S�N� BEL�RLEYEN CX YAZMAC DEGER�N� YIGINDA SAKLA 

MOV CL,4		;//DONDURME �SLEM�N�N TEKRAR SAY�S� CL'DE
ROR AL,CL		;//AL VE AH DEGERLER�N� KEND� ��LER�NDE CL �LE 
ROR AH,CL		;//BEL�RLENEN DEGER KADAR (4) SAGA DONDUR
MOV [SI],AX		;//AX UZER�NDE OLUSAN YEN� DEGER� YER�NE KOY
ADD SI,2		;//SI'YI SONRAK� WORDU GOSTERECEK B�C�MDE AYARLA
POP CX			;//YIGINDA SAKLANAN DEGER� ALARAK �SLEME DEVAM ET
LOOP CEVRIM		;//�SLEM� CX'DE BEL�RLENEN SAY� KADAR TEKRARLA 
RET				;//D�N
ENDIAN ENDP
CSEG ENDS
END ENDIAN		;//PROGRAM�N BASLANG�C NOKTAS�


