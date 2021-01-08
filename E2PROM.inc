ESCR_E2PROM

	MOVF 	CONTADOR,W

	BANK2 					;BANKSEL EEDATA
	MOVWF 	EEDATA
	
	BANK0
	MOVF	ENDERECO,W
	
	BANK2 					;BANKSEL EEADR
	MOVWF	EEADR
	
	BANK3 					;BANKSEL EECON1
	BCF		EECON1,EEPGD
	BSF		EECON1,WREN
	MOVLW	0x55
	MOVWF	EECON2 			;OBRIGAT�RIO.
	MOVLW	0xAA
	MOVWF	EECON2			;OBRIGAT�RIO.
	BSF		EECON1,WR 		;INICIA ESCRITA.
	BTFSC	EECON1,WR
	GOTO 	$-1
	BCF		EECON1,WREN
	
	BANK0
	RETURN					;RETORNA

LEIT_E2PROM

	MOVF 	ENDERECO,W
	
	BANK2 					;BANKSEL EEADR
	MOVWF 	EEADR
	
	BANK3 					;BANKSEL EECON1
	BCF 	EECON1,EEPGD
	BSF 	EECON1,RD
	
	BANK2 					;BANKSEL EEDATA
	MOVF	EEDATA,W
	
	BANK0 					;BANKSEL DADO
	MOVWF	DADO

	RETURN					;RETORNA