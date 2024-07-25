program:ornek 9.3 asm 
10 elamanl� bir dizideki tek ve cift say�lar�n adedini bulan program 
bu programda shift metodu kullan�l�r
------------------------------------------------------------------------------------------------

PAGE 60,80
TITLE 	tek C�FT/shift kullanarak
SSEG 	SEGMENT PARA STACK 'STACK'
DW 		12 DUP(0)
SSEG 	ends
DSEG SEGMENT PARA 'DATA'

De�i�ken tan�mlar�

DIZI   	DW 10,21,43,71,199,67,88,234,0,467
ELEMAN 	DW 10 
TEK_S 	DW 0 
CIFT_S 	DW 0
DSEG   	ENDS
CSEG   	SEGMENT PARA 'CODE'
TC     	PROC   FAR
       ASSUME CS:CSEG, SS:SSEG DS:DSEG
------------------------------------------------------------------------------------------------

;D�n�� i�in gerekli olan de�erler y���nda saklan�yor
------------------------------------------------------------------------------------------------

       PUSH DS 
       XOR AX, AX    
       PUSH AX 
------------------------------------------------------------------------------------------------

; DSEG ismiyle tan�ml� kesim alan�na eri�ebilmek i�in gerekli tan�mlar
------------------------------------------------------------------------------------------------

       MOV AX, DSEG
       MOV DS, AX
------------------------------------------------------------------------------------------------

  ;Kontrol i�leminin ger�ekle�tirildi�i kod blo�u
------------------------------------------------------------------------------------------------
	//cx e eleman sayis�n� atar�z
       MOV CX, ELEMAN ; 		;�evrim de�i�kenine eleman say�s� konur 
    //indisi 0 lar�z   
       MOV SI,0        			;DIZI, s�f�r�nc� indisli elemandan ba�lar 
    //burda S� indisli eleman Ax e atar�z   
CEVRIM: MOVE AX,DIZI[SI]		;Elemanlar s�ras� ile AX yazmac�na aktar�l�r
	//Ax say�m�z� 1 saga rigt ederiz.carry flag deki deger 1 ise tek 0 ise c�fttir
        SHR  AX, 1         		;Sa�a do�ru �teleme ile en az anlaml� bit CF'ye 
        //tek sayi adedini artt�r�yoruz carry flag 1 ise ��nk� 1 ise tektir
        ADC  TEK_S, 0      		;CF, 1 ise tektir ve tek say� adedine eklenir 
    //dizi word tan�ml� oldugu i�in 2 artt�rd�k
       ADD SI, 2         		;DIZI word tan�ml� oldu�u i�in bir sonraki dizi eleman� 2 byte ileride olacak
    //burda ise dongumuzu d�nd�r�yoruz                    		
       LOOP CEVRIM      		;i�lemi dizinin son eleman�na gelinceye kadar tekrarlamay� sa�layan �evrim komutu
    //eleman sayisi ax e atar�z                    		
       MOV AX, ELEMAN   		;sonu� olarak tek say� olan eleman say�s�n� biliyoruz.
                        		
	//Bunu ELEMAN say�s�ndan ��kartal�m							 
       SUB AX, TEK_S    		;b�ylece kalanlar�n �ift oldu�unu bulduk 
       //boylece cift sayilari da bulmus olduk
       MOV CIFT_S, AX   		;bulunan de�eri �ift say� adedi olarak atan�r
       RET
       ENDP 
       ENDS 
       END TC         ; program�n ba�lang�� noktas�


