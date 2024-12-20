#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100  // Maksimalniy razmer steka

typedef struct {
    int arr[MAX];  // Massiv dlya hraneniya elementov steka
    int top;       // Indeks vershini steka
} Stack;

// Inicializaciya steka
void init(Stack* s) {
    s->top = -1;  // Ustanavlivaem vershinu steka v -1, chto ozna4aet, chto stek pust
}

// Proverka, pust li stek
int is_empty(Stack* s) {
    return s->top == -1;  // Esli vershina steka ravna -1, to stek pust
}

// Proverka, polon li stek
int is_full(Stack* s) {
    return s->top == MAX - 1;  // Esli vershina steka ravna MAX - 1, to stek polon
}

// Dobavlenie elementa v stek
void push(Stack* s, int value) {
    if (is_full(s)) {
        printf("Perepolnenie steka\n");  // Esli stek polon, vyvodim soobchenie ob oshibke
        return;
    }
    s->arr[++s->top] = value;  // Uvelichivaem verhinu steka i dobavlyaem element
}

// Udalenie elementa iz steka
int pop(Stack* s) {
    if (is_empty(s)) {
        printf("Stek pust\n");  // Esli stek pust, vyvodim soobchenie ob oshibke
        return -1;  // Vozvras4aem -1 kak indikator oshibki
    }
    return s->arr[s->top--];  // Vozvras4aem element s vershini steka i umenshaem vershinu
}

// Prosmotr elementa na vershine steka
int peek(Stack* s) {
    if (is_empty(s)) {
        printf("Stek pust\n");  // Esli stek pust, vyvodim soob6enie ob oshibke
        return -1;  // Vozvras4aem -1 kak indikator oshibki
    }
    return s->arr[s->top];  // Vozvras4aem element s vershini steka
}

// Vyvod soderzhimogo steka
void print_stack(Stack* s) {
    if (is_empty(s)) {
        printf("Stek pust\n");  // Esli stek pust, vyvodim soobchenie
        return;
    }
    printf("Stek: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);  // Vyvodim elementy steka ot osnovaniya do verhini
    }
    printf("\n");
}

// Testirovanie steka
void run_tests() {
    Stack s;
    init(&s);  // Inicializiruem stek

    // Test 1: Dobavlenie elementov i vyvod steka
    printf("Test 1: Dobavlenie elementov i vyvod steka\n");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    print_stack(&s);  // Ozhidaemyi vyvod: Stek: 10 20 30

    // Test 2: Udalenie elementa i vyvod steka
    printf("Test 2: Udalenie elementa i vyvod steka\n");
    printf("Udaleno: %d\n", pop(&s));  // Ozhidaemyi vyvod: Udaleno: 30
    print_stack(&s);  // Ozhidaemyi vyvod: Stek: 10 20

    // Test 3: Prosmotr elementa na vershine steka
    printf("Test 3: Prosmotr elementa na vershine steka\n");
    printf("Verhniy element: %d\n", peek(&s));  // Ozhidaemyi vyvod: Verhniy element: 20

    // Test 4: Proverka, pust li stek
    printf("Test 4: Proverka, pust li stek\n");
    printf("Stek pust? %s\n", is_empty(&s) ? "Da" : "Net");  // Ozhidaemyi vyvod: Stek pust? Net

    // Test 5: Udalenie vseh elementov i proverka, pust li stek
    printf("Test 5: Udalenie vseh elementov i proverka, pust li stek\n");
    pop(&s);
    pop(&s);
    print_stack(&s);  // Ozhidaemyi vyvod: Stek pust
    printf("Stek pust? %s\n", is_empty(&s) ? "Da" : "Net");  // Ozhidaemyi vyvod: Stek pust? Da

    // Test 6: Dobavlenie elementov do perepolneniya steka
    printf("Test 6: Dobavlenie elementov do perepolneniya steka\n");
    for (int i = 0; i < MAX; i++) {
        push(&s, i);
    }
    print_stack(&s);  // Ozhidaemyi vyvod: Stek: 0 1 2 ... 99
    push(&s, 100);  // Ozhidaemyi vyvod: Perepolnenie steka

    // Test 7: Udalenie vseh elementov i proverka, pust li stek
    printf("Test 7: Udalenie vseh elementov i proverka, pust li stek\n");
    for (int i = 0; i < MAX; i++) {
        pop(&s);
    }
    print_stack(&s);  // Ozhidaemyi vyvod: Stek pust
    printf("Stek pust? %s\n", is_empty(&s) ? "Da" : "Net");  // Ozhidaemyi vyvod: Stek pust? Da

    // Test 8: Popytka udaleniya iz pustogo steka
    printf("Test 8: Popytka udaleniya iz pustogo steka\n");
    int result = pop(&s);
    if (result == -1) {
        printf("Stek pust\n");  // Ozhidaemyi vyvod: Stek pust
    }
    else {
        printf("Udaleno: %d\n", result);
    }
}

int main() {
    run_tests();  // Zapusk testov
    return 0;
}
