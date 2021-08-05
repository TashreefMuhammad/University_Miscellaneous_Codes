; ******************************************************
; * EXPERIMENT N0.: 3                                  *
; * GROUP NO.     : 1                                  *
; * TOPIC         : DISPLAYING A SPECIAL SHIFT PATTERN *
; *                 USING 7 SEGMENT DISPLAY            *
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
    CALL ROTE1
    CALL TIMER
    CALL ROTE2
    CALL TIMER
    INC SI
    JMP L1
    
    INT 3

L3: DEC SI
    MOV AL,BYTE PTR CS:[SI]
    CMP AL,00H
    JE L2
    OUT PPIA,AL
    CALL TIMER
    CALL ROTE1
    CALL TIMER
    CALL ROTE2
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

ROTE1:  MOV AL,11111110B
ROTE :  CMP AL,10111111B
        JE  EXIT
        OUT PPIA,AL
        CALL TIMER
        SHL AL,1
        OR AL,00000001B
        JMP ROTE
        RET

ROTE2:  MOV AL,11011111B
ROTE3:  CMP AL,11111111B
        JE EXIT
        OUT PPIA, AL
        CALL TIMER
        SHR AL,1
        OR AL,10000000B
        JMP ROTE3
        RET

EXIT:
        RET
DATA:   DB 00000000B
        DB 11000000B
        DB 11111001B
        DB 10100100B
        DB 10110000B
        DB 10011001B
        DB 10010010B
        DB 00000000B
        CODE ENDS
        END