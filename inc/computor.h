/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:30:16 by bmenant           #+#    #+#             */
/*   Updated: 2022/01/20 21:37:39 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_FUNCTIONS_H
# define COMPUTOR_FUNCTIONS_H

bool strPotentialD(std::string str, bool first);
bool strPotentialPositiveI(std::string str);
int badParsing();
bool argHandler(int nbr, char **tab);
int niceHandler(int argc, char **argv);
int simpleHandler(int argc, char **argv);

#endif