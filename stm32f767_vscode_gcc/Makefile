PROJ_NAME = main

CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy

CFLAGS  = -g -O2 -Wall -TSTM32F767ZITx_FLASH.ld
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m7 -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv5-d16

CFLAGS += --specs=nosys.specs
LFLAGS += --specs=nosys.specs

SRCS = stm32f7xx_it.c system_stm32f7xx.c stm32f7xx_hal_msp.c sys.c usart.c delay.c ltdc.c sdram.c tftlcd.c main.c

vpath %.c USER SYSTEM/usart SYSTEM/delay SYSTEM/sys LCD STM32F767
vpath %.a HAL

ROOT=$(shell pwd)

CFLAGS += -ILCD -ISYSTEM/sys -ISYSTEM/usart -ISYSTEM/delay -IUSER
CFLAGS += -IHAL/Inc -IHAL/Inc/Legacy -IINC -ISTM32F767 
CFLAGS += -DSTM32F767xx -DUSE_GCC

SRCS += STM32F767/gcc/startup_stm32f767xx.s

OBJS = $(SRCS:.c=.o)

.PHONY: lib proj

all: lib proj

lib:
	$(MAKE) -C HAL
proj: 	$(PROJ_NAME).elf
$(PROJ_NAME).elf: $(SRCS)
	$(CC) $(CFLAGS)  $^ -o $@ -LHAL -lstm32f7
	$(OBJCOPY) -O ihex -S $(PROJ_NAME).elf $(PROJ_NAME).hex
	$(OBJCOPY) -O binary $(PROJ_NAME).elf $(PROJ_NAME).bin

clean:
	$(MAKE) -C HAL clean
	rm -f $(PROJ_NAME).elf
	rm -f $(PROJ_NAME).hex
	rm -f $(PROJ_NAME).bin    