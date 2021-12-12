/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:30:26 by bmenant           #+#    #+#             */
/*   Updated: 2021/12/12 19:57:45 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/computor.h"

using namespace std;

void parse(int paramNbr, char param[])
{
    cout << "there is " <<  paramNbr - 1 << " argument for this program and it is  : \"" << param << "\"" << endl;
}