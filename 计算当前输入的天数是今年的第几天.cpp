#include<stdio.h>

main() {
	int year,month,day,daysum,i,p,n=0;
	int arry[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
	int checkyear(int year);
	scanf("%d",&p);
	int group[p];
	while(p) {
		scanf("%d%d%d",&year,&month,&day);
		daysum=0;
		if(checkyear(year)) {
			for(i=0; i<month-1; i++) {
				daysum+=arry[i];
			}
			if(month>=2) day+=1;
			daysum+=day;
		} else {
			for(i=0; i<month-1; i++)
			{
				daysum+=arry[i];
			}
			daysum+=day;
		}
		group[n++]=daysum;
		p--;
	}
	for(i=0; i<n; i++) printf("%d\n",group[i]);
}
int checkyear(int year) {
	if((year%100)&&(year%4==0)||year%400==0) {
		return 1;
	} else {
		return 0;
	}
}
