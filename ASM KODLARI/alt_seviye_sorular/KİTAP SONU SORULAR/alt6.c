
----------------------------------------------------------------------------------------------------------------

		Final Sýnavýnda Baþarýlý, Baþansýz ve Bütünlemeye Kalan Öðrencilerin Tespiti
       
	   
	   n kiþinin kaydolduðu bir dersin final sýnavýnda eþik deðerin altýnda not alan 
       öðrenciler dersten kalmýþtýr. Eþik deðerin üstünde not alan oðrencilerAn al- 
       dýðý notlarýn ortalamasý hesaplanýr ve bu ortalamanýn üstünde olan öðrenciler 
       final sýnavýndan baþarý sayýlýr, ortalamanýn altýnda olan öðrenciler ise bü- 
       tünleme sýnavýna girmeleri gerekmektedir. Final sýnavý sonunda baþarýlý, ba- 
       þarýsýz ve bütünlemeye kalan öðrencilerin sayýsýný bulan ExE.tipi assembly 
       programýný yazalým.
 ----------------------------------------------------------------------------------------------------------------
      
       n=280-------->cx
       dizi[n]={....}---------------->i miz sý ile tutarýz.
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
	ort=topknot/esýkustu--------------->ort =al
	
	for(i=1;i<n;i++)
	if(ort<=dizi[i])--------------------->burdaki dizimiz ah ile tutulur
	basarili++
	else{
		if(dizi[i]>=esik)
		but++
	}
        
		stop
----------------------------------------------------------------------------------------------------------------
		
		
		Tüm öðrenciler dersten baþarýlý, baþarýsýz veya bütünleme olarak
        gruplanabileceðinden bu deðiþkenlerin tipleri word olarak tanýmlanmýþtýr.

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
       
	    MYCS    	SEGMENT PARA 'CODE'              • V
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
  					//biz burda ilk önce sý mýzý yani indisimiz 0 larýz.
					XOR SI, SI;DIZI'nin indis yazmacý O'lanýr.
					//sonra döngü sayimizi cx yazmacýna yani döngü yazmacýna atarýz.
                  	MOV CX, N; DIZI'nin eleman sayýsý CX'e yerleþtirilir. 
                  	//dizinin sý ýndisindeki elemaný al ye alýrýz.
          L1:     	MOV AL, DIZI[SI]   	; DIZI'nin sý indisli elemaný, AL yazmacýna alýnýr.
                    //sonra bunu esik degerimizle yani sýnýrla karsýlastýrýz burda kalanlarý ve gecenleri buluruz                 	
                  	CMP AL, ESIK       	; AL, ESIK deðiþkeni ile karþýlaþtýrýlýr.
                  	//al esik degerden buyuk esitse gecmissindir
                  	JAE ESIKUSTU       	; AL, ESIK deðerinden büyük eþitse ESIKUSTU  etiketine atlanýr.
                                     	
                  	//eger al esik den buyuk esit degilse gecememissindir o zamanda kalanlarý bir arttýrýrsýn
					INC BASARISIZ      	; AL: ESIK deðerinden küçükse BASARISIZ  degiþkeni deðeri 1 arttýrýlýr.
                                  		
                  	JMP D1             	; Baþarýsýz notu olan bir öðrenci bulunduðu ; için, bu not ortalamaya katýlmayacaðýndan ; toplama iþlemine gerek olmadýðý için ; atlanarak D1 etiketine gidilir.
                                     	
                                     
                    //eger basarýlý bir ogrenci bulursak bunu worde yani ax'e genisletiriz          		        
        ESIKUSTU:  	CBW      			; Öðrencinin, AL içerisindeki notu ESIK deðerin üstünde ise AL, AX'e geniþletilir. 
                    //sonra basarýlýlarýn yani gecenlerin notlarýný toplýcagýmýz için ax le topnot u toplarýz                  
                  	ADD TOPNOT,AX      	; Böylece mord tanýmlý TOPNOT deðiþkeni ile  tip uyumsuzluðu olmadan toplanabilir.
                    //burda ise indisimizi bir arttýrýp döngüyü döndürürüz       ‘         
          D1:     	INC SI           	; Yeni nota eriþmek için SI, 1 arttýrýlýr. 
                  	LOOP L1            	; iþlemin N kez tekrarlanmasý saðlanýr.
                  	//öðrenci sayisi cx e atýlýr
					MOV CX,N       		; Ögrenci sayýsý (N), CX içerisine alýnýr. 
					//toplam öðrenci sayisindan basarýsýzlarý çýkartýrýz.ve gecenleri buluruz
                  	SUB CX,BASARISIZ   	; Baþarýsýzlarýn sayýsý CX'ten çýkarýlýr.
                  	//daha sonra dx sýfýrlanýr çünkü 16 bitlik bölme iþlemi yapýcaz
                  	XOR DX,DX       	; 16-bit'lik bölme iþlemi öncesi DX O'lanýr. 
                  	//ax üzerinden bolme yapýcagýmýz için ax e topnot degeri atanýr
                  	MOV AX,TOPNOT     	; Baþarýsýz öðrenciler hariç diðer  öðrencilerin notlarý AX'e yerleþtirilir. 
                                     
                    //notlarýmýzýn toplamýný gecenlere bolerek ortalama bir deger bulunur.            	 	
					DIV CX   		   	; DX:AX / CX iþlemi sonucunda Bölüm: AX,; Kalan: DX üzerinde oluþur. Yani ; baþarýsýzlar hariç diðer öðrencilerin ; notlarýnýn ortalamasý AX yazmacýndadýr.
                                 
                                     
                                     	//8 bitlik islemlerde aralýk -127-128 arasýnda ortalamamýz da maks zaten 100 çýkabilir o zaman ah'ýn degeri 0 dir ortalama al içindedir
                                     	; Notlar 0-100 arasýnda olduðu için AH'nýn  deðeri O olmalýdýr. Yani ortalama AL  içerisindedir.
                                     
                    //sý indisi 0 lanýr
                  	XOR SI, SI         	; DIZI indisi sý, tekrar O'lanýr.
                  	//öðrenci sayisi tekrar cx içine atýlýr
                  	MOV CX, N          	; N öðrenci sayýsý CX içerisine atýlýr. 
                  	//dizinin sý indisli elemaný ah a atýlýr.
            L2;     MOV AH, DIZI[SI]    ;DIZI'nin sý indisli elemaný (sýrasý sý olan öðrencinin notu), AH'ya atýlýr.
                 	//daha sonra al(yani ortalama) ve ah karsýlastýrýlýr                     
       		       	CMP AL, AH         	; AL (eþik üstü öðrencilerin not ortalamasý)  ile AH karþýlaþtýrýlýr.
                    //eger ortalamadan buyukse gecti etiketine atlanýr                 
                  	JBE GECTI          	; AL, AH'dan küçük eþitse GECTI etiketine atlanýr.
                    //eger ortalamanýn altýnda kalan cocuk notu esikden buyukse bute hak kazanýr                 
                 	CMP AH, ESIK       	; AL, AH'dan büyükse, AH ile ESIK deðeri  karþýlaþtýrýlýr.
                  
                    //cocugun notu esikden kucukse bu sefer kalýr bute de giremez      
              		JB KALDI     		; AH, ESIK deðerinden kiiçükse KALDI  etiketine atlanýr.
                    //esikden buyukse but e girenlerin sayisini bir arttýrýrýz       
              		INC BUT      		; AH, ESIK deðerinden büyük eþitse, BUT  deðiþkeni deðeri 1 arttýrýlýr.
                    //kaldý etiketine gider ve döngü döner.       
              		JMP KALDI    		; KALDI etiketine atlanýr.
       GECTI: 		INC BASARILI 		; BASARýlý deðiþkeni 1 arttýrýlýr.•
       KALDI: 		INC SI       		; Ýndis yazmacý SI deðeri 1 arttirýlýr. 
              		LOOP L2      		; N kere çevrim iþlemleri tekrarlanýr.
             		RETF
       CAN    		ENDP
       NYCS   		ENDS
              		END CAN




