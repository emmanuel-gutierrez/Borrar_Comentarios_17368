#include <stdio.h>
#include <string.h>

int main ()
{
    FILE *resultado;
    FILE *origen;
    char c;

    resultado = fopen("archivo_escribir.txt", "w");
    origen = fopen("archivo_leer.txt", "r");
    if ( origen == NULL){
        printf("Error abriendo el archivo\n");
        return 1;
    }
    while((c=getc(origen)) != EOF)
    {
        if (c == '/')
        {
            if ( c == '*')
            {
                c=getc(origen);
                bookmark:while( c != '*')
                {
                     c=getc(origen);
                }
                c=getc(origen);
                if (c!= '/')
                    goto bookmark;
            }

            else if(c == '/')
            {
                c=getc(origen);
                while (c != '\n')
                {
                     c=getc(origen);
                }
            }
            else
            {
             putc(c,resultado);
            }
        }
        putc(c,resultado);
    }

    fclose(origen);
    fclose(resultado);
    printf("Creacion de nuevo archivo sin comentarios exitosa\n");
    return 0;
}
