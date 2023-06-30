#include "libft.h"
#include <string.h>

 int main()
 {
    char *str = strdup("hello world whatever");
    ft_replace(&str, "world", "wwdefreg");
    printf("%s\n", str);
 }