target =  miniproject2.o stud_add.o stud_del.o stud_save.o stud_show.o

cc = gcc

student :$(target)
	@echo "running final.."
	$(cc) $(target) -o student
miniproject2.o	: miniproject2.c
	$(cc) -c miniproject2.c
stud_add.o	: stud_add.c
	$(cc) -c stud_add.c
stud_del.o	: stud_del.c
	$(cc) -c stud_del.c
stud_save.o	: stud_save.c
	$(cc) -c stud_save.c
stud_show.o	: stud_show.c
	$(cc) -c stud_show.c

clear	:
	@ echo "cleaning up ..."
	@ rm *.o student

