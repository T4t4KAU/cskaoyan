#include <iostream>

using namespace std;

typedef struct Node {
    float co;
    int ex;
    struct Node *next;
} *Polynomial;

// 多项式相加
Polynomial addPoly(Polynomial A, Polynomial B) {
    Polynomial C = new struct Node;
    Polynomial p = C;

    while (A != NULL && B != NULL) {
        Polynomial x = new struct Node;
        x->next = NULL;

        if (A->ex < B->ex) { // A的指数小于B的指数
            x->ex = A->ex;
            x->co = A->co;
            A = A->next;
        } else if (A->ex > B->ex) { // A的指数大于B的指数
            x->ex = B->ex;
            x->co = B->co;
            B = B->next;
        } else { // AB指数相等 合并同类项
            x->ex = B->ex;
            x->co = A->co + B->co;
            A = A->next;
            B = B->next;
        }

        p->next = x;
        p = p->next;
    }

   if (A != NULL) {
        p->next = A;
    }

    if (B != NULL) {
        p->next = B;
    }

    return C->next;
}