JPGFILES := $(wildcard *.jpg)

%.png: %.jpg
	convert -monitor $< $@

clean:
	for i in $(JPGFILES); do (rm $(subst .jpg .png $$i)); done
