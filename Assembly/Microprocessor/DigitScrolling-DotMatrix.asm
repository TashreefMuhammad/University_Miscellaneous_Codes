
; ******************************************************
; * EXPERIMENT No.: 2                                  *
; * GROUP NO.     : 1                                  *
; * TOPIC         : Displaying the digit "1" scrolling *
;                   bottom to top using 8x8 dot matrix *
; ******************************************************

CODE	SEGMENT
	ASSUME	CS:CODE,DS:CODE,ES:CODE,SS:CODE
	
PPIC_C	EQU	1EH     ; control register
PPIC	EQU	1CH     ; c port
PPIB	EQU	1AH
PPIA	EQU	18H
	
	ORG	1000H
	MOV	AL,10000000B
	OUT	PPIC_C,AL
	
	MOV	AL,11111111B
	OUT	PPIA,AL
	
L1:	MOV	SI,OFFSET FONT	
	MOV	BL,16           ; Font No.
	
L3:	MOV	BH,50           ; Display time
	
L2:	PUSH    SI
	CALL    SCAN
	POP	SI
	DEC	BH
	JNZ	L2
	
	ADD	SI,8
	DEC	BL
	JNZ	L3   
	JMP	L1

SCAN PROC NEAR
	MOV	AH,00000001B
	
SCAN1:	MOV	AL,BYTE PTR CS:[SI]
	    OUT	PPIA,AL 
	    NOT AL
	    OUT PPIB,AL
			
	    MOV	    AL,AH
	    OUT	    PPIC,AL
	    CALL    TIMER
	    INC	SI
	    CLC
	    ROL	AH,1
	    JNC	SCAN1
	    RET
SCAN	ENDP
	
TIMER :	MOV	CX,300
TIMER1:	NOP
	    NOP
	    NOP
	    NOP
	    LOOP    TIMER1
	    RET
	   
FONT:   DB      11111111B
        DB      11111111B
        DB      11111111B
        DB      11111111B
        DB      11111111B
        DB      11111111B
        DB      11111111B
        DB      11111111B	
	
FONT1:  DB      11111111B
        DB      11111111B
        DB      11111111B
        DB      11111111B
        DB      11111110B
        DB      11111111B
        DB      11111111B
        DB      11111111B
	
FONT2:  DB      11111111B
        DB      11111111B
        DB      11111111B
        DB      11111110B
        DB      11111100B
        DB      11111111B
        DB      11111111B
        DB      11111111B
	
FONT3:  DB      11111111B
        DB      11111111B
        DB      11111110B
        DB      11111101B
        DB      11111000B
        DB      11111111B
        DB      11111111B
        DB      11111111B
	
FONT4:  DB      11111111B
        DB      11111111B
        DB      11111101B
        DB      11111011B
        DB      11110000B
        DB      11111111B
        DB      11111111B
        DB      11111111B
	
FONT5:  DB      11111111B
        DB      11111111B
        DB      11111011B
        DB      11110111B
        DB      11100000B
        DB      11111111B
        DB      11111111B
        DB      11111111B
	
FONT6:  DB      11111111B
        DB      11111111B
        DB      11110111B
        DB      11101111B
        DB      11000000B
        DB      11111111B
        DB      11111111B
        DB      11111111B
		
FONT7:  DB      11111111B
        DB      11111111B
        DB      11101111B
        DB      11011111B
        DB      10000000B
        DB      11111111B
        DB      11111111B
        DB      11111111B

FONT8:  DB      11111111B
        DB      11111111B
        DB      11011110B
        DB      10111110B
        DB      00000000B
        DB      11111110B
        DB      11111110B
        DB      11111111B

FONT9:  DB      11111111B
        DB      11111111B
        DB      10111101B
        DB      01111101B
        DB      00000001B
        DB      11111101B
        DB      11111101B
        DB      11111111B

FONT10: DB      11111111B
        DB      11111111B
        DB      01111011B
        DB      11111011B
        DB      00000011B
        DB      11111011B
        DB      11111011B
        DB      11111111B

FONT11: DB      11111111B
        DB      11111111B
        DB      11110111B
        DB      11110111B
        DB      00000111B
        DB      11110111B
        DB      11110111B
        DB      11111111B

FONT12: DB      11111111B
        DB      11111111B
        DB      11101111B
        DB      11101111B
        DB      00001111B
        DB      11101111B
        DB      11101111B
        DB      11111111B

FONT13: DB      11111111B
        DB      11111111B
        DB      11011111B
        DB      11011111B
        DB      00011111B
        DB      11011111B
        DB      11011111B
        DB      11111111B

FONT14: DB      11111111B
        DB      11111111B
        DB      10111111B
        DB      10111111B
        DB      00111111B
        DB      10111111B
        DB      10111111B
        DB      11111111B

FONT15: DB      11111111B
        DB      11111111B
        DB      01111111B
        DB      01111111B
        DB      01111111B
        DB      01111111B
        DB      01111111B
        DB      11111111B
CODE	ENDS
END