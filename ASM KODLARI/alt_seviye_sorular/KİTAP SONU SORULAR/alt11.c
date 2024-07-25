YANA yordam kodu içerisinde harici yordam olarak ALAN_BUL kullanýlmaktadýr.
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
          MOV CX, N                   ;Dizinin eleman târýsý CX içerisine 
                                     ;alýnýr.
          XOR SI, SI                 ;KEN dizisi id4Obýsý SI sýfýrlanýr. 
          PUSH KEN[SI]               ;Ýlk kenar ychna atýlýr.
          PUSH KEN[SI+2]             ;Ýkinci kenar ',Iðýna atýlýr. 
          PUSH KEN[SI+4]             ;Üçüncü kç-nagyýðýna atýlýr. 
          CALL ALAN_BUL               ALAN_BUk9Srdamý çaðýrýlýr.
          CMP AX, ENBYKALAN          ;ALAN_BUL'*ordamýndan dönen sonuç AX 
                                     ;yazmý.içerisindedir. Yani yýðýna 
                                     ;konu10 3 kenarýn oluþturduðu üçgenin
                                     ;al    in karesi AX'tedir.
                                      AX%BYKALAN deðiþkeni ile 
                                     ;karþýlaþtýrýlýr.
          JBE KUCUK                   AX, ENBYKALAN deðiþkeninden küçük 
                                     ; eþitse KUCUK etiketine atlanýr.
          MOV ENBYKALAN, AX           AX, ENBYKALAN deðiþkeninden büyükse 
                                     ; AX'in deðeri ENBYKALAN deðiþkeninin 
                                     ; içerisine yerleþtirilir.
KUCUK:    ADD SI, 6                  ; KEN dizisi içerisinde word tanýmlý 3 
                                     ; kenar ardýþýl olarak tutulmakta
                                     ; olduðundan bir sonraki üçgenin
                                     ; kenarlarýna ulaþmak için 3 kenar 
                             •       ; sonraya yani 6 sonraya atlanýr.
                                     ; Bunun için SI'ya eklenir.
          LOOP Li                    ; Ll çevrim iþlemleri N kez tekrarlanýr.
          RETF
ANA       ENDP
MYCS      ENDS         •

          END ANA


•,
; ALAN_BULharicordamýnda sadece    kod kesimi tanýmlanmýþtýr.


          PUB>ALAN_BUL 
MYCODE    SEGMENT PARA 'KOD' 
          ASSUME CS:MYCODE 
ALAN_BUL  PRJC FAR

; iþlem  
; deðe  
; ku
; ty) 
O
)
Y
arasýnda kullanacaðýmýz yazmaçlarýn daha önce sahip olduðu
kayýp etmemesi için yýðýnda saklamalýyýz. Benzer þekilde yýðýn  
tarak parametre aktaracaðýmýz için BP'nin de saklanmasý gerekir.
PUSH BX  
PUSH CX  
PUSH DI  
PUSH BP  
MOV BP, SP
XOR AX, AX
ADD AX, [BP+12] 
ADD AX, [BP+14]
Harici yordamda kullanýlan yazmaçlar  
BX, CX, DI ve BP yýðýna atýlýr.
Stack Pointer ile Base Pointer'ýn  
; ayný yeri göstermesi saðlanýr.
; Kenar deðerleri AX içerisinde
; toplanacaðýndan AX deðeri sýfýrlanýr. 
; Yýðýna ilk atýlan deðerle AX toplanýr. 
; ikinci atýlan deðerle de AX toplanýr.

          ADD AX, [BP+16]         ; Üçüncü atýlan deðerle de AX toplanýr.
          SHR AX, 1                 AX içerisinde olan 3 kenarýn toplamý 
                                  ; 2'ye bölünerek u deðeri bulunur.
          MOV BX, AX              ; u deðeri BX içerisine yerleþtWlir. 
          SUB BX, [BP+12]         ; u'dan ilk kenar çýkarýlýr. ,(qa)
          MOV CX, AX              ; u deðeri CX içerisine yerlþtrilir. 
          SUB CX, [BP+14]         ; u'dan ikinci kenar çýkarkkýý". (u-b) 
          MOV DI, AX              ; u deðeri DI içerisine r.!1-þtirilir. 
          SUB DI, [BP+16]         ; u'dan üçüncü kenar çýkarýlýr. (u-c) 
          MUL BX                  ; AX'de olan u ile BX'de olan (u-a)
                                  ; çarpýlýr ve sonuç ^^ e oluþur.
                                  ; AX * BX -> DX:AX, v en deðerler ile 
                                  ; DX'in bu iþlem sonundaa her daim 0
                                  ; olacaðý görülebQmektedir.
          MUL CX                  ; AX'de olan u(11Ö)Yile CX'de olan
                                  ; (u-b) çarpýlý,£`kp sonuç AX'de oluþur. 
          MUL DI                  ; AX'de olan u(era)(u-b) ile DI'da olan 
                                  ; (u-c) çarplq-v ve sonuç AX'de oluþur. 
                                  ; AX'de u(u-a)(i.ý-b)(u-c) deðeri, yani
                                  ; u'lu alamf&mülü gereði kenarlarý 
                                  ; verilen üçgenin alanýnýn karesi AX 
                                  ; içerisind oluþur.
          POP BP                  ; Baþl gaçta yýðýna atýlan yazmaçlar 
          POP DI                  ; atýl  larý sýralarýn tersiyle
          POP CX                  ; yý ý an alýnýrlar.
          POP BX 
          RETF 6                  ; ANA YORDAMIN YIÐINA ATTIÐI 3 KENAR 
                                    DEÐERÝ REFT 6 KOMUTU ÝLE YIÐINDAN 
                                    KALDIRILIR.
ALAN_BUL ENDP 
MYCODE    ENDS
          END 


