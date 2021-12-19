/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Equation.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:35:20 by bmenant           #+#    #+#             */
/*   Updated: 2021/12/19 20:16:50 by bmenant          ###   ########.fr       */
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

void Equation::takeCoeff()
{
    m_finalCoeff.push_back(0);
    m_finalCoeff.push_back(0);
    m_finalCoeff.push_back(0);

    for (int i(0); i < m_leftOpe.size(); i++)
    {
        if ((m_leftOpe[i + 1] == "+" || m_leftOpe[i + 1] == "-" || m_leftOpe[i - 1] == "+" || m_leftOpe[i - 1] == "-") && strPotentialD(m_leftOpe[i]))
            m_finalCoeff[0] += (i > 0 && m_leftOpe[i - 1] == "-") ? stod(m_leftOpe[i]) : (stod(m_leftOpe[i]) * -1);
        else if (m_leftOpe.size() > i + 2 && m_leftOpe[i + 1] == "*" && m_leftOpe[i + 2] == "X" && strPotentialD(m_leftOpe[i]))
            m_finalCoeff[1] += (i > 0 && m_leftOpe[i - 1] == "-") ? stod(m_leftOpe[i]) : (stod(m_leftOpe[i]) * -1);
        else if (m_leftOpe.size() > i + 2 && m_leftOpe[i + 1] == "*" && m_leftOpe[i + 2] == "X^2" && strPotentialD(m_leftOpe[i]))
            m_finalCoeff[2] += (i > 0 && m_leftOpe[i - 1] == "-") ? stod(m_leftOpe[i]) : (stod(m_leftOpe[i]) * -1);
    }
    for (int i(0); i < m_rightOpe.size(); i++)
    {
        if ((m_rightOpe[i + 1] == "+" || m_rightOpe[i + 1] == "-" || m_rightOpe[i - 1] == "+" || m_rightOpe[i - 1] == "-") && strPotentialD(m_rightOpe[i]))
            m_finalCoeff[0] -= (i > 0 && m_rightOpe[i - 1] == "-") ? stod(m_rightOpe[i]) : (stod(m_rightOpe[i]) * -1);
        else if (m_rightOpe.size() > i + 2 && m_rightOpe[i + 1] == "*" && m_rightOpe[i + 2] == "X" && strPotentialD(m_rightOpe[i]))
            m_finalCoeff[1] -= (i > 0 && m_rightOpe[i - 1] == "-") ? stod(m_rightOpe[i]) : (stod(m_rightOpe[i]) * -1);
        else if (m_rightOpe.size() > i + 2 && m_rightOpe[i + 1] == "*" && m_rightOpe[i + 2] == "X^2" && strPotentialD(m_rightOpe[i]))
            m_finalCoeff[2] -= (i > 0 && m_rightOpe[i - 1] == "-") ? stod(m_rightOpe[i]) : (stod(m_rightOpe[i]) * -1);
    }
    cout << "end of takeCoeff : Coeffs are " << endl;
    for (int i(0); i < 3; i++)
    {
        cout << "Coeff " + to_string(i) + " = " + to_string(m_finalCoeff[i]) << endl;
    }
}

bool Equation::equationInTwoTabs()
{
    bool equal = false;
    int i(0);
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
    cout << "Equation in 2 tabs - here are the two tabs : " << endl;
    for (int i(0); i < m_leftOpe.size(); i++)
    {
        cout << "Left - element numbr " << i << " : " + m_leftOpe[i] << endl;
    }
        for (int i(0); i < m_rightOpe.size(); i++)
    {
        cout << "Right - element numbr " << i << " : " + m_rightOpe[i] << endl;
    }
    return true;
}

void Equation::showTheEquation()
{
    cout << endl << "THE TOTAL EQUATION IS : " << endl;
    for (int i(0); i < m_leftOpe.size(); i++)
    {
        if (i > 0)
            cout << " ";
        cout << m_leftOpe[i];
    }
    cout << " =";
        for (int i(0); i < m_rightOpe.size(); i++)
    {
        cout << " " + m_rightOpe[i]; 
    }
    cout << endl << endl;
}