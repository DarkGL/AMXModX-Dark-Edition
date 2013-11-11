
CODE	; 0
;program exit point
	halt 0

CODE	; 8
	proc	; getPointerFunc
	break	; c
	;$lcl funcName c
	break	; 10
	;$lcl idFunc fffffffc
	stack fffffffc
	push.s c
	;$par
	push.c 4
	sysreq.c 0	; funcidx
	stack 8
	stor.s.pri fffffffc
	;$exp
	break	; 44
	load.s.pri fffffffc
	eq.c.pri ffffffff
	jzer 1c
	;$exp
	break	; 60
	zero.pri
	;$exp
	stack 4
	retn
l.1c		; 74
	break	; 74
	;$lcl pointer fffffff8
	push.c 0
	;$exp
	lctrl 1
	add.c 14
	stor.s.pri fffffff8
	break	; 98
	load.s.pri fffffff8
	;$exp
	stack 8
	retn


CODE	; b0
	proc	; plugin_init
	break	; b4
	break	; b8
	;$lcl funcTest fffffffc
	stack fffffffc
	push.c 0
	;$par
	push.c 4
	call getPointerFunc
	stor.s.pri fffffffc
	;$exp
	break	; e4
	;$lcl funcTest2 fffffff8
	stack fffffffc
	push.c 24
	;$par
	push.c 4
	call getPointerFunc
	stor.s.pri fffffff8
	;$exp
	break	; 110
	pushaddr fffffff8
	;$par
	pushaddr fffffffc
	;$par
	push.c 4c
	;$par
	push.c c
	sysreq.c 1	; log_amx
	stack 10
	;$exp
	stack 8
	zero.pri
	retn


DATA	; 0
dump 66 75 6e 63 54 65 73 74 0 66 75 6e 63 54 65 73 
dump 74 32 0 20 25 64 20 7c 20 25 64 0 

CODE	; 154
	proc	; funcTest
	break	; 158
	;$lcl variable c
	break	; 15c
	pushaddr c
	;$par
	push.c 70
	;$par
	push.c 8
	sysreq.c 1	; log_amx
	stack c
	;$exp
	zero.pri
	retn


DATA	; 1c
dump 66 75 6e 63 54 65 73 74 3a 20 25 64 0 

CODE	; 190
	proc	; funcTest2
	break	; 194
	break	; 198
	push.c a4
	;$par
	push.c 4
	sysreq.c 1	; log_amx
	stack 8
	;$exp
	zero.pri
	retn


DATA	; 29
dump 66 75 6e 63 54 65 73 74 32 0 

STKSIZE 1000
