
----------------------------------------------------------------------------------------------------------------

		Final S�nav�nda Ba�ar�l�, Ba�ans�z ve B�t�nlemeye Kalan ��rencilerin Tespiti
       
	   
	   n ki�inin kaydoldu�u bir dersin final s�nav�nda e�ik de�erin alt�nda not alan 
       ��renciler dersten kalm��t�r. E�ik de�erin �st�nde not alan o�rencilerAn al- 
       d��� notlar�n ortalamas� hesaplan�r ve bu ortalaman�n �st�nde olan ��renciler 
       final s�nav�ndan ba�ar� say�l�r, ortalaman�n alt�nda olan ��renciler ise b�- 
       t�nleme s�nav�na girmeleri gerekmektedir. Final s�nav� sonunda ba�ar�l�, ba- 
       �ar�s�z ve b�t�nlemeye kalan ��rencilerin say�s�n� bulan ExE.tipi assembly 
       program�n� yazal�m.
 ----------------------------------------------------------------------------------------------------------------
      
       n=280-------->cx
       dizi[n]={....}---------------->i miz s� ile tutar�z.
       knt=0
       topNOt=0;
       basarisiz=0
       but=0
       basarili=0
       esik=40
       
       for(i=1;i<n;i++)
       if(dizi[i]>=esik)--------------->burdaki dizimi al ile tutulur
       topnot+=dizi[i]
       else
       basarisiz++
	
	
	esikustu=n-basarisiz------------->cx
	ort=topknot/es�kustu--------------->ort =al
	
	for(i=1;i<n;i++)
	if(ort<=dizi[i])--------------------->burdaki dizimiz ah ile tutulur
	basarili++
	else{
		if(dizi[i]>=esik)
		but++
	}
        
		stop
----------------------------------------------------------------------------------------------------------------
		
		
		T�m ��renciler dersten ba�ar�l�, ba�ar�s�z veya b�t�nleme olarak
        gruplanabilece�inden bu de�i�kenlerin tipleri word olarak tan�mlanm��t�r.

        MYDS    	SEGMENT PARA 'DATA'
        DIZI    	DB 280 DUP(?)
        N       	DW 280
        BASARISIZ 	DW 0 
        BASARILI 	DW 0
        BUT     	DW 0
        TOPNOT  	DW 0
        ESIK    	DB 40
        MYDS    	ENDS

        MYS5    	SEGMENT PARA STACK 'STACK'
                  	DW 20 DUP(?) 
        MYSS    	ENDS
       
	    MYCS    	SEGMENT PARA 'CODE'              � V
                  	ASSUME DS:MYDS, SS:MYSS, CS:MYCS 
        CAN     	PROC FAR
                  	PUSH DS
                  	XOR AX, AX 
                  	PUSH AX
                  	MOV AX, MYDS 
                  	MOV DS, AX 
                  	----------------------------------------------------------------------------------------------------------------
					kod buradan sonra
					----------------------------------------------------------------------------------------------------------------
  					//biz burda ilk �nce s� m�z� yani indisimiz 0 lar�z.
					XOR SI, SI;DIZI'nin indis yazmac� O'lan�r.
					//sonra d�ng� sayimizi cx yazmac�na yani d�ng� yazmac�na atar�z.
                  	MOV CX, N; DIZI'nin eleman say�s� CX'e yerle�tirilir. 
                  	//dizinin s� �ndisindeki eleman� al ye al�r�z.
          L1:     	MOV AL, DIZI[SI]   	; DIZI'nin s� indisli eleman�, AL yazmac�na al�n�r.
                    //sonra bunu esik degerimizle yani s�n�rla kars�last�r�z burda kalanlar� ve gecenleri buluruz                 	
                  	CMP AL, ESIK       	; AL, ESIK de�i�keni ile kar��la�t�r�l�r.
                  	//al esik degerden buyuk esitse gecmissindir
                  	JAE ESIKUSTU       	; AL, ESIK de�erinden b�y�k e�itse ESIKUSTU  etiketine atlan�r.
                                     	
                  	//eger al esik den buyuk esit degilse gecememissindir o zamanda kalanlar� bir artt�r�rs�n
					INC BASARISIZ      	; AL: ESIK de�erinden k���kse BASARISIZ  degi�keni de�eri 1 artt�r�l�r.
                                  		
                  	JMP D1             	; Ba�ar�s�z notu olan bir ��renci bulundu�u ; i�in, bu not ortalamaya kat�lmayaca��ndan ; toplama i�lemine gerek olmad��� i�in ; atlanarak D1 etiketine gidilir.
                                     	
                                     
                    //eger basar�l� bir ogrenci bulursak bunu worde yani ax'e genisletiriz          		        
        ESIKUSTU:  	CBW      			; ��rencinin, AL i�erisindeki notu ESIK de�erin �st�nde ise AL, AX'e geni�letilir. 
                    //sonra basar�l�lar�n yani gecenlerin notlar�n� topl�cag�m�z i�in ax le topnot u toplar�z                  
                  	ADD TOPNOT,AX      	; B�ylece mord tan�ml� TOPNOT de�i�keni ile  tip uyumsuzlu�u olmadan toplanabilir.
                    //burda ise indisimizi bir artt�r�p d�ng�y� d�nd�r�r�z       �         
          D1:     	INC SI           	; Yeni nota eri�mek i�in SI, 1 artt�r�l�r. 
                  	LOOP L1            	; i�lemin N kez tekrarlanmas� sa�lan�r.
                  	//��renci sayisi cx e at�l�r
					MOV CX,N       		; �grenci say�s� (N), CX i�erisine al�n�r. 
					//toplam ��renci sayisindan basar�s�zlar� ��kart�r�z.ve gecenleri buluruz
                  	SUB CX,BASARISIZ   	; Ba�ar�s�zlar�n say�s� CX'ten ��kar�l�r.
                  	//daha sonra dx s�f�rlan�r ��nk� 16 bitlik b�lme i�lemi yap�caz
                  	XOR DX,DX       	; 16-bit'lik b�lme i�lemi �ncesi DX O'lan�r. 
                  	//ax �zerinden bolme yap�cag�m�z i�in ax e topnot degeri atan�r
                  	MOV AX,TOPNOT     	; Ba�ar�s�z ��renciler hari� di�er  ��rencilerin notlar� AX'e yerle�tirilir. 
                                     
                    //notlar�m�z�n toplam�n� gecenlere bolerek ortalama bir deger bulunur.            	 	
					DIV CX   		   	; DX:AX / CX i�lemi sonucunda B�l�m: AX,; Kalan: DX �zerinde olu�ur. Yani ; ba�ar�s�zlar hari� di�er ��rencilerin ; notlar�n�n ortalamas� AX yazmac�ndad�r.
                                 
                                     
                                     	//8 bitlik islemlerde aral�k -127-128 aras�nda ortalamam�z da maks zaten 100 ��kabilir o zaman ah'�n degeri 0 dir ortalama al i�indedir
                                     	; Notlar 0-100 aras�nda oldu�u i�in AH'n�n  de�eri O olmal�d�r. Yani ortalama AL  i�erisindedir.
                                     
                    //s� indisi 0 lan�r
                  	XOR SI, SI         	; DIZI indisi s�, tekrar O'lan�r.
                  	//��renci sayisi tekrar cx i�ine at�l�r
                  	MOV CX, N          	; N ��renci say�s� CX i�erisine at�l�r. 
                  	//dizinin s� indisli eleman� ah a at�l�r.
            L2;     MOV AH, DIZI[SI]    ;DIZI'nin s� indisli eleman� (s�ras� s� olan ��rencinin notu), AH'ya at�l�r.
                 	//daha sonra al(yani ortalama) ve ah kars�last�r�l�r                     
       		       	CMP AL, AH         	; AL (e�ik �st� ��rencilerin not ortalamas�)  ile AH kar��la�t�r�l�r.
                    //eger ortalamadan buyukse gecti etiketine atlan�r                 
                  	JBE GECTI          	; AL, AH'dan k���k e�itse GECTI etiketine atlan�r.
                    //eger ortalaman�n alt�nda kalan cocuk notu esikden buyukse bute hak kazan�r                 
                 	CMP AH, ESIK       	; AL, AH'dan b�y�kse, AH ile ESIK de�eri  kar��la�t�r�l�r.
                  
                    //cocugun notu esikden kucukse bu sefer kal�r bute de giremez      
              		JB KALDI     		; AH, ESIK de�erinden kii��kse KALDI  etiketine atlan�r.
                    //esikden buyukse but e girenlerin sayisini bir artt�r�r�z       
              		INC BUT      		; AH, ESIK de�erinden b�y�k e�itse, BUT  de�i�keni de�eri 1 artt�r�l�r.
                    //kald� etiketine gider ve d�ng� d�ner.       
              		JMP KALDI    		; KALDI etiketine atlan�r.
       GECTI: 		INC BASARILI 		; BASAR�l� de�i�keni 1 artt�r�l�r.�
       KALDI: 		INC SI       		; �ndis yazmac� SI de�eri 1 arttir�l�r. 
              		LOOP L2      		; N kere �evrim i�lemleri tekrarlan�r.
             		RETF
       CAN    		ENDP
       NYCS   		ENDS
              		END CAN




