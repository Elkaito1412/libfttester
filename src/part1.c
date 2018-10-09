/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 17:36:40 by abiri             #+#    #+#             */
/*   Updated: 2018/10/09 11:20:30 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../header.h"
#define ERROR(x) startc(RED); printf(x); endc();
#define OK startc(GREEN); printf("[OK] "); endc();
#define STARTED(x) startc(CYAN); printf("\n"); printf(x); printf(" : "); endc();

int main(void)
{
	startc(GREEN);
	printf("-------------------LIBFTTESTER V0.1-----------------\n");
	startc(MAGENTA);
	printf("-:-:-:           testing ft_memset             :-:-:-\n");
/*------testing ft_memset*/
	unsigned char memset_b[15];
	int memset_b_int[] = {0,1};	
	STARTED("FT_MEMSET  ");
	/*testing for function return*/
	if(ft_memset(memset_b, 'O', 15))
	{
		OK;
		/*testing for function replacing*/
		for(int i = 0;i < 15;i++)
		{
			if(*(memset_b + i) != 'O')
			{
				ERROR("[KO] Your ft_memset does not work ");
				break;
			}
			else
				OK;
			break ;
		}
		ft_memset(memset_b_int, '0', 8);
		if(memset_b_int[0] == 808464432 && memset_b_int[1] == 808464432)
		{
			OK;
		}
		else
		{
			ERROR("[KO] Your ft_memset does not work");
		}	
		/*testing for int replacement*/
	}
	else
	{
		ERROR("[KO] Your ft_memset does not return :( ");
	}
/*------testing ft_bzero*/
	STARTED("FT_BZERO   ");
	unsigned char bzero_s[] = "hello";
	/*testing for function result*/
	ft_bzero(bzero_s, 6);
	for (int i = 0;i < 6;i++)
	{
		if (bzero_s[i] != 0)
		{
			ERROR("[KO] Your bzero_s does not work (does not zero) ");
			break ;
		}
		else
		{
			OK;
			break ;
		}
	}
/*------testing ft_memcpy*/
	STARTED("FT_MEMCPY  ");
	char *memcpy_dest = malloc(11);
	const char memcpy_src[] = "hellothere";
	int *memcpy_dest_int = malloc(12);
	const int	memcpy_src_int[] = {1,2,3};
	char *result;
	/*testing for return*/
	if ((result = ft_memcpy(memcpy_dest, memcpy_src, 11)))
	{
		OK;
		/*testing for same address for dest and return*/
		if (result != memcpy_dest)
		{
			ERROR("[KO] Your ft_memcpy does not return dest ");
		}
		else
		{
			OK;
		}
		/*testing if function returns src*/
		if (result == memcpy_src)
		{
			ERROR("[KO] Your ft_memcpy has dest and src pointing to the same address ");
		}
		else
		{
			OK;
		}
		/*testing if function copies every byte*/
		for(int i = 0;i < 11;i++)
		{
			if (memcpy_dest[i] != memcpy_src[i])
			{
				ERROR("[KO] Your ft_memcpy does not copy every byte from src to dest ");
				break ;
			}
			else
			{
				OK;
				break ;
			}
		}
		/*testing with int*/
		ft_memcpy(memcpy_dest_int, memcpy_src_int, 12);
		for(int i = 0;i < 3;i++)
		{
			if (memcpy_dest_int[i] != memcpy_src_int[i])
			{
				ERROR("[KO] Your ft_memcpy does not work with int (may not copy byte by bit) ");
				break ;
			}
			else
			{
				OK;
				break ;
			}
		}
	}
	else
	{
		ERROR("[KO] Your ft_memcpy does not return ");
	}
/*------testing ft_memccpy*/
	STARTED("FT_MEMCCPY ")
		const char memccpy_src[] = "testing";
	char *memccpy_dest = malloc(8);
	result = NULL;
	/*testing the return value*/
	if ((result = ft_memccpy(memccpy_dest, memccpy_src, 'i', 8)))
	{
		OK;
		/*testing if function stops if the specified value is found*/
		for (int i = 0; i < 8; i++)
		{
			if (*(result + i) == 'i')
			{
				ERROR("[KO] your function does not stop at the memory value specified ");
				break ;
			}
			else
			{
				OK;
				break ;
			}
		}
		/*checking if the copying really does take place*/
		for (int i = 0; i < 4 ; i++)
		{
			if (*(memccpy_dest + i) != *(memccpy_src + i))
			{
				ERROR("[KO] your function does not copy every byte ");
				break ;
			}
			else
			{
				OK;
				break ;
			}
		}
	}
	else
	{
		ERROR("[KO] your memccpy does not return the right value ");
	}
/*------testing ft_memmove*/
	STARTED("FT_MEMMOVE ");
	char *memmove_dest = malloc(11);
	const char memmove_src[] = "hellothere";
	int *memmove_dest_int = malloc(12);
	const int   memmove_src_int[] = {1,2,3};
	result = NULL;
	/*testing for return*/
	if ((result = ft_memmove(memmove_dest, memmove_src, 11)))
	{
		OK;
		/*testing for same address for dest and return*/
		if (result != memmove_dest)
		{
			ERROR("[KO] Your ft_memmove does not return dest ");
		}
		else
		{
			OK;
		}
		/*testing if function returns src*/
		if (result == memmove_src)
		{
			ERROR("[KO] Your ft_memmove has dest and src pointing to the same address ");
		}
		else
		{
			OK;
		}
		/*testing if function copies every byte*/
		for(int i = 0;i < 11;i++)
		{
			if (memmove_dest[i] != memmove_src[i])
			{
				ERROR("[KO] Your ft_memmove does not copy every byte from src to dest ");
				break ;
			}
			else
			{
				OK;
				break ;
			}
		}
		/*testing with int*/
		ft_memcpy(memmove_dest_int, memmove_src_int, 12);
		for(int i = 0;i < 3;i++)
		{
			if (memmove_dest_int[i] != memmove_src_int[i])
			{
				ERROR("[KO] Your ft_memmove does not work with int (may not copy byte by bit) ");
				break ;
			}
			else
			{
				OK;
				break ;
			}
		}
	}
	else
	{
		ERROR("[KO] Your ft_memmove does not return ");
	}
/*------testing memchr*/
	STARTED("FT_MEMCHR  ");
	char memchr_s[] = "abcdefedcba";
	int memchr_int = 1651077737;
	int memchr_c_int = 'r';
	int memchr_c = 'e';
	result = NULL;
	/*testing return value*/
	if ((result = ft_memchr(memchr_s, memchr_c, 12)))
	{
		OK;
		/*testing if function stops at first occurence*/
		if (*result != memchr_c && memchr_s != (result - 4))
		{
			ERROR("[KO] your function does not stop at first occurence of c ");
		}
		else
		{
			OK;
		}
		/*testing if functions wotks with int*/
		result = ft_memchr(&memchr_int, memchr_c_int, 4);
		if (result == ((char*)&memchr_int + 1) && *result == 'r')
		{
			OK;
		}
		else
		{
			ERROR("[KO] your function does not work with int (maybe does not compare byte by byte)");
		}
	}
	else
	{
		ERROR("[KO] your return value is NULL ");
	}
/*------testing memcmp*/
	STARTED("FT_MEMCMP  ");
	char memcmp_s1[] = "hello ";
	char memcmp_s2[] = "hello\t";
	int memcmp_int1 = 1651077737;
	int memcmp_int2 = 1651077699;
	int result_int = 0;
	/*testing function return*/
	result_int = ft_memcmp(memcmp_s1, memcmp_s2, 5);
	if (result_int == 0)
	{
		OK;
		/*testing result with str*/
		result_int = ft_memcmp(memcmp_s1, memcmp_s2, 7);
		if (result_int == ' ' - '\t')
		{
			OK;
		}
		else
		{
			ERROR("[KO] your function does not return the correct diff ");
		}
		result_int = ft_memcmp(&memcmp_int1, &memcmp_int2, 4);
		/*testing result with int*/
		if (result_int == 'i' -  'C')
		{
			OK;
		}
		else
		{
			ERROR("[KO] your function does not compare int values (may not compare byte by byte) ")
		}
	}
	else
	{
		ERROR("[KO] your function may not stop at n characters ");
	}
/*------testing strlen*/
	STARTED("FT_STRLEN  ");
	char strlen_s[] = "Hellotheretestthis";
	result_int = 0;
	result_int = ft_strlen(strlen_s);
	/*testing result*/
	if (result_int == 18)
	{
		OK;
	}
	else
	{
		ERROR("[KO] the ength value is wrong ");
	}
/*-------testing strdup*/
	STARTED("FT_STRDUP  ");
	char strdup_src[] = "hello world";
	result = NULL;
	/*testing function return*/
	if ((result = ft_strdup(strdup_src)))
	{
		OK;
		/*testing if result is dest*/
		if (!strcmp(result, strdup_src))
		{
			OK;
		}
		else
		{
			ERROR("[KO] your result is not an exact copy of the original str ");
		}
		/*testing if result is not src*/
		if (result != strdup_src)
		{
			OK;
		}
		else
		{
			ERROR("[KO] your function does not duplicate the source string but returns it ");
		}
	}
	else
	{
		ERROR("[KO] your function returns NULL ");
	}
/*-------testing strcpy*/
	STARTED("FT_STRCPY  ");
	char strcpy_src[] = "hello world";
	char strcpy_dest[12];
	result = 0;
	result = ft_strcpy(strcpy_dest, strcpy_src);
	if (result)
	{
		OK;
		if (!strcmp(strcpy_src, strcpy_dest))
		{
			OK;
		}
		else
		{
			ERROR("[KO] your function does not copy the string correctly ");
		}
		if (strcpy_dest != result)
		{
			ERROR("[KO] your strcpy does not return dest ");
		}
	}
	else
	{
		ERROR("[KO] your function returns NULL ");
	}
/*--------testing strcat*/
	STARTED("FT_STRCAT  ");
	char strcat_1[] = "Hello";
	char strcat_2[] = "World";

}/*End of test*/
