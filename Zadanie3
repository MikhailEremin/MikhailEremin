#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main() {
    setlocale (LC_ALL, "Russian");
        int s1 = 0, s2 = 0, s3 = 0, f, z = 0, j = 0, k = 0, h = 0, q = 0, i = 0;
            char n, m;
                char *a = NULL, *b = NULL;
                    FILE *graphfile = fopen("graphfile.dot", "w");
                if (graphfile == NULL) {
            printf("Файл не открыт");
        exit(0);
    } else {
            printf("Ваш Граф: \n1.Неориентированный \n2.Ориентированный \n");
                m = (char) getchar();
                    switch (m) {
                        case 49:
                    fputs("graph G { ", graphfile);
                break;
            case 50:
                fputs("digraph G { ", graphfile);
            break;
        default:

                printf("Ошибка\n");
            exit(0);


        }
        printf("Граф является простым: \n1.Да \n2.Нет \n");
        scanf("%d",&f);
        switch (f) {
        case 1:
            {

                printf("Опишите граф: \n");

    			getchar();
    			while (n != '\n')
				{
                        n = (char) getchar();
                        if (n=='-' or n=='>'){
						s2++;
					}
                            if (n!='-' and n!=' ' and n!='>' and n!=';'){
                                b = (char *) realloc(b, (j + 1) * sizeof(char));
                                    b[j] = n;
                                j++;
    				}
    				a = (char *) realloc(a, (i + 1) * sizeof(char));
                        a[i] = n;
   					i++;
    			}
                   for (k = 0 ; k < j-1; k++){
                            printf ("%c",b[k]);
                                q=0;
                            for (h = k+1; h<j; h++){
                        if (b[k] == b[h]){
                    q=1;
					}
				}
				if (q==0){
					s1++;
				}
			}
            printf ("\n");
                for (int tmp = 0; tmp < i; tmp++)
			{
    			putc(a[tmp], graphfile);
    		}
    			float x = 0, y=0;
                    y=s2/2;
                        x=((s1-1)*(s1-2))/2;
    		if (y > x){
   				printf("Граф является связным. \n ");
			}
			else {
				printf("Граф не является связным. \n ");
			}
            break;
            }
            case 2:
            	{
                printf("Опишите граф: \n");
                    getchar();
    			while (n != '\n')
				{
    				n = (char) getchar();
                        a = (char *) realloc(a, (i + 1) * sizeof(char));
                        a[i] = n;
    				i++;
    			}
                    for (int tmp = 0; tmp < i; tmp++)
				{
    				putc(a[tmp], graphfile);
    			}
                    break;
            	}
                default:
                    printf("Ошибка\n");
            exit(0);
        }

    fputs(" }", graphfile);
    fclose(graphfile);
    system("C:\\Users\\Vano\\Desktop\\release\\bin\\gvedit.exe graphfile.dot");
        }
    }
