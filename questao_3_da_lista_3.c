#include <stdio.h>
#include <string.h>
#include <ctype.h>

int placa_valida(char placa[])
{
  int tam = strlen(placa);
  int i;
  int letras = 0;
  int numeros = 0;
  int hifen = 0;

  if (tam != 7 && tam != 8)
  {
    return 0;
  }

  for (i = 0; i < tam; i++)
  {
    if (isalpha(placa[i]))
    {
      letras++;
    }
    else if (isdigit(placa[i]))
    {
      numeros++;
    }
    else if (placa[i] == '-')
    {
      hifen++;
    }
    else
    {
      return 0;
    }
  }

  if (letras == 3 && numeros == 4 && hifen == 1 && placa[3] == '-')
  {
    return 1;
  }

  if (letras == 4 && numeros == 3 && hifen == 0)
  {
    return 1;
  }

  return 0;
}

int dia_valido(char dia[])
{
  char dias[7][15] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};
  int i;

  for (i = 0; i < 7; i++)
  {
    if (strcmp(dia, dias[i]) == 0)
    {
      return 1;
    }
  }

  return 0;
}

int pode_circular(char placa[], char dia[])
{
  int ultimo_num;
  int tam = strlen(placa);

  ultimo_num = placa[tam - 1] - '0';

  if (strcmp(dia, "SABADO") == 0 || strcmp(dia, "DOMINGO") == 0)
  {
    return 1;
  }

  if (strcmp(dia, "SEGUNDA-FEIRA") == 0)
  {
    if (ultimo_num == 0 || ultimo_num == 1)
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }

  if (strcmp(dia, "TERCA-FEIRA") == 0)
  {
    if (ultimo_num == 2 || ultimo_num == 3)
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }

  if (strcmp(dia, "QUARTA-FEIRA") == 0)
  {
    if (ultimo_num == 4 || ultimo_num == 5)
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }

  if (strcmp(dia, "QUINTA-FEIRA") == 0)
  {
    if (ultimo_num == 6 || ultimo_num == 7)
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }

  if (strcmp(dia, "SEXTA-FEIRA") == 0)
  {
    if (ultimo_num == 8 || ultimo_num == 9)
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }

  return -1;
}

int main()
{
  char placa[10];
  char dia[15];
  int resultado;

  scanf("%s", placa);
  scanf("%s", dia);

if (placa_valida(placa) == 0)
{
  printf("Placa invalida\n");
}

if (dia_valido(dia) == 0)
{
  printf("Dia da semana invalido\n");
}

else
{
  if (placa_valida(placa) == 1)
  {
    resultado = pode_circular(placa, dia);

    if (resultado == 1)
    {
      if (strcmp(dia, "SABADO") == 0 || strcmp(dia, "DOMINGO") == 0)
      {
        printf("Nao ha proibicao no fim de semana\n");
      }
      else
      {
        strlwr(dia);
        printf("%s pode circular %s\n", placa, dia);
      }
    }
    
    else if (resultado == 0)
    {
      strlwr(dia);
      printf("%s nao pode circular %s\n", placa, dia);
    }
  }
}

  return 0;
}