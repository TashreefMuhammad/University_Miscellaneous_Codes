
; ******************************************************
; * EXPERIMENT N0.: 1                                  *
; * GROUP NO.     : 1                                  *
; * TOPIC         : Displaying the digit “1” using 8X8 *
; *                 dot matrix                         *
; ******************************************************

CODE SEGMENT
     ASSUME CS:CODE,DS:CODE,ES:CODE,SS:CODE


PPIC_C  EQU 1EH     ; control register
PPIC    EQU 1CH     ; c port
PPIB    EQU 1AH
PPIA    EQU 18H

    ORG 1000H
    MOV AL,10000000B
    OUT PPIC_C,AL

    MOV AL,11111111B
    OUT PPIA,AL

L1: MOV SI,OFFSET FONT

    MOV AH,00000001B

L2: MOV AL,BYTE PTR CS:[SI]
    OUT PPIA,AL
    NOT AL
    OUT PPIB,AL

    MOV AL,AH
    OUT PPIC,AL
    CALL TIMER
    INC SI
    CLC
    ROL AH,1
    JNC L2
    JMP L1

    INT 3

TIMER   : MOV CX,300
TIMER1  : NOP
          NOP
          NOP
          NOP
          LOOP TIMER1
          RET

FONT:   DB 11111111B
        DB 11111111B
        DB 11011110B
        DB 10111110B
        DB 00000000B
        DB 11111110B
        DB 11111110B
        DB 11111111B
    CODE ENDS
END