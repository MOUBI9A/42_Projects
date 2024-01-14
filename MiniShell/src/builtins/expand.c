/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:10:16 by hel-moue          #+#    #+#             */
/*   Updated: 2023/12/14 02:10:16 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	chi_haja(t_tools k, char **result,
	size_t *resultindex, t_Environment *env)
{
	const char	*afterdollarpos;
	size_t		varnamelength;
	char		*varname;
	char		*envvalue;

	afterdollarpos = k.input + k.i + 1;
	varnamelength = 
		ft_strcspn_helmoue(afterdollarpos, " =:-;\t\n\"\\'+!$/@#%^&(){}[]<>");
	varname = malloc(varnamelength + 1);
	if (varname == NULL)
		exit(EXIT_FAILURE);
	strncpy(varname, afterdollarpos, varnamelength);
	varname[varnamelength] = '\0';
	envvalue = get_get_env_var(env, varname);
	if (envvalue != NULL)
	{
		ft_some(result, resultindex, (ft_strlen_helmoue(envvalue) + 1));
		ft_strcpy(*result + *resultindex, envvalue);
		*resultindex = *resultindex + ft_strlen_helmoue(envvalue);
	}
	free(varname);
	varname = NULL;
	return (k.i + varnamelength);
}

void	ft_ft2(char *result, size_t *resultindex, char *input, size_t *i)
{
	ft_some(&result, resultindex, 1);
	result[*resultindex] = input[*i];
	(*resultindex)++;
	(*i)++;
}

typedef struct s_norm	t_norm;

struct s_norm
{
	size_t	i;
	char	*result;
};

int	norm_cond(char *input, size_t i)
{
	return (input[i] == '$' && input[i + 1] != '\0' && rr(input, i) == 1);
}

char	*ft_ft(t_tools k, t_Environment *env, size_t i, t_norm norm)
{
	while (++k.i < i)
	{
		if (norm_cond(k.input, k.i) == 1)
		{
			if (handel_specialcase(&k, &norm.result, &norm.i, env) == 1)
			{
				continue ;
			}
			else if (ft_con(k.input, k.i) == 1)
				k.i = chi_haja(k, &norm.result, &norm.i, env);
			else
			{
				ft_some(&norm.result, &norm.i, 1);
				norm.result[norm.i++] = k.input[k.i];
			}
		}
		else
		{
			ft_some(&norm.result, &norm.i, 1);
			norm.result[norm.i++] = k.input[k.i];
		}
	}
	ft_some(&norm.result, &norm.i, 1);
	norm.result[norm.i] = '\0';
	return (norm.result);
}

char	*replace_env_var(char *input, t_Environment *env)
{
	size_t	inputlength;
	t_tools	k;
	t_norm	norm;

	k.i = -1;
	k.input = input; 
	inputlength = ft_strlen_helmoue(input);
	norm.result = malloc(inputlength + 1);
	norm.i = 0;
	return (ft_ft(k, env, inputlength, norm));
}
