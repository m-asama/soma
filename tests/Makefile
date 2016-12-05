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
		../kernel/util.o

KERNEL_SRCS   = ${KERNEL_OBJS:=.cpp}

OBJS	      = linked_list_test.o \
		sorted_list_test.o \
		hash_table_test.o \
		memory_pool_test.o \
		memory_block_test.o \
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

doxygen:
	doxygen doxygen.conf

