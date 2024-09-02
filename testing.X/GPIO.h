#ifndef GPIO_H
#define GPIO_H

#define IN   0
#define OUT  1
void SET_PIN(char *ddr, int n, int dir);
void PIN_WRITE(char *port, int n, int val);
int PIN_READ(char *pin, int n);

#endif /* GPIO_H */