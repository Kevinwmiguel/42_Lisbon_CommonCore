/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:01:02 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/11 10:01:03 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_memcmp(const void * ptr1, const void *ptr2, size_t num)
{
    const unsigned char *p = ptr1;
    const unsigned char *s = ptr2;

    while(num > 0)
    {
        if (p[num - 1] < s[num - 1])
        {
            return -1;
        } else if(p[num - 1] > s[num - 1])
        {
            return 1;
        }
        num--;
    }
    return 0;
}