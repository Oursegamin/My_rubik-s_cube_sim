/*
** EPITECH PROJECT, 2024
** lib
** File description:
** vector3
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/main.h"

static void redirect_all_std(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

void assert_vector3(Vector3i vec, Vector3i truth) {
    cr_assert_eq(vec.x, truth.x);
    cr_assert_eq(vec.y, truth.y);
    cr_assert_eq(vec.z, truth.z);
}

Test(Vector3, assert_init_cpy, .init = redirect_all_std) {
    Vector3 v(1, 2, 3);
    assert_vector3(v, Vector3(1, 2, 3));

    Vector3 cpy(v);
    assert_vector3(cpy, Vector3(1, 2, 3));
}

Test(Vector3, assert_add, .init = redirect_all_std) {
    Vector3 a(1, 2, 3);
    Vector3 b(4, 5, 6);
    Vector3 sum = a + b;
    assert_vector3(sum, Vector3(5, 7, 9));

    a += b;
    assert_vector3(a, Vector3(5, 7, 9));
}

Test(Vector3, assert_sub, .init = redirect_all_std) {
    Vector3 a(1, 2, 3);
    Vector3 b(4, 5, 6);
    Vector3 diff = a - b;
    assert_vector3(diff, Vector3(-3, -3, -3));
    diff = -diff;
    assert_vector3(diff, Vector3(3, 3, 3));

    a -= b;
    assert_vector3(a, Vector3(-3, -3, -3));
}

Test(Vector3, assert_mul, .init = redirect_all_std) {
    Vector3 a(1, 2, 3);
    Vector3 prod = a * 2;
    assert_vector3(prod, Vector3(2, 4, 6));

    a *= 2;
    assert_vector3(a, Vector3(2, 4, 6));
}

Test(Vector3, assert_div, .init = redirect_all_std) {
    Vector3 a(2, 4, 6);
    Vector3 quot = a / 2;
    assert_vector3(quot, Vector3(1, 2, 3));

    a /= 2;
    assert_vector3(a, Vector3(1, 2, 3));
}

Test(Vector3, div_error, .init = redirect_all_std) {
    Vector3 a(2, 4, 6);
    cr_assert_throw({
        Vector3 quot = a / 0;
    }, std::invalid_argument, "Division by zero");
    cr_assert_throw({
        a /= 0;
    }, std::invalid_argument, "Division by zero");
}

Test(Vector3, assert_eq, .init = redirect_all_std) {
    Vector3 a(1, 2, 3);
    Vector3 b(1, 2, 3);
    Vector3 c(2, 3, 4);
    cr_assert(a == b);
    cr_assert(a != c);
}

Test(Vector3, assert_stream, .init = redirect_all_std) {
    Vector3 a(1, 2, 3);
    std::cout << a << std::endl;
    cr_assert_stdout_eq_str("x : 1, y : 2, z : 3\n");
}
