------------------------------------------------------------------------------------------------
 
    PAGE 60,80
TITLE 	HEX digitleri ters y�z etme
SSEG 	SEGMENT PARA STACK 'STACK'
DW 		12 DUP(0)
SSEG 	ends
DSEG 	SEGMENT PARA 'DATA' 
  
	
------------------------------------------------------------------------------------------------
	
	;Dizi elemanlar� ve eleman say�s� tan�mlanm��t�r.
------------------------------------------------------------------------------------------------

     ELEMAN DW 10
     DIZI   DW 1234H,2345H,3456H,4567H,5678H,6789H,789AH,89ABH,9ABCH2OABCDH
     DSEG   ENDS
     CSEG   SEGMENT PARA 'CODE'
     ENDIAN PROC FAR
            ASSUME CS:CSEG,SS:SSEG, :DSEG
------------------------------------------------------------------------------------------------

    ;D�n�� i�in gerekli olan degerler y���nda saklan�yor
------------------------------------------------------------------------------------------------

            PUSH DS 
            SUB AX, AX 
            PUSH AX
 ------------------------------------------------------------------------------------------------
                           
    ;DSEG ismiyle tan�ml� kesim alan�na eri�ebilmek i�in gerekli tan�mlar
------------------------------------------------------------------------------------------------

            MOV AX, DSEG 
            MOV DS, AX
------------------------------------------------------------------------------------------------

    ;Kontrol i�leminin ger�ekle�tirildi�i kod blo�u
------------------------------------------------------------------------------------------------
		//eleman sayisi Cx e at�l�r
            MOV CX,10           ; Eleman say�s� CX'e yerle�tirildi
            //dizinin bas�ndaki eleman S� adresine atan�r
            LEA SI, DIZI        ;Elemanlara eri�mek i�in SI indis olacak
            //adresteki eleman ax e atan�r
     CEVRIM:MOV AX,[SI]       	;Say� �zerindek� i�lemi h�zl� yapabilmek i�in AX yazmac� �zerinden yap�yoruz
            //bas�ndaki ve sonundaki byte lar� degistir                   	
            XCHG AL, AH        	;D���k ve y�ksek anlaml� byte'lar� de�i�tir 
            //cx i stack e at cunku cx imiz degiscek birazdan
            PUSH CX             ;Tekrar say�s�n� belirleyen CX yazma� de�erini y���nda sakla
            //cl ye 4 degerini ata                   
            MOV CL, 4          	;d�nd�rme i�leminin tekrar say�s� CL de
            //cl kadar yani 4 kere saga �tele al ve ah �
            ROR AL, CL          ;AL ve AH de�erlerini kendi i�lerinde CL ile belirlenen de�er kadar (4) sa�a d�nd�r
       		ROR AH, CL         	
       		//ax �zerinde olusan yeni degeri yerine koy
            MOV [SI], AX       	;AX �zerinde olu�an yeni de�er� yerine koy 
            //indisi 1 artt�r
            ADD SI,1           	;SI'y� sonraki word'� g�sterecek bi�imde ayarla 
            //Cx i stack ten �ek
     		POP CX             	;Y���nda saklanan de�eri alarak i�leme devam et 
            LOOP CEVRIM        	;i�lemi CX de belirlenen say� kadar tekrarla d�n
            RET                	
     ENDIAN ENDP
	CSEG    ENDS
            END ENDIAN         ;program�n ba�lang�� noktas�


