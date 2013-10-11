
compilation : avr-gcc -g -Os -finline-limit=800 -mmcu=atmega88 -DF_CPU=20000000 -c *.c
link        : avr-gcc -L /usr/local/avr/avr/lib -mmcu=atmega88 *.o executable
transformation .hex : avr-objcopy -O ihex -R .eeprom executable fichier.hex
decompilation : avr-objdump -h -S executable
taille : avr-size

