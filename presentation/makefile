CC = pdflatex
BIBCC = bibtex
TEX = Presentacion
ARGS = -aux-directory=GRBG
OUT = *.aux *.log *.nav *.out *.pdf *.snm *.toc *.vrb *.bbl *.bbg *.blg

all:
	$(CC) $(TEX)
	$(BIBCC) $(TEX)
	$(CC) $(TEX)
	$(CC) $(TEX)

single:
	$(CC) $(TEX)

clean:
	rm -f $(OUT)

cleanWin:
	del $(OUT) 2>nul
