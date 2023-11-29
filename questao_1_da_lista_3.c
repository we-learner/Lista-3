#include <stdio.h>
#include <string.h>

int valor(char c)
{
  switch (c)
  {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
  }
}

int romano_para_decimal(char *romano)
{
  unsigned int i, n = 0;
  for (i = 0; i < strlen(romano); i++)
  {
    int v1 = valor(romano[i]);
    int v2 = valor(romano[i+1]);

    if (v1 >= v2)
    {
      n += v1;
    }

    else
    {
      n -= v1;
    }
  }
  return n;
}

void imprimir_base(int n, int base)
{
  char algarismos[] = "0123456789abcdef";
  char resultado[32];
  int i = 0;

  while (n > 0)
  {
    resultado[i] = algarismos[n % base];
    n /= base;
    i++;
  }

  for (i = i - 1; i >= 0; i--)
  {
    printf("%c", resultado[i]);
  }
  
  printf("\n");
}

int main()
{
  char romano[13];
  int decimal;
  scanf("%s", romano);
  decimal = romano_para_decimal(romano);
  printf("%s na base 2: ", romano);
  imprimir_base(decimal, 2);
  printf("%s na base 10: %d\n", romano, decimal);
  printf("%s na base 16: ", romano);
  imprimir_base(decimal, 16);
  return 0;
}