; PROGRAM : �rnek 11-1-1.ASM
; �rnek 11-1.ASM isimli program taraf�ndan �a��r�lan yard�mc� yordam 
; Kod kesimleri birle�tirilmi�tir.

        PAGE 60,80
        TITLE code kesimleri birle�ik - yard�mc� yordam �a��rma

; BUYUK isimli yordam ba�ka programlar taraf�ndan da kullan�labilir. 
; DIZI ise ba�ka bir kesim de word tan�ml� harici veridir.

        EXTRN DIZI: WORD 
        PUBLIC BUYUK
CDSEG   SEGMENT PARA PUBLIC 'CODE'       ; Kesim birle�tirilecek
        ASSUME CS: CDSEG 
BUYUK PROC FAR

; i�lem blo�u ba�l�yor
; cx �zerinden dizil-;in eleman say�s� bu yordama aktar�l�yor.

        XOR SI, SI       ; SI dizi indisi olarak kullan�lacak
        MOV AX. LIZI[SI] ; ilk eleman� en b�y�k kabul et
        SUB cx, 1        ; geri kalan elemanlar �zerinden i�lem yap�lacak
L1:     ADD SI, 2        ; DW tan�ml� bir sonraki elaman 2 byte ileride
        CMP AX, DIZI [SI]
        14. DEVAM
        MOV AX, DIZI[SI] ; dizinin eleman� daha b�y�k
DEVAM:  LOOP L1          ; cevrimi tekrarla
        RET              ; �a��ran noktaya geri don
BUYUK   ENDP
CDSEG   ENDS
        END


