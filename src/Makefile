NAME = s21_smart_calc.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
SRCS = s21_smart_calc/*.c
TEST_SRCS = tests/*.c
TEST_FLAGS = -lcheck -lm -lpthread
GCOV_FLAGS = -ftest-coverage -fprofile-arcs
UNAME_S = $(shell uname -s)

ifeq ($(shell uname), Linux)
	TEST_FLAGS += -lrt -lsubunit
endif

all: ${NAME}

${NAME}:
	$(CC) $(CFLAGS) -c ${SRCS}
	ar rc $(NAME) *.o
	ranlib $(NAME)
	rm *.o

APP = build/smart_calc.app

test: rebuild
	$(CC) $(CFLAGS) -c ${TEST_SRCS}
	$(CC) $(CFLAGS) *.o ${NAME} ${TEST_FLAGS}  -o test
	./test

add_coverage_flag:
	$(eval FLAGS += --coverage)

gcov_report: 
	clean add_coverage_flag test
	lcov --capture --directory . --output-file coverage.info
	rm *tests*.gcda *tests*.gcno
	gcov -b -l -p -c *.gcno
	gcovr -o gcov_report.html --html --html-details
	open gcov_report.html

install: 
	cleanAll
	mkdir build
	cd smart_calc && qmake && make && make clean && rm Makefile && cd ../ && mv smart_calc/smart_calc.app build

uninstall:
	rm -rf build

dvi: 
	open dvi.html

dist:
	rm -rf Archive_SmartCalc_v1.0/
	mkdir Archive_SmartCalc_v1.0/
	mkdir Archive_SmartCalc_v1.0/src
	mkdir Archive_SmartCalc_v1.0/src/smart_calc
	cp Makefile *.c *.h dvi.html Archive_SmartCalc_v1.0/src/
	cp smart_calc/*.h smart_calc/*.pro smart_calc/*.cpp smart_calc/*.ui smart_calc/*.user Archive_SmartCalc_v1.0/src/smart_calc/ 
	tar cvzf Archive_SmartCalc_v1.0.tgz Archive_SmartCalc_v1.0/
	mv Archive_SmartCalc_v1.0.tgz $(HOME)/Desktop/
	rm -rf Archive_SmartCalc_v1.0/

rebuild: clean all

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