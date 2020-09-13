#include <stdio.h>

void isCorrect(char *expression)
{
    int parentesesAberto = 0, ehCorreto = 0;
    for (int position = 0; expression[position] != '\0'; position++)
    {
        if (expression[position] == ')')
        {
            if (parentesesAberto == 0)
            {
                // equação incorreta
                ehCorreto = 0;
                break;
            }
            else
            {
                parentesesAberto--;
                ehCorreto++;
            }
        }
        else if (expression[position] == '(')
        {
            // equação ainda válida mas não 100% correta
            parentesesAberto++;
            ehCorreto = 0;
        }
    }
    
    (ehCorreto && (parentesesAberto == 0))? printf("correct\n") : printf("incorrect\n");
}

int main()
{
    int position = 0;
    char input = '\0', expression[1001] = {0};
    
    while ((input = getchar()) != EOF)
    {
        expression[position] = input;
        position++;
        if (input == '\0')
        {
            isCorrect(expression);
            position = 0;
        }
    }

    return 0;
}
