

; ******************************************************
; * EXPERIMENT N0.: 1                                  *
; * GROUP NO.     : 1                                  *
; * TOPIC         : DISPLAYING A SPECIAL PATTERN USING *
; *                 4 LED DISPLAY                      *
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

    MOV AL,11111111B
    OUT PPIA,AL

    MOV AL,00000000B
    OUT PPIC,AL

L1: MOV SI,OFFSET DATA
L2: MOV AL,BYTE PTR CS:[SI]
    OUT PPIB,AL
    CMP AL,00H
    JE  L1
    CALL TIMER
    INC SI
    JMP L2

    INT 3

TIMER :MOV CX,0
TIMER1:NOP
       NOP
       NOP
       NOP
       LOOP TIMER1
       RET

DATA: DB 00001000B
      DB 00000010B
      DB 00000001B
      DB 00000100B
      DB 00000000B
      DB 00000000B
      CODE ENDS
      END