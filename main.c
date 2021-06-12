#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

typedef char *string;

int
GetInt(void);

string
GetString(void);

int
main(int argc, char *argv[])
{

    printf("\nDigite o texto: ");
    string texto;
    texto = GetString();

    printf("\nDigite um número: ");
    int chave;
    chave = GetInt();

    printf("\nO texto decifrado: ");

    for(int i = 0; i < strlen(texto); i++)
    {    
        if((texto[i] >= 65 && texto[i] <= 90) || (texto[i] >= 97 && texto[i] <= 122))
        {
            if(chave > 26)
            {
                int modulo = chave % 26;
                int soma = texto[i] + modulo;

                if(soma > 122 || ((soma > 90 && soma < 116) && isupper(texto[i])))
                {
                    printf("%c",soma - 26);
                }
                else if((soma >= 97 && soma <= 122) || (soma >= 65 && soma <= 90))
                {
                    printf("%c",soma);
                }
            }
            else if(chave < 26 && chave > 0)
            {
                int soma = texto[i] + chave;
                
                if(soma > 122 || (soma > 90 && soma < 97))
                {
                    printf("%c",soma - 26);
                }
                else if((soma <= 122 && soma >= 97) || (soma <= 90 && soma >= 65))
                {
                    printf("%c",soma);
                }
            }
            else 
            {
                return 1;
            }
        }
        else
        {
            printf("%c",texto[i]);
        }
    }
    return 0;
}