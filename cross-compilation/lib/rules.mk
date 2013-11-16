LIB_SRC = $(wildcard $(TOP_DIR)/lib/*.c)

$(TOP_DIR)/lib/serial.o: $(TOP_DIR)/lib/serial.h
$(TOP_DIR)/lib/convert.o: $(TOP_DIR)/lib/convert.h
$(TOP_DIR)/lib/led.o: $(TOP_DIR)/lib/led.h
$(TOP_DIR)/lib/timer.o: $(TOP_DIR)/lib/timer.h