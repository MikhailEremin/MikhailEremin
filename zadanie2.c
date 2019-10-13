#include <stdio.h>
#include <stdlib.h>


int main() {
    int i = 0, s1 = 0, s2 = 0;
    char n, m;
    char *a = NULL;
    FILE *graphfile = fopen("graphfile.dot", "w");
    if (graphfile == NULL) {
        printf("file ne otkrit");
        exit(0);
    } else {
        printf("Graph: \n1.neor \n2.or \n");
        m = (char) getchar();
        switch (m) {
        case 49:
            fputs("graph G { ", graphfile);
            break;
        case 50:
            fputs("digraph G { ", graphfile);
            break;
        default:

            printf("error \n");
            exit(0);


        }

        printf("describe your graph: \n");

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
}
    fputs(" }", graphfile);
    fclose(graphfile);
    system("C:\\Users\\Alex\\Desktop\\release\\bin\\graphfile.dot Graphviz2.38 ");

}
