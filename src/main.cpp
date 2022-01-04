/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:04:18 by bmenant           #+#    #+#             */
/*   Updated: 2022/01/04 18:41:44 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/computor.h"
#include "../inc/Parser.h"
#include "../inc/Equation.h"
#include "../inc/Solver.h"

using namespace std;

int badParsing()
{
    cout << "Your equation is poorly constructed." << endl
            << "Please follow this example: \"a + b * X + c * X^2 = d + e * X + f * X^2\"." << endl
            << "Respect the spaces and the order: X^0, then X, then X^2." << endl;
    return 0;
}

bool strPotentialD(string str)
{
    bool point = false;

    for (int i(0); i < (int)str.size(); i++)
    {
        if (str[i] == '.' && point)
            return false;
        else if (str[i] == '.' && !point)
            point = true;
        else if (!isdigit(str[i]))
            return false;
    }
    // cout << "strPotentialD : true returned for " << str << endl;
    return true;
}

int main(int argc, char *argv[])
{
    int parseNbr(-1);

    if (argc == 1 || argc > 2)
    {
        if (argc > 2)
            cout << "Warning: Too many parameters" << endl;
        cout << "Usage: ./computor <Polynomial equation>" << endl << "        Example : \"a + b * X + c * X^2 = d\" " << endl;
        return 0;
    }

    Parser p(argv[1]);

    if (p.equationInTwoTabs() && p.parseConstruct() && p.parseOrder() && p.parseCheckX() >= 0)
    {
        // p.showTheEquation();
        parseNbr = p.parseCheckX();
    }
    else
        return badParsing();

    if (argc == 2 && parseNbr >= 0 && parseNbr < 3) 
    {
        Equation eq(argv[1], p.getLeftOpe(), p.getRightOpe());
        eq.handleCoeff();
        eq.showReducedForm();
        eq.showPolynomialDegree();

        Solver s(eq.getFinalCoeff());
        // s.showCoeff();
        s.solveEquation();
    }
    else if (parseNbr > 2)
    {
        
        if (parseNbr == 3)
        {
            Equation eq(argv[1], p.getLeftOpe(), p.getRightOpe());
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