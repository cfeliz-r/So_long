/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:19:14 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/06/26 13:25:35 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

void				ft_bzero1(void *dest, size_t n);
char				*get_next_line(int fd);
char				*ft_strjoin1(char *s1, char *s2);
char				*ft_substr1(char *s, unsigned int start, size_t len);
char				*ft_strchr1(char *str, int c);
size_t				ft_strlen1(char *s);

#endif
