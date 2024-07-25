; PROGRAM : Örnek 11-1-1.ASM
; örnek 11-1.ASM isimli program tarafýndan çaðýrýlan yardýmcý yordam 
; Kod kesimleri birleþtirilmiþtir.

        PAGE 60,80
        TITLE code kesimleri birleþik - yardýmcý yordam çaðýrma

; BUYUK isimli yordam baþka programlar tarafýndan da kullanýlabilir. 
; DIZI ise baþka bir kesim de word tanýmlý harici veridir.

        EXTRN DIZI: WORD 
        PUBLIC BUYUK
CDSEG   SEGMENT PARA PUBLIC 'CODE'       ; Kesim birleþtirilecek
        ASSUME CS: CDSEG 
BUYUK PROC FAR

; iþlem bloðu baþlýyor
; cx üzerinden dizil-;in eleman sayýsý bu yordama aktarýlýyor.

        XOR SI, SI       ; SI dizi indisi olarak kullanýlacak
        MOV AX. LIZI[SI] ; ilk elemaný en büyük kabul et
        SUB cx, 1        ; geri kalan elemanlar üzerinden iþlem yapýlacak
L1:     ADD SI, 2        ; DW tanýmlý bir sonraki elaman 2 byte ileride
        CMP AX, DIZI [SI]
        14. DEVAM
        MOV AX, DIZI[SI] ; dizinin elemaný daha büyük
DEVAM:  LOOP L1          ; cevrimi tekrarla
        RET              ; çaðýran noktaya geri don
BUYUK   ENDP
CDSEG   ENDS
        END


