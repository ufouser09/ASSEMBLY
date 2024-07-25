------------------------------------------------------------------------------------

; DOSYA: ORNEK.MAC
; Bu dosya harici macro'lar�n yer ald��� bir dosyad�r.
------------------------------------------------------------------------------------


------------------------------------------------------------------------------------

; INT 10H yard�m�yla ekran silmeyi sa�layan macro kodu
------------------------------------------------------------------------------------

SIL    MACRO
       MOV CX, OOOOH ; Ekran�n sol �st k��esi sat�r/s�tun adresi 
       MOV DX, 184FH ; Ekran�n sa� alt k��esi sat�r/sutun adresi 
       MOV BH, 07H   ; attribute byte
       MOV AX, 0600H ; AH = 06H pencereyi yukar� kayd�r
       Wr 10H        ; 10H numaral� kesmeyi �a��r
       FNDM
------------------------------------------------------------------------------------

; INT 21H yard�m�yla ekrana mesaj yazd�ran macro
------------------------------------------------------------------------------------

YAZDIR MACRO text
       LEA DX, text  ; DX yazd�r�lacak mesaj�n ba��n� g�stermeli 
       MOV AH, 09H   ; AH = 09H ekrana mesaj yaz
       INT 21H       ; 21H numaral� kesmeyi �a��r
       ENDM
------------------------------------------------------------------------------------


