/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:30:16 by bmenant           #+#    #+#             */
/*   Updated: 2021/12/19 17:44:58 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_FUNCTIONS_H
# define COMPUTOR_FUNCTIONS_H

void parse(int paramNbr, char param[]);
bool strPotentialD(std::string str);
bool orderCheck(std::vector<std::string>);
void badParsing();

#endif