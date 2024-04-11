/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:02:29 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/11 10:02:35 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return i;    
}

char *ft_strtrim(char const *s1, char const *set)
{
    int i;
    int j;

    i = 0;
    int size = ft_strlen(s1);
    char *nova = (char *)malloc(size + 1);
    while(s1[i] != '\0')
    {
        j = 0;
        while(set[j] != '\0')
        {
            if (s1[i] != set[j])
            {
                nova[i] = s1[i];
            }
            j++;
        }
        i++;
    }
    nova[i] != '\0';
    return nova;
}