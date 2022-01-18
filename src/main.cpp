/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:04:18 by bmenant           #+#    #+#             */
/*   Updated: 2022/01/18 17:21:49 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/computor.h"
#include "../inc/Parser.h"
#include "../inc/Equation.h"
#include "../inc/Solver.h"
#include "../inc/Parsersimplified.h"
#include "../inc/Equationsimplified.h"

using namespace std;

int badParsing()
{
    cout << "Your equation is poorly constructed." << endl
            << "Please follow this example: \"a + b * X + c * X^2 = d + e * X + f * X^2\"." << endl
            << "Respect the spaces." << endl << endl;
    return 0;
}

bool strPotentialD(string str, bool first)
{
    bool point = false;

    for (int i(0); i < (int)str.size(); i++)
    {
        if (i == 0 && first == true && str[i] == '-')
            point = false;
        else if (i > 0 && str[i] == '.' && point)
            return false;
        else if (i > 0 && str[i] == '.' && !point)
            point = true;
        else if (!isdigit(str[i]))
            return false;
    }
    cout << "strPotentialD : true returned for " << str << " and the first is " << first << endl;
    return true;
}

bool argHandler(int nbr, char **tab)
{
    if (nbr == 1 || nbr > 3)
    {
        if (nbr > 3)
            cout << "Warning: Too many parameters" << endl;
        cout << "Usage: ./computor (-n) <Polynomial equation>" << endl 
            << "        Example : \"a * X^0 + b * X^1 + c * X^2 = d\"" << endl 
            << "        Example natural : \"a + b * X + c * X^2 = d\" " << endl << endl;
        return false;
    }
    if (nbr == 3 && strncmp(tab[1], "-n", 2))
    {
        cout << "Warning: parameters are not correctly implemented" << endl;
        cout << "Usage: ./computor (-n) <Polynomial equation>" << endl 
            << "        Example : \"a * X^0 + b * X^1 + c * X^2 = d\"" << endl 
            << "        Example natural : \"a + b * X + c * X^2 = d\" " << endl << endl;
        return false;
    }
    return true;
}

int niceHandler(int argc, char **argv)
{
    int parseNbr(-1);

    Parser p(argv[2]);

    if (p.equationInTwoTabs() && p.parseConstruct() && p.parseOrder() && p.parseCheckX() >= 0)
    {
        // p.showTheEquation();
        parseNbr = p.parseCheckX();
    }
    else
        return badParsing();

    if (argc == 3 && parseNbr >= 0 && parseNbr < 3) 
    {
        Equation eq(argv[2], p.getLeftOpe(), p.getRightOpe());
        eq.handleCoeff();
        eq.showReducedForm();
        eq.showPolynomialDegree();

        Solver s(eq.getFinalCoeff());
        // s.showCoeff();
        s.solveEquation();
        cout  << endl;
    }
    else if (parseNbr > 2)
    {
        
        if (parseNbr == 3)
        {
            Equation eq(argv[2], p.getLeftOpe(), p.getRightOpe());
            eq.handleCoeff();
            eq.showReducedForm();
            eq.showPolynomialDegree();
            cout << "The polynomial degree is strictly greater than 2, I can't solve." << endl << endl;
        }
        else
        {
            cout << "Polynomial degree > 3" << endl;
            cout << "The polynomial degree is strictly greater than 3, I can't solve (and I won't show you the reduced form, please consider my capacities)." << endl << endl;
        }
    }
    else
    {
        cout << "Your equation is poorly constructed." << endl
            << "Please follow this example: \"a + b * X + c * X^2 = d + e * X + f * X^2\"." << endl
            << "Respect the spaces and the order: X^0, then X, then X^2." << endl << endl;
    }

    return 0;
}

int simpleHandler(int argc, char **argv)
{
    int parseNbr(-1);

    Parsersimplified p(argv[1]);

    if (p.equationInTwoTabs() && p.parseCheckX() >= 0)
    {
        // p.showTheEquation();
        parseNbr = p.parseCheckX();
    }
    else
        return badParsing();

    if (argc == 2 && parseNbr >= 0 && parseNbr < 3) 
    {
        Equationsimplified eq(argv[1], p.getLeftOpe(), p.getRightOpe());
        eq.handleCoeff();
        eq.showReducedForm();
        eq.showPolynomialDegree();

        Solver s(eq.getFinalCoeff());
        // s.showCoeff();
        s.solveEquation();
        cout  << endl;
    }
    else if (parseNbr > 2)
    {
        
        if (parseNbr == 3)
        {
            Equationsimplified eq(argv[1], p.getLeftOpe(), p.getRightOpe());
            eq.handleCoeff();
            eq.showReducedForm();
            eq.showPolynomialDegree();
            cout << "The polynomial degree is strictly greater than 2, I can't solve." << endl << endl;
        }
        else
        {
            cout << "Polynomial degree > 3" << endl;
            cout << "The polynomial degree is strictly greater than 3, I can't solve (and I won't show you the reduced form, please consider my capacities)." << endl << endl;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    cout << endl;
    if (!argHandler(argc, argv))
        return (0);

    if (argc == 3)
        return niceHandler(argc, argv);
    else
        return simpleHandler(argc, argv);

    return (0);
}