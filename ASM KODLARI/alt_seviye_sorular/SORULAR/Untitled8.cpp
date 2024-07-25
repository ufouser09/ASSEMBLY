------------------------------------------------------------------------------------

; DOSYA: ORNEK.MAC
; Bu dosya harici macro'larýn yer aldýðý bir dosyadýr.
------------------------------------------------------------------------------------


------------------------------------------------------------------------------------

; INT 10H yardýmýyla ekran silmeyi saðlayan macro kodu
------------------------------------------------------------------------------------

SIL    MACRO
       MOV CX, OOOOH ; Ekranýn sol üst köþesi satýr/sütun adresi 
       MOV DX, 184FH ; Ekranýn sað alt köþesi satýr/sutun adresi 
       MOV BH, 07H   ; attribute byte
       MOV AX, 0600H ; AH = 06H pencereyi yukarý kaydýr
       Wr 10H        ; 10H numaralý kesmeyi çaðýr
       FNDM
------------------------------------------------------------------------------------

; INT 21H yardýmýyla ekrana mesaj yazdýran macro
------------------------------------------------------------------------------------

YAZDIR MACRO text
       LEA DX, text  ; DX yazdýrýlacak mesajýn baþýný göstermeli 
       MOV AH, 09H   ; AH = 09H ekrana mesaj yaz
       INT 21H       ; 21H numaralý kesmeyi çaðýr
       ENDM
------------------------------------------------------------------------------------


