/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** yannis.alouache@epitech.eu
** maxime.lespineux@epitech.eu
*/

int is_char_alpha(char letter);

int my_compute_factorial_it(int nb);

int my_compute_factorial_rec(int nb);

int my_compute_power_it(int nb, int p);

int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb);

int my_strlength(char const *str);

int my_find_prime_sup(int nb);

int my_getnbr(char const *str);

int my_is_prime(int nb);

int my_isneg(int n);

int my_print_alpha(void);

int my_print_comb(void);

void my_print_div_mod(int number);

int my_print_digits(void);

int my_print_revalpha(void);

void my_put_nbr(int nb);

void my_putchar(char c);

int my_putstr(char const *str);

char *my_revstr(char *str);

int my_showmem(char const *str, int size);

int my_showstr(char const *str);

void my_sort_int_array(int *tab, int size);

int my_str_isalpha(char const *str);

int my_str_islower(char const *str);

int my_str_isnum(char const *str);

int my_str_isprintable(char const *str);

int my_str_isupper(char const *str);

char *my_strcapitalize(char *str);

char *my_strcat(char *dest, char const *src);

int my_strcmp(char *s1, char *s2);

char *my_strcpy(char *dest, char const *src);

int my_strlen(char const *str);

char *my_strlowcase(char *str);

char *my_strncat(char *dest, char const *src, int nb);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strncpy(char *dest, char const *src, int n);

char *my_strstr(char *str, char *to_find);

char *my_strupcase(char *str);

void my_swap(int *a, int *b);

struct info_params *my_params_to_array(int ac, char **av);

char *my_evil_str(char *str);

int my_print_comb2(void);

int mod(int a, int b);

int add(int a, int b);

int sub(int a, int b);

int mul(int a, int b);

char **my_str_to_word_array(char const *str);

void check_ops_len(char const *ops);

void check_base_len(char const *b);

void check_ac_len(int ac, char **av);

void check_op_b(char *b, char *o);

void check_error(int ac, char **av, char *expr);

void check_2_id_nb(char *b);

void check_2_op(char *o);

void check_unmatched_par(char *b, char *expr);

void check_output_size(char **av);

char *infini_add(char *s1, char *s2);

char *addition(char *expr);

int is_operator(char op);

void check_inv_expr(char *expr, char *o);

void check_expr_b(char *expr, char *b, char *o);

char *infini_mul(char *s1, char *s2);

char *multiplication(char *expr);

char *infini_div(char *s1, char *s2);

char *operators_to_letter(char *expr, char **av);

char *base_to_letter(char *expr, char **av);

char *zero_one(int count, char *expr, char **av);

char *two_three(int count, char *expr, char **av);

char *four_five(int count, char *expr, char **av);

char *six_seven(int count, char *expr, char **av);

char *eight_nine(int count, char *expr, char **av);

char *infini_mod(char *s1, char *s2);

void substract(char expr, int *is_nb2, char **final_str, char **nb);

int my_atoi(char *str);

void is_div(char expr, int *is_nb2, char **final_str, char **nb);

void is_mod(char expr, int *is_nb2, char **final_str, char **nb);

void is_mul(char expr, int *is_nb2, char **final_str, char **nb);

char *int_to_char_array(int n, char *final_str);

void my_spe_put_nbr(unsigned int n);

char *integer_to_hex(long int nb, int is_upper);

char *integer_to_oct(long int nb);

char *long_to_hex(unsigned long nb, int is_upper);

char *integer_to_bin(unsigned long nb);

int my_printf(const char *format, ...);

int my_spe_putstr(unsigned char const *str);
