               �ekil 25-15: Dizileri s�ral� birle�tirme ak�� diyagram�


           lar i�aretli olabilece�i i�in kar��la�t�rma i�lemleri uygun kodlarla
    P? cekle�tirilmi�tir.
  
  
  MY_SS     SEGMENT PARA STACK STACK'
  	        DW 20 DUP(?)
  MY_SS 		ENDS
 
 MY_DS    SEGMENT PARA 'DATA'
    N1       DW 7
    N2       DW 6

      D1         DB 7, 12, 64, 98, 104, 105, 125
      D2         DB -70, -10, 9, 17, 68, 90 
      DSON     	 DB 13 DUP(?)
      MY_DS      ENDS

      MY CS      SEGMENT PARA 'CODE'
                 ASSUME DS:MY.DS, SS:MY_SS, CS:MY_CS 
      MAIN       PROC FAR
                 PUSH DS
                 XOR AX, AX 
                 PUSH AX                                         Cb
                 MOV AX, MY_DS 
                 MOV DS, AX 
                 XOR BX, BX            ; indis de�i�kenleri BX, SI, DI s�f�rlan�r. 
                 XOR SI, SI 
                 XOR DI, DI 
      DoN:       CMP SI, N1            ; SI ile D1 dizisin boyutu olan N1 de�eri
                                       ; kar��la�t�r�l�r.; SI, N1 de�erinden KUCUK e�itse ATLA 
                 jAE ATLA
                                       ; et�ket�ne gidilir. Yani D1 dizisi ; elemanlar� once bitmi�se ATLA'ya gidilir. 
                                       
                 cmP DI, N2            ; SI, N1 de�er�nden b�y�kse DI ile D2
                                       ; dizisinin  boyutu olan N2 kar��la�t�r�l�r. 
                 jAE ATLA              ; DI, N2 degerinden k���k e�itse ATLA
                                       ; et�ketine gidilir. Yani D2 dizisi
                                       ; elemanlar� �nce bitmi�se ATLA'ya gidilir. 
                 MOV AL, D1[SI]        ; Dl'in SI indisli eleman� AL'ye al�n�r.
                 MOV AH, D2CDIl        ; D2'in DI indisli eleman� ah ye al�n�r. 
                 cmp AL, AH            ; AL ile AH kar��la�t�r�l�r.
                 jL jd1                ; AL, AHden k���k Ise JD1 etiketine atlan�r. 
                 MOV DSON [BX],ah      ; AL, AH den b�y�kk e�itse ah yazmac� de�eri 
                                       ; DSON .dizisinin BX �ndisli eleman�na korur. 
                 INC DI                ; D2 dizisi byte tan�ml� oldugu i�in DI 
                                       ; 1 artt�r�l�r.
                 jmP ORTAK             ; ORTAK ETIKETiNE ATLANIR.
      3D1:       MOV DSON[BX], AL      ; AL yazmas� de�eri DSON dizisinin BX indisli 
                                       ; eleman�na korur.
                 INC SI                ;D1 dizisi byte tan�ml� oldu�u i�in SI  1 artt�r�l�r.
                                    	
      ORTAK:     INC BX              	; DSoN dizisi byte tamml� oldu�u i�in BX 
                                       	; 1 artt�r�l�r.
                 jMP DON              	; DON etiketine atlanarak �evrim sa�lamr. 
      ATLA:      CMP DI, N2         	; �evrimden hangi ko�ul bozularak ��k�ld��� 
                                       	; anla��lmaya �al���l�r. DI ile N2
                                       	; kar��la�t�r�l�r.
                 jE ld2               	; DI �le N2 e�itse LD2 etiketine atlan�r.
                 MOV Cx, N2            	; DI ile N2 e��t de�ilse D1 dizisi �nce
                                       	; bitmi�tir ve D2 dizisinin kalan elemanlar� 
                                       	; DSoN I�erisine konulmal�d�r. Burun i�in N2 
                                       	; de�er� CX i�erisine at�l�r.
                 sub CX, DI           	D2 'nin DSoN I�erisine �uana kadar ka� 
                                       	; eleman at�ld�ysa, N2'den bu de�er
                                       	; ��kar�lmal�d�r. Burun i�in CX'ten DI 
                                       	; ��kar�l�r.
      Ll:        MOv AL, D2[DI]      	; D2'nin DI indisli eleman.: AL'ye korur. 
                 MOv DSON,[BX],al       ; AL, ODSON dizisinin bX indisine korur. 
                 INC BX                	; BX 1 artt�r�l�r.
                 INC DI                	; DI 1 artt�r�l�r.
                LOOP L1             	; Ll �evrimi i�lemleri CX-DI kez yap�l�r. 
                 jMP SON               	; SON etiketine atlan�r.
    LD2        	MOV CX, N1            	; DI ile N2 e�itse D2 dizisi �nce bitmi�tir
                                       	; ve D1 dizis�nin kalan elemanlar� DSON 
                                       	; i�erisine korulmal�d�r. Burun i�in N1 
                                   		; de�eri CX i�erisine at�l�r.
                 SUB CX, SI            	D1 'nin DSON I�erisine �uana kadar ka� 
                                       	; elemam at�ld�ysa, N1'den bu de�er




                                  ; ��kar�lmal�d�r. Burun i�in CX'ten SI
                                  ; ��kar�l�r.
         L2:     MOV AL,          ; D1'nin SI indisli eleman.: AL'ye konur.
                 MOV Dson [BX],AL; AL, DSON dizisinin BX indisine konur.
                 INC BX           ; BX 1 artt�r�l�r. 
                 INC SI           ; SI 1 artt�r�l�r.
                 LooP L2
         SON:    RETF
         MAIN    ENDP
         MY CS   ENDS
                 END MAIN


