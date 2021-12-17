/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Equation.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:35:20 by bmenant           #+#    #+#             */
/*   Updated: 2021/12/17 20:13:08 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Equation.h"
#include "../inc/computor.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Equation::Equation(string totalEquation) : m_totalEquation(totalEquation)
{
}

void Equation::equationInTwoTabs()
{
    bool equal = false;
    int i(0);
    int j(0);

    m_leftOpe.push_back("");
    while(m_totalEquation[i])
    {
        if (m_totalEquation[i] == '=')
        {
            equal = true;
            j = -1;
        }

        else if (m_totalEquation[i] != ' ' && m_totalEquation[i] != '=')
        {
            equal ? m_rightOpe[j].push_back(m_totalEquation[i]) : m_leftOpe[j].push_back(m_totalEquation[i]);
        }
        
        else if (m_totalEquation[i] == ' ')
        {
            equal ? m_rightOpe.push_back("") : m_leftOpe.push_back("");
            j++;
        }
        i++;
    }
}

void Equation::showTheEquation()
{
    cout << "the total equation is : " << endl;
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
}

bool Equation::parseOrder()
{
    int i(0);
    while (i < m_leftOpe.size())
    {
        if (!strPotentialD(m_leftOpe[i]))
            return false;

        if (i + 1 < m_leftOpe.size() && (m_leftOpe[i + 1] != "*" || m_leftOpe[i + 1] != "+" || m_leftOpe[i + 1] != "-"))
            return false;

        if (i + 1 < m_leftOpe.size() && m_leftOpe[i + 1] == "*" && i + 2 < m_leftOpe.size() && m_leftOpe[i + 2][0] != 'X')
            return false;

        if (i + 1 < m_leftOpe.size() && m_leftOpe[i + 1] == "*" && i + 2 < m_leftOpe.size() && m_leftOpe[i + 2][0] == 'X' &&
            i + 3 < m_leftOpe.size() && (m_leftOpe[i + 1] != "+" || m_leftOpe[i + 1] != "-"))
            return false;

        i += (i + 1 < m_leftOpe.size() && m_leftOpe[i + 1] == "*") ? 4 : 2;
    }
    return true;
}