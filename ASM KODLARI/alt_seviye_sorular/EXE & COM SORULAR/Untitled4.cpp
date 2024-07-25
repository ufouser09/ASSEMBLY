program ornek 9.3 asm
10 elemanl� bir dizideki tek ve cift sayilarin adedini bulan program
bu programda test komutu kullan�lm�st�r
------------------------------------------------------------------------------------------------

 PAGE 60,80
TITLE 	tek C�FT/shift kullanarak
SSEG 	SEGMENT PARA STACK 'STACK'
DW 		12 DUP(0)
SSEG 	ends
DSEG 	SEGMENT PARA 'DATA' 
  
  De�i�ken tan�mlar�

DIZI    DW 10,21,43,71,199,67,88,234,0,467
ELEMAN 	DW 10 
TEK_S 	DW 0 
CIFT_S 	DW 0
DSEG    ENDS
CSEG    SEGMENT PARA 'CODE'
TC      PROC   FAR
        ASSUME CS:CSEG, SS:SSEG, DS:DSEG
------------------------------------------------------------------------------------------------

; D�n�� i�in gerekli olan de�erler y���nda saklan�yor
------------------------------------------------------------------------------------------------

        PUSH DS
        XOR AX, AX          �
        PUSH AX
------------------------------------------------------------------------------------------------

; DSEG ismiyle tan�ml� kesim  alan�na eri�ebilmek i�in gerekli tan�mlar
------------------------------------------------------------------------------------------------

        MOV AX, DSEG  �
        MOV DS, AX
------------------------------------------------------------------------------------------------

; Kontrol i�lemini  ger�ekle�tirildi�i kod blo�u
------------------------------------------------------------------------------------------------
		//eleman sayisi cx e at�l�r
        MOV CX,ELEMAN       				;�evrim de�i�kenine eleman say�s� konur
        //dizinin bas�ndaki deger S� adresine gider
        LEA SI,DIZI            				;DIZI'nin ba�lang�� adresi SI yazmac�nda
        //Test komutu 0001 le and ler sonuc 0 ise sayi �ift 1 ise sayi tektir
CEVRIM: TEST WORD PTR [SI], 0001H
        //sonuc 0 ise �ift adresine git                  					;TEST komutu i�lenenleri bozmaz
        JZ c�ft           					;Sonu� s�f�r ise say� �ifttir ilgili sat�ra git 
        //0 degilse tek sayi adedini artt�r
TEK:    INC TEK_S         					;say� tekdir, tek say� adedini artt�r
		//bir sonraki elemana erismek i�in S� bir artar
CIFT:   ADD SI, 2        					; bir sonraki elemana eri�mek i�in SI artt�r�l�r 
                        					; DIZI word tan�ml� oldu�u i�in bir sonraki dizi eleman� 2 byte ileride olacakt�r.
        //dongu doner                					
     	LOOP CEVRIM      					; i�lemi dizinin son eleman�na gelinceye kadar tekrarlamay� sa�layan �evrim komutu
        //donguden sonra Ax e eleman sayisi konur             						
   		MOV AX, ELEMAN     					; �evrim sonucunda sadece tek olan ka� tane eleman oldu�unu biliyoruz. ELEMAN say�s�ndan ��kart�r 
        //eleman sayisindan Tek sayilari da ��kart�rsan �ift sayilari elde edersin                					
  		SUB AX, TEK_S   					; b�ylece kalanlar�n �ift oldu�unu bulabiliriz
        MOV CIFT_S, AX  					; buldu�umuz de�eri tan�ml� de�i�kene yaz
        RET
TC      ENDP
CSEG    ENDS
        END TC          					; program�n ba�lang�� noktas�


