YANA yordam kodu i�erisinde harici yordam olarak ALAN_BUL kullan�lmaktad�r.
Y     EXTRN ALAN_BUL:FAR
 MYSS SEGMENT PARA STACK 'S'
      DW 20 DUP(?)
 MYSS ENDS

MYDS      SEGMENT PARA 'D'
KEN       DW 6, 8, 5, 9, 4, 8, 2, 2, 3
N         DW 3
ENBYKALAN DW 0 
MYDS      ENDS


MYCS      SEGMENT PARA 'K'
          ASSUME CS:MYCS, DS:MYDS, SS:MYSS 
ANA       PROC FAR
          PUSH DS
          XOR AX, AX
          PUSH AX
          MOV AX, MYDS
          MOV DS, AX
          MOV CX, N                   ;Dizinin eleman t�r�s� CX i�erisine 
                                     ;al�n�r.
          XOR SI, SI                 ;KEN dizisi id4Ob�s� SI s�f�rlan�r. 
          PUSH KEN[SI]               ;�lk kenar ychna at�l�r.
          PUSH KEN[SI+2]             ;�kinci kenar ',I��na at�l�r. 
          PUSH KEN[SI+4]             ;���nc� k�-nagy���na at�l�r. 
          CALL ALAN_BUL               ALAN_BUk9Srdam� �a��r�l�r.
          CMP AX, ENBYKALAN          ;ALAN_BUL'*ordam�ndan d�nen sonu� AX 
                                     ;yazm�.i�erisindedir. Yani y���na 
                                     ;konu10 3 kenar�n olu�turdu�u ��genin
                                     ;al    in karesi AX'tedir.
                                      AX%BYKALAN de�i�keni ile 
                                     ;kar��la�t�r�l�r.
          JBE KUCUK                   AX, ENBYKALAN de�i�keninden k���k 
                                     ; e�itse KUCUK etiketine atlan�r.
          MOV ENBYKALAN, AX           AX, ENBYKALAN de�i�keninden b�y�kse 
                                     ; AX'in de�eri ENBYKALAN de�i�keninin 
                                     ; i�erisine yerle�tirilir.
KUCUK:    ADD SI, 6                  ; KEN dizisi i�erisinde word tan�ml� 3 
                                     ; kenar ard���l olarak tutulmakta
                                     ; oldu�undan bir sonraki ��genin
                                     ; kenarlar�na ula�mak i�in 3 kenar 
                             �       ; sonraya yani 6 sonraya atlan�r.
                                     ; Bunun i�in SI'ya eklenir.
          LOOP Li                    ; Ll �evrim i�lemleri N kez tekrarlan�r.
          RETF
ANA       ENDP
MYCS      ENDS         �

          END ANA


�,
; ALAN_BULharicordam�nda sadece    kod kesimi tan�mlanm��t�r.


          PUB>ALAN_BUL 
MYCODE    SEGMENT PARA 'KOD' 
          ASSUME CS:MYCODE 
ALAN_BUL  PRJC FAR

; i�lem  
; de�e  
; ku
; ty) 
O
)
Y
aras�nda kullanaca��m�z yazma�lar�n daha �nce sahip oldu�u
kay�p etmemesi i�in y���nda saklamal�y�z. Benzer �ekilde y���n  
tarak parametre aktaraca��m�z i�in BP'nin de saklanmas� gerekir.
PUSH BX  
PUSH CX  
PUSH DI  
PUSH BP  
MOV BP, SP
XOR AX, AX
ADD AX, [BP+12] 
ADD AX, [BP+14]
Harici yordamda kullan�lan yazma�lar  
BX, CX, DI ve BP y���na at�l�r.
Stack Pointer ile Base Pointer'�n  
; ayn� yeri g�stermesi sa�lan�r.
; Kenar de�erleri AX i�erisinde
; toplanaca��ndan AX de�eri s�f�rlan�r. 
; Y���na ilk at�lan de�erle AX toplan�r. 
; ikinci at�lan de�erle de AX toplan�r.

          ADD AX, [BP+16]         ; ���nc� at�lan de�erle de AX toplan�r.
          SHR AX, 1                 AX i�erisinde olan 3 kenar�n toplam� 
                                  ; 2'ye b�l�nerek u de�eri bulunur.
          MOV BX, AX              ; u de�eri BX i�erisine yerle�tWlir. 
          SUB BX, [BP+12]         ; u'dan ilk kenar ��kar�l�r. ,(qa)
          MOV CX, AX              ; u de�eri CX i�erisine yerl�trilir. 
          SUB CX, [BP+14]         ; u'dan ikinci kenar ��karkk��". (u-b) 
          MOV DI, AX              ; u de�eri DI i�erisine r.!1-�tirilir. 
          SUB DI, [BP+16]         ; u'dan ���nc� kenar ��kar�l�r. (u-c) 
          MUL BX                  ; AX'de olan u ile BX'de olan (u-a)
                                  ; �arp�l�r ve sonu� ^^ e olu�ur.
                                  ; AX * BX -> DX:AX, v en de�erler ile 
                                  ; DX'in bu i�lem sonundaa her daim 0
                                  ; olaca�� g�r�lebQmektedir.
          MUL CX                  ; AX'de olan u(11�)Yile CX'de olan
                                  ; (u-b) �arp�l�,�`kp sonu� AX'de olu�ur. 
          MUL DI                  ; AX'de olan u(era)(u-b) ile DI'da olan 
                                  ; (u-c) �arplq-v ve sonu� AX'de olu�ur. 
                                  ; AX'de u(u-a)(i.�-b)(u-c) de�eri, yani
                                  ; u'lu alamf&m�l� gere�i kenarlar� 
                                  ; verilen ��genin alan�n�n karesi AX 
                                  ; i�erisind olu�ur.
          POP BP                  ; Ba�l ga�ta y���na at�lan yazma�lar 
          POP DI                  ; at�l  lar� s�ralar�n tersiyle
          POP CX                  ; y� � an al�n�rlar.
          POP BX 
          RETF 6                  ; ANA YORDAMIN YI�INA ATTI�I 3 KENAR 
                                    DE�ER� REFT 6 KOMUTU �LE YI�INDAN 
                                    KALDIRILIR.
ALAN_BUL ENDP 
MYCODE    ENDS
          END 


