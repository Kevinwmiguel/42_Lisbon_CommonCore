/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:01:36 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/18 10:56:08 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*string;

	len = ft_strlen(str);
	i = 0;
	string = (char *)malloc(len + 1);
	if (!string)
		return (NULL);
	while (i < len)
	{
		string[i] = str[i];
		i++;
	}
	string[len] = '\0';
	return ((char *)string);
}
// int main() {
//     const char *original = "Hello, world!";
//     char *copied = strdup(original);

//     if (copied != NULL) {
//         printf("String original: %s\n", original);
//         printf("String copiada: %s\n", copied);

//         // Não se esqueça de liberar a memória alocada
//         free(copied);
//     } else {
//         printf("Falha ao copiar a string.\n");
//     }

//     return 0;
// }