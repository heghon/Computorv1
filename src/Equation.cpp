/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Equation.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:35:20 by bmenant           #+#    #+#             */
/*   Updated: 2021/12/29 16:55:12 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Equation.h"
#include "../inc/Parser.h"
#include "../inc/computor.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Equation::Equation(string totalEquation) : m_totalEquation(totalEquation)
{
}

void Equation::showPolynomialDegree()
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

void Equation::showReducedForm()
{
    cout << "Reduced form: ";
    if (m_finalCoeff[0] != 0.0)
        cout << m_finalCoeff[0];
    if (m_finalCoeff[1] != 0.0)
    {
        if (m_finalCoeff[1] <= 0.0)
            cout << " - " << (-1 * m_finalCoeff[1]) << " * X";
        else
            cout << " + " << m_finalCoeff[1] << " * X";
    }
    if (m_finalCoeff[2] != 0.0)
    {
        if (m_finalCoeff[2] <= 0.0)
            cout << " - " << (-1 * m_finalCoeff[2]) << " * X^2";
        else
            cout << " + " << m_finalCoeff[2] << " * X^2";
    }
    if (m_finalCoeff[3] != 0.0)
    {
        if (m_finalCoeff[3] <= 0.0)
            cout << " - " << (-1 * m_finalCoeff[3]) << " * X^3";
        else
            cout << " + " << m_finalCoeff[3] << " * X^3";
    }
    cout << " = 0" << endl;
}

void Equation::putCoeff(vector<string> opeTab, int side)
{
    for (unsigned long i(0); i < opeTab.size(); i++)
    {
        if ((i == 0 && opeTab.size() == 1 && strPotentialD(opeTab[i])) ||
            (i == 0 && i + 1 < opeTab.size() && (opeTab[i + 1] == "+" || opeTab[i + 1] == "-") && strPotentialD(opeTab[i])))

            m_finalCoeff[0] += (i > 0 && opeTab[i - 1] == "-") ? stod(opeTab[i]) * -1 * side : (stod(opeTab[i])) * side;

        else if (i + 2 < opeTab.size() && opeTab[i + 1] == "*" && opeTab[i + 2] == "X" && strPotentialD(opeTab[i]))

            m_finalCoeff[1] += (i > 0 && opeTab[i - 1] == "-") ? stod(opeTab[i]) * -1 * side : (stod(opeTab[i])) * side;

        else if (i + 2 < opeTab.size() && opeTab[i + 1] == "*" && opeTab[i + 2] == "X^2" && strPotentialD(opeTab[i]))

            m_finalCoeff[2] += (i > 0 && opeTab[i - 1] == "-") ? stod(opeTab[i]) * -1 * side : (stod(opeTab[i])) * side;

        else if (i + 2 < opeTab.size() && opeTab[i + 1] == "*" && opeTab[i + 2] == "X^3" && strPotentialD(opeTab[i]))

            m_finalCoeff[3] += (i > 0 && opeTab[i - 1] == "-") ? stod(opeTab[i]) * -1 * side : (stod(opeTab[i])) * side;
    }
}

void Equation::handleCoeff()
{
    m_finalCoeff.push_back(0.0);
    m_finalCoeff.push_back(0.0);
    m_finalCoeff.push_back(0.0);
    m_finalCoeff.push_back(0.0);

    putCoeff(m_leftOpe, 1);
    putCoeff(m_rightOpe, -1);
    cout << endl << "End of the Coeff - Coeffs are : " << endl;
    for (int i(0); i < m_finalCoeff.size(); i++)
    {
        cout << "Coeff " << i << " : " << m_finalCoeff[i] << endl;
    }
}

bool Equation::equationInTwoTabs()
{
    bool equal = false;
    unsigned long i(0);
    int j(0);

    m_leftOpe.push_back("");
    while(m_totalEquation[i])
    {
        if (m_totalEquation[i] == '=')
        {
            if ((i - 1 > 0 && m_totalEquation[i - 1] != ' ') || equal)
                return false;
            equal = true;
            j = -1;
        }

        else if (m_totalEquation[i] != ' ' && m_totalEquation[i] != '=')
        {
            if (equal && j == -1)
                return false;
            equal ? m_rightOpe[j].push_back(m_totalEquation[i]) : m_leftOpe[j].push_back(m_totalEquation[i]);
        }
        
        else if (m_totalEquation[i] == ' ')
        {
            if (i + 1 < m_totalEquation.size() && m_totalEquation[i + 1] != '=')
                equal ? m_rightOpe.push_back("") : m_leftOpe.push_back("");
            j++;
        }
        i++;
    }
    // cout << "Equation in 2 tabs - here are the two tabs : " << endl;
    // for (int i(0); i < m_leftOpe.size(); i++)
    // {
    //     cout << "Left - element numbr " << i << " : " + m_leftOpe[i] << endl;
    // }
    //     for (int i(0); i < m_rightOpe.size(); i++)
    // {
    //     cout << "Right - element numbr " << i << " : " + m_rightOpe[i] << endl;
    // }
    return true;
}

void Equation::showTheEquation()
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