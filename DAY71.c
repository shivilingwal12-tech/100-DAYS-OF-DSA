/*Problem Statement Implement a hash table using quadratic probing with formula: h(k, i) = (h(k) + i*i) % m*/


#include <stdio.h>
#include <string.h>

int table[100];

int hash(int key, int m) {
    return key % m;
}

void insert(int key, int m) {
    int h = hash(key, m);
    int i = 0;

    while (i < m) {
        int idx = (h + i * i) % m;
        if (table[idx] == -1) {
            table[idx] = key;
            return;
        }
        i++;
    }
}

void search(int key, int m) {
    int h = hash(key, m);
    int i = 0;

    while (i < m) {
        int idx = (h + i * i) % m;

        if (table[idx] == -1) {
            printf("NOT FOUND\n");
            return;
        }

        if (table[idx] == key) {
            printf("FOUND\n");
            return;
        }

        i++;
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, q;

    printf("Enter table size: ");
    scanf("%d", &m);

    printf("Enter number of operations: ");
    scanf("%d", &q);

    for (int i = 0; i < m; i++) {
        table[i] = -1;
    }

    char op[10];
    int key;

    printf("Enter operations (INSERT key / SEARCH key):\n");

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key, m);
        }
    }

    return 0;
}