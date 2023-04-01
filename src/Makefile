CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
CHECKFLAGS = -lcheck -lsubunit -coverage -pthread -lrt
APP = build/untitled.app
TST_LIBS = -lcheck

ifeq ($(shell uname), Linux)
	TST_LIBS += -lpthread -lrt -lsubunit -lm
endif

LIB_NAME = s21_calc

SRCS = s21_calc.c

OBJS=$(SRCS:.c=.o)

all:install $(LIB_NAME).a
 gcov_report 
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIB_NAME).a: $(OBJS)
	ar rc $(LIB_NAME).a $^
	ranlib $(LIB_NAME).a

test: clean $(LIB_NAME).a
	$(CC) $(FLAGS) tests.c $(LIB_NAME).a $(TST_LIBS) -o test
	./test

add_coverage_flag:
	$(eval FLAGS += --coverage)

gcov_report: clean add_coverage_flag test
	lcov --capture --directory . --output-file coverage.info
	rm *tests*.gcda *tests*.gcno
	gcov -b -l -p -c *.gcno
	gcovr -o gcov_report.html --html --html-details
	open gcov_report.html

install: cleanAll
	mkdir build
	cd untitled && qmake && make && make clean && rm Makefile && cd ../ && mv untitled/untitled.app build

uninstall:
	rm -rf build

dvi: 
	open dvi.html

dist:
	rm -rf Archive_SmartCalc_v1.0/
	mkdir Archive_SmartCalc_v1.0/
	mkdir Archive_SmartCalc_v1.0/src
	mkdir Archive_SmartCalc_v1.0/src/untitled
	cp Makefile *.c *.h dvi.html Archive_SmartCalc_v1.0/src/
	cp untitled/*.h untitled/*.pro untitled/*.cpp untitled/*.ui untitled/*.user Archive_SmartCalc_v1.0/src/untitled/ 
	tar cvzf Archive_SmartCalc_v1.0.tgz Archive_SmartCalc_v1.0/
	mv Archive_SmartCalc_v1.0.tgz $(HOME)/Desktop/
	rm -rf Archive_SmartCalc_v1.0/

clean:
	rm -rf test *.gcov *.css gcov*.html
	rm -rf *.o *.a *.out 
	rm -rf *.gcda *.gcno *.info *.gch
	rm -rf test report

cleanAll:
	rm -rf test *.gcov *.css gcov*.html
	rm -rf *.o *.a *.out 
	rm -rf *.gcda *.gcno *.info *.gch
	rm -rf test report
	rm -rf build