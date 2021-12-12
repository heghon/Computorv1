/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:04:18 by bmenant           #+#    #+#             */
/*   Updated: 2021/12/12 19:54:41 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/computor.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 1 || argc > 2)
    {
        if (argc > 2)
            cout << "Warning : Too many parameters" << endl;
        cout << "Usage : ./computor <Polynomial equation>" << endl << "        Example : \"a * X^0 + b * x^1 + c * X^2 = d\" " << endl;
    }
    parse(argc, argv[1]);
    return 0;
}