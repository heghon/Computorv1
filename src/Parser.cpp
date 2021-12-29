/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:48:20 by bmenant           #+#    #+#             */
/*   Updated: 2021/12/29 16:46:37 by bmenant          ###   ########.fr       */
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
    cout << endl;
    return true;
}

void Parser::showTheEquation()
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

bool Parser::orderCheckHandler(vector<string> tab, int i)
{
    while (i < tab.size())
    {
        if (tab.size() >= i + 1 && !strPotentialD(tab[i]))
            return false;
        cout << "first if passed" << endl;
        if (tab.size() >= i + 2 && tab[i + 1] != "*")
            return false;
        cout << "second if passed" << endl;
        if (tab.size() >= i + 3 && tab[i + 2][0] != 'X')
            return false;
        cout << "third if passed" << endl;
        if (tab.size() >= i + 4 && !(tab[i + 3] == "+" || tab[i + 3] == "-"))
            return false;
        cout << "last if passed" << endl;
        i += 4;
    }
    return true;
}

bool Parser::orderCheck(vector<string> tab)
{
    cout << "in order check function - " << endl;
    bool ret(false);

    for (int a(0); a < tab.size(); a++)
    {
        cout << "tab en cours : tab[" << a << "] = " << tab[a] << endl;
    }
    
    ret = (tab.size() >= 2 && (tab[1] == "+" || tab[1] == "-")) ? orderCheckHandler(tab, 2) : orderCheckHandler(tab, 0);

    return ret;
}

bool Parser::parseOrder()
{
    cout << endl << "in parse order function -" << endl;

    if (!strPotentialD(m_leftOpe[0]) || !strPotentialD(m_rightOpe[0]))
        return false;

    if (!orderCheck(m_leftOpe) || !orderCheck(m_rightOpe))
        return false;

    return true;
}

int Parser::parseCheckX()
{
    cout << endl << "In parse check x function - " << endl;

    bool check(false);
    int j(1);
    int deg(0);

    for (int i(0); i < m_leftOpe.size(); i++)
    {
        check = false;
        if (m_leftOpe[i][0] == 'X')
        {
            if (m_leftOpe[i] == (j == 1 ? "X" : "X^" + to_string(j)))
            {
                check = true;
                deg = j > deg ? j : deg;
            }
            if (!check)
                return -1;
            j++;
        }
    }
    cout << "first tab done" << endl;
    j = 1;
    for (int i(0); i < m_rightOpe.size(); i++)
    {
        check = false;
        if (m_rightOpe[i][0] == 'X')
        {
            if (m_rightOpe[i] == (j == 1 ? "X" : "X^" + to_string(j)))
            {
                check = true;
                deg = j > deg ? j : deg;
            }
            if (!check)
                return -1;
            j++;
        }
    }
    return (deg);
}

bool Parser::constructSide(vector<string> tab)
{
    int i(0);
    while (i < tab.size())
    {
        cout << endl << "For "<< i << " : " + tab[i] << endl;
        if (!strPotentialD(tab[i]) || (strPotentialD(tab[i]) && i + 1 == tab.size()))
            return false;
        cout << "first if passed for " + tab[i] << endl;

        if (i + 1 < tab.size())
            cout << "After first if, i + 1 = " << i + 1 << " et size = " << tab.size() << " et m_leftOpe[i + 1] = " + tab[i + 1] << endl;
        if (i + 1 < tab.size() && tab[i + 1] != "*" && tab[i + 1] != "+" && tab[i + 1] != "-")
            return false;
        cout << "second if passed for " + tab[i] << endl;

        if (i + 1 < tab.size() && tab[i + 1] == "*" && i + 2 < tab.size() && tab[i + 2][0] != 'X')
            return false;
        cout << "third if passed for " + tab[i] << endl;

        if (i + 1 < tab.size() && tab[i + 1] == "*" && i + 2 < tab.size() && tab[i + 2][0] == 'X' &&
            i + 3 < tab.size() && tab[i + 3] != "+" && tab[i + 3] != "-")
            return false;
        cout << "last if passed for " + tab[i] << endl;

        if (tab[tab.size() - 1] == "-" || tab[tab.size() - 1] == "+" || tab[tab.size() - 1] == "*")
            return false;
        
        i += (i + 1 < tab.size() && tab[i + 1] == "*") ? 4 : 2;
    }
    return true;
}

bool Parser::parseConstruct()
{
    cout << "parse construct function -" << endl;
    return (constructSide(m_leftOpe) && constructSide(m_rightOpe));
}