  #include <stdio.h>
  int main(void)
  {
      int ret;

      ret = printf("Test: %");
      printf("\nRetour: %d\n", ret);

      ret = printf("Test: %\n");
      printf("Retour: %d\n", ret);
  }
