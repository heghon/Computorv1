/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:48:20 by bmenant           #+#    #+#             */
/*   Updated: 2022/01/24 17:56:46 by bmenant          ###   ########.fr       */
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
    
    while (i < (int)tab.size())
    {
        if ((int)tab.size() >= i + 1 && (i == 0 ? strPotentialD(tab[i], true) : strPotentialD(tab[i], false)) &&
                (int)tab.size() >= i + 2 && tab[i + 1] == "*" && 
                (int)tab.size() >= i + 3 && tab[i + 2][0] == 'X' &&
                (int)tab.size() >= i + 4 && (tab[i + 3] == "+" || tab[i + 3] == "-") && 
                (int)tab.size() >= i + 5 && strPotentialD(tab[i + 4], false))
        {
            i += 4;
        }

        else if ((int)tab.size() >= i + 1 && (i == 0 ? strPotentialD(tab[i], true) : strPotentialD(tab[i], false)) &&
            (int)tab.size() >= i + 2 && (tab[i + 1] == "+" || tab[i + 1] == "-") &&
            (int)tab.size() >= i + 3 && strPotentialD(tab[i + 2], false))
        {
            i += 2;
        }
        
        else if ((int)tab.size() >= i + 1 && (i == 0 ? strPotentialD(tab[i], true) : strPotentialD(tab[i], false)) &&
                (int)tab.size() >= i + 2 && tab[i + 1][0] == '*' && 
                (int)tab.size() == i + 3 && tab[i + 2][0] == 'X')
        {
            return true;
        }

        else if ((int)tab.size() == i + 1 && (i == 0 ? strPotentialD(tab[i], true) : strPotentialD(tab[i], false)))
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    return false;
}

bool Parser::parseOrder()
{
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

    for (int i(0); i < (int)tab.size(); i++)
    {
        check = false;
        if (tab[i][0] == 'X')
        {
            if (tab[i].size() > 1 && tab[i][1] != '^')
                return -1;

            string pwr = "";
            
            for (int k = 2; k < (int)tab[i].size(); k++)
            {
                pwr.push_back(tab[i][k]);
            }

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
                return -1;
        }
    }
    return deg;
}

int Parser::parseCheckX()
{

    int degL(0);
    int degR(0);

    degL = checkHandlerX(m_leftOpe);
    degR = checkHandlerX(m_rightOpe);

    if (degL == -1 || degR == -1)
        return -1;
    return (degL > degR ? degL : degR);
}

bool Parser::constructSide(vector<string> tab)
{
    int i(0);
    while (i < (int)tab.size())
    {
        if (i == 0 ? !strPotentialD(tab[i], true) : !strPotentialD(tab[i], false))
            return false;

        if (i + 1 < (int)tab.size() && tab[i + 1] != "*" && tab[i + 1] != "+" && tab[i + 1] != "-")
            return false;

        if (i + 1 < (int)tab.size() && tab[i + 1] == "*" && i + 2 < (int)tab.size() && tab[i + 2][0] != 'X')
            return false;

        if (i + 1 < (int)tab.size() && tab[i + 1] == "*" && i + 2 < (int)tab.size() && tab[i + 2][0] == 'X' &&
            i + 3 < (int)tab.size() && tab[i + 3] != "+" && tab[i + 3] != "-")
            return false;

        if (tab[tab.size() - 1] == "-" || tab[tab.size() - 1] == "+" || tab[tab.size() - 1] == "*")
            return false;
        
        i += (i + 1 < (int)tab.size() && tab[i + 1] == "*") ? 4 : 2;
    }
    return true;
}

bool Parser::parseConstruct()
{
    return (constructSide(m_leftOpe) && constructSide(m_rightOpe));
}