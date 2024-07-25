program:ornek 9.3 asm 
10 elamanlý bir dizideki tek ve cift sayýlarýn adedini bulan program 
bu programda shift metodu kullanýlýr
------------------------------------------------------------------------------------------------

PAGE 60,80
TITLE 	tek CÝFT/shift kullanarak
SSEG 	SEGMENT PARA STACK 'STACK'
DW 		12 DUP(0)
SSEG 	ends
DSEG SEGMENT PARA 'DATA'

Deðiþken tanýmlarý

DIZI   	DW 10,21,43,71,199,67,88,234,0,467
ELEMAN 	DW 10 
TEK_S 	DW 0 
CIFT_S 	DW 0
DSEG   	ENDS
CSEG   	SEGMENT PARA 'CODE'
TC     	PROC   FAR
       ASSUME CS:CSEG, SS:SSEG DS:DSEG
------------------------------------------------------------------------------------------------

;Dönüþ için gerekli olan deðerler yýðýnda saklanýyor
------------------------------------------------------------------------------------------------

       PUSH DS 
       XOR AX, AX    
       PUSH AX 
------------------------------------------------------------------------------------------------

; DSEG ismiyle tanýmlý kesim alanýna eriþebilmek için gerekli tanýmlar
------------------------------------------------------------------------------------------------

       MOV AX, DSEG
       MOV DS, AX
------------------------------------------------------------------------------------------------

  ;Kontrol iþleminin gerçekleþtirildiði kod bloðu
------------------------------------------------------------------------------------------------
	//cx e eleman sayisýný atarýz
       MOV CX, ELEMAN ; 		;Çevrim deðiþkenine eleman sayýsý konur 
    //indisi 0 larýz   
       MOV SI,0        			;DIZI, sýfýrýncý indisli elemandan baþlar 
    //burda Sý indisli eleman Ax e atarýz   
CEVRIM: MOVE AX,DIZI[SI]		;Elemanlar sýrasý ile AX yazmacýna aktarýlýr
	//Ax sayýmýzý 1 saga rigt ederiz.carry flag deki deger 1 ise tek 0 ise cýfttir
        SHR  AX, 1         		;Saða doðru öteleme ile en az anlamlý bit CF'ye 
        //tek sayi adedini arttýrýyoruz carry flag 1 ise çünkü 1 ise tektir
        ADC  TEK_S, 0      		;CF, 1 ise tektir ve tek sayý adedine eklenir 
    //dizi word tanýmlý oldugu için 2 arttýrdýk
       ADD SI, 2         		;DIZI word tanýmlý olduðu için bir sonraki dizi elemaný 2 byte ileride olacak
    //burda ise dongumuzu döndürüyoruz                    		
       LOOP CEVRIM      		;iþlemi dizinin son elemanýna gelinceye kadar tekrarlamayý saðlayan çevrim komutu
    //eleman sayisi ax e atarýz                    		
       MOV AX, ELEMAN   		;sonuç olarak tek sayý olan eleman sayýsýný biliyoruz.
                        		
	//Bunu ELEMAN sayýsýndan çýkartalým							 
       SUB AX, TEK_S    		;böylece kalanlarýn çift olduðunu bulduk 
       //boylece cift sayilari da bulmus olduk
       MOV CIFT_S, AX   		;bulunan deðeri çift sayý adedi olarak atanýr
       RET
       ENDP 
       ENDS 
       END TC         ; programýn baþlangýç noktasý


