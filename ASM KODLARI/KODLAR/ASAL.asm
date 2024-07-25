DATASG SEGMENT PARA 'DARA'
     DIZI DW 20 DUP(0)
    
    DATASG ENDS

STACKSG SEGMENT PARA STACK 'STACK'
      DW 20 DUP(?)
                
                
    STACKSG ENDS
CODESG SEGMENT PARA 'CODE' 
       ASSUME SS:STACKSG,CS:CODESG,DS:DATASG
    
         MAIN PROC FAR
    
    
    
    PUSH DX
    XOR AX,AX
    PUSH AX
    MOV AX,DATASG
    MOV DS,AX
    
   
        
     
    MOV AX,3
    MOV SI,2
    XOR DI,DI
    MOV BX,1
    L1:
    CMP BX,0
    JE SON_IF2
    CMP SI,AX
    JE SON_IF
    PUSH AX
    XOR DX,DX
    DIV SI
    CMP DX,0
    JNE DEVAM
    MOV BX,0
    
    
    DEVAM:INC SI
    JMP L1
    
    SON_IF:
    MOV DIZI[DI],AX
    INC DI 
    INC SI
    
    SON_IF2:POP AX
    INC AX
    MOV BX,1
    MOV SI,2  
    JMP L1
    
       
        
        
        
        
        
        
        
        
        
 
 
 
 
 
    RETF            
 MAIN ENDP
    CODESG ENDS
    END MAIN
 
        