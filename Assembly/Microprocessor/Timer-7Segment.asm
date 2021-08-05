

; ******************************************************
; * EXPERIMENT N0.: 2                                  *
; * GROUP NO.     : 1                                  *
; * TOPIC         : DISPLAYING AN UP & DOWN TIMER USING*
; *                 7 SEGMENT DISPLAY                  *
; ******************************************************


CODE SEGMENT
     ASSUME CS:CODE,DS:CODE,ES:CODE,SS:CODE

PPIC_C  EQU 1FH
PPIC    EQU 1DH
PPIB    EQU 1BH
PPIA    EQU 19H

    ORG 1000H
    MOV AL,10000000B
    OUT PPIC_C,AL

    MOV AL,11110000B
    OUT PPIB,AL

    MOV AL,00000000B
    OUT PPIC,AL

    MOV SI,OFFSET DATA

L2: INC SI
L1: MOV AL,BYTE PTR CS:[SI]
    CMP AL,00H
    JE  L3
    OUT PPIA,AL
    CALL TIMER
    INC SI
    JMP L1

    INT 3

L3: DEC SI
    MOV AL,BYTE PTR CS:[SI]
    CMP AL,00H
    JE  L2
    OUT PPIA,AL
    CALL TIMER
    JMP L3
    INT 3
TIMER : MOV CX,0
TIMER1: NOP
        NOP
        NOP
        NOP
        LOOP TIMER1
        RET

DATA:DB 00000000B
     DB 11000000B
     DB 11111001B
     DB 10100100B
     DB 10110000B
     DB 10011001B
     DB 10010010B
     DB 00000000H
     CODE ENDS
     END