./a.out:	inptry1.o giantcc.o client.o insert.o indexgenerator.o fltry.o bfstry1.o
		gcc inptry1.o giantcc.o client.o insert.o indexgenerator.o fltry.o bfstry1.o

inptry1.o:	inptry1.c header1.h
		gcc -c inptry1.c

giantcc.o:	giantcc.c header1.h
		gcc -c giantcc.c

client.o:	client.c header1.h
		gcc -c client.c

insert.o:	insert.c header1.h
		gcc -c insert.c

indexgenerator.o:	indexgenerator.c header1.h
			gcc -c indexgenerator.c

fltry.o:	fltry.c header1.h
		gcc -c fltry.c

bfstry1.o:	bfstry1.c header1.h
		gcc -c bfstry1.c



