/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 11:48:22 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 19:18:40 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# define BUFF_SIZE 32

typedef struct		s_rest
{
	char			*rest;
	int				fd;
	struct s_rest	*next;
}					t_rest;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_lstr
{
	char			*str;
	int				l;
	struct s_lstr	*next;
}					t_lstr;

typedef struct		s_date
{
	int				year;
	int				month;
	int				day;
	int				hour;
	int				minute;
	int				second;
}					t_date;

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

t_date				*ft_date(long t);

void				ft_lstadd(t_list **alst, t_list *newb);
int					ft_lstaddback(t_list **begin_list, void *data,
		size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
int					ft_lstraddback(t_lstr **begin_list, char *data, int l);
void				ft_lstrclr(t_lstr *lst);
t_lstr				*ft_lstrnew(char *str, int l);

long long			ft_abs(long long nbr);
unsigned long long	ft_pow(long long n, int exp);
long double			ft_round(long double n, int decimal);
int					ft_sqrt(int nb);

void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);

int					ft_atoi(const char *nptr);
char				*ft_ftoa(long double n, int decimal, int z);
int					ft_intlen(int n);
char				*ft_itoa(long long n);
char				*ft_ttob(unsigned long long n, int base);
int					ft_uintlen(unsigned int n);
char				*ft_uitoa(unsigned long long n);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(long long n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putunbr(unsigned int n);

int					get_next_line(const int fd, char **line);
char				*ft_strbase(int n);
char				*ft_strcat(char *dest, const char *src);
int					ft_strchar(char *s, char c);
int					ft_strchar_last(char *s, char c);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strinit(char c, size_t len);
int					ft_strins(char *str, char *ins, int start);
int					ft_stris(char *s, int (*f)(int));
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strnchr(const char *s, int end, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrep(char *src, char *newb);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);

#endif
