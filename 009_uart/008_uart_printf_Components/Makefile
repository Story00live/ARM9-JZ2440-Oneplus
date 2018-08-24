# 指定编译器
# CROSS_COMPILE = /home/kyj/Tools/gcc-3.4.5-glibc-2.3.6/bin/arm-linux-
CROSS_COMPILE = arm-linux-

# 指定编译器命令
AS            = $(CROSS_COMPILE)as
LD            = $(CROSS_COMPILE)ld
CC            = $(CROSS_COMPILE)gcc
OBJCOPY       = $(CROSS_COMPILE)objcopy
OBJDUMP       = $(CROSS_COMPILE)objdump

# 指定程序默认名称
TARGET        = Demo

# 命令行中使用p=X或P=X修改默认程序名称
ifeq ("$(origin out)", "command line")
TARGET = $(out)
endif

ifeq ("$(origin Out)", "command line")
TARGET = $(Out)
endif

# 指定所有目录及子目录
DIRS          = $(shell find . -type d)

# 找出所有的.S .c .h .a .so文件及目录
SFILES_DIR    = $(shell find . -type f -name "*.S")
SFILES        = $(notdir $(SFILES_DIR))
SDIRS         = $(sort $(dir $(SFILES_DIR)))

CFILES_DIR    = $(shell find . -type f -name "*.c")
CFILES        = $(notdir $(CFILES_DIR))
CDIRS         = $(sort $(dir $(CFILES_DIR)))

HFILES_DIR    = $(shell find . -type f -name "*.h")
HFILES        = $(notdir $(HFILES_DIR))
HDIRS         = $(sort $(dir $(HFILES_DIR)))

AFILES_DIR    = $(shell find . -type f -name "lib*.a")
AFILES        = $(notdir $(AFILES_DIR))
ADIRS         = $(sort $(dir $(AFILES_DIR)))

SOFILES_DIR   = $(shell find . -type f -name "lib*.so")
SOFILES       = $(notdir $(SOFILES_DIR))
SODIRS        = $(sort $(dir $(SOFILES_DIR)))

# 包含所有含有.h文件的目录
INCLUDES     += $(HDIRS:%=-I%)
$(warning INCLUDES : [ $(INCLUDES) ])
CFLAGS       += $(INCLUDES)

# 编译标志(-Wall: 打开gcc的所有警告, -Werror: gcc将所有的警告当成错误进行处理)
CFLAGS       += -Wall -Werror

# 指定.a .so文件的目录
LDFLAGS      += $(ADIRS:%=-L%)
LDFLAGS      += $(SODIRS:%=-L%)

# 引用库文件
LDFLAGS      += $(AFILES:lib%.a=-l%)
LDFLAGS      += $(SOFILES:lib%.so=-l%)

# 链接标志
LDFLAGS      += -Ttext 0 -Tdata 0xEC4
$(warning LDFLAGS : [ $(LDFLAGS) ])

# 包含所有的目录
VPATH         = $(DIRS)

# 包含所有.c文件
CSOURCES      = $(CFILES)
$(warning CSOURCES : [ $(CSOURCES) ])

# 包含所有.S文件
SSOURCES      = $(SFILES)
$(warning SSOURCES : [ $(SSOURCES) ])

# 目标及依赖
COBJS         = $(CSOURCES:%.c=Output/%.o)
SOBJS         = $(SSOURCES:%.S=Output/%.o)
DEPS          = $(CSOURCES:%.c=Output/%.d)

.PHONY : all clean cleanall

all : Output/$(TARGET)
	$(OBJCOPY) -O binary -S Output/$(TARGET).elf Output/$(TARGET).bin
	$(OBJDUMP) -D Output/$(TARGET).elf > Output/$(TARGET).dis

Output/$(TARGET) : $(COBJS) $(SOBJS)
	@mkdir -p Output
	$(LD) $(LDFLAGS) $^ -o $@.elf
	
Output/%.o : %.c
	@mkdir -p Output
	$(CC) $(CFLAGS) -c -o $@ $<
	
Output/%.o : %.S
	@mkdir -p Output
	$(CC) $(CFLAGS) -c -o $@ $<
	
clean :
	rm -rf $(COBJS) $(SOBJS) $(DEPS) Output/$(TARGET).elf
	
cleanall :
	rm -rf $(COBJS) $(SOBJS) $(DEPS) Output/$(TARGET).elf Output/$(TARGET).bin Output/$(TARGET).dis
	