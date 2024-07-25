/*
10 elemanlý elemanlarý word tanýmlý bir dizi verilmektedir.bu dizinin elemanlarinin on altýlý 
sayi sistemindeki gösterimlerindeki hanelerini(hex-digit)ters-yüz eden programý EXE tipinde yazalým

bizden istenen 0ABCDH olarak verilen bir sayinin islem sonucunda 0DCBAH seklini almasýdýr.
bunu yapabilmek için dondurme komutlarýndan yararlanýlmasý uygun olacaktýr.
ancak sayiyi 16 defa saga veya sola dondurecek olursak ayný degeri elde ederiz.

benzer biçimde sayiyi saða dogru 4 defa dondursek 0DABCH,8 defa dondurursek 0CDABH degerlerini elde ederiz.
bunlardan hiçbiri bizi istedigimiz sonuca ulastýrmaz.

oysa once sayinin yuksek anlamlý byte'ý ile dusuk anlamlý byte'ýnýn yerini degistererek 0CDABH
degerini elde edebiliriz.
ardýndan bu degerin hem yuksek anlamlý,hem de dusuk anlamlý byte'larýný saða veya sola dogru 4 defa dondurursek
0DCBAH degerini elde etmemiz mumkun olur.
fakat kodlama sýrasýnda assembly diline has bir durumu da goz onune almak gereklidir.
tekrarlanan islemlerde CX yazmacý tekrar sayisini tutmak uzere kullanýlýr.
bizim problemimizde tarif edilen dondurme iþlemleri 10 eleman için ayrý ayrý tekrarlanacaktýr.
ayrýca dondurme iþlemini de 4 defa yapacagýmýz dusunulecek olursa CX yazmacý iki farkli degeri tutacak sekilde kullanýlmalýdýr.

Program :ornek 9-4 ASM
16 bitlik bir sayinin on altýlýk tabandaki ifadesindeki hanelerinin terstten yazýlmasýný saglayan exe tipinde program

*/
PAGE 60,80
TITLE HEX DÝGÝTLERÝ TERSYÜZ ETME
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
//DONUS ÝÇÝN GEREKLÝ OLAN DEGERLER YIGINDA SAKLANIYOR
PUSH DS
SUB AX,AX
PUSH AX

//DSEG ÝSMÝYLE TANIMLI KESÝM ALANÝNA ERÝSEBÝLMEK ÝÇÝN GEREKLÝ TANIMLAR
MOV AX,DSEG
MOV DS,AX
//KONTROL ÝSLEMÝNÝN GERCEKLESTÝRÝLDÝGÝ KOD BLOGU

MOV CX,10		;//ELEMAN SAYÝSÝ CX'E YERLESTÝRÝLDÝ
LEA SI,DIZI		;//ELEMANLARA ERÝSMEK ÝÇÝN SI ÝNDÝS OLACAK
CEVRIM:MOV AX,[SI]	;//SAYÝ UZERÝNDEKÝ ÝSLEMÝ HIZLI YAPABÝLMEK ÝÇÝN AX YAZMACI UZERÝNDEN YAPIYORUZ

XCHG AL,AH		;//DUSUK VE YUKSEK ANLAMLI BYTELARI DEGÝSTÝR
PUSH CX			;//TEKRAR SAYÝSÝNÝ BELÝRLEYEN CX YAZMAC DEGERÝNÝ YIGINDA SAKLA 

MOV CL,4		;//DONDURME ÝSLEMÝNÝN TEKRAR SAYÝSÝ CL'DE
ROR AL,CL		;//AL VE AH DEGERLERÝNÝ KENDÝ ÝÇLERÝNDE CL ÝLE 
ROR AH,CL		;//BELÝRLENEN DEGER KADAR (4) SAGA DONDUR
MOV [SI],AX		;//AX UZERÝNDE OLUSAN YENÝ DEGERÝ YERÝNE KOY
ADD SI,2		;//SI'YI SONRAKÝ WORDU GOSTERECEK BÝCÝMDE AYARLA
POP CX			;//YIGINDA SAKLANAN DEGERÝ ALARAK ÝSLEME DEVAM ET
LOOP CEVRIM		;//ÝSLEMÝ CX'DE BELÝRLENEN SAYÝ KADAR TEKRARLA 
RET				;//DÖN
ENDIAN ENDP
CSEG ENDS
END ENDIAN		;//PROGRAMÝN BASLANGÝC NOKTASÝ


