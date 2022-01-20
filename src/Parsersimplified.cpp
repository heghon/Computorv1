/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsersimplified.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:12:23 by bmenant           #+#    #+#             */
/*   Updated: 2022/01/21 00:34:08 by bmenant          ###   ########.fr       */
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

Parsersimplified::Parsersimplified(string totalEquation) : m_totalEquation(totalEquation)
{
}

vector<string> Parsersimplified::getLeftOpe()
{
    return m_leftOpe;
}

vector<string> Parsersimplified::getRightOpe()
{
    return m_rightOpe;
}

bool Parsersimplified::equationInTwoTabs()
{
    bool equal = false;
    int i(0);
    int j(0);

    m_leftOpe.push_back("");
    while(m_totalEquation[i])
    {
        if (m_totalEquation[i] == '=')
        {
            if ((i - 1 >= 0 && m_totalEquation[i - 1] != ' ') || equal)
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
            if (i + 1 < (int)m_totalEquation.size() && m_totalEquation[i + 1] != '=')
                equal ? m_rightOpe.push_back("") : m_leftOpe.push_back("");
            j++;
        }
        i++;
    }
    if ((int)m_leftOpe.size() == 1 && m_leftOpe[0] == "")
        m_leftOpe.pop_back();
        /*
    cout << "Equation in 2 tabs - here are the two tabs : " << endl;
    for (int i(0); i < (int)m_leftOpe.size(); i++)
    {
        cout << "Left - element numbr " << i << " : " + m_leftOpe[i] << endl;
    }
        for (int i(0); i < (int)m_rightOpe.size(); i++)
    {
        cout << "Right - element numbr " << i << " : " + m_rightOpe[i] << endl;
    }
    cout << endl;*/
    return true;
}

void Parsersimplified::showTheEquation()
{
    cout << endl << "THE TOTAL EQUATION IS : " << endl;
    for (int i(0); i < (int)m_leftOpe.size(); i++)
    {
        if (i > 0)
            cout << " ";
        cout << m_leftOpe[i];
    }
    cout << " =";
        for (int i(0); i < (int)m_rightOpe.size(); i++)
    {
        cout << " " + m_rightOpe[i]; 
    }
    cout << endl << endl;
}


int Parsersimplified::checkHandlerX(vector<string> tab)
{
    bool check(false);
    int deg(0);

    //cout << "In checkHandlerX" << endl;
    for (int i(0); i < (int)tab.size(); i++)
    {
        check = false;
        if (tab[i][0] == 'X')
        {
            //cout << "In the if, tab[i] = " << tab[i] << endl;
            string pwr = "";
            for (int k = 2; k < (int)tab[i].size(); k++)
            {
                pwr.push_back(tab[i][k]);
            }
            //cout << "After push back, pwr = " << pwr << ", and is pwr potentially int ? " << strPotentialPositiveI(pwr) << endl;
            //if (pwr == "")
                //cout << "So, pwr == \"\"" << endl;
            deg = deg > stoi(pwr) ? deg : stoi(pwr);
        }
    }
    return deg;
}

int Parsersimplified::parseCheckX()
{
    //cout << endl << "In parse check x function - " << endl;

    int degL(0);
    int degR(0);

    degL = checkHandlerX(m_leftOpe);
    // cout << endl << "After degL = " << degL << endl;
    degR = checkHandlerX(m_rightOpe);
    // cout << endl << "After degR = " << degR  << endl;

    return (degL > degR ? degL : degR);
}