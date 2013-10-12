JPGFILES := $(wildcard *.jpg)
PNGFILES = $(wildcard *.png)

all: png bb

png: $(JPGFILES:.jpg=.png)

bb: $(PNGFILES:.png=.eps)
	grep %%BoundingBox $^
	rm -f $^

%.eps: %.png
	convert $< $@

%.png: %.jpg
	convert $< $@

clean:
	rm -f $(JPGFILES:.jpg=.png)