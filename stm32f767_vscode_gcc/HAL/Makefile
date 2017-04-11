CC=arm-none-eabi-gcc
AR=arm-none-eabi-ar

###########################################
vpath %.c Src 

CFLAGS += -mthumb -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-d16

CFLAGS  = -g -O2 -Wall
CFLAGS += -mthumb -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-d16
CFLAGS += -mlittle-endian  -mthumb-interwork

CFLAGS += -ffreestanding -nostdlib

CFLAGS += -IInc -I../INC -IInc/Legacy -I../STM32F767
CFLAGS += -DSTM32F767xx -DUSE_HAL_DRIVER

#CFLAGS += --specs=nosys.specs
#LFLAGS += --specs=nosys.specs

SRCS = $(wildcard Src/*.c)
OBJS = $(SRCS:.c=.o)

.PHONY: libstm32f7.a
all: libstm32f7.a
%.o : %.c
	$(CC) $^ $(CFLAGS) -c -o $@ 
libstm32f7.a: $(OBJS)
	$(AR) -r $@ $(OBJS)
clean:
	rm -f $(OBJS) libstm32f7.a