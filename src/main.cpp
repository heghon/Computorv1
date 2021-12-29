/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:04:18 by bmenant           #+#    #+#             */
/*   Updated: 2021/12/29 16:55:41 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/computor.h"
#include "../inc/Equation.h"

using namespace std;

int main(int argc, char *argv[])
{
    int parseNbr;

    if (argc == 1 || argc > 2)
    {
        if (argc > 2)
            cout << "Warning: Too many parameters" << endl;
        cout << "Usage: ./computor <Polynomial equation>" << endl << "        Example : \"a + b * X + c * X^2 = d\" " << endl;
        return 0;
    }

    parseNbr = parse(argc, argv[1]);
    Equation eq(argv[1]);
    
    if (argc == 2 && parseNbr >= 0 && parseNbr < 3) 
    {
        if (eq.equationInTwoTabs())
        {
            eq.handleCoeff();
            eq.showReducedForm();
            eq.showPolynomialDegree();
        }
    }
    else if (parseNbr > 2 && eq.equationInTwoTabs())
    {
        
        if (parseNbr == 3)
        {
            eq.handleCoeff();
            eq.showReducedForm();
            eq.showPolynomialDegree();
            cout << "The polynomial degree is strictly greater than 2, I can't solve." << endl;
        }
        else
        {
            cout << "Polynomial degree > 3" << endl;
            cout << "The polynomial degree is strictly greater than 3, I can't solve (and I won't show you the reduced form, please consider my capacities)." << endl;
        }
    }
    else
    {
        cout << "Your equation is poorly constructed." << endl
            << "Please follow this example: \"a + b * X + c * X^2 = d + e * X + f * X^2\"." << endl
            << "Respect the spaces and the order: X^0, then X, then X^2." << endl;
    }

    return 0;
}