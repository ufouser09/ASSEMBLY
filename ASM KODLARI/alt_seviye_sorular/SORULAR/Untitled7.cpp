------------------------------------------------------------------------------------

; PROGRAM :�rnek 10-4.ASM
; COM yap�s�ndaki programda macro kullan�m�
; Program ekran� temizledikten sonra bir mesaj yazacakt�r 
; Macro'lar harici bir dosyadan al�narak kullan�lacakt�r.
------------------------------------------------------------------------------------

       PAGE 60,80
       TITLE Ekrana mesaj yazma
------------------------------------------------------------------------------------

; Kullan�lacak Macro'lar ORNEK.MAC isimli dosyadan al�nmaktad�r
------------------------------------------------------------------------------------

       INCLUDE ornek.mac
CDSEG  SEGMENT PARA 'CODE'
       ORG 100H        ; COM program 100H den ba�lar
       ASSUME CS:CDSEG, SS:CDSEG, DS:CDSEG
------------------------------------------------------------------------------------

 Macro'lar� kullanarak i�lemi ger�ekle�tiren yordam
------------------------------------------------------------------------------------

BASLA PROC NEAR
       SIL             ; SIL isimli macro'y�� kullan
       YAZDIR MESAJ    ; YAZDIR makrosunu MESAJ parametresi ile kullan
       RET
BASLA ENDP
------------------------------------------------------------------------------------

; Mesaj tan�m�
------------------------------------------------------------------------------------

MESAJ  DB 'Macro'lar Ornek.mac Dosyas�ndan al�nd�','$'
CDSEG  ENDS
       END BASLA      ; program�n ba�lang�� noktas�
------------------------------------------------------------------------------------


