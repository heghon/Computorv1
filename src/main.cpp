/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:04:18 by bmenant           #+#    #+#             */
/*   Updated: 2021/12/17 19:53:18 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/computor.h"
#include "../inc/Equation.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 1 || argc > 2)
    {
        if (argc > 2)
            cout << "Warning : Too many parameters" << endl;
        cout << "Usage : ./computor <Polynomial equation>" << endl << "        Example : \"a + b * X + c * X^2 = d\" " << endl;
    }
    if (argc == 2)
        parse(argc, argv[1]);

    bool test[] = {true, true};
    if (test[2])
        cout << "done" << test;
    return 0;
}