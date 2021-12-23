/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:30:26 by bmenant           #+#    #+#             */
/*   Updated: 2021/12/23 15:48:26 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>
#include "../inc/computor.h"
#include "../inc/Parser.h"
#include "../inc/Equation.h"

using namespace std;

void badParsing()
{
    cout << "Your equation's expression is false, you should rewrite it correctly" << endl;
    exit(0);
}

bool strPotentialD(string str)
{
    bool point = false;

    for (int i(0); i < str.size(); i++)
    {
        if (str[i] == '.' && point)
            return false;
        else if (str[i] == '.' && !point)
            point = true;
        else if (!isdigit(str[i]))
            return false;
    }
        cout << "strPotentialD : true returned for " << str << endl;
    return true;
}

bool orderCheck(vector<string> tab)
{
    cout << "in order check function - " << endl;
    int i(2);
    int j(1);

    for (int a(0); a < tab.size(); a++)
    {
        cout << "tab en cours : tab[" << a << "] = " << tab[a] << endl;
    }
    if (tab.size() >= 2 && (tab[1] == "+" || tab[1] == "-"))
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
            j++;
        }
    }

    else
    {
        i = 0;
        while (i < tab.size())
        {
            if (tab.size() >= i + 1 && !strPotentialD(tab[i]))
                return false;
            cout << "first sif passed" << endl;
            if (tab.size() >= i + 2 && tab[i + 1] != "*")
                return false;
            cout << "second sif passed" << endl;
            if (tab.size() >= i + 3 && tab[i + 2][0] != 'X')
                return false;
            cout << "third sif passed" << endl;
            if (tab.size() >= i + 4 && !(tab[i + 3] == "+" || tab[i + 3] == "-"))
                return false;
            cout << "last sif passed" << endl;
            i += 4;
            j++;
        }
    }

    return true;
}

int parse(int paramNbr, char param[])
{
    Parser p(param);

    if (p.equationInTwoTabs() && p.parseConstruct() && p.parseOrder() && p.parseCheckX() >= 0)
    {
        p.showTheEquation();
        return p.parseCheckX();
    }
    return -1;

    // int pwr[]={0, 0, 0}; // power[0] = x^0, power[1] = x^1, power[2] = x^2
    // bool boolPwr[]={false, false, false};
    // int afterPwr[]={0, 0, 0}; // for after the = sign
    // bool boolAfterPwr[]={false, false, false};

    // string nbrTemp = "";
    // string pwrTemp = "";
    // char signTemp = NULL;

    // if (paramNbr > 1)
    // {
    //     cout << "there is " <<  paramNbr - 1 << " argument for this program and the first is : \"" << param << "\"" << endl;

    //     int i(0);
    //     int j(0);
    //     while (param[i])
    //     {
            

            // if (param[i] != ' ' && (param[i] == '+' || param[i] == '-'))
            // {
            //     signTemp = param[i];
            //     if (pwr[j] != 0)
            //     {
            //         boolPwr[j] = true;
            //         j++;
            //     }
            // }
            // else if (param[i] != ' ' && isdigit(param[i]) && (signTemp == '+' || signTemp == '-' || i == 0 || nbrTemp != ""))
            // {
            //     nbrTemp.push_back(param[i]);
            // }
            // else if (param[i] != ' ' && (param[i] == 'X' || param[i] == '^' || isdigit(param[i])))
            // {
            //     pwrTemp.push_back(param[i]);
            // }
            // else if (param[i] == ' ')
            // {
            //     if (nbrTemp != "")
            //     {
            //         cout << "there is a number" << endl;
            //         pwr[j] = stoi(nbrTemp);
            //         pwr[j] *= signTemp == '-' ? -1 : 1;
            //         nbrTemp = "";
            //         signTemp = NULL;
            //     }
            //     else if (pwrTemp != "")
            //     {
            //         cout << "power is here" << endl;
            //         if (pwr[j] && (pwrTemp == "X" || pwrTemp == "X^2"))
            //         {
            //             boolPwr[j] = true;
            //             j++;
            //         }
            //         else
            //             badParsing();
            //     }
            // }
            // else 
            //     badParsing();
            // i++; 
        // }
    // }
}