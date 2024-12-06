// /*
// ** EPITECH PROJECT, 2024
// ** lib
// ** File description:
// ** matrix3
// */

// #include <criterion/criterion.h>
// #include <criterion/redirect.h>
// #include "../include/main.h"

// static void redirect_all_std(void) {
//     cr_redirect_stdout();
//     cr_redirect_stderr();
// }

// static Matrix4 identity (
//     1, 0, 0,
//     0, 1, 0,
//     0, 0, 1
// );

// static Matrix4 base_matrix (
//     1, 2, 3,
//     4, 5, 6,
//     7, 8, 9
// );

// static Matrix4 base_matrix_neg (
//     -1, -2, -3,
//     -4, -5, -6,
//     -7, -8, -9
// );

// static Matrix4 base_matrix_t2 (
//     2, 4, 6,
//     8, 10, 12,
//     14, 16, 18
// );

// static Matrix4 base_matrix_mult (
//     30, 36, 42,
//     66, 81, 96,
//     102, 126, 150
// );

// Test(Matrix4, assert_eq, .init = redirect_all_std) {
//     Matrix4 a(base_matrix);
//     Matrix4 b(base_matrix);
//     Matrix4 c(identity);
//     cr_assert(a == b);
//     cr_assert(a != c);
// }

// Test(Matrix4, assert_init_cpy, .init = redirect_all_std) {
//     Matrix4 m(
//         1, 2, 3,
//         4, 5, 6,
//         7, 8, 9
//     );
//     cr_assert_eq(m == base_matrix, true);

//     Matrix4 cpy(m);
//     cr_assert_eq(cpy == base_matrix, true);
// }

// Test(Matrix4, assert_init_cpy_type, .init = redirect_all_std) {
//     Matrix4i m(
//         1, 2, 3,
//         4, 5, 6,
//         7, 8, 9
//     );
//     Matrix4f cpy(m);
//     cr_assert_eq(cpy == base_matrix, true);

//     Matrix4f cpy2;
//     cpy2 = m.Transpose();
//     cr_assert_eq(cpy2 == base_matrix, true);
// }

// Test(Matrix4, assert_transpose, .init = redirect_all_std) {
//     Matrix4 m(base_matrix);
//     m.Set_identity();
//     cr_assert_eq(m == identity, true);
//     cr_assert_eq(m.Transpose() == m, true);
// }

// Test(Matrix4, assert_determinant_inverse, .init = redirect_all_std) {
//     Matrix4 m(identity);
//     cr_assert_eq(m.Determinant() == 1, true);
//     m = m.Inverse();
//     cr_assert_eq(m == identity, true);
//     m = base_matrix;
//     m = m.Inverse();
//     cr_assert_eq(m == identity, true);
// }



// Test(Matrix4, assert_add, .init = redirect_all_std) {
//     Matrix4 a(base_matrix);
//     Matrix4 b(base_matrix);
//     Matrix4 sum = a + b;
//     cr_assert_eq(sum == base_matrix_t2, true);

//     a += b;
//     cr_assert_eq(a == base_matrix_t2, true);
// }

// Test(Matrix4, assert_sub, .init = redirect_all_std) {
//     Matrix4 a(base_matrix_t2);
//     Matrix4 b(base_matrix);
//     Matrix4 diff = a - b;
//     std::cout << diff << std::endl;
//     cr_assert_eq(diff == base_matrix, true);
//     diff = -diff;
//     cr_assert_eq(diff == base_matrix_neg, true);

//     a -= b;
//     cr_assert_eq(a == base_matrix, true);
// }

// Test(Matrix4, assert_mul, .init = redirect_all_std) {
//     Matrix4 a(base_matrix);
//     Matrix4 prod = a * a;
//     cr_assert_eq(prod == base_matrix_mult, true);

//     a *= a;
//     cr_assert_eq(a == base_matrix_mult, true);
// }

// Test(Matrix4, assert_stream, .init = redirect_all_std) {
//     Matrix4 a(base_matrix);
//     std::cout << a << std::endl;
//     cr_assert_stdout_eq_str("[[1, 2, 3],\n [4, 5, 6],\n [7, 8, 9]]\n");
// }
