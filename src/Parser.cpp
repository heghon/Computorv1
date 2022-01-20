/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:48:20 by bmenant           #+#    #+#             */
/*   Updated: 2022/01/20 23:52:05 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Equation.h"
#include "../inc/Parser.h"
#include "../inc/computor.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Parser::Parser(string totalEquation) : m_totalEquation(totalEquation)
{
}

vector<string> Parser::getLeftOpe()
{
    return m_leftOpe;
}

vector<string> Parser::getRightOpe()
{
    return m_rightOpe;
}

bool Parser::equationInTwoTabs()
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
    /*cout << "Equation in 2 tabs - here are the two tabs : " << endl;
    for (int i(0); (unsigned long)i < m_leftOpe.size(); i++)
    {
        cout << "Left - element numbr " << i << " : " + m_leftOpe[i] << endl;
    }
        for (int i(0); (unsigned long)i < m_rightOpe.size(); i++)
    {
        cout << "Right - element numbr " << i << " : " + m_rightOpe[i] << endl;
    }
    cout << endl;*/
    return true;
}

void Parser::showTheEquation()
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

bool Parser::orderCheck(vector<string> tab)
{
    int i(0);
    
    //cout << "in order check - tab size = " << tab.size() << endl;
    while (i < (int)tab.size())
    {
        //cout << "i = " << i << endl;
        if ((int)tab.size() >= i + 1 && (i == 0 ? strPotentialD(tab[i], true) : strPotentialD(tab[i], false)) &&
                (int)tab.size() >= i + 2 && tab[i + 1] == "*" && 
                (int)tab.size() >= i + 3 && tab[i + 2][0] == 'X' &&
                (int)tab.size() >= i + 4 && (tab[i + 3] == "+" || tab[i + 3] == "-") && 
                (int)tab.size() >= i + 5 && strPotentialD(tab[i + 4], false))
        {
            //cout << "first if passed" << endl;
            i += 4;
        }

        else if ((int)tab.size() >= i + 1 && (i == 0 ? strPotentialD(tab[i], true) : strPotentialD(tab[i], false)) &&
            (int)tab.size() >= i + 2 && (tab[i + 1] == "+" || tab[i + 1] == "-") &&
            (int)tab.size() >= i + 3 && strPotentialD(tab[i + 2], false))
        {
            //cout << "second if passed" << endl;
            i += 2;
        }
        
        else if ((int)tab.size() >= i + 1 && (i == 0 ? strPotentialD(tab[i], true) : strPotentialD(tab[i], false)) &&
                (int)tab.size() >= i + 2 && tab[i + 1][0] == '*' && 
                (int)tab.size() == i + 3 && tab[i + 2][0] == 'X')
        {
            //cout << "third if passed" << endl;
            return true;
        }

        else if ((int)tab.size() == i + 1 && (i == 0 ? strPotentialD(tab[i], true) : strPotentialD(tab[i], false)))
        {
            //cout << "fourth if passed" << endl;
            return true;
        }
        else
        {
            //cout << "Not a good parse order..." << endl;
            return false;
        }

    }
    return false;
}

bool Parser::parseOrder()
{
    //cout << endl << "in parse order function -" << endl;

    if ((int)m_leftOpe.size() == 0 || (int)m_rightOpe.size() == 0)
        return false;

    if (!strPotentialD(m_leftOpe[0], true) || !strPotentialD(m_rightOpe[0], true))
        return false;

    if (!orderCheck(m_leftOpe) || !orderCheck(m_rightOpe))
        return false;

    return true;
}

int Parser::checkHandlerX(vector<string> tab)
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
            if (tab[i].size() > 1 && tab[i][1] != '^')
                return -1;
            string pwr = "";
            for (int k = 2; k < (int)tab[i].size(); k++)
            {
                pwr.push_back(tab[i][k]);
            }
            //cout << "After push back, pwr = " << pwr << ", and is pwr potentially int ? " << strPotentialPositiveI(pwr) << endl;
            //if (pwr == "")
                //cout << "So, pwr == \"\"" << endl;
            if (pwr == "")
            {
                check = true;
                deg = deg > 1 ? deg : 1;
            }
            else if (strPotentialPositiveI(pwr))
            {
                check = true;
                deg = deg > stoi(pwr) ? deg : stoi(pwr);
            }

            if (!check)
            {
                //cout << "!check" << endl;
                return -1;
            }
        }
    }
    return deg;
}

int Parser::parseCheckX()
{
    //cout << endl << "In parse check x function - " << endl;

    int degL(0);
    int degR(0);

    degL = checkHandlerX(m_leftOpe);
    // cout << endl << "After degL = " << degL << endl;
    degR = checkHandlerX(m_rightOpe);
    // cout << endl << "After degR = " << degR  << endl;

    if (degL == -1 || degR == -1)
        return -1;
    return (degL > degR ? degL : degR);
}

bool Parser::constructSide(vector<string> tab)
{
    int i(0);
    while (i < (int)tab.size())
    {
        //cout << endl << "For "<< i << " : " + tab[i] << endl;
        if (i == 0 ? !strPotentialD(tab[i], true) : !strPotentialD(tab[i], false) /*|| (strPotentialD(tab[i]) && i + 1 == tab.size())*/)
            return false;
        //cout << "first if passed for " + tab[i] << endl;

        //if (i + 1 < (int)tab.size())
        //    cout << "After first if, i + 1 = " << i + 1 << " et size = " << tab.size() << " et m_leftOpe[i + 1] = " + tab[i + 1] << endl;
        if (i + 1 < (int)tab.size() && tab[i + 1] != "*" && tab[i + 1] != "+" && tab[i + 1] != "-")
            return false;
        //cout << "second if passed for " + tab[i] << endl;

        if (i + 1 < (int)tab.size() && tab[i + 1] == "*" && i + 2 < (int)tab.size() && tab[i + 2][0] != 'X')
            return false;
        //cout << "third if passed for " + tab[i] << endl;

        if (i + 1 < (int)tab.size() && tab[i + 1] == "*" && i + 2 < (int)tab.size() && tab[i + 2][0] == 'X' &&
            i + 3 < (int)tab.size() && tab[i + 3] != "+" && tab[i + 3] != "-")
            return false;
        //cout << "last if passed for " + tab[i] << endl;

        if (tab[tab.size() - 1] == "-" || tab[tab.size() - 1] == "+" || tab[tab.size() - 1] == "*")
            return false;
        
        i += (i + 1 < (int)tab.size() && tab[i + 1] == "*") ? 4 : 2;
    }
    return true;
}

bool Parser::parseConstruct()
{
    //cout << "parse construct function -" << endl;
    return (constructSide(m_leftOpe) && constructSide(m_rightOpe));
}