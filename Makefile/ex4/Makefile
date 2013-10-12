JPGFILES := $(wildcard *.jpg)

all: png bb

png: $(JPGFILES:*.jpg=*.png)

bb:

%.png: %.jpg
	convert -monitor $< $@

clean:
	for i in $(JPGFILES); do
		rm $(subst .jpg .png $$i)); done
