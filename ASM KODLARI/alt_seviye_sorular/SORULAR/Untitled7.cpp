------------------------------------------------------------------------------------

; PROGRAM :Örnek 10-4.ASM
; COM yapýsýndaki programda macro kullanýmý
; Program ekraný temizledikten sonra bir mesaj yazacaktýr 
; Macro'lar harici bir dosyadan alýnarak kullanýlacaktýr.
------------------------------------------------------------------------------------

       PAGE 60,80
       TITLE Ekrana mesaj yazma
------------------------------------------------------------------------------------

; Kullanýlacak Macro'lar ORNEK.MAC isimli dosyadan alýnmaktadýr
------------------------------------------------------------------------------------

       INCLUDE ornek.mac
CDSEG  SEGMENT PARA 'CODE'
       ORG 100H        ; COM program 100H den baþlar
       ASSUME CS:CDSEG, SS:CDSEG, DS:CDSEG
------------------------------------------------------------------------------------

 Macro'larý kullanarak iþlemi gerçekleþtiren yordam
------------------------------------------------------------------------------------

BASLA PROC NEAR
       SIL             ; SIL isimli macro'yýý kullan
       YAZDIR MESAJ    ; YAZDIR makrosunu MESAJ parametresi ile kullan
       RET
BASLA ENDP
------------------------------------------------------------------------------------

; Mesaj tanýmý
------------------------------------------------------------------------------------

MESAJ  DB 'Macro'lar Ornek.mac Dosyasýndan alýndý','$'
CDSEG  ENDS
       END BASLA      ; programýn baþlangýç noktasý
------------------------------------------------------------------------------------


