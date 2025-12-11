#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
double area(triangle t) {
    double s = (t.a + t.b + t.c) / 2.0;
    return sqrt(s * (s - t.a) * (s - t.b) * (s - t.c));
}
int cmp(const void *p1, const void *p2) {
    triangle *t1 = (triangle *)p1;
    triangle *t2 = (triangle *)p2;
    double area1 = area(*t1);
    double area2 = area(*t2);

    if (area1 < area2) return -1;
    else if (area1 > area2) return 1;
    else return 0;
}

void sort_by_area(triangle* tr, int n) {
    qsort(tr, n, sizeof(triangle), cmp);
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
