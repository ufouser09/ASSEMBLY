               Þekil 25-15: Dizileri sýralý birleþtirme akýþ diyagramý


           lar iþaretli olabileceði için karþýlaþtýrma iþlemleri uygun kodlarla
    P? cekleþtirilmiþtir.
  
  
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
                 XOR BX, BX            ; indis deðiþkenleri BX, SI, DI sýfýrlanýr. 
                 XOR SI, SI 
                 XOR DI, DI 
      DoN:       CMP SI, N1            ; SI ile D1 dizisin boyutu olan N1 deðeri
                                       ; karþýlaþtýrýlýr.; SI, N1 deðerinden KUCUK eþitse ATLA 
                 jAE ATLA
                                       ; etýketýne gidilir. Yani D1 dizisi ; elemanlarý once bitmiþse ATLA'ya gidilir. 
                                       
                 cmP DI, N2            ; SI, N1 deðerýnden büyükse DI ile D2
                                       ; dizisinin  boyutu olan N2 karþýlaþtýrýlýr. 
                 jAE ATLA              ; DI, N2 degerinden küçük eþitse ATLA
                                       ; etýketine gidilir. Yani D2 dizisi
                                       ; elemanlarý önce bitmiþse ATLA'ya gidilir. 
                 MOV AL, D1[SI]        ; Dl'in SI indisli elemaný AL'ye alýnýr.
                 MOV AH, D2CDIl        ; D2'in DI indisli elemaný ah ye alýnýr. 
                 cmp AL, AH            ; AL ile AH karþýlaþtýrýlýr.
                 jL jd1                ; AL, AHden küçük Ise JD1 etiketine atlanýr. 
                 MOV DSON [BX],ah      ; AL, AH den büyükk eþitse ah yazmacý deðeri 
                                       ; DSON .dizisinin BX ýndisli elemanýna korur. 
                 INC DI                ; D2 dizisi byte tanýmlý oldugu için DI 
                                       ; 1 arttýrýlýr.
                 jmP ORTAK             ; ORTAK ETIKETiNE ATLANIR.
      3D1:       MOV DSON[BX], AL      ; AL yazmasý deðeri DSON dizisinin BX indisli 
                                       ; elemanýna korur.
                 INC SI                ;D1 dizisi byte tanýmlý olduðu için SI  1 arttýrýlýr.
                                    	
      ORTAK:     INC BX              	; DSoN dizisi byte tammlý olduðu için BX 
                                       	; 1 arttýrýlýr.
                 jMP DON              	; DON etiketine atlanarak çevrim saðlamr. 
      ATLA:      CMP DI, N2         	; Çevrimden hangi koþul bozularak çýkýldýðý 
                                       	; anlaþýlmaya çalýþýlýr. DI ile N2
                                       	; karþýlaþtýrýlýr.
                 jE ld2               	; DI ýle N2 eþitse LD2 etiketine atlanýr.
                 MOV Cx, N2            	; DI ile N2 eþýt deðilse D1 dizisi önce
                                       	; bitmiþtir ve D2 dizisinin kalan elemanlarý 
                                       	; DSoN Içerisine konulmalýdýr. Burun için N2 
                                       	; deðerý CX içerisine atýlýr.
                 sub CX, DI           	D2 'nin DSoN Içerisine þuana kadar kaç 
                                       	; eleman atýldýysa, N2'den bu deðer
                                       	; çýkarýlmalýdýr. Burun için CX'ten DI 
                                       	; çýkarýlýr.
      Ll:        MOv AL, D2[DI]      	; D2'nin DI indisli eleman.: AL'ye korur. 
                 MOv DSON,[BX],al       ; AL, ODSON dizisinin bX indisine korur. 
                 INC BX                	; BX 1 arttýrýlýr.
                 INC DI                	; DI 1 arttýrýlýr.
                LOOP L1             	; Ll çevrimi iþlemleri CX-DI kez yapýlýr. 
                 jMP SON               	; SON etiketine atlanýr.
    LD2        	MOV CX, N1            	; DI ile N2 eþitse D2 dizisi önce bitmiþtir
                                       	; ve D1 dizisýnin kalan elemanlarý DSON 
                                       	; içerisine korulmalýdýr. Burun için N1 
                                   		; deðeri CX içerisine atýlýr.
                 SUB CX, SI            	D1 'nin DSON Içerisine þuana kadar kaç 
                                       	; elemam atýldýysa, N1'den bu deðer




                                  ; çýkarýlmalýdýr. Burun için CX'ten SI
                                  ; çýkarýlýr.
         L2:     MOV AL,          ; D1'nin SI indisli eleman.: AL'ye konur.
                 MOV Dson [BX],AL; AL, DSON dizisinin BX indisine konur.
                 INC BX           ; BX 1 arttýrýlýr. 
                 INC SI           ; SI 1 arttýrýlýr.
                 LooP L2
         SON:    RETF
         MAIN    ENDP
         MY CS   ENDS
                 END MAIN


