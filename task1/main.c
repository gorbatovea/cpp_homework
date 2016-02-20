#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int x1,x2,y1,y2;
    n++;
    scanf("%d",&x1);
    int *ptrTable;
    ptrTable = (int *) malloc(n * n * sizeof(int));
    while(x1 != 0) {
        scanf("%d %d %d", &y1, &x2, &y2);
        for (int i = y1; i <= y2; i++) {
            for (int j = x1; j <= x2; j++) {
                *(ptrTable + i * n + j) = i * j;
            }
        }

        for (int i = y1; i <= y2; i++) {
            for (int j = x1; j <= x2; j++) {
                printf("%d ", *(ptrTable + i * n + j));
            }
            printf("\n");
        }
        scanf("%d",&x1);
    }
        free(ptrTable);
        return 0;
}
