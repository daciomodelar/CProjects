#ifndef UTILS_H
#define UTILS_H

void print_utf8(const char *str, int width);
void sanitize_string(char *str);
void to_lower_case(char *str);
long long now_ms();
long long now_ns();

#endif