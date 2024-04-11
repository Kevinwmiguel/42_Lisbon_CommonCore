/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:02:04 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/11 10:02:05 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strncmp(const char *s1, const char *s2, size_t n) {
    size_t i = 0;

    while (i < n && (s1[i] != '\0' || s2[i] != '\0')) {
        if (s1[i] > s2[i])
            return 1;
        else if (s1[i] < s2[i])
            return -1;
        i++;
    }

    if (i < n) {
        if (s1[i] == '\0')
            return -1; // s1 é mais curto que s2
        else
            return 1; // s1 é mais longo que s2
    }

    return 0;
}