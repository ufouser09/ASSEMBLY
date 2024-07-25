myss        SEGMENT PARA STACK 'yigin'
            DW 200 DUP(?)
myss        ENDS

myds        SEGMENT PARA 'data'

myds        ENDS

mycs        SEGMENT PARA 'kod'
            ASSUME CS:mycs, DS:myds, SS:myss



ANA 	PROC   FAR		    ; Recursive olduğu için herhangi bir loop kullanımı yok.
							;Fonksiyonlar arası kullanıcıdan gelen degere gore(odevde deger 10) donuyoruz

    PUSH    DS
    XOR     AX, AX
    PUSH    AX
    MOV     AX, myds
    MOV     DS, AX				

							
    MOV     AX, 10      	; Push işlemini direkt olarak yapamadığımız için register atayarak pushladık
    PUSH    AX              ; AX'i, kullanıcının bulmak istedigi degerini pushladık
    CALL    FAR PTR dnum  ; Islemlerimizin basladigi ilk kısım aynı codeseg oldugu icin FAR PTR olarak
    POP     AX              ; AX = dnum(Kullanicinin degeri)
	push ax
    CALL    PRINTINT        	

    RETF

ANA ENDP

;-----------------------------------------------------------------------------------------------------------------------------------------------------------------------


dnum PROC FAR
	PUSH    BP
	MOV     BP, SP
    PUSH    AX				; degerleri atma sıramız AX,BX,CX,BP
    PUSH    BX				; poplarken de tersi olarak çekicez aşağıda
	PUSH	DX
    PUSH    CX
	

             
    mov ax, word ptr [bp+6]

    CMP     AX, 0           ; AX 0 mı diye kontrol ettik. 
    JA      dnuma3		; jump above
    MOV     AX, 0           ; return 0
    JMP     dnum_end
	

dnuma3:					; 1 ya da 2 olduğu durum
    CMP     AX, 2           ; AX 0 ise dnum1'e gelmişti.
    JA      dnumu3			; 2 değilse de aşağıya devam etti ve AX 1 döndü.
    MOV     AX, 1           
    JMP     dnum_end

 
dnumu3:

    SUB AX,1              ; AX 'i bir azalttık AX<- n-1
    PUSH    AX              ; Yeni AX degerini pushladık
    CALL    FAR PTR dnum  ; dnum fonksiyonuna gittik
    POP     AX              ; BX = a(n - 1) sonucunu BX'e popladık

    PUSH    AX              ; a(n-1) tekrar stacke pushladık  
    CALL    FAR PTR dnum  ; Tekrar dnum fonksiyonuna gittik
    POP     CX              ; CX = a(a(n - 1)) yeni olusan degeri CX'e popladık
	
	
	mov bx, word ptr [bp+6]
	SUB BX,1					;DX<-N-2
	PUSH BX					; DX STACK PUSHLADIK
	CALL    FAR PTR dnum	;Tekrar dnum fonksiyonuna gittik
	POP BX;

    mov dx, word ptr [bp+6] 
	SUB DX,1
	;PUSH DX; AX degerimizi n-1 yapmistik.tekrar n yaptik.
    SUB     DX, BX          ; AX=n-1 idi DX ise a(n - 2) yani SUB, n-1 - a(n - 2)
    
	PUSH    DX              ; Yeni Ax degerini pushladık
    CALL    FAR PTR dnum  ; a(n - a(n - 1)) 
    POP     DX              ; AX = a(n - a(n - 1))


	PUSH DX
	POP AX
    ADD AX, CX          ; AX = a(a(n - 1)) + a(n - 1 - a(n - 2)) fibonacciye benzer şekilde toplayarak ilerledik.
	
dnum_end:
    MOV     [BP+6], AX        ; BP'ye dnum_son'a geldiğimiz için 

	POP     CX			; degerleri AX,BX,CX,BP olarak attigimiz icin tersi olarak cekiyoruz
	POP 	DX				;				; pop BP,CX,BX,AX
    POP     BX				; NOT: aslında hocam kitabınızda pusha popa diye bir ifade var.Bu işlemi direkt olarak tek satırda yapıyormuş ama sanırım hepsini atıyor
    POP     AX
	POP		BP; Ayrıca bir de .186 diye bir kütüphane tanımlanması gerekiyormuş o yüzden böyle yapmamız gerekti.Yoksa daha kısa olabilirdi burası, tek satır gibi
    RETF   
	
dnum ENDP


;----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
PRINTINT  proc near
    push ax
    push bx
    push cx
    push dx
    push bp
    
    mov bp, sp
    mov ax, 10
    mov bx, [bp+12]

mark1:     
    mov cx, 10
        mul cx
        cmp ax, bx
        jna mark1
        div cx
        xchg ax, bx      
mark2:     
        xor dx, dx   

        div bx 
        push dx 
        xor dx, dx
        xchg ax, bx
        div cx
        xchg ax, bx
        pop dx
        xchg ax, dx
          
        push ax
           
        mov ah, 2
        add dl, '0'
        int 21h
        pop ax
        cmp ax,0
        ja mark2
    
    pop bp
    pop dx
    pop cx
    pop bx
    pop ax

    ret 2
PRINTINT  endp
mycs ENDS
	END ANA