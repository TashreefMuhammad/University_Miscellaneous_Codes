.MODEL SMALL
.STACK 100H


.DATA
    ;DECLARING VARIABLES
    
.CODE
    
    ;MAIN PROCEDURE
    MAIN PROC
        
        MOV AH,1    ;PREPARING TO TAKE INPUT
        INT 21H
                    ;TAKING INPUT
        MOV BL,AL   ;CONVERTING TO UPPERCASE USING ASCII
        SUB BL,32
        
        MOV AH,2
        MOV DL,0AH  ;LINE RETURN
        INT 21H
        MOV DL,0DH  ;CARIIAGE RETURN
        INT 21H
        
        MOV DL,BL
        INT 21H 
        
        MOV AH,4CH
        INT 21H
        
     MAIN ENDP
    
END MAIN
        
        