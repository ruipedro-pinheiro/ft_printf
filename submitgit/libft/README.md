# Libft - Ma bibliothèque C personnalisée

Premier projet du cursus de 42 Lausanne. Reconstruction de fonctions de la bibliothèque standard C.

## Description

Libft est une bibliothèque C contenant des réimplémentations de fonctions standard (libc) ainsi que des fonctions utilitaires supplémentaires. Ce projet permet de comprendre en profondeur le fonctionnement de la gestion mémoire et des structures de données en C.

## Fonctions implémentées

### Partie 1 - Fonctions de la libc
- Manipulation de chaînes : ft_strlen, ft_strcpy, ft_strdup, ft_strjoin, etc.
- Manipulation de mémoire : ft_memset, ft_memcpy, ft_memmove, ft_calloc
- Conversion : ft_atoi, ft_itoa
- Tests de caractères : ft_isalpha, ft_isdigit, ft_isalnum, etc.

### Partie 2 - Fonctions supplémentaires
- ft_substr, ft_strtrim, ft_split
- ft_strmapi, ft_striteri
- ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd

## Compilation
```bash
make        # Compile la bibliothèque
make clean  # Supprime les fichiers objets
make fclean # Supprime tout
make re     # Recompile tout
```

## Utilisation
```c
#include "libft.h"

int main(void)
{
    char *str = ft_strdup("Hello 42");
    ft_putendl_fd(str, 1);
    free(str);
    return (0);
}
```

## Projet 42

Projet réalisé dans le cadre du cursus de 42 Lausanne.
Score : 100/100
