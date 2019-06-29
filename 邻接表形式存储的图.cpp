#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int data;
	struct node *next;
};

int main() {
	int n, u, j, i, v;
	struct node *p, *a[5050];
	while(~scanf("%d", &n)) {
		for(i = 0; i < n; i++)
			a[i] = NULL;
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				scanf("%d", &u);
				if(u == 1) {
					if(a[i] == NULL) {
						p = (struct node *)malloc(sizeof(struct node));
						p -> data = j;
						p -> next = NULL;
						a[i] = p;
					} else {
						p = (struct node *)malloc(sizeof(struct node));
						p -> next = a[i] -> next;
						p -> data = j;
						a[i] -> next = p;
					}
				}
			}
		}
		//
		int q;
		scanf("%d", &q);
		while(q--) {
			scanf("%d%d", &u, &v);
			p = a[u];
			int flag = 0;
			while(p) {
				if(p -> data == v) {
					flag = 1;
					break;
				}
				p = p -> next;
			}
			if(flag)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}

