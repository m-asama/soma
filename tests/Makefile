#
# Author:
# 	Masakazu Asama <m-asama@ginzado.co.jp>
#

.include "../soma.mk"

CXXFLAGS      = -Wall -O2 -pipe -fPIC -I. -I../kernel -ffreestanding \
                -mno-red-zone -mno-mmx -mno-sse -mno-aes -mno-avx -msoft-float \
                -std=c++11 -Qunused-arguments \
		-nostdinc -nostdlibinc -nobuiltininc \
		-fno-exceptions -fno-rtti -fno-use-cxa-atexit

KERNEL_OBJS   = ../kernel/memory_management.o \
		../kernel/memory_block.o \
		../kernel/font.o \
		../kernel/font_data.o \
		../kernel/unicode.o \
		../kernel/print.o \
		../kernel/utf8str.o \
		../kernel/console_msg.o \
		../kernel/config_model_node.o \
		../kernel/config_model_type.o \
		../kernel/config_model_argument.o \
		../kernel/config_model_length.o \
		../kernel/config_model_pattern.o \
		../kernel/config_model_range.o \
		../kernel/config_model_build.o \
		../kernel/config_model_nodes.o \
		../kernel/config_model_functions.o \
		../kernel/config_model_descriptions.o \
		../kernel/config_model_argument_descriptions.o \
		../kernel/config_model_formats.o \
		../kernel/config_data_node.o \
		../kernel/virtqueue.o \
		../kernel/packet_buffer.o \
		../kernel/util.o

KERNEL_SRCS   = ${KERNEL_OBJS:=.cpp}

OBJS	      = utf8str_test.o \
		linked_list_test.o \
		sorted_list_test.o \
		hash_table_test.o \
		memory_pool_test.o \
		memory_management_test.o \
		ring_buffer_test.o \
		util_test.o \
		config_test.o \
		virtqueue_test.o \
		packet_buffer_test.o \
		main.o

all: main

test: main
	@./main

main: ${OBJS}
	make -C ../kernel
	clang++38 -std=c++11 -o main $> ${KERNEL_OBJS}

main.o: main.cpp
	clang++38 -std=c++11 -I../kernel -c main.cpp

.cpp.o:
	clang++38 $(CXXFLAGS) -c $<

clean:
	rm -f *.o main.core main

