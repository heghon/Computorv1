/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Equation.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:35:33 by bmenant           #+#    #+#             */
/*   Updated: 2021/12/19 19:55:36 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_EQUATION
#define DEF_EQUATION

#include <string>
#include <vector>

class Equation
{
    public:

    Equation(std::string totalEquation);
    bool equationInTwoTabs();
    void showTheEquation();
    void takeCoeff();

    private:

    std::vector<std::string> m_leftOpe;
    std::vector<std::string> m_rightOpe;
    std::vector<double> m_temp;
    std::vector<double> m_leftCoeff;
    std::vector<double> m_rightCoeff;
    std::vector<double> m_finalCoeff;
    std::string m_totalEquation;
};

#endif