SECTIONS {
	.text	0x00000000	:			{ *(.text) }
	
	.rodata				:			{ *(.rodata) }
	
	.data	0x30000000	: AT(0x800)	{
		data_load_addr		= LOADADDR(.data);
		data_start		= . ;
		*(.data)
		data_end			= . ;
	}
	
	.bss					:			{
		bss_start			= . ;
		*(.bss)
		bss_end			= . ;
		*(.COMMON)
	}
}
