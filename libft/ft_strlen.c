/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:58:33 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/11 09:58:35 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    ft_istrlen(char *str)
{
    int     i;

    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}
