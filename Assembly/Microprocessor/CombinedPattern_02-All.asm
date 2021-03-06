CODE    SEGMENT
ASSUME	CS:CODE,DS:CODE,ES:CODE,SS:CODE

PPIC_C  EQU 1EH 
PPIC    EQU 1CH 
PPIB    EQU 1AH
PPIA    EQU 18H

PPIC_C1	EQU 1FH 
PPIC1 	EQU 1DH
PPIB1   EQU 1BH
PPIA1  	EQU 19H

ORG 1000H
MOV AL,10000000B
OUT PPIC_C,AL
OUT PPIC_C1,AL

MOV AL, 11111111B
OUT PPIC,AL
OUT PPIB,AL
        
OUT PPIA1,AL   
MOV AL,11110000B
OUT PPIB1,AL
MOV AL,00000000B
OUT PPIC1,AL
START:
    MOV  BL,11111110B  
    MOV  DL,11110001B 
    MOV  SI,OFFSET DATA   
L2:
    MOV  AL,BL
    OUT  PPIA,Al
    CALL TIMER
    STC
    ROL  BL,1
    JC   Le2
    JMP  L1			  
L1:  
    MOV  BL,11111110B 
    JMP  Le2
Le2: 
    MOV  AL,DL
    OUT	 PPIB1,al
    CALL TIMER
    SHL  DL,1
    TEST DL,00010000B
    JNZ  Le1
    OR   DL,11110000B
    JMP  Lf1		
Le1:	
    MOV	 DL,11110001B    
    JMP  Lf1
Lf1:  
    MOV  BH,BYTE PTR CS:[SI]
    CMP	 BH,10010000B
    JE   Lf2 
    MOV  AH,BH
    OUT	 PPIA1,AL
    CALL TIMER
    INC	 SI
    JMP	 L2		
Lf2: 		
    MOV	 AL,BH
    OUT	 PPIA1,AL
    MOV  SI,OFFSET DATA
    JMP  L2    
    INT	 3 
     		
TIMER:	
    MOV	 CX,0FFFFH    
TIMER1:	
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    LOOP TIMER1
    RET    	
DATA:
    DB 11000000B
    DB 11111001B
    DB 10100100B
    DB 10110000B
    DB 10011001B
    DB 10010010B
    DB 10000010B
    DB 11111000B
    DB 10000000B
    DB 10010000B
    DB 00000000B
 
CODE ENDS
    END	
