/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Equation.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:35:20 by bmenant           #+#    #+#             */
/*   Updated: 2022/01/20 23:53:23 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Equation.h"
#include "../inc/Parser.h"
#include "../inc/computor.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Equation::Equation(string totalEquation, vector<string> leftOpe, vector<string> rightOpe) : m_leftOpe(leftOpe), m_rightOpe(rightOpe), m_totalEquation(totalEquation)
{
}

vector<double> Equation::getFinalCoeff()
{
    return m_finalCoeff;
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
    else if (m_finalCoeff[0] == 0.0 && m_finalCoeff[1] == 0.0 && m_finalCoeff[2] == 0.0 && m_finalCoeff[3] == 0.0)
        cout << "0";
    if (m_finalCoeff[1] != 0.0)
    {
        if (m_finalCoeff[0] == 0 && m_finalCoeff[1] < 0.0)
            cout << "-" << (-1 * m_finalCoeff[1]) << " * X";
        else if (m_finalCoeff[0] == 0 && m_finalCoeff[1] > 0.0)
            cout << m_finalCoeff[1] << " * X";
        else if (m_finalCoeff[1] < 0.0)
            cout << " - " << (-1 * m_finalCoeff[1]) << " * X";
        else
            cout << " + " << m_finalCoeff[1] << " * X";
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

void Equation::putCoeff(vector<string> opeTab, int side)
{
    for (unsigned long i(0); i < opeTab.size(); i++)
    {
        if ((i == 0 && opeTab.size() == 1 && strPotentialD(opeTab[i], true)) ||
            (i > 0 && i + 1 < opeTab.size() && (opeTab[i + 1][0] == '+' || opeTab[i + 1][0] == '-') && (opeTab[i - 1][0] == '+' || opeTab[i - 1][0] == '-') && strPotentialD(opeTab[i], false)) ||
            (i > 0 && i + 1 == opeTab.size() && (opeTab[i - 1][0] == '+' || opeTab[i - 1][0] == '-') && strPotentialD(opeTab[i], false)) ||
            (i == 0 && i + 1 < opeTab.size() && (opeTab[i + 1][0] == '+' || opeTab[i + 1][0] == '-') && strPotentialD(opeTab[i], true)))
        {
            m_finalCoeff[0] += (i > 0 && opeTab[i - 1][0] == '-') ? stod(opeTab[i]) * -1 * side : (stod(opeTab[i])) * side;
        }

        else if (i + 2 < opeTab.size() && opeTab[i + 1][0] == '*' && opeTab[i + 2] == "X" && (i == 0 ? strPotentialD(opeTab[i], true) : strPotentialD(opeTab[i], false)))
        {
            m_finalCoeff[1] += (i > 0 && opeTab[i - 1][0] == '-') ? stod(opeTab[i]) * -1 * side : (stod(opeTab[i])) * side;
        }

        else if (i + 2 < opeTab.size() && opeTab[i + 1][0] == '*' && opeTab[i + 2] == "X^2" && (i == 0 ? strPotentialD(opeTab[i], true) : strPotentialD(opeTab[i], false)))
        {
            m_finalCoeff[2] += (i > 0 && opeTab[i - 1][0] == '-') ? stod(opeTab[i]) * -1 * side : (stod(opeTab[i])) * side;
        }

        else if (i + 2 < opeTab.size() && opeTab[i + 1][0] == '*' && opeTab[i + 2] == "X^3" && (i == 0 ? strPotentialD(opeTab[i], true) : strPotentialD(opeTab[i], false)))
        {
            m_finalCoeff[3] += (i > 0 && opeTab[i - 1][0] == '-') ? stod(opeTab[i]) * -1 * side : (stod(opeTab[i])) * side;
        }
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