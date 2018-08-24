SECTIONS {
	. = 0x30000000;
	
	.text				:			{
		.				= ALIGN(4);
		__text_start		= . ;
		*(.text)
		_test_end			= . ;
	}
	
	.rodata				:			{
		.				= ALIGN(4);
		__rodata_start		= . ;
		*(.rodata)
		_rodata_end		= . ;
	}
	
	.data				:			{
		.				= ALIGN(4);
		__data_start		= . ;
		*(.data)
		_data_end			= . ;
	}
	
	.bss					:			{
		.				= ALIGN(4);
		__bss_start		= . ;
		*(.bss)
		_bss_end			= . ;
		*(.COMMON)
	}
}
