.MODEL SMALL
.STACK 100H
.DATA
    ;VARIABLES WILL  BE DECLARED HERE  
    NUM1 DB ?
    NUM2 DB ?
.CODE
    
    MAIN PROC
               
        MOV AH, 1      ;INPUT
        INT 21H
        MOV NUM1, AL     ;SAVE INPUT IN BL 
        INT 21H
        
        MOV AH,2       ;LINE FEED
        MOV DL, 0AH
        INT 21H 
        MOV DL, 0DH    ;CARRIAGE RETURN
        INT 21H 
        
        MOV AH, 1      ;INPUT
        INT 21H
        MOV NUM2, AL 
        INT 21H
        
        MOV AH,2       ;LINE FEED
        MOV DL, 0AH
        INT 21H 
        MOV DL, 0DH    ;CARRIAGE RETURN
        INT 21H  
        
        MOV BL,NUM1
        SUB BL,48
        
        MOV CL,NUM2
        SUB CL,48
        
        SUB BL,CL      ;BL = BL-CL
        ADD BL,48
        
        MOV AH, 2
        MOV DL, BL
        INT 21H 
        
        
        
        MOV AH,4CH  
        INT 21H   
        
    MAIN ENDP

    ;OTHER PROCEDURES (IF ANY)

END MAIN