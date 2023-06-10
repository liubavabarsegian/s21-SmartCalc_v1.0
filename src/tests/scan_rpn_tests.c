#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../s21_smart_calc/scan_rpn.h"

START_TEST(test_1) {
    char input[] = "100  +  100";
    double result_real = 100 + 100;
    char result_s21[255];
    scan_rpn(input, result_s21);
    ck_assert_float_eq(atof(result_s21), result_real);
}
END_TEST

START_TEST(test_2) {
    char input[] = "-200 + 200";
    double result_real = -200 + 200;
    char result_s21[255];
    scan_rpn(input, result_s21);
    ck_assert_float_eq(atof(result_s21), result_real);
}
END_TEST

START_TEST(test_3) {
    char input[] = "-15";
    double result_real = -15;
    char result_s21[255];
    scan_rpn(input, result_s21);
    ck_assert_float_eq(atof(result_s21), result_real);
}
END_TEST

START_TEST(test_4) {
    char input[] = "-5";
    double result_real = -5;
    char result_s21[255];
    scan_rpn(input, result_s21);
    ck_assert_float_eq(atof(result_s21), result_real);
}
END_TEST

START_TEST(test_5) {
    char input[] = "15";
    double result_real = 15;
    char result_s21[255];
    scan_rpn(input, result_s21);
    ck_assert_float_eq(atof(result_s21), result_real);
}
END_TEST

START_TEST(test_6) {
    char input[] = "9^4 - 78 / 5";
    double result_real = pow(9, 4) - 78 / 5;
    printf("real: %f\n", result_real);
    char result_s21[255];
    scan_rpn(input, result_s21);
    ck_assert(fabs(atof(result_s21) - result_real) < 1e-5);
    // ck_assert_float_eq(atof(result_s21), result_real);
}
END_TEST

START_TEST(test_7) {
    char input[] = "-45.6/5-67*4-(+8*2-5)";
    double result_real = -45.6/5-67*4-(+8*2-5);
    printf("real: %f\n", result_real);
    char result_s21[255];
    scan_rpn(input, result_s21);
    ck_assert(fabs(atof(result_s21) - result_real) < 1e-5);
    // ck_assert_float_eq(atof(result_s21), result_real);
}
END_TEST

START_TEST(test_8) {
    char input[] = "-45%-5";  
    double result_real = -45%-5;
    printf("real: %f\n", result_real);
    char result_s21[255];
    scan_rpn(input, result_s21);
    ck_assert_float_eq(atof(result_s21), result_real);
    // ck_assert(fabs(atof(result_s21) - result_real) < 1e-5);
}
END_TEST

void calc_tests(TCase *tc1_1) {
    tcase_add_test(tc1_1, test_1);
    tcase_add_test(tc1_1, test_2);
    tcase_add_test(tc1_1, test_3);
    tcase_add_test(tc1_1, test_4);
    tcase_add_test(tc1_1, test_5);
    tcase_add_test(tc1_1, test_6);
    tcase_add_test(tc1_1, test_7);
    tcase_add_test(tc1_1, test_8);
}

int main(void) {
    Suite *s1 = suite_create("RPN");
    TCase *tc1_1 = tcase_create("RP");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    
    calc_tests(tc1_1);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}