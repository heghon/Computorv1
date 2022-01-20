/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Equationsimplified.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:15:40 by bmenant           #+#    #+#             */
/*   Updated: 2022/01/21 00:32:03 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Equation.h"
#include "../inc/Parser.h"
#include "../inc/computor.h"
#include "../inc/Parsersimplified.h"
#include "../inc/Equationsimplified.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Equationsimplified::Equationsimplified(string totalEquation, vector<string> leftOpe, vector<string> rightOpe) : m_leftOpe(leftOpe), m_rightOpe(rightOpe), m_totalEquation(totalEquation)
{
}

vector<double> Equationsimplified::getFinalCoeff()
{
    return m_finalCoeff;
}

void Equationsimplified::showPolynomialDegree()
{
    if (m_finalCoeff[3] != 0.0)
        cout << "Polynomial degree: 3" << endl;
    else if (m_finalCoeff[2] != 0.0)
        cout << "Polynomial degree: 2" << endl;
    else if (m_finalCoeff[1] != 0.0)
        cout << "Polynomial degree: 1" << endl;
    else if (m_finalCoeff[0] != 0.0)
        cout << "Polynomial degree: 0" << endl;
    else
        cout << "Polynomial degree: 0" << endl;
}

void Equationsimplified::showReducedForm()
{
    cout << "Reduced form: ";
    if (m_finalCoeff[0] != 0.0)
        cout << m_finalCoeff[0]<< " * X^0";
    else if (m_finalCoeff[0] == 0.0 && m_finalCoeff[1] == 0.0 && m_finalCoeff[2] == 0.0 && m_finalCoeff[3] == 0.0)
        cout << "0";
    if (m_finalCoeff[1] != 0.0)
    {
        if (m_finalCoeff[0] == 0 && m_finalCoeff[1] < 0.0)
            cout << "-" << (-1 * m_finalCoeff[1]) << " * X^1";
        else if (m_finalCoeff[0] == 0 && m_finalCoeff[1] > 0.0)
            cout << m_finalCoeff[1] << " * X^1";
        else if (m_finalCoeff[1] < 0.0)
            cout << " - " << (-1 * m_finalCoeff[1]) << " * X^1";
        else
            cout << " + " << m_finalCoeff[1] << " * X^1";
    }
    if (m_finalCoeff[2] != 0.0)
    {
        if (m_finalCoeff[0] == 0 && m_finalCoeff[1] == 0.0 && m_finalCoeff[2] > 0.0)
            cout << "-" << (-1 * m_finalCoeff[2]) << " * X^2";
        else if (m_finalCoeff[0] == 0 && m_finalCoeff[1] == 0.0 && m_finalCoeff[2] > 0.0)
            cout << m_finalCoeff[2] << " * X^2";
        else if (m_finalCoeff[2] < 0.0)
            cout << " - " << (-1 * m_finalCoeff[2]) << " * X^2";
        else
            cout << " + " << m_finalCoeff[2] << " * X^2";
    }
    if (m_finalCoeff[3] != 0.0)
    {
        if (m_finalCoeff[0] == 0 && m_finalCoeff[1] == 0.0 && m_finalCoeff[2] == 0.0 && m_finalCoeff[3] < 0.0)
            cout << "-" << (-1 * m_finalCoeff[3]) << " * X^3";
        else if (m_finalCoeff[0] == 0 && m_finalCoeff[1] == 0.0 && m_finalCoeff[2] == 0.0 && m_finalCoeff[3] > 0.0)
            cout << m_finalCoeff[3] << " * X^3";
        else if (m_finalCoeff[3] < 0.0)
            cout << " - " << (-1 * m_finalCoeff[3]) << " * X^3";
        else
            cout << " + " << m_finalCoeff[3] << " * X^3";
    }
    cout << " = 0" << endl;
}

void Equationsimplified::putCoeff(vector<string> opeTab, int side)
{
    for (unsigned long i(0); i < opeTab.size(); i++)
    {
        if (i + 2 < opeTab.size() && opeTab[i + 1] == "*" && opeTab[i + 2] == "X^0")

            m_finalCoeff[0] += (i > 0 && opeTab[i - 1] == "-") ? stod(opeTab[i]) * -1 * side : (stod(opeTab[i])) * side;

        else if (i + 2 < opeTab.size() && opeTab[i + 1] == "*" && opeTab[i + 2] == "X^1")

            m_finalCoeff[1] += (i > 0 && opeTab[i - 1] == "-") ? stod(opeTab[i]) * -1 * side : (stod(opeTab[i])) * side;

        else if (i + 2 < opeTab.size() && opeTab[i + 1] == "*" && opeTab[i + 2] == "X^2")

            m_finalCoeff[2] += (i > 0 && opeTab[i - 1] == "-") ? stod(opeTab[i]) * -1 * side : (stod(opeTab[i])) * side;

        else if (i + 2 < opeTab.size() && opeTab[i + 1] == "*" && opeTab[i + 2] == "X^3")

            m_finalCoeff[3] += (i > 0 && opeTab[i - 1] == "-") ? stod(opeTab[i]) * -1 * side : (stod(opeTab[i])) * side;
    }
}

void Equationsimplified::handleCoeff()
{
    m_finalCoeff.push_back(0.0);
    m_finalCoeff.push_back(0.0);
    m_finalCoeff.push_back(0.0);
    m_finalCoeff.push_back(0.0);

    putCoeff(m_leftOpe, 1);
    putCoeff(m_rightOpe, -1);
    // cout << endl << "End of the Coeff - Coeffs are : " << endl;
    // for (int i(0); i < m_finalCoeff.size(); i++)
    // {
    //     cout << "Coeff " << i << " : " << m_finalCoeff[i] << endl;
    // }
}

void Equationsimplified::showTheEquation()
{
    cout << endl << "THE TOTAL EQUATION IS : " << endl;
    for (unsigned long i(0); i < m_leftOpe.size(); i++)
    {
        if (i > 0)
            cout << " ";
        cout << m_leftOpe[i];
    }
    cout << " =";
        for (unsigned long i(0); i < m_rightOpe.size(); i++)
    {
        cout << " " + m_rightOpe[i]; 
    }
    cout << endl << endl;
}