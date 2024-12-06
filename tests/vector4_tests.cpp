/*
** EPITECH PROJECT, 2024
** lib
** File description:
** vector4
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/main.h"

static void redirect_all_std(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

void assert_vector4(Vector4i vec, Vector4i truth) {
    cr_assert_eq(vec.x, truth.x);
    cr_assert_eq(vec.y, truth.y);
    cr_assert_eq(vec.z, truth.z);
    cr_assert_eq(vec.w, truth.w);
}

Test(Vector4, assert_init_cpy, .init = redirect_all_std) {
    Vector4 v(1, 2, 3, 4);
    assert_vector4(v, Vector4(1, 2, 3, 4));

    Vector4 cpy(v);
    assert_vector4(cpy, Vector4(1, 2, 3, 4));
}

Test(Vector4, assert_add, .init = redirect_all_std) {
    Vector4 a(1, 2, 3, 4);
    Vector4 b(5, 6, 7, 8);
    Vector4 sum = a + b;
    assert_vector4(sum, Vector4(6, 8, 10, 12));

    a += b;
    assert_vector4(a, Vector4(6, 8, 10, 12));
}

Test(Vector4, assert_sub, .init = redirect_all_std) {
    Vector4 a(1, 2, 3, 4);
    Vector4 b(5, 6, 7, 8);
    Vector4 diff = a - b;
    assert_vector4(diff, Vector4(-4, -4, -4, -4));
    diff = -diff;
    assert_vector4(diff, Vector4(4, 4, 4, 4));

    a -= b;
    assert_vector4(a, Vector4(-4, -4, -4, -4));
}

Test(Vector4, assert_mul, .init = redirect_all_std) {
    Vector4 a(1, 2, 3, 4);
    Vector4 prod = a * 2;
    assert_vector4(prod, Vector4(2, 4, 6, 8));

    a *= 2;
    assert_vector4(a, Vector4(2, 4, 6, 8));
}

Test(Vector4, assert_div, .init = redirect_all_std) {
    Vector4 a(2, 4, 6, 8);
    Vector4 quot = a / 2;
    assert_vector4(quot, Vector4(1, 2, 3, 4));

    a /= 2;
    assert_vector4(a, Vector4(1, 2, 3, 4));
}

Test(Vector4, div_error, .init = redirect_all_std) {
    Vector4 a(2, 4, 6, 8);
    cr_assert_throw({
        Vector4 quot = a / 0;
    }, std::invalid_argument, "Division by zero");
    cr_assert_throw({
        a /= 0;
    }, std::invalid_argument, "Division by zero");
}

Test(Vector4, assert_eq, .init = redirect_all_std) {
    Vector4 a(1, 2, 3, 4);
    Vector4 b(1, 2, 3, 4);
    Vector4 c(2, 3, 4, 5);
    cr_assert(a == b);
    cr_assert(a != c);
}

Test(Vector4, assert_stream, .init = redirect_all_std) {
    Vector4 a(1, 2, 3, 4);
    std::cout << a << std::endl;
    cr_assert_stdout_eq_str("x : 1, y : 2, z : 3, w : 4\n");
}
